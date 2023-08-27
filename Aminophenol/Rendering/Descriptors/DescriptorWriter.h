
#ifndef DESCRIPTOR_WRITER_H
#define DESCRIPTOR_WRITER_H

#include "Rendering/Descriptors/DescriptorSetLayout.h"
#include "Rendering/Descriptors/DescriptorPool.h"

namespace Aminophenol
{

	class DescriptorWriter
	{
	public:

		DescriptorWriter(
			DescriptorSetLayout& descriptorSetLayout,
			DescriptorPool& descriptorPool
		);
		~DescriptorWriter() = default;

		DescriptorWriter& writeBuffer(
			uint32_t binding,
			VkDescriptorBufferInfo* bufferInfo
		);
		DescriptorWriter& writeImage(
			uint32_t binding,
			VkDescriptorImageInfo* imageInfo
		);

		void build(VkDescriptorSet& descriptorSet);
		void overwrite(VkDescriptorSet& descriptorSet);

	private:

		DescriptorSetLayout& m_descriptorSetLayout;
		DescriptorPool& m_descriptorPool;
		std::vector<VkWriteDescriptorSet> m_writeDescriptorSets;

	};

} // namespace Aminophenol

#endif // !DESCRIPTOR_WRITER_H
