
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
		void * mappedData;
		map(&mappedData);
		std::memcpy(mappedData, data, static_cast<size_t>(m_size));
		unmap();
	}

	DescriptorWriter UniformBuffer::getDescriptorWriter(DescriptorSetLayout& layout, DescriptorPool& pool, uint32_t binding) const
	{
		VkDescriptorBufferInfo bufferInfo = {};
		bufferInfo.buffer = m_buffer;
		bufferInfo.offset = 0;
		bufferInfo.range = m_size;

		DescriptorWriter writer(layout, pool);
		writer.writeBuffer(
			binding,
			&bufferInfo
		);

		return writer;
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
