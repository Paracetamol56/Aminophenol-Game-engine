
#include "pch.h"
#include "ImageDepth.h"

namespace Aminophenol
{

	ImageDepth::ImageDepth(
		const LogicalDevice& logicalDevice,
		const PhysicalDevice& physicalDevice,
		const VkExtent3D& extent
	)
		: Image{
			logicalDevice,
			physicalDevice,
			extent,
			VK_IMAGE_TILING_OPTIMAL,
			VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT,
			VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT,
			Image::findDepthFormat(physicalDevice),
		}
	{
		if (m_format == VK_FORMAT_UNDEFINED)
			throw std::runtime_error("No depth stencil format could be selected");

		VkImageAspectFlags aspectMask = VK_IMAGE_ASPECT_DEPTH_BIT;
		if (hasStencilComponent(m_format))
			aspectMask |= VK_IMAGE_ASPECT_STENCIL_BIT;

		createImage(logicalDevice, m_image, m_imageMemory, m_extent, m_format, m_tiling, m_usage, m_properties);
		createSampler(logicalDevice, m_sampler, VK_FILTER_LINEAR, VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE, false, 1);
		createImageView(logicalDevice, m_image, m_imageView, VK_IMAGE_VIEW_TYPE_2D, m_format, VK_IMAGE_ASPECT_DEPTH_BIT, 1, 0, 1, 0);
	}

} // namespace Aminophenol
