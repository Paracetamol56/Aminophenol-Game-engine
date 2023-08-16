
#include "pch.h"
#include "UniformBuffer.h"

namespace Aminophenol
{

	UniformBuffer::UniformBuffer(const LogicalDevice& logicalDevice, VkDeviceSize size, const void* data)
		: Buffer(
			logicalDevice,
			size,
			VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT,
			VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT,
			data
		)
	{}

	void UniformBuffer::update(const void* data)
	{
		void *mappedMemory;
		map(&mappedMemory);
		std::memcpy(mappedMemory, data, static_cast<size_t>(m_size));
		unmap();
	}

	VkWriteDescriptorSet UniformBuffer::getWriteDescriptor(VkDescriptorSet descriptorSet, VkDescriptorType descriptorType, uint32_t binding, uint32_t descriptorCount)
	{
		VkDescriptorBufferInfo bufferInfo = {};
		bufferInfo.buffer = m_buffer;
		bufferInfo.offset = 0;
		bufferInfo.range = VK_WHOLE_SIZE;

		VkWriteDescriptorSet descriptorWrite = {};
		descriptorWrite.sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
		descriptorWrite.dstSet = descriptorSet;
		descriptorWrite.dstBinding = binding;
		descriptorWrite.dstArrayElement = 0;
		descriptorWrite.descriptorType = descriptorType;
		descriptorWrite.descriptorCount = descriptorCount;
		descriptorWrite.pBufferInfo = &bufferInfo;

		return descriptorWrite;

	}

	VkDescriptorSetLayoutBinding UniformBuffer::getDescriptorSetLayoutBinding(uint32_t binding, VkDescriptorType descriptorType, VkShaderStageFlags stageFlags, uint32_t descriptorCount)
	{
		VkDescriptorSetLayoutBinding descriptorSetLayoutBinding = {};
		descriptorSetLayoutBinding.binding = binding;
		descriptorSetLayoutBinding.descriptorType = descriptorType;
		descriptorSetLayoutBinding.descriptorCount = descriptorCount;
		descriptorSetLayoutBinding.stageFlags = stageFlags;
		descriptorSetLayoutBinding.pImmutableSamplers = nullptr;

		return descriptorSetLayoutBinding;
	}

}
