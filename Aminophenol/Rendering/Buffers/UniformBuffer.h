
#ifndef UNIFORM_BUFFER_H
#define UNIFORM_BUFFER_H

#include "Rendering/Buffers/Buffer.h"
#include "Rendering/Descriptors/DescriptorWriter.h"

namespace Aminophenol
{

	class UniformBuffer
		: public Buffer
	{
	public:

		UniformBuffer(const LogicalDevice& logicalDevice, VkDeviceSize size, const void *data);

		void update(void *data);

		DescriptorWriter getDescriptorWriter(DescriptorSetLayout& layout, DescriptorPool& pool, uint32_t binding) const;
		static VkDescriptorSetLayoutBinding getDescriptorSetLayoutBinding(uint32_t binding, VkDescriptorType descriptorType, VkShaderStageFlags stageFlags, uint32_t descriptorCount = 1);

	};

}

#endif // !UNIFORM_BUFFER_H
