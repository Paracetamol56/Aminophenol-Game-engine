
#include "pch.h"
#include "DescriptorWriter.h"
#include "DescriptorSetLayout.h"

namespace Aminophenol
{

	DescriptorWriter::DescriptorWriter(DescriptorSetLayout& descriptorSetLayout, DescriptorPool& descriptorPool)
		: m_descriptorSetLayout(descriptorSetLayout)
		, m_descriptorPool(descriptorPool)
	{}

	DescriptorWriter& DescriptorWriter::writeBuffer(uint32_t binding, VkDescriptorBufferInfo* bufferInfo)
	{
		if (m_descriptorSetLayout.m_bindings.count(binding) == 0)
			throw std::runtime_error("Binding not found in descriptor set layout");

		VkDescriptorSetLayoutBinding& bindingDescription = m_descriptorSetLayout.m_bindings[binding];

		VkWriteDescriptorSet writeDescriptorSet = {};
		writeDescriptorSet.sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
		writeDescriptorSet.dstBinding = binding;
		writeDescriptorSet.descriptorType = bindingDescription.descriptorType;
		writeDescriptorSet.descriptorCount = 1;
		writeDescriptorSet.pBufferInfo = bufferInfo;

		m_writeDescriptorSets.push_back(writeDescriptorSet);

		return *this;
	}

	DescriptorWriter& DescriptorWriter::writeImage(uint32_t binding, VkDescriptorImageInfo* imageInfo)
	{
		VkDescriptorSetLayoutBinding& bindingDescription = m_descriptorSetLayout.m_bindings[binding];

		VkWriteDescriptorSet writeDescriptorSet = {};
		writeDescriptorSet.sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
		writeDescriptorSet.dstBinding = binding;
		writeDescriptorSet.descriptorType = bindingDescription.descriptorType;
		writeDescriptorSet.descriptorCount = 1;
		writeDescriptorSet.pImageInfo = imageInfo;

		m_writeDescriptorSets.push_back(writeDescriptorSet);

		return *this;
	}

	void DescriptorWriter::build(VkDescriptorSet& descriptorSet)
	{
		m_descriptorPool.allocateDescriptorSet(m_descriptorSetLayout.getDescriptorSetLayout(), descriptorSet);
		overwrite(descriptorSet);
	}

	void DescriptorWriter::overwrite(VkDescriptorSet& descriptorSet)
	{
		for (VkWriteDescriptorSet& writeDescriptorSet : m_writeDescriptorSets)
			writeDescriptorSet.dstSet = descriptorSet;

		vkUpdateDescriptorSets(
			m_descriptorPool.m_logicalDevice,
			m_writeDescriptorSets.size(),
			m_writeDescriptorSets.data(),
			0,
			nullptr
		);
	}

} // namespace Aminophenol
