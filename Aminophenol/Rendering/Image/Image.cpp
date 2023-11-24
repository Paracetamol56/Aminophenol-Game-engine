
#include "pch.h"
#include "Image.h"

#include "Rendering/Commands/CommandBuffer.h"

namespace Aminophenol {

	Image::Image(
		const LogicalDevice& logicalDevice,
		const PhysicalDevice& physicalDevice,
		std::shared_ptr<CommandPool> commandPool,
		VkExtent3D extent,
		VkImageTiling tiling,
		VkImageUsageFlags usage,
		VkMemoryPropertyFlags properties,
		VkFormat format,
		VkImageLayout layout
	)
		: m_logicalDevice{ logicalDevice }
		, m_physicalDevice{ physicalDevice }
		, m_commandPool{ commandPool }
		, m_extent{ extent }
		, m_tiling{ tiling }
		, m_usage{ usage }
		, m_properties{ properties }
		, m_format{ format }
		, m_imageLayout{ layout }
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

	DescriptorWriter Image::getDescriptorWriter(uint32_t binding, DescriptorSetLayout& layout, DescriptorPool& pool) const
	{
		VkDescriptorImageInfo imageInfo{};
		imageInfo.imageLayout = m_imageLayout;
		imageInfo.imageView = m_imageView;
		imageInfo.sampler = m_sampler;

		DescriptorWriter writer{ layout, pool };
		writer.writeImage(binding, &imageInfo);

		return writer;
	}

	VkDescriptorSetLayoutBinding Image::getDescriptorSetLayoutBinding(uint32_t binding, VkDescriptorType descriptorType, VkShaderStageFlags stageFlags, uint32_t descriptorCount)
	{
		VkDescriptorSetLayoutBinding descriptorSetLayoutBinding{};
		descriptorSetLayoutBinding.binding = binding;
		descriptorSetLayoutBinding.descriptorType = descriptorType;
		descriptorSetLayoutBinding.descriptorCount = descriptorCount;
		descriptorSetLayoutBinding.stageFlags = stageFlags;
		descriptorSetLayoutBinding.pImmutableSamplers = nullptr;

		return descriptorSetLayoutBinding;
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

			if (tiling == VK_IMAGE_TILING_LINEAR && (properties.linearTilingFeatures & features) == features)
				return format;
			else if (tiling == VK_IMAGE_TILING_OPTIMAL && (properties.optimalTilingFeatures & features) == features)
				return format;
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

	bool Image::hasStencilComponent(VkFormat format)
	{
		return format == VK_FORMAT_D32_SFLOAT_S8_UINT || format == VK_FORMAT_D24_UNORM_S8_UINT;
	}

	void Image::createImage(
		const LogicalDevice& logicalDevice,
		VkImage& image,
		VkDeviceMemory& memory,
		const VkExtent3D& extent,
		VkFormat format,
		VkImageTiling tiling,
		VkImageUsageFlags usage,
		VkMemoryPropertyFlags properties
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
		createInfo.flags = 0;

		if (vkCreateImage(logicalDevice.getDevice(), &createInfo, nullptr, &image) != VK_SUCCESS) {
			throw std::runtime_error("Failed to create image!");
		}

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
			throw std::runtime_error("Failed to create image view!");
		}
	}

	void Image::transitionImageLayout(
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
	)
	{
		CommandBuffer commandBuffer{ logicalDevice, commandPool };
		commandBuffer.begin();


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
		case VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL:
			if (barrier.srcAccessMask == 0)
				barrier.srcAccessMask = VK_ACCESS_HOST_WRITE_BIT | VK_ACCESS_TRANSFER_WRITE_BIT;
			
			barrier.dstAccessMask = VK_ACCESS_SHADER_READ_BIT;
			break;
		default:
			throw std::invalid_argument("Unsupported layout transition destination layout!");
		}

		// Temporary
		barrier.srcAccessMask = 0;
		barrier.dstAccessMask = 0;

		vkCmdPipelineBarrier(
			commandBuffer,
			VK_PIPELINE_STAGE_ALL_COMMANDS_BIT, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
			0,
			0, nullptr,
			0, nullptr,
			1, &barrier
		);

		commandBuffer.submitIdle();
	}

	void Aminophenol::Image::copyBufferToImage(
		const LogicalDevice& logicalDevice,
		std::shared_ptr<CommandPool> commandPool,
		const VkBuffer& buffer,
		const VkImage& image,
		const VkExtent3D& extent,
		uint32_t layerCount,
		uint32_t baseArrayLayer
	)
	{
		CommandBuffer commandBuffer{ logicalDevice, commandPool };
		commandBuffer.begin();

		VkBufferImageCopy region{};
		region.bufferOffset = 0;
		region.bufferRowLength = 0;
		region.bufferImageHeight = 0;
		region.imageSubresource.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
		region.imageSubresource.baseArrayLayer = baseArrayLayer;
		region.imageSubresource.layerCount = layerCount;
		region.imageSubresource.mipLevel = 0;
		region.imageOffset = { 0, 0, 0 };
		region.imageExtent = extent;

		vkCmdCopyBufferToImage(
			commandBuffer,
			buffer,
			image,
			VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
			1,
			&region
		);

		commandBuffer.submitIdle();
	}
	
} // namespace Aminophenol