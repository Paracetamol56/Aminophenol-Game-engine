
#ifndef IMAGE_H
#define IMAGE_H

#include "Rendering/Device/LogicalDevice.h"
#include "Rendering/Device/PhysicalDevice.h"
#include "Rendering/Commands/CommandPool.h"
#include "Rendering/Descriptors/DescriptorWriter.h"

namespace Aminophenol
{

	class Image
	{
	public:

		Image(
			const LogicalDevice& logicalDevice,
			const PhysicalDevice& physicalDevice,
			std::shared_ptr<CommandPool> commandPool,
			VkExtent3D extent,
			VkSampleCountFlagBits samples,
			uint32_t mipLevels,
			VkImageTiling tiling,
			VkImageUsageFlags usage,
			VkMemoryPropertyFlags properties,
			VkFormat format,
			VkImageLayout layout
		);
		~Image();

		// Getters
		const VkImage& getImage() const;
		const VkImageView& getImageView() const;
		const VkSampler& getSampler() const;

		DescriptorWriter getDescriptorWriter(uint32_t binding, DescriptorSetLayout& layout, DescriptorPool& pool) const;
		static VkDescriptorSetLayoutBinding getDescriptorSetLayoutBinding(uint32_t binding, VkDescriptorType descriptorType, VkShaderStageFlags stageFlags, uint32_t descriptorCount = 1);

		// Static helper functions
		static uint32_t findMipLevels(const VkExtent3D& extent);
		static VkFormat findSupportedFormat(
			const PhysicalDevice& physicalDevice,
			const std::vector<VkFormat>& candidates,
			VkImageTiling tiling,
			VkFormatFeatureFlags features
		);
		static VkFormat findDepthFormat(const PhysicalDevice& physicalDevice);
		static bool hasStencilComponent(VkFormat format);

		// Helper functions
		void createImage();
		void createSampler(
			VkFilter filter,
			VkSamplerAddressMode addressMode,
			bool anisotropic
		);
		void createImageView(
			VkImageViewType type,
			VkImageAspectFlags imageAspect,
			uint32_t mipLevels,
			uint32_t baseMipLevel,
			uint32_t layerCount,
			uint32_t baseArrayLayer
		);
		void transitionImageLayout(
			VkImageLayout srcImageLayout,
			VkImageLayout dstImageLayout,
			VkImageAspectFlags imageAspect,
			uint32_t mipLevels,
			uint32_t baseMipLevel,
			uint32_t layerCount,
			uint32_t baseArrayLayer
		);
		void copyBufferToImage(
			const VkBuffer& buffer,
			uint32_t layerCount,
			uint32_t baseArrayLayer
		);

	protected:

		const LogicalDevice& m_logicalDevice;
		const PhysicalDevice& m_physicalDevice;
		std::shared_ptr<CommandPool> m_commandPool;
		VkExtent3D m_extent;
		VkSampleCountFlagBits m_samples;
		uint32_t m_mipLevels;
		VkImageTiling m_tiling;
		VkImageUsageFlags m_usage;
		VkMemoryPropertyFlags m_properties;
		VkFormat m_format;
		VkImageLayout m_imageLayout;

		// Ressources
		VkImage m_image{ VK_NULL_HANDLE };
		VkDeviceMemory m_imageMemory{ VK_NULL_HANDLE };
		VkImageView m_imageView{ VK_NULL_HANDLE };
		VkSampler m_sampler{ VK_NULL_HANDLE };

	};

} // namespace Aminophenol

#endif // !IMAGE_H
