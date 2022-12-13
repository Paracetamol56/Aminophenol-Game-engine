
#include "pch.h"
#include "CommandBuffer.h"

namespace Aminophenol {
	
	CommandBuffer::CommandBuffer(const LogicalDevice& logicalDevice, const CommandPool& commandPool, const VkCommandBufferLevel& level)
		: m_logicalDevice(logicalDevice)
		, m_commandPool(commandPool)
	{
		// Allocate command buffer
		// Documentation: https://registry.khronos.org/vulkan/specs/1.3-khr-extensions/html/chap6.html#VkCommandBufferAllocateInfo
		VkCommandBufferAllocateInfo commandBufferAllocateInfo{};
		commandBufferAllocateInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
		commandBufferAllocateInfo.commandPool = m_commandPool;
		commandBufferAllocateInfo.level = level;
		commandBufferAllocateInfo.commandBufferCount = 1;

		// Documentation: https://registry.khronos.org/vulkan/specs/1.3-khr-extensions/html/chap6.html#commandbuffer-allocation
		if (vkAllocateCommandBuffers(m_logicalDevice, &commandBufferAllocateInfo, &m_commandBuffer) != VK_SUCCESS)
		{
			throw std::runtime_error("Failed to allocate command buffer!");
		}
	}

	CommandBuffer::~CommandBuffer()
	{
	}

	CommandBuffer::operator const VkCommandBuffer& () const
	{
		return m_commandBuffer;
	}

} // namespace Aminophenol

