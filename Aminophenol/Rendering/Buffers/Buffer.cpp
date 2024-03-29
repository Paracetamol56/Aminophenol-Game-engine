
#include "pch.h"
#include "Buffer.h"

namespace Aminophenol {

	Buffer::Buffer(const LogicalDevice& logicalDevice, VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, const void* data)
		: m_logicalDevice{ logicalDevice }
		, m_size{ size }
	{
		// Get an array of queue families that support graphics operations
		const std::array<uint32_t, 3> queueFamilyIndices
		{
			m_logicalDevice.getGraphicsQueueFamilyIndex(),
			m_logicalDevice.getPresentQueueFamilyIndex(),
			m_logicalDevice.getComputeQueueFamilyIndex(),
		};
		
		VkBufferCreateInfo bufferCreateInfo = {};
		bufferCreateInfo.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
		bufferCreateInfo.size = m_size;
		bufferCreateInfo.usage = usage;
		bufferCreateInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;
		bufferCreateInfo.queueFamilyIndexCount = static_cast<uint32_t>(queueFamilyIndices.size());
		bufferCreateInfo.pQueueFamilyIndices = queueFamilyIndices.data();

		// Create the buffer
		if (vkCreateBuffer(m_logicalDevice.getDevice(), &bufferCreateInfo, nullptr, &m_buffer) != VK_SUCCESS)
			throw std::runtime_error("Failed to create buffer!");

		VkMemoryRequirements memRequirements;
		vkGetBufferMemoryRequirements(m_logicalDevice.getDevice(), m_buffer, &memRequirements);

		VkMemoryAllocateInfo memoryAllocateInfo = {};
		memoryAllocateInfo.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
		memoryAllocateInfo.allocationSize = memRequirements.size;
		memoryAllocateInfo.memoryTypeIndex = m_logicalDevice.findMemoryType(memRequirements.memoryTypeBits, properties);

		// Allocate the memory
		if (vkAllocateMemory(m_logicalDevice.getDevice(), &memoryAllocateInfo, nullptr, &m_bufferMemory) != VK_SUCCESS)
			throw std::runtime_error("Failed to allocate buffer memory!");

		// Bind the memory to the buffer
		vkBindBufferMemory(m_logicalDevice.getDevice(), m_buffer, m_bufferMemory, 0);

		// If data is provided, copy it to the buffer
		if (data != nullptr)
		{
			void* mappedData;
			map(&mappedData);
			std::memcpy(mappedData, data, static_cast<size_t>(m_size));
			if ((properties & VK_MEMORY_PROPERTY_HOST_COHERENT_BIT) == 0) {
				VkMappedMemoryRange mappedMemoryRange = {};
				mappedMemoryRange.sType = VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE;
				mappedMemoryRange.memory = m_bufferMemory;
				mappedMemoryRange.offset = 0;
				mappedMemoryRange.size = m_size;
				vkFlushMappedMemoryRanges(m_logicalDevice.getDevice(), 1, &mappedMemoryRange);
			}
			unmap();
		}
	}

	Buffer::~Buffer()
	{
		vkDestroyBuffer(m_logicalDevice, m_buffer, nullptr);
		vkFreeMemory(m_logicalDevice, m_bufferMemory, nullptr);
	}

	void Buffer::map(void** data) const
	{
		vkMapMemory(m_logicalDevice, m_bufferMemory, 0, m_size, 0, data);
	}

	void Buffer::unmap() const
	{
		vkUnmapMemory(m_logicalDevice, m_bufferMemory);
	}

	Buffer::operator const VkBuffer& () const
	{
		return m_buffer;
	}
	
	VkDeviceSize Buffer::getSize() const
	{
		return m_size;
	}

	VkBuffer Buffer::getBuffer() const
	{
		return m_buffer;
	}

	VkDeviceMemory Buffer::getBufferMemory() const
	{
		return m_bufferMemory;
	}
	
} // namespace Aminophenol
