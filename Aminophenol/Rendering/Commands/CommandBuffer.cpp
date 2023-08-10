
#include "pch.h"
#include "CommandBuffer.h"

namespace Aminophenol {
	
	CommandBuffer::CommandBuffer(
		const LogicalDevice& logicalDevice, const std::shared_ptr<CommandPool> commandPool,
		const VkQueueFlagBits queueType, const VkCommandBufferLevel& level
	)
		: m_logicalDevice(logicalDevice)
		, m_commandPool(commandPool)
		, m_queueType(queueType)
	{
		// Allocate command buffer
		// Documentation: https://registry.khronos.org/vulkan/specs/1.3-khr-extensions/html/chap6.html#VkCommandBufferAllocateInfo
		VkCommandBufferAllocateInfo commandBufferAllocateInfo{};
		commandBufferAllocateInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
		commandBufferAllocateInfo.commandPool = *m_commandPool;
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
		vkFreeCommandBuffers(m_logicalDevice, *m_commandPool, 1, &m_commandBuffer);
	}

	CommandBuffer::operator const VkCommandBuffer& () const
	{
		return m_commandBuffer;
	}

	const VkCommandBuffer& CommandBuffer::getCommandBuffer() const
	{
		return m_commandBuffer;
	}

	void CommandBuffer::begin(const VkCommandBufferUsageFlags& usage)
	{
		if (m_isRecording)
			throw std::runtime_error("Command buffer is already recording!");

		VkCommandBufferBeginInfo commandBufferBeginInfo{};
		commandBufferBeginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
		commandBufferBeginInfo.flags = usage;

		if (vkBeginCommandBuffer(m_commandBuffer, &commandBufferBeginInfo) != VK_SUCCESS)
			throw std::runtime_error("Failed to begin recording command buffer!");

		m_isRecording = true;
	}
	
	void CommandBuffer::end()
	{
		if (!m_isRecording)
			throw std::runtime_error("Command buffer is not recording!");

		if (vkEndCommandBuffer(m_commandBuffer) != VK_SUCCESS)
			throw std::runtime_error("Failed to end recording command buffer!");

		m_isRecording = false;
	}

	void CommandBuffer::submit(const VkSemaphore& waitSemaphore, const VkSemaphore& signalSemaphore, VkFence fence)
	{
		if (m_isRecording)
			end();

		VkSubmitInfo submitInfo{};
		submitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
		submitInfo.commandBufferCount = 1;
		submitInfo.pCommandBuffers = &m_commandBuffer;

		if (waitSemaphore != VK_NULL_HANDLE) {
			static VkPipelineStageFlags submitPipelineStages = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;

			submitInfo.pWaitDstStageMask = &submitPipelineStages;
			submitInfo.waitSemaphoreCount = 1;
			submitInfo.pWaitSemaphores = &waitSemaphore;
		}

		if (signalSemaphore != VK_NULL_HANDLE) {
			submitInfo.signalSemaphoreCount = 1;
			submitInfo.pSignalSemaphores = &signalSemaphore;
		}

		if (fence != VK_NULL_HANDLE) {
			if (vkResetFences(m_logicalDevice, 1, &fence) != VK_SUCCESS)
				throw std::runtime_error("Failed to reset fence!");
		}

		if (vkQueueSubmit(getQueue(), 1, &submitInfo, fence) != VK_SUCCESS)
			throw std::runtime_error("Failed to submit command buffer to queue!");
	}

	void CommandBuffer::submitIdle()
	{
		if (m_isRecording)
			end();

		VkSubmitInfo submitInfo{};
		submitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
		submitInfo.commandBufferCount = 1;
		submitInfo.pCommandBuffers = &m_commandBuffer;

		VkFenceCreateInfo fenceCreateInfo{};
		fenceCreateInfo.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;

		VkFence fence;
		if (vkCreateFence(m_logicalDevice, &fenceCreateInfo, nullptr, &fence) != VK_SUCCESS)
			throw std::runtime_error("Failed to create fence!");

		if (vkResetFences(m_logicalDevice, 1, &fence) != VK_SUCCESS)
			throw std::runtime_error("Failed to reset fence!");

		if (vkQueueSubmit(getQueue(), 1, &submitInfo, fence) != VK_SUCCESS)
			throw std::runtime_error("Failed to submit command buffer to queue!");

		if (vkWaitForFences(m_logicalDevice, 1, &fence, VK_TRUE, UINT64_MAX) != VK_SUCCESS)
			throw std::runtime_error("Failed to wait for fence!");

		vkDestroyFence(m_logicalDevice, fence, nullptr);
	}

	VkQueue CommandBuffer::getQueue() const
	{
		switch (m_queueType)
		{
		case VK_QUEUE_GRAPHICS_BIT:
			return m_logicalDevice.getGraphicsQueue();
		case VK_QUEUE_COMPUTE_BIT:
			return m_logicalDevice.getComputeQueue();
		default:
			return VK_NULL_HANDLE;
		}
	}

} // namespace Aminophenol
