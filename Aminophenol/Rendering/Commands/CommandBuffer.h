
#ifndef COMMAND_BUFFER_H
#define COMMAND_BUFFER_H

#include "pch.h"

#include "Rendering/LogicalDevice.h"
#include "Rendering/Commands/CommandPool.h"

namespace Aminophenol {

	class CommandBuffer
	{
	public:
		
		CommandBuffer(const LogicalDevice& logicalDevice, const CommandPool& commandPool, const VkCommandBufferLevel& level = VK_COMMAND_BUFFER_LEVEL_PRIMARY);
		~CommandBuffer();

		operator const VkCommandBuffer& () const;

		const VkCommandBuffer& getCommandBuffer() const;
		
	private:
		
		VkCommandBuffer m_commandBuffer{ VK_NULL_HANDLE };

		const LogicalDevice& m_logicalDevice;
		const CommandPool& m_commandPool;
		
	};

} // namespace Aminophenol

#endif // COMMAND_BUFFER_H
