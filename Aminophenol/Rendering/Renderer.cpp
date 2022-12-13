
#include "pch.h"
#include "Renderer.h"

#include "Logging/Logger.h"

namespace Aminophenol {

	Renderer::Renderer(const LogicalDevice& logicalDevice, const Swapchain& swapchain, const RenderPass& renderPass, const CommandPool& commandPool)
		: m_logicalDevice{ logicalDevice }
		, m_swapchain{ swapchain }
		, m_renderPass{ renderPass }
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
			framebufferInfo.renderPass = m_renderPass;
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

			m_commandBuffers.emplace_back(std::make_unique<CommandBuffer>(m_logicalDevice, m_commandPool));

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
		for (size_t i = 0; i < m_frameBuffers.size(); i++)
		{
			vkDestroyFramebuffer(m_logicalDevice, m_frameBuffers[i], nullptr);
			
			vkDestroySemaphore(m_logicalDevice, m_imageAvailableSemaphores[i], nullptr);
			vkDestroySemaphore(m_logicalDevice, m_renderFinishedSemaphores[i], nullptr);
			vkDestroyFence(m_logicalDevice, m_inFlightFences[i], nullptr);
		}
	}

	const std::vector<VkFramebuffer>& Renderer::getFrameBuffers() const
	{
		return m_frameBuffers;
	}

} // namespace Aminophenol
