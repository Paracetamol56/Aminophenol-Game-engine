
#include "pch.h"
#include "DescriptorSetLayout.h"

namespace Aminophenol
{

	DescriptorSetLayout::DescriptorSetLayout(const LogicalDevice& logicalDevice, const std::unordered_map<uint32_t, VkDescriptorSetLayoutBinding>& bindings)
		: m_logicalDevice{ logicalDevice }
		, m_bindings{ bindings }
	{
		std::vector<VkDescriptorSetLayoutBinding> layoutBindings;
		layoutBindings.reserve(bindings.size());
		for (const auto& binding : bindings)
			layoutBindings.push_back(binding.second);

		VkDescriptorSetLayoutCreateInfo layoutInfo{};
		layoutInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
		layoutInfo.bindingCount = static_cast<uint32_t>(layoutBindings.size());
		layoutInfo.pBindings = layoutBindings.data();

		if (vkCreateDescriptorSetLayout(m_logicalDevice, &layoutInfo, nullptr, &m_descriptorSetLayout) != VK_SUCCESS)
			throw std::runtime_error("Failed to create descriptor set layout!");
	}

	DescriptorSetLayout::~DescriptorSetLayout()
	{
		vkDestroyDescriptorSetLayout(m_logicalDevice, m_descriptorSetLayout, nullptr);
	}

	DescriptorSetLayout::operator const VkDescriptorSetLayout& () const
	{
		return m_descriptorSetLayout;
	}

	const VkDescriptorSetLayout& DescriptorSetLayout::getDescriptorSetLayout() const
	{
		return m_descriptorSetLayout;
	}

} // namespace Aminophenol
