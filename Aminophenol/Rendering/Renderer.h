
#ifndef RENDERER_H
#define RENDERER_H

#include "pch.h"

#include "Rendering/LogicalDevice.h"
#include "Rendering/Swapchain/Swapchain.h"
#include "Rendering/Swapchain/RenderPass.h"
#include "Rendering/Commands/CommandPool.h"
#include "Rendering/Commands/CommandBuffer.h"

namespace Aminophenol {

	class AMINOPHENOL_API Renderer
	{
	public:

		Renderer(const LogicalDevice& logicalDevice, const Swapchain& swapchain, const RenderPass& renderPass, const CommandPool& commandPool);
		~Renderer();

		const std::vector<VkFramebuffer>& getFrameBuffers() const;

	private:

		// Buffers
		std::vector<VkFramebuffer> m_frameBuffers{};
		std::vector<std::unique_ptr<CommandBuffer>> m_commandBuffers{};
		std::unique_ptr<CommandBuffer> m_globalCommandBuffer;
		
		// Syncronization
		std::vector<VkSemaphore> m_imageAvailableSemaphores{};
		std::vector<VkSemaphore> m_renderFinishedSemaphores{};
		std::vector<VkFence> m_inFlightFences{};

		// References
		const LogicalDevice& m_logicalDevice;
		const Swapchain& m_swapchain;
		const RenderPass& m_renderPass;
		const CommandPool& m_commandPool;
		const std::vector<VkImageView> m_attachments;

	};

} // namespace Aminophenol

#endif // RENDERER_H