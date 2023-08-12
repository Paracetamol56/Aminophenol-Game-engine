
#ifndef UNIFORM_BUFFER_H
#define UNIFORM_BUFFER_H

#include "Rendering/Buffers/Buffer.h"

namespace Aminophenol
{

	class UniformBuffer
		: public Buffer
	{
	public:

		UniformBuffer(const LogicalDevice& logicalDevice, VkDeviceSize size, const void *data);
		~UniformBuffer() = default;

		void update(const void *data);

		VkWriteDescriptorSet getWriteDescriptor(VkDescriptorSet descriptorSet, VkDescriptorType descriptorType, uint32_t binding, uint32_t descriptorCount = 1);
		static VkDescriptorSetLayoutBinding getDescriptorSetLayoutBinding(uint32_t binding, VkDescriptorType descriptorType, VkShaderStageFlags stageFlags, uint32_t descriptorCount = 1);

	};

}

#endif // !UNIFORM_BUFFER_H
