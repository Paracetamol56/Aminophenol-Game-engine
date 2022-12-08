
#ifndef FRAME_BUFFERS_H
#define FRAME_BUFFERS_H

#include "pch.h"

#include "Rendering/LogicalDevice.h"
#include "Rendering/Swapchain/Swapchain.h"
#include "Rendering/Swapchain/RenderPass.h"

namespace Aminophenol {

	class AMINOPHENOL_API FrameBuffers
	{
	public:

		FrameBuffers(const LogicalDevice& logicalDevice, const Swapchain& swapchain, const RenderPass& renderPass);
		~FrameBuffers();

		const std::vector<VkFramebuffer>& getFrameBuffers() const;

	private:

		std::vector<VkFramebuffer> m_frameBuffers;
		std::vector<VkImageView> m_attachments;

		const LogicalDevice& m_logicalDevice;
		const Swapchain& m_swapchain;
		const RenderPass& m_renderPass;

	};

} // namespace Aminophenol

#endif // FRAME_BUFFERS_H
