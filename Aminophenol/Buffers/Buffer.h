
#ifndef BUFFER_H
#define BUFFER_H

#include "pch.h"

#include "Rendering/Device/LogicalDevice.h"

namespace Aminophenol {

	class AMINOPHENOL_API Buffer
	{
	public:

		/// <summary>
		/// Buffer constructor.
		/// The buffer object is an abstraction of a Vulkan buffer. This object handles the creation and destruction of the buffer on the device memory.
		/// </summary>
		/// <param name="logicalDevice">The logical device reference.</param>
		/// <param name="size">The size of the buffer (for one instance).</param>
		/// <param name="usage">The usage flags of the buffer.</param>
		/// <param name="properties">The memory properties of the buffer.</param>
		/// <param name="data">The data to be copied to the buffer.</param>
		/// <param name="instanceCount">The number of instances of the buffer.</param>
		/// <param name="minOffsetAlignment">The minimum offset alignment of the buffer.</param>
		Buffer(LogicalDevice& logicalDevice, VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, void* data = nullptr, uint32_t instanceCount = 1, VkDeviceSize minOffsetAlignment = 1);
		~Buffer();

		VkResult mapMemory(void** data) const;
		void unmapMemory() const;
		
		operator const VkBuffer& () const;
		const VkBuffer& getBuffer() const;
		const VkDeviceMemory& getDeviceMemory() const;
		const VkDeviceSize& getSize() const;
		const uint32_t& getInstanceCount() const;
		const VkDeviceSize& getMinOffsetAlignment() const;

	protected:

		LogicalDevice& m_logicalDevice;

		VkBuffer m_buffer;
		VkDeviceMemory m_bufferMemory;

		VkDeviceSize m_size;
		VkBufferUsageFlags m_usage;
		VkMemoryPropertyFlags m_properties;
		uint32_t m_instanceCount;
		VkDeviceSize m_minOffsetAlignment;

		uint32_t findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties) const;

	};

} // namespace Aminophenol

#endif // BUFFER_H
