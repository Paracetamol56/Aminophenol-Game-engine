
#ifndef BUFFER_H
#define BUFFER_H

#include "Rendering/Device/LogicalDevice.h"

namespace Aminophenol {

	class Buffer
	{
	public:

		Buffer(const LogicalDevice& logicalDevice, VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, const void* data = nullptr);
		~Buffer();

		void map(void* data) const;
		void unmap() const;

		operator const VkBuffer& () const;
		
		VkDeviceSize getSize() const;
		VkBuffer getBuffer() const;
		VkDeviceMemory getBufferMemory() const;

	protected:

		const LogicalDevice& m_logicalDevice;

		VkDeviceSize m_size;
		VkBuffer m_buffer{ VK_NULL_HANDLE };
		VkDeviceMemory m_bufferMemory{ VK_NULL_HANDLE };

	};

} // namespace Aminophenol

#endif BUFFER_H
