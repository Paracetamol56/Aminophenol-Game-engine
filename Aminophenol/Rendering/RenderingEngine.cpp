
#include "pch.h"
#include "RenderingEngine.h"
#include "Maths/Matrix4.h"

#include "Logging/Logger.h"

namespace Aminophenol {

	RenderingEngine::RenderingEngine(const Window& window, const std::string& appName)
		: NonCopyable()
		, m_window{ window }
		, m_instance{ std::make_unique<Instance>(appName) }
		, m_physicalDevice{ std::make_unique<PhysicalDevice>(*m_instance) }
		, m_logicalDevice{ std::make_unique<LogicalDevice>(*m_instance, *m_physicalDevice) }
		, m_surface{ std::make_unique<Surface>(*m_instance, window, *m_logicalDevice, *m_physicalDevice) }
		, m_swapchain{ std::make_unique<Swapchain>(*m_logicalDevice, *m_physicalDevice, *m_surface, window.getExtent()) }
		, m_pipeline{ std::make_unique<Pipeline>(*m_logicalDevice, m_swapchain->getExtent(), m_swapchain->getFormat(), "../Aminophenol/Shaders/shader.vert.spv", "../Aminophenol/Shaders/shader.frag.spv") }
		, m_commandPool{ std::make_unique<CommandPool>(*m_logicalDevice) }
		, m_globalCommandBuffer{ std::make_unique<CommandBuffer>(*m_logicalDevice, m_commandPool) }
	{
		// Initialize the frame objects
		initFrameObjects();

		m_globalDescriptorSetLayout = std::make_unique<DescriptorSetLayout>(
			*m_logicalDevice,
			std::unordered_map<uint32_t, VkDescriptorSetLayoutBinding>{
				{ 0, UniformBuffer::getDescriptorSetLayoutBinding(0, VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, VK_SHADER_STAGE_VERTEX_BIT) }
			}
		);

		m_globalDescriptorPool = std::make_unique<DescriptorPool>(
			*m_logicalDevice,
			std::vector<VkDescriptorPoolSize>{
				VkDescriptorPoolSize{ VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, static_cast<uint32_t>(m_maxFramesInFlight) }
			},
			m_maxFramesInFlight,
			0
		);

		// Create a gloabal descriptor set
		std::vector<VkDescriptorSet> globalDescriptorSets{ m_maxFramesInFlight };
		for (size_t i = 0; i < m_maxFramesInFlight; ++i)
		{
			DescriptorWriter writer = m_frames[i].uniformBuffer->getDescriptorWriter(
				*m_globalDescriptorSetLayout,
				*m_globalDescriptorPool,
				0
			);
			
			writer.build(globalDescriptorSets[i]);
		}

		Logger::log(LogLevel::Trace, "Global CommandBuffer initialized");
	}

	RenderingEngine::~RenderingEngine()
	{
		vkDeviceWaitIdle(*m_logicalDevice);
		
		destroyFrameObjects();

		m_activeScene.reset();

		m_frames.clear();
		m_globalDescriptorSetLayout.reset();
		m_globalDescriptorPool.reset();
		m_globalCommandBuffer.reset();
		m_commandPool.reset();
		m_pipeline.reset();
		m_swapchain.reset();
		m_surface.reset();
		m_logicalDevice.reset();
		m_physicalDevice.reset();
		m_instance.reset();
		
		Logger::log(LogLevel::Trace, "Rendering engine destroyed.");
	}

