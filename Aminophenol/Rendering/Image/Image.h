
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

		static void createImage(
			const LogicalDevice& logicalDevice,
			VkImage& image,
			VkDeviceMemory& memory,
			const VkExtent3D& extent,
			VkFormat format,
			VkImageTiling tiling,
			VkImageUsageFlags usage,
			VkMemoryPropertyFlags properties
		);
		static void createSampler(
			const LogicalDevice& logicalDevice,
			VkSampler& sampler,
			VkFilter filter,
			VkSamplerAddressMode addressMode,
			bool anisotropic,
			uint32_t mipLevels
		);
		static void createImageView(
			const LogicalDevice& logicalDevice,
			VkImage& image,
			VkImageView& imageView,
			VkImageViewType type,
			VkFormat format,
			VkImageAspectFlags imageAspect,
			uint32_t mipLevels,
			uint32_t baseMipLevel,
			uint32_t layerCount,
			uint32_t baseArrayLayer
		);
		static void transitionImageLayout(
			const LogicalDevice& logicalDevice,
			std::shared_ptr<CommandPool> commandPool,
			const VkImage& image,
			VkFormat format,
			VkImageLayout srcImageLayout,
			VkImageLayout dstImageLayout,
			VkImageAspectFlags imageAspect,
			uint32_t mipLevels,
			uint32_t baseMipLevel,
			uint32_t layerCount,
			uint32_t baseArrayLayer
		);

	protected:

		const LogicalDevice& m_logicalDevice;
		const PhysicalDevice& m_physicalDevice;
		std::shared_ptr<CommandPool> m_commandPool;
		VkExtent3D m_extent;
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

		// CommandBuffer m_commandBuffer;
		// VkQueue m_queue;

	};

} // namespace Aminophenol

#endif // !IMAGE_H
