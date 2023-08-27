
#include "pch.h"
#include "DescriptorPool.h"

namespace Aminophenol
{

	DescriptorPool::DescriptorPool(
		const LogicalDevice& logicalDevice,
		const std::vector<VkDescriptorPoolSize>& poolSizes,
		uint32_t maxSets,
		VkDescriptorPoolCreateFlags flags
	)
		: m_logicalDevice{ logicalDevice }
	{
		VkDescriptorPoolCreateInfo poolInfo{};
		poolInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
		poolInfo.poolSizeCount = static_cast<uint32_t>(poolSizes.size());
		poolInfo.pPoolSizes = poolSizes.data();
		poolInfo.maxSets = maxSets;
		poolInfo.flags = flags;

		if (vkCreateDescriptorPool(m_logicalDevice, &poolInfo, nullptr, &m_descriptorPool) != VK_SUCCESS)
			throw std::runtime_error("Failed to create descriptor pool!");
	}

	DescriptorPool::~DescriptorPool()
	{
		vkDestroyDescriptorPool(m_logicalDevice, m_descriptorPool, nullptr);
	}

	void DescriptorPool::allocateDescriptorSet(
		const VkDescriptorSetLayout& descriptorSetLayout,
		VkDescriptorSet& descriptorSet
	)
	{
		VkDescriptorSetLayout layouts[] = { descriptorSetLayout };

		VkDescriptorSetAllocateInfo allocInfo{};
		allocInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO;
		allocInfo.descriptorPool = m_descriptorPool;
		allocInfo.descriptorSetCount = 1;
		allocInfo.pSetLayouts = layouts;

		if (vkAllocateDescriptorSets(m_logicalDevice, &allocInfo, &descriptorSet) != VK_SUCCESS)
			throw std::runtime_error("Failed to allocate descriptor sets!");
	}

	void DescriptorPool::freeDescriptorSets(std::vector<VkDescriptorSet>& descriptorSets)
	{
		vkFreeDescriptorSets(
			m_logicalDevice,
			m_descriptorPool,
			static_cast<uint32_t>(descriptorSets.size()),
			descriptorSets.data()
		);
		descriptorSets.clear();
	}

	void DescriptorPool::resetDescriptorPool()
	{
		vkResetDescriptorPool(m_logicalDevice, m_descriptorPool, 0);
	}

	DescriptorPool::operator const VkDescriptorPool& () const
	{
		return m_descriptorPool;
	}

	const VkDescriptorPool& DescriptorPool::getDescriptorPool() const
	{
		return m_descriptorPool;
	}

} // namespace Aminophenol
