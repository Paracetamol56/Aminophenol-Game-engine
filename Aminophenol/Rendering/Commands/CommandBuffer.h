
#ifndef COMMAND_BUFFER_H
#define COMMAND_BUFFER_H

#include "pch.h"

#include "Rendering/Device/LogicalDevice.h"
#include "Rendering/Commands/CommandPool.h"

namespace Aminophenol {

	class CommandBuffer
	{
	public:
		
		CommandBuffer(
			const LogicalDevice& logicalDevice,
			const std::shared_ptr<CommandPool> commandPool,
			const VkQueueFlagBits queueType = VK_QUEUE_GRAPHICS_BIT,
			const VkCommandBufferLevel& level = VK_COMMAND_BUFFER_LEVEL_PRIMARY
		);
		~CommandBuffer();

		operator const VkCommandBuffer& () const;
		const VkCommandBuffer& getCommandBuffer() const;

		void begin(const VkCommandBufferUsageFlags& usage = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT);
		void end();
		void submit(const VkSemaphore& waitSemaphore, const VkSemaphore& signalSemaphore, VkFence fence);
		void submitIdle();

	private:
		
		VkCommandBuffer m_commandBuffer{ VK_NULL_HANDLE };

		const LogicalDevice& m_logicalDevice;
		std::shared_ptr<CommandPool> m_commandPool;
		const VkQueueFlagBits m_queueType;
		VkQueue getQueue() const;
		
		bool m_isRecording{ false };

	};

} // namespace Aminophenol

#endif // COMMAND_BUFFER_H