	void RenderingEngine::update()
	{
		// No need to render if the window is minimized
		if (m_window.isMinimized())
			return;

		// Wait for the fence to be signaled
		vkWaitForFences(*m_logicalDevice, 1, &m_frames[m_currentFrame].inFlightFence, VK_TRUE, UINT64_MAX);

		// Acquire the next image
		uint32_t imageIndex;
		VkResult aquiringResult = vkAcquireNextImageKHR(*m_logicalDevice, *m_swapchain, UINT64_MAX, m_frames[m_currentFrame].imageAvailableSemaphore, VK_NULL_HANDLE, &imageIndex);
		if (aquiringResult == VK_ERROR_OUT_OF_DATE_KHR)
		{
			Logger::log(LogLevel::Trace, "Failed to acquire next image. Swapchain is out of date. Recreating swapchain...");
			recreateSwapchain();
			return;
		}
		else if (aquiringResult != VK_SUCCESS && aquiringResult != VK_SUBOPTIMAL_KHR)
		{
			throw std::runtime_error("Failed to acquire swapchain image!");
		}

		vkResetCommandBuffer(m_frames[imageIndex].commandBuffer->getCommandBuffer(), 0);

		recordDrawCommand(imageIndex);

		// Submit the command buffer
		VkSubmitInfo submitInfo{};
		submitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;

		VkSemaphore waitSemaphores{ m_frames[m_currentFrame].imageAvailableSemaphore };
		VkSemaphore signalSemaphores{ m_frames[m_currentFrame].renderFinishedSemaphore };

		m_frames[imageIndex].commandBuffer->submit(waitSemaphores, signalSemaphores, m_frames[m_currentFrame].inFlightFence);

		// Present the image
		VkPresentInfoKHR presentInfo{};
		presentInfo.sType = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR;
		presentInfo.waitSemaphoreCount = 1;
		presentInfo.pWaitSemaphores = &signalSemaphores;

		VkSwapchainKHR swapChains[] = { *m_swapchain };
		presentInfo.swapchainCount = 1;
		presentInfo.pSwapchains = swapChains;
		presentInfo.pImageIndices = &imageIndex;
		presentInfo.pResults = nullptr;

		VkResult presentingResult = vkQueuePresentKHR(m_logicalDevice->getPresentQueue(), &presentInfo);
		if (presentingResult == VK_ERROR_OUT_OF_DATE_KHR || presentingResult == VK_SUBOPTIMAL_KHR)
		{
			Logger::log(LogLevel::Trace, "Failed to present image. Swapchain is out of date. Recreating swapchain...");
			recreateSwapchain();
			return;
		}
		else if (presentingResult != VK_SUCCESS)
		{
			throw std::runtime_error("Failed to present swapchain image!");
		}

		m_currentFrame = (m_currentFrame + 1) % m_maxFramesInFlight;
	}
	
	Instance& RenderingEngine::getInstance() const
	{
		return *m_instance;
	}

	PhysicalDevice& RenderingEngine::getPhysicalDevice() const
	{
		return *m_physicalDevice;
	}

	LogicalDevice& RenderingEngine::getLogicalDevice() const
	{
		return *m_logicalDevice;
	}
	
	Surface& RenderingEngine::getSurface() const
	{
		return *m_surface;
	}
	
	Swapchain& RenderingEngine::getSwapchain() const
	{
		return *m_swapchain;
	}

	Pipeline& RenderingEngine::getPipeline() const
	{
		return *m_pipeline;
	}

	const std::shared_ptr<CommandPool> RenderingEngine::getCommandPool() const
	{
		return m_commandPool;
	}

	void Aminophenol::RenderingEngine::setActiveScene(const std::shared_ptr<Scene> scene)
	{
		m_activeScene = scene;
		if (m_activeScene->getActiveCamera())
			m_activeScene->getActiveCamera()->setAspectRatio(m_swapchain->getExtent().width / static_cast<float>(m_swapchain->getExtent().height));
	}
	std::shared_ptr<Scene> RenderingEngine::getActiveScene() const
	{
		return m_activeScene;
	}

