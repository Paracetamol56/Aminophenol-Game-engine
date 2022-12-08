
#include "pch.h"
#include "FrameBuffers.h"

namespace Aminophenol {

	FrameBuffers::FrameBuffers(const LogicalDevice& logicalDevice, const Swapchain& swapchain, const RenderPass& renderPass)
		: m_logicalDevice{ logicalDevice }
		, m_swapchain{ swapchain }
		, m_renderPass{ renderPass }
		, m_attachments{ m_swapchain.getImageViews() }
	{
		m_frameBuffers.resize(m_attachments.size());

		for (size_t i = 0; i < m_attachments.size(); i++)
		{
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
				throw std::runtime_error("failed to create framebuffer!");
			}
		}
	}

	FrameBuffers::~FrameBuffers()
	{
		for (auto framebuffer : m_frameBuffers)
		{
			vkDestroyFramebuffer(m_logicalDevice, framebuffer, nullptr);
		}
	}

	const std::vector<VkFramebuffer>& FrameBuffers::getFrameBuffers() const
	{
		return m_frameBuffers;
	}

} // namespace Aminophenol