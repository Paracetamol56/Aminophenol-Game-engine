
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
	{
		initFrameObjects();

		m_globalCommandBuffer = std::make_unique<CommandBuffer>(*m_logicalDevice, m_commandPool);

		Logger::log(LogLevel::Trace, "Global CommandBuffer initialized");
	}

	RenderingEngine::~RenderingEngine()
	{
		vkDeviceWaitIdle(*m_logicalDevice);
		
		destroyFrameObjects();

		m_activeScene.reset();

		m_commandBuffers.clear();
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
		vkWaitForFences(*m_logicalDevice, 1, &m_inFlightFences[m_currentFrame], VK_TRUE, UINT64_MAX);

		// Acquire the next image
		uint32_t imageIndex;
		VkResult aquiringResult = vkAcquireNextImageKHR(*m_logicalDevice, *m_swapchain, UINT64_MAX, m_imageAvailableSemaphores[m_currentFrame], VK_NULL_HANDLE, &imageIndex);
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

		vkResetCommandBuffer(m_commandBuffers[imageIndex]->getCommandBuffer(), 0);

		recordDrawCommand(imageIndex);

		// Submit the command buffer
		VkSubmitInfo submitInfo{};
		submitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;

		VkSemaphore waitSemaphores[] = { m_imageAvailableSemaphores[m_currentFrame] };
		VkPipelineStageFlags waitStages[] = { VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT };
		submitInfo.waitSemaphoreCount = 1;
		submitInfo.pWaitSemaphores = waitSemaphores;
		submitInfo.pWaitDstStageMask = waitStages;
		submitInfo.commandBufferCount = 1;
		submitInfo.pCommandBuffers = &m_commandBuffers[imageIndex]->getCommandBuffer();

		VkSemaphore signalSemaphores[] = { m_renderFinishedSemaphores[m_currentFrame] };
		submitInfo.signalSemaphoreCount = 1;
		submitInfo.pSignalSemaphores = signalSemaphores;

		vkResetFences(*m_logicalDevice, 1, &m_inFlightFences[m_currentFrame]);

		if (vkQueueSubmit(m_logicalDevice->getGraphicsQueue(), 1, &submitInfo, m_inFlightFences[m_currentFrame]) != VK_SUCCESS)
		{
			Logger::log(LogLevel::Error, "Failed to submit draw command buffer!");
		}

		// Present the image
		VkPresentInfoKHR presentInfo{};
		presentInfo.sType = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR;
		presentInfo.waitSemaphoreCount = 1;
		presentInfo.pWaitSemaphores = signalSemaphores;

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

		m_frameBuffers.resize(m_maxFramesInFlight);
		m_commandBuffers.resize(m_maxFramesInFlight);
		m_imageAvailableSemaphores.resize(m_maxFramesInFlight);
		m_renderFinishedSemaphores.resize(m_maxFramesInFlight);
		m_inFlightFences.resize(m_maxFramesInFlight);

		// Initialize all syncronization objects
		for (size_t i = 0; i < m_maxFramesInFlight; i++)
		{
			// Create a frame buffer
			VkImageView attachments[] = { m_attachments[i] };

			VkFramebufferCreateInfo framebufferInfo{};
			framebufferInfo.sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
			framebufferInfo.renderPass = m_pipeline->getRenderPass();
			framebufferInfo.attachmentCount = 1;
			framebufferInfo.pAttachments = attachments;
			framebufferInfo.width = m_swapchain->getExtent().width;
			framebufferInfo.height = m_swapchain->getExtent().height;
			framebufferInfo.layers = 1;

			if (vkCreateFramebuffer(m_logicalDevice->getDevice(), &framebufferInfo, nullptr, &m_frameBuffers[i]) != VK_SUCCESS)
			{
				throw std::runtime_error("Failed to create framebuffer!");
			}

			Logger::log(LogLevel::Trace, "FrameBuffer %d initialized", i);

			m_commandBuffers[i] = std::make_unique<CommandBuffer>(*m_logicalDevice, m_commandPool);

			Logger::log(LogLevel::Trace, "CommandBuffer %d initialized", i);

			// Create 2 semaphores and 1 fence
			VkSemaphoreCreateInfo semaphoreInfo{};
			semaphoreInfo.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;

			if (vkCreateSemaphore(m_logicalDevice->getDevice(), &semaphoreInfo, nullptr, &m_imageAvailableSemaphores[i]) != VK_SUCCESS ||
				vkCreateSemaphore(m_logicalDevice->getDevice(), &semaphoreInfo, nullptr, &m_renderFinishedSemaphores[i]) != VK_SUCCESS)
			{
				throw std::runtime_error("Failed to create semaphores!");
			}

			VkFenceCreateInfo fenceInfo{};
			fenceInfo.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
			fenceInfo.flags = VK_FENCE_CREATE_SIGNALED_BIT;

			if (vkCreateFence(m_logicalDevice->getDevice(), &fenceInfo, nullptr, &m_inFlightFences[i]) != VK_SUCCESS)
			{
				throw std::runtime_error("Failed to create fences!");
			}
		}
	}

	void RenderingEngine::destroyFrameObjects()
	{
		for (size_t i = 0; i < m_maxFramesInFlight; i++)
		{
			vkDestroyFramebuffer(m_logicalDevice->getDevice(), m_frameBuffers[i], nullptr);
			vkDestroySemaphore(m_logicalDevice->getDevice(), m_imageAvailableSemaphores[i], nullptr);
			vkDestroySemaphore(m_logicalDevice->getDevice(), m_renderFinishedSemaphores[i], nullptr);
			vkDestroyFence(m_logicalDevice->getDevice(), m_inFlightFences[i], nullptr);
		}
	}

	void RenderingEngine::recordDrawCommand(uint32_t imageIndex)
	{
		// Begin recording
		VkCommandBufferBeginInfo beginInfo{};
		beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
		beginInfo.flags = VK_COMMAND_BUFFER_USAGE_SIMULTANEOUS_USE_BIT;

		if (vkBeginCommandBuffer(m_commandBuffers[imageIndex]->getCommandBuffer(), &beginInfo) != VK_SUCCESS)
		{
			throw std::runtime_error("Failed to begin recording command buffer!");
		}
		
		// Begin render pass
		VkRenderPassBeginInfo renderPassInfo{};
		renderPassInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
		renderPassInfo.renderPass = m_pipeline->getRenderPass();
		renderPassInfo.framebuffer = m_frameBuffers[imageIndex];
		renderPassInfo.renderArea.offset = { 0, 0 };
		renderPassInfo.renderArea.extent = m_swapchain->getExtent();

		if (m_activeScene == nullptr)
		{
			Logger::log(LogLevel::Warning, "No active scene!");
		}
		else
		{
			VkClearValue clearColor{0.0f, 0.0f, 0.0f, 1.0f};

			renderPassInfo.clearValueCount = 1;
			renderPassInfo.pClearValues = &clearColor;

			vkCmdBeginRenderPass(m_commandBuffers[imageIndex]->getCommandBuffer(), &renderPassInfo, VK_SUBPASS_CONTENTS_INLINE);

			vkCmdBindPipeline(m_commandBuffers[imageIndex]->getCommandBuffer(), VK_PIPELINE_BIND_POINT_GRAPHICS, *m_pipeline);
			
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

			vkCmdSetViewport(m_commandBuffers[imageIndex]->getCommandBuffer(), 0, 1, &viewport);
			vkCmdSetScissor(m_commandBuffers[imageIndex]->getCommandBuffer(), 0, 1, &scissor);
			
			static int frame = 0;
			++frame;

			PushConstantData push{};
			push.modelTransform =
				Maths::Matrix4f::translation({ 0.0f, 0.0f, 0.5f }) *
				Maths::Matrix4f::rotation({ {0.2f, 0.7f, 0.6f}, frame / 5000.0f }) *
				Maths::Matrix4f::scale({ 0.5f, 0.5f, 0.5f });
			
			vkCmdPushConstants(
				m_commandBuffers[imageIndex]->getCommandBuffer(),
				m_pipeline->getPipelineLayout(),
				VK_SHADER_STAGE_VERTEX_BIT,
				0,
				sizeof(PushConstantData),
				&push
			);
		
			// Iterate through all renderables in the active scene and draw them
			for (std::vector<std::unique_ptr<Node>>::iterator it = m_activeScene->begin(); it != m_activeScene->end(); ++it)
			{
				// If the Node has a MeshRenderer component, draw it
				std::vector<MeshRenderer*> renderers = (*it)->getComponentsOfType<MeshRenderer>();
				for (std::vector<MeshRenderer*>::iterator it2 = renderers.begin(); it2 != renderers.end(); ++it2)
				{
					(*it2)->renderMesh(m_commandBuffers[imageIndex]->getCommandBuffer());
				}
			}

			vkCmdEndRenderPass(m_commandBuffers[imageIndex]->getCommandBuffer());
		}
		
		// End recording
		if (vkEndCommandBuffer(m_commandBuffers[imageIndex]->getCommandBuffer()) != VK_SUCCESS)
		{
			throw std::runtime_error("Failed to record command buffer!");
		}
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
		initFrameObjects();
	}

} // namespace Aminophenol