	void RenderingEngine::initFrameObjects()
	{
		m_attachments = m_swapchain->getImageViews();

		// Resize vectors
		m_maxFramesInFlight = m_attachments.size();

		m_frames.resize(m_maxFramesInFlight);

		// Initialize all syncronization objects
		for (size_t i = 0; i < m_maxFramesInFlight; i++)
		{
			// Create a depth buffer
			m_frames[i].depthBuffer = std::make_unique<ImageDepth>(
				*m_logicalDevice, *m_physicalDevice, m_commandPool,
				VkExtent3D{ m_swapchain->getExtent().width, m_swapchain->getExtent().height, 1 }
			);

			Logger::log(LogLevel::Trace, "DepthBuffer %d initialized", i);

			// Create a frame buffer
			std::array<VkImageView, 2> attachments = { m_attachments[i], m_frames[i].depthBuffer->getImageView() };

			VkFramebufferCreateInfo framebufferInfo{};
			framebufferInfo.sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
			framebufferInfo.renderPass = m_pipeline->getRenderPass();
			framebufferInfo.attachmentCount = static_cast<uint32_t>(attachments.size());
			framebufferInfo.pAttachments = attachments.data();
			framebufferInfo.width = m_swapchain->getExtent().width;
			framebufferInfo.height = m_swapchain->getExtent().height;
			framebufferInfo.layers = 1;

			if (vkCreateFramebuffer(m_logicalDevice->getDevice(), &framebufferInfo, nullptr, &m_frames[i].frameBuffer) != VK_SUCCESS)
			{
				throw std::runtime_error("Failed to create framebuffer!");
			}

			Logger::log(LogLevel::Trace, "FrameBuffer %d initialized", i);

			// Create a command buffer
			m_frames[i].commandBuffer = std::make_unique<CommandBuffer>(*m_logicalDevice, m_commandPool);

			Logger::log(LogLevel::Trace, "CommandBuffer %d initialized", i);

			// Create a UBO
			m_frames[i].uniformBuffer = std::make_unique<UniformBuffer>(*m_logicalDevice, sizeof(FrameUniformBufferObject), &m_frames[i].uniformBufferData);

			Logger::log(LogLevel::Trace, "UniformBuffer %d initialized", i);

			// Create 2 semaphores and 1 fence
			VkSemaphoreCreateInfo semaphoreInfo{};
			semaphoreInfo.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;

			if (vkCreateSemaphore(m_logicalDevice->getDevice(), &semaphoreInfo, nullptr, &m_frames[i].imageAvailableSemaphore) != VK_SUCCESS ||
				vkCreateSemaphore(m_logicalDevice->getDevice(), &semaphoreInfo, nullptr, &m_frames[i].renderFinishedSemaphore) != VK_SUCCESS)
			{
				throw std::runtime_error("Failed to create semaphores!");
			}

			VkFenceCreateInfo fenceInfo{};
			fenceInfo.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
			fenceInfo.flags = VK_FENCE_CREATE_SIGNALED_BIT;

			if (vkCreateFence(m_logicalDevice->getDevice(), &fenceInfo, nullptr, &m_frames[i].inFlightFence) != VK_SUCCESS)
			{
				throw std::runtime_error("Failed to create fences!");
			}
		}
	}

	void RenderingEngine::destroyFrameObjects()
	{
		for (size_t i = 0; i < m_maxFramesInFlight; ++i)
		{
			vkDestroyFramebuffer(m_logicalDevice->getDevice(), m_frames[i].frameBuffer, nullptr);
			m_frames[i].depthBuffer.reset();
			m_frames[i].commandBuffer.reset();
			m_frames[i].uniformBuffer.reset();
			vkDestroySemaphore(m_logicalDevice->getDevice(), m_frames[i].imageAvailableSemaphore, nullptr);
			vkDestroySemaphore(m_logicalDevice->getDevice(), m_frames[i].renderFinishedSemaphore, nullptr);
			vkDestroyFence(m_logicalDevice->getDevice(), m_frames[i].inFlightFence, nullptr);
		}
	}

