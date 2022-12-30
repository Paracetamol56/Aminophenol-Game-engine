
#include "pch.h"
#include "Buffer.h"

namespace Aminophenol {

	Buffer::Buffer(LogicalDevice& logicalDevice, VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, void* data, uint32_t instanceCount, VkDeviceSize minOffsetAlignment)
		: m_logicalDevice(logicalDevice)
		, m_size(size), m_usage(usage)
		, m_properties(properties)
		, m_instanceCount(instanceCount)
		, m_minOffsetAlignment(minOffsetAlignment)
	{
		// Create the buffer
		VkBufferCreateInfo bufferInfo = {};
		bufferInfo.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
		bufferInfo.size = m_size;
		bufferInfo.usage = m_usage;
		bufferInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;
		
		if (vkCreateBuffer(m_logicalDevice, &bufferInfo, nullptr, &m_buffer) != VK_SUCCESS) {
			throw std::runtime_error("Failed to create buffer!");
		}
		
		// Get the memory requirements for the buffer
		VkMemoryRequirements memoryRequirements;
		vkGetBufferMemoryRequirements(m_logicalDevice, m_buffer, &memoryRequirements);

		// Allocate the memory for the buffer
		VkMemoryAllocateInfo allocInfo = {};
		allocInfo.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
		allocInfo.allocationSize = memoryRequirements.size;
		allocInfo.memoryTypeIndex = findMemoryType(memoryRequirements.memoryTypeBits, m_properties);
		
		if (vkAllocateMemory(m_logicalDevice, &allocInfo, nullptr, &m_bufferMemory) != VK_SUCCESS) {
			throw std::runtime_error("Failed to allocate buffer memory!");
		}

		// If some data is provided, copy it to the buffer
		if (data != nullptr) {
			void* mappedData;
			vkMapMemory(m_logicalDevice, m_bufferMemory, 0, m_size, 0, &mappedData);
			std::memcpy(mappedData, data, static_cast<size_t>(m_size));
			vkUnmapMemory(m_logicalDevice, m_bufferMemory);
		}

		// Bind the memory to the buffer
		vkBindBufferMemory(m_logicalDevice, m_buffer, m_bufferMemory, 0);
	}

	Buffer::~Buffer()
	{
		vkDestroyBuffer(m_logicalDevice, m_buffer, nullptr);
		vkFreeMemory(m_logicalDevice, m_bufferMemory, nullptr);
	}

	VkResult Buffer::mapMemory(void** data) const
	{
		return vkMapMemory(m_logicalDevice, m_bufferMemory, 0, m_size, 0, data);
	}

	void Buffer::unmapMemory() const
	{
		vkUnmapMemory(m_logicalDevice, m_bufferMemory);
	}

	Buffer::operator const VkBuffer& () const
	{
		return m_buffer;
	}

	const VkBuffer& Buffer::getBuffer() const
	{
		return m_buffer;
	}

	const VkDeviceMemory& Buffer::getDeviceMemory() const
	{
		return m_bufferMemory;
	}

	const VkDeviceSize& Buffer::getSize() const
	{
		return m_size;
	}

	const uint32_t& Buffer::getInstanceCount() const
	{
		return m_instanceCount;
	}

	const VkDeviceSize& Buffer::getMinOffsetAlignment() const
	{
		return m_minOffsetAlignment;
	}

	uint32_t Buffer::findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties) const
	{
		VkPhysicalDeviceMemoryProperties memProperties;
		vkGetPhysicalDeviceMemoryProperties(m_logicalDevice.getPhysicalDevice(), &memProperties);

		for (uint32_t i = 0; i < memProperties.memoryTypeCount; i++) {
			if ((typeFilter & (1 << i)) && (memProperties.memoryTypes[i].propertyFlags & properties) == properties) {
				return i;
			}
		}

		throw std::runtime_error("Failed to find suitable memory type!");
	}

} // namespace Aminophenol
