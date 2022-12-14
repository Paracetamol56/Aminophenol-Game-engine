
#include "pch.h"
#include "Renderer.h"

#include "Logging/Logger.h"

namespace Aminophenol {

	Renderer::Renderer(const LogicalDevice& logicalDevice, const Swapchain& swapchain, const Pipeline& pipeline, const CommandPool& commandPool)
		: m_logicalDevice{ logicalDevice }
		, m_swapchain{ swapchain }
		, m_pipeline{ pipeline }
		, m_commandPool{ commandPool }
		, m_attachments{ m_swapchain.getImageViews() }
	{
		Logger::log(LogLevel::Trace, "Global CommandBuffer initialized");

		size_t size = m_attachments.size();

		m_frameBuffers.resize(size);
		m_commandBuffers.resize(size);
		m_imageAvailableSemaphores.resize(size);
		m_renderFinishedSemaphores.resize(size);
		m_inFlightFences.resize(size);

		for (size_t i = 0; i < size; i++)
		{
			// Create the frame buffer for the current swapchain image
			VkImageView attachments[] = { m_attachments[i] };

			VkFramebufferCreateInfo framebufferInfo{};
			framebufferInfo.sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
			framebufferInfo.renderPass = m_pipeline.getRenderPass();
			framebufferInfo.attachmentCount = 1;
			framebufferInfo.pAttachments = attachments;
			framebufferInfo.width = m_swapchain.getExtent().width;
			framebufferInfo.height = m_swapchain.getExtent().height;
			framebufferInfo.layers = 1;

			if (vkCreateFramebuffer(m_logicalDevice, &framebufferInfo, nullptr, &m_frameBuffers[i]) != VK_SUCCESS)
			{
				throw std::runtime_error("Failed to create framebuffer!");
			}

			Logger::log(LogLevel::Trace, "FrameBuffer %d initialized", i);

			m_commandBuffers[i] = std::make_unique<CommandBuffer>(m_logicalDevice, m_commandPool);

			Logger::log(LogLevel::Trace, "CommandBuffer %d initialized", i);
			
			// Create semaphores for the current swapchain image
			VkSemaphoreCreateInfo semaphoreInfo{};
			semaphoreInfo.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;
			
			if (vkCreateSemaphore(m_logicalDevice, &semaphoreInfo, nullptr, &m_imageAvailableSemaphores[i]) != VK_SUCCESS ||
				vkCreateSemaphore(m_logicalDevice, &semaphoreInfo, nullptr, &m_renderFinishedSemaphores[i]) != VK_SUCCESS)
			{
				throw std::runtime_error("Failed to create semaphores!");
			}

			Logger::log(LogLevel::Trace, "Semaphores %d initialized", i);

			// Create the fence for the current swapchain image
			VkFenceCreateInfo fenceInfo{};
			fenceInfo.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
			fenceInfo.flags = VK_FENCE_CREATE_SIGNALED_BIT;
			
			if (vkCreateFence(m_logicalDevice, &fenceInfo, nullptr, &m_inFlightFences[i]) != VK_SUCCESS)
			{
				throw std::runtime_error("Failed to create fence!");
			}
			
			Logger::log(LogLevel::Trace, "Fence %d initialized", i);
		}

		m_globalCommandBuffer = std::make_unique<CommandBuffer>(m_logicalDevice, m_commandPool);

		Logger::log(LogLevel::Trace, "Global CommandBuffer initialized");
	}

	Renderer::~Renderer()
	{
		vkDeviceWaitIdle(m_logicalDevice);

		for (size_t i = 0; i < m_frameBuffers.size(); i++)
		{
			vkDestroyFramebuffer(m_logicalDevice, m_frameBuffers[i], nullptr);
			
			vkDestroySemaphore(m_logicalDevice, m_imageAvailableSemaphores[i], nullptr);
			vkDestroySemaphore(m_logicalDevice, m_renderFinishedSemaphores[i], nullptr);
			vkDestroyFence(m_logicalDevice, m_inFlightFences[i], nullptr);
		}
	}