	void RenderingEngine::recordDrawCommand(uint32_t imageIndex)
	{
		m_frames[imageIndex].commandBuffer->begin(VK_COMMAND_BUFFER_USAGE_SIMULTANEOUS_USE_BIT);
		
		// Begin render pass
		VkRenderPassBeginInfo renderPassInfo{};
		renderPassInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
		renderPassInfo.renderPass = m_pipeline->getRenderPass();
		renderPassInfo.framebuffer = m_frames[imageIndex].frameBuffer;
		renderPassInfo.renderArea.offset = { 0, 0 };
		renderPassInfo.renderArea.extent = m_swapchain->getExtent();

		if (m_activeScene == nullptr)
		{
			Logger::log(LogLevel::Warning, "No active scene!");
			m_frames[imageIndex].commandBuffer->end();
			return;
		}
		
		std::array<VkClearValue, 2> clearValues{};
		clearValues[0].color = {
			m_activeScene->getBackgroundColor().r,
			m_activeScene->getBackgroundColor().g,
			m_activeScene->getBackgroundColor().b,
			m_activeScene->getBackgroundColor().a
		};
		clearValues[1].depthStencil = { 1.0f, 0 };

		renderPassInfo.clearValueCount = static_cast<uint32_t>(clearValues.size());
		renderPassInfo.pClearValues = clearValues.data();

		vkCmdBeginRenderPass(m_frames[imageIndex].commandBuffer->getCommandBuffer(), &renderPassInfo, VK_SUBPASS_CONTENTS_INLINE);

		vkCmdBindPipeline(m_frames[imageIndex].commandBuffer->getCommandBuffer(), VK_PIPELINE_BIND_POINT_GRAPHICS, *m_pipeline);

		// Update viewport and scissor
		VkViewport viewport{};
		viewport.x = 0.0f;
		viewport.y = 0.0f;
		viewport.width = (float)m_swapchain->getExtent().width;
		viewport.height = (float)m_swapchain->getExtent().height;
		viewport.minDepth = 0.0f;
		viewport.maxDepth = 1.0f;

		VkRect2D scissor{};
		scissor.offset = { 0, 0 };
		scissor.extent = m_swapchain->getExtent();

		vkCmdSetViewport(m_frames[imageIndex].commandBuffer->getCommandBuffer(), 0, 1, &viewport);
		vkCmdSetScissor(m_frames[imageIndex].commandBuffer->getCommandBuffer(), 0, 1, &scissor);

		// Iterate through all renderables in the active scene and draw them
		for (std::vector<std::unique_ptr<Node>>::iterator it = m_activeScene->begin(); it != m_activeScene->end(); ++it)
		{
			PushConstantData push{};
			push.projectionMatrix = m_activeScene->getActiveCamera()->getProjectionMatrix();
			push.viewMatrix = m_activeScene->getActiveCamera()->getViewMatrix();
			push.modelMatrix = (*it)->transform.getMatrix();
			push.normalMatrix = (*it)->transform.getMatrix();

			vkCmdPushConstants(
				m_frames[imageIndex].commandBuffer->getCommandBuffer(),
				m_pipeline->getPipelineLayout(),
				VK_SHADER_STAGE_VERTEX_BIT,
				0,
				sizeof(PushConstantData),
				&push
			);

			// If the Node has a MeshRenderer component, draw it
			std::vector<MeshRenderer*> renderers = (*it)->getComponentsOfType<MeshRenderer>();
			for (std::vector<MeshRenderer*>::iterator it2 = renderers.begin(); it2 != renderers.end(); ++it2)
			{
				(*it2)->renderMesh(m_frames[imageIndex].commandBuffer->getCommandBuffer());
			}
		}

		vkCmdEndRenderPass(m_frames[imageIndex].commandBuffer->getCommandBuffer());
		
		m_frames[imageIndex].commandBuffer->end();
	}

	void RenderingEngine::recreateSwapchain()
	{	
		int width = 0, height = 0;
		glfwGetFramebufferSize(m_window, &width, &height);
		while (width == 0 || height == 0)
		{
			glfwGetFramebufferSize(m_window, &width, &height);
			glfwWaitEvents();
		}

		vkDeviceWaitIdle(*m_logicalDevice);

		destroyFrameObjects();
		m_swapchain.reset(new Swapchain(*m_logicalDevice, *m_physicalDevice, *m_surface, m_window.getExtent(), m_swapchain.get()));
		m_activeScene->getActiveCamera()->setAspectRatio(m_swapchain->getExtent().width / static_cast<float>(m_swapchain->getExtent().height));
		initFrameObjects();
	}

} // namespace Aminophenol
