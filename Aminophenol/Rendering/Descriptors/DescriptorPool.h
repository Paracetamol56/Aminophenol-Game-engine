
#ifndef DESCRIPTOR_POOL_H
#define DESCRIPTOR_POOL_H

#include "Utils/NonCopyable.h"
#include "Rendering/Device/LogicalDevice.h"

namespace Aminophenol
{

	class DescriptorPool
		: public NonCopyable
	{
	public:

		DescriptorPool(
			const LogicalDevice& logicalDevice,
			const std::vector<VkDescriptorPoolSize>& poolSizes,
			uint32_t maxSets,
			VkDescriptorPoolCreateFlags flags
		);
		~DescriptorPool();

		void allocateDescriptorSet(
			const VkDescriptorSetLayout& descriptorSetLayout,
			VkDescriptorSet& descriptorSet
		);
		void freeDescriptorSets(
			std::vector<VkDescriptorSet>& descriptorSets
		);
		void resetDescriptorPool();

		operator const VkDescriptorPool& () const;
		const VkDescriptorPool& getDescriptorPool() const;

	private:

		const LogicalDevice& m_logicalDevice;
		VkDescriptorPool m_descriptorPool;

		friend class DescriptorWriter;

	};

} // namespace Aminophenol

#endif // !DESCRIPTOR_POOL_H