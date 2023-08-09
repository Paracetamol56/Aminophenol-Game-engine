
#ifndef IMAGE_H
#define IMAGE_H

#include "pch.h"
#include "Rendering/Device/LogicalDevice.h"
#include "Rendering/Device/PhysicalDevice.h"
#include "Rendering/Commands/CommandPool.h"

namespace Aminophenol
{

	class Image
	{
	public:

		Image(
			const LogicalDevice& logicalDevice,
			const PhysicalDevice& physicalDevice,
			const VkExtent3D& extent,
			VkImageTiling tiling,
			VkImageUsageFlags usage,
			VkMemoryPropertyFlags properties,
			VkFormat format
		);
		~Image();

		// Getters
		const VkImage& getImage() const;
		const VkImageView& getImageView() const;
		const VkSampler& getSampler() const;

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
			VkImageUsageFlags usage
		);
		static void createSampler(
			const LogicalDevice& logicalDevice,
			VkSampler& sampler,
			VkFilter filter,
			VkSamplerAddressMode addressMode,
			bool anisotropic,
			uint32_t mipLevels
		);
		static void createImageMemory(
			const LogicalDevice& logicalDevice,
			VkImage& image,
			VkDeviceMemory& memory,
			VkMemoryPropertyFlags properties
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
		const VkExtent3D& m_extent;
		const VkImageTiling& m_tiling;
		const VkImageUsageFlags& m_usage;
		const VkMemoryPropertyFlags& m_properties;
		const VkFormat& m_format;

		// Ressources
		VkImage m_image;
		VkDeviceMemory m_imageMemory;
		VkImageView m_imageView;
		VkSampler m_sampler;

		// CommandBuffer m_commandBuffer;
		// VkQueue m_queue;

	};

} // namespace Aminophenol

#endif // !IMAGE_H