	void Renderer::render()
	{
		// Wait for the fence to be signaled
		vkWaitForFences(m_logicalDevice, 1, &m_inFlightFences[m_currentFrame], VK_TRUE, UINT64_MAX);
		vkResetFences(m_logicalDevice, 1, &m_inFlightFences[m_currentFrame]);

		// Acquire the next image
		uint32_t imageIndex;

		if (vkAcquireNextImageKHR(m_logicalDevice, m_swapchain, UINT64_MAX, m_imageAvailableSemaphores[m_currentFrame], VK_NULL_HANDLE, &imageIndex) != VK_SUCCESS)
		{
			Logger::log(LogLevel::Error, "Failed to acquire swapchain image!");
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
		
		if (vkQueueSubmit(m_logicalDevice.getGraphicsQueue(), 1, &submitInfo, m_inFlightFences[m_currentFrame]) != VK_SUCCESS)
		{
			Logger::log(LogLevel::Error, "Failed to submit draw command buffer!");
		}

		// Present the image
		VkPresentInfoKHR presentInfo{};
		presentInfo.sType = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR;
		presentInfo.waitSemaphoreCount = 1;
		presentInfo.pWaitSemaphores = signalSemaphores;

		VkSwapchainKHR swapChains[] = { m_swapchain };
		presentInfo.swapchainCount = 1;
		presentInfo.pSwapchains = swapChains;
		presentInfo.pImageIndices = &imageIndex;
		presentInfo.pResults = nullptr;
		
		if (vkQueuePresentKHR(m_logicalDevice.getPresentQueue(), &presentInfo) != VK_SUCCESS)
		{
			Logger::log(LogLevel::Error, "Failed to present swapchain image!");
		}
	}
	
	const std::vector<VkFramebuffer>& Renderer::getFrameBuffers() const
	{
		return m_frameBuffers;
	}

	void Renderer::recordDrawCommand(uint32_t imageIndex)
	{
		VkCommandBufferBeginInfo beginInfo{};
		beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
		beginInfo.flags = VK_COMMAND_BUFFER_USAGE_SIMULTANEOUS_USE_BIT;
		
		if (vkBeginCommandBuffer(m_commandBuffers[imageIndex]->getCommandBuffer(), &beginInfo) != VK_SUCCESS)
		{
			throw std::runtime_error("Failed to begin recording command buffer!");
		}

		VkRenderPassBeginInfo renderPassInfo{};
		renderPassInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
		renderPassInfo.renderPass = m_pipeline.getRenderPass();
		renderPassInfo.framebuffer = m_frameBuffers[imageIndex];
		renderPassInfo.renderArea.offset = { 0, 0 };
		renderPassInfo.renderArea.extent = m_swapchain.getExtent();
		
		VkClearValue clearColor = {0.2f, 0.5f, 1.0f, 1.0f};
		renderPassInfo.clearValueCount = 1;
		renderPassInfo.pClearValues = &clearColor;
		
		vkCmdBeginRenderPass(m_commandBuffers[imageIndex]->getCommandBuffer(), &renderPassInfo, VK_SUBPASS_CONTENTS_INLINE);
		
		vkCmdBindPipeline(m_commandBuffers[imageIndex]->getCommandBuffer(), VK_PIPELINE_BIND_POINT_GRAPHICS, m_pipeline);

		vkCmdDraw(m_commandBuffers[imageIndex]->getCommandBuffer(), 3, 1, 0, 0);

		vkCmdEndRenderPass(m_commandBuffers[imageIndex]->getCommandBuffer());
				
		if (vkEndCommandBuffer(m_commandBuffers[imageIndex]->getCommandBuffer()) != VK_SUCCESS)
		{
			throw std::runtime_error("Failed to record command buffer!");
		}
	}

} // namespace Aminophenol
