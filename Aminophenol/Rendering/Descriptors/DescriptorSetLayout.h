
#ifndef DESCRIPTOR_SET_LAYOUT_H
#define DESCRIPTOR_SET_LAYOUT_H

#include "Utils/NonCopyable.h"
#include "Rendering/Device/LogicalDevice.h"
#include <unordered_map>

namespace Aminophenol
{

	class DescriptorSetLayout
		: public NonCopyable
	{
	public:

		DescriptorSetLayout(const LogicalDevice& logicalDevice, const std::unordered_map<uint32_t, VkDescriptorSetLayoutBinding>& bindings);
		~DescriptorSetLayout();

		operator const VkDescriptorSetLayout& () const;
		const VkDescriptorSetLayout& getDescriptorSetLayout() const;

	private:

		const LogicalDevice& m_logicalDevice;
		VkDescriptorSetLayout m_descriptorSetLayout;
		std::unordered_map<uint32_t, VkDescriptorSetLayoutBinding> m_bindings;

		friend class DescriptorWriter;
	};

} // namespace Aminophenol

#endif // !DESCRIPTOR_SET_LAYOUT_H
