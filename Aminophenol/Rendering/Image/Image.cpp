
#include "pch.h"
#include "Image.h"

#include "Rendering/Commands/CommandBuffer.h"

namespace Aminophenol {



	Image::Image(
		const LogicalDevice& logicalDevice,
		const PhysicalDevice& physicalDevice,
		const VkExtent3D& extent,
		VkImageTiling tiling,
		VkImageUsageFlags usage,
		VkMemoryPropertyFlags properties,
		VkFormat format
	)
		: m_logicalDevice{ logicalDevice }
		, m_physicalDevice{ physicalDevice }
		, m_extent{ extent }
		, m_tiling{ tiling }
		, m_usage{ usage }
		, m_properties{ properties }
		, m_format{ format }
	{}

	Image::~Image()
	{
		vkFreeMemory(m_logicalDevice, m_imageMemory, nullptr);
		vkDestroyImage(m_logicalDevice, m_image, nullptr);
		vkDestroyImageView(m_logicalDevice, m_imageView, nullptr);
		vkDestroySampler(m_logicalDevice, m_sampler, nullptr);
	}

	const VkImage& Image::getImage() const
	{
		return m_image;
	}

	const VkImageView& Image::getImageView() const
	{
		return m_imageView;
	}

	const VkSampler& Image::getSampler() const
	{
		return m_sampler;
	}

	uint32_t Image::findMipLevels(const VkExtent3D& extent)
	{
		return static_cast<uint32_t>(std::floor(std::log2(std::max(extent.width, extent.height)))) + 1;
	}

	VkFormat Image::findSupportedFormat(
		const PhysicalDevice& physicalDevice,
		const std::vector<VkFormat>& candidates,
		VkImageTiling tiling,
		VkFormatFeatureFlags features
	)
	{
		for (const VkFormat& format : candidates) {
			VkFormatProperties properties;
			vkGetPhysicalDeviceFormatProperties(physicalDevice, format, &properties);

			if (tiling == VK_IMAGE_TILING_LINEAR && (properties.linearTilingFeatures & features) == features) {
				return format;
			}
			else if (tiling == VK_IMAGE_TILING_OPTIMAL && (properties.optimalTilingFeatures & features) == features) {
				return format;
			}
		}

		throw std::runtime_error("Failed to find supported format!");
	}

	VkFormat Image::findDepthFormat(const PhysicalDevice& physicalDevice)
	{
		return findSupportedFormat(
			physicalDevice,
			{ VK_FORMAT_D32_SFLOAT, VK_FORMAT_D32_SFLOAT_S8_UINT, VK_FORMAT_D24_UNORM_S8_UINT },
			VK_IMAGE_TILING_OPTIMAL,
			VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT
		);
	}

	bool Image::hasStencilComponent(VkFormat format) {
		return format == VK_FORMAT_D32_SFLOAT_S8_UINT || format == VK_FORMAT_D24_UNORM_S8_UINT;
	}

	void Image::createImage(
		const LogicalDevice& logicalDevice,
		VkImage& image,
		VkDeviceMemory& memory,
		const VkExtent3D& extent,
		VkFormat format,
		VkImageTiling tiling,
		VkImageUsageFlags usage
	)
	{
		VkImageCreateInfo createInfo{};
		createInfo.sType = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
		createInfo.imageType = VK_IMAGE_TYPE_2D;
		createInfo.extent = extent;
		createInfo.mipLevels = 1;
		createInfo.arrayLayers = 1;
		createInfo.format = format;
		createInfo.tiling = tiling;
		createInfo.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
		createInfo.usage = usage;
		createInfo.samples = VK_SAMPLE_COUNT_1_BIT;
		createInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;

		if (vkCreateImage(logicalDevice.getDevice(), &createInfo, nullptr, &image) != VK_SUCCESS) {
			throw std::runtime_error("Failed to create image!");
		}
	}


	void Image::createSampler(
		const LogicalDevice& logicalDevice,
		VkSampler& sampler,
		VkFilter filter,
		VkSamplerAddressMode addressMode,
		bool anisotropic,
		uint32_t mipLevels
	)
	{
		VkSamplerCreateInfo createInfo{};
		createInfo.sType = VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO;
		createInfo.magFilter = filter;
		createInfo.minFilter = filter;
		createInfo.addressModeU = addressMode;
		createInfo.addressModeV = addressMode;
		createInfo.addressModeW = addressMode;
		createInfo.anisotropyEnable = static_cast<VkBool32>(anisotropic);
		createInfo.maxAnisotropy = 16; // TODO: Find max anisotropy
		createInfo.borderColor = VK_BORDER_COLOR_INT_OPAQUE_BLACK;
		createInfo.unnormalizedCoordinates = VK_FALSE;
		createInfo.compareEnable = VK_FALSE;
		createInfo.compareOp = VK_COMPARE_OP_ALWAYS;
		createInfo.mipmapMode = VK_SAMPLER_MIPMAP_MODE_LINEAR;
		createInfo.mipLodBias = 0.0f;
		createInfo.minLod = 0.0f;
		createInfo.maxLod = static_cast<float>(mipLevels);

		if (vkCreateSampler(logicalDevice.getDevice(), &createInfo, nullptr, &sampler) != VK_SUCCESS) {
			throw std::runtime_error("Failed to create texture sampler!");
		}
	}

	void Image::createImageMemory(
		const LogicalDevice& logicalDevice,
		VkImage& image,
		VkDeviceMemory& memory,
		VkMemoryPropertyFlags properties
	)
	{
		VkMemoryRequirements memRequirements;
		vkGetImageMemoryRequirements(logicalDevice.getDevice(), image, &memRequirements);
	
		VkMemoryAllocateInfo allocInfo{};
		allocInfo.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
		allocInfo.allocationSize = memRequirements.size;
		allocInfo.memoryTypeIndex = logicalDevice.findMemoryType(memRequirements.memoryTypeBits, properties);

		if (vkAllocateMemory(logicalDevice.getDevice(), &allocInfo, nullptr, &memory) != VK_SUCCESS) {
			throw std::runtime_error("Failed to allocate image memory!");
		}

		vkBindImageMemory(logicalDevice.getDevice(), image, memory, 0);
	}

	void Image::createImageView(
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
	)
	{
		VkImageViewCreateInfo createInfo{};
		createInfo.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
		createInfo.image = image;
		createInfo.viewType = type;
		createInfo.format = format;
		createInfo.components.r = VK_COMPONENT_SWIZZLE_R;
		createInfo.components.g = VK_COMPONENT_SWIZZLE_G;
		createInfo.components.b = VK_COMPONENT_SWIZZLE_B;
		createInfo.components.a = VK_COMPONENT_SWIZZLE_A;
		createInfo.subresourceRange.aspectMask = imageAspect;
		createInfo.subresourceRange.baseMipLevel = baseMipLevel;
		createInfo.subresourceRange.levelCount = mipLevels;
		createInfo.subresourceRange.baseArrayLayer = baseArrayLayer;
		createInfo.subresourceRange.layerCount = layerCount;

		if (vkCreateImageView(logicalDevice.getDevice(), &createInfo, nullptr, &imageView) != VK_SUCCESS) {
			throw std::runtime_error("Failed to create texture image view!");
		}
	}

	void Image::transitionImageLayout(
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
	)
	{
		/*VkCommandBuffer commandBuffer = beginSingleTimeCommands(logicalDevice);

		VkImageMemoryBarrier barrier{};
		barrier.sType = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
		barrier.oldLayout = srcImageLayout;
		barrier.newLayout = dstImageLayout;
		barrier.srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
		barrier.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
		barrier.image = image;
		barrier.subresourceRange.aspectMask = imageAspect;
		barrier.subresourceRange.baseMipLevel = baseMipLevel;
		barrier.subresourceRange.levelCount = mipLevels;
		barrier.subresourceRange.baseArrayLayer = baseArrayLayer;
		barrier.subresourceRange.layerCount = layerCount;

		switch (srcImageLayout) {
		case VK_IMAGE_LAYOUT_UNDEFINED:
			barrier.srcAccessMask = 0;
			break;
		case VK_IMAGE_LAYOUT_PREINITIALIZED:
			barrier.srcAccessMask = VK_ACCESS_HOST_WRITE_BIT;
			break;
		case VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL:
			barrier.srcAccessMask = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;
			break;
		case VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL:
			barrier.srcAccessMask = VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT;
			break;
		case VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL:
			barrier.srcAccessMask = VK_ACCESS_TRANSFER_READ_BIT;
			break;
		case VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL:
			barrier.srcAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
			break;
		case VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL:
			barrier.srcAccessMask = VK_ACCESS_SHADER_READ_BIT;
			break;
		default:
			throw std::invalid_argument("Unsupported layout transition source layout!");
		}

		switch (dstImageLayout)
		{
		case VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL:
			barrier.dstAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
			break;
		case VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL:
			barrier.dstAccessMask = VK_ACCESS_TRANSFER_READ_BIT;
			break;
		case VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL:
			barrier.dstAccessMask = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;
			break;
		case VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL:
			if (barrier.srcAccessMask == 0)
				barrier.srcAccessMask = VK_ACCESS_HOST_WRITE_BIT | VK_ACCESS_TRANSFER_WRITE_BIT;
			
			barrier.dstAccessMask = VK_ACCESS_SHADER_READ_BIT;
			break;
		default:
			throw std::invalid_argument("Unsupported layout transition destination layout!");
		}

		vkCmdPipelineBarrier(
			commandBuffer,
			VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
			0,
			0, nullptr,
			0, nullptr,
			1, &barrier
		);

		endSingleTimeCommands(logicalDevice, commandBuffer);*/
	}
	
} // namespace Aminophenol