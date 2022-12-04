
#include "pch.h"
#include "Swapchain.h"

#include "Logging/Logger.h"

namespace Aminophenol {
	
	Swapchain::Swapchain(const LogicalDevice& logicalDevice, const PhysicalDevice& physicalDevice, const Surface& surface, const VkExtent2D& extent, const Swapchain* oldSwapchain)
		: m_logicalDevice{ logicalDevice }
		, m_physicalDevice{ physicalDevice }
		, m_surface{ surface }
		, m_extent{ extent }
		, m_oldSwapchain{ oldSwapchain }
		, m_presentMode{ VK_PRESENT_MODE_FIFO_KHR }
		, m_preTransform{ VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR }
		, m_compositeAlpha{ VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR }
	{
		Logger::log(LogLevel::Trace, "Creating swapchain...");
		
		getSwapchainDetails();
		createSwapchain();
		createImageViews();

		Logger::log(LogLevel::Trace, "Successfully created swapchain.");
	}

	Swapchain::~Swapchain()
	{
		Logger::log(LogLevel::Trace, "Destroying swapchain...");
		
		if (m_swapchain != VK_NULL_HANDLE)
		{
			vkDestroySwapchainKHR(m_logicalDevice, m_swapchain, nullptr);
			m_swapchain = VK_NULL_HANDLE;
		}

		for (uint32_t i = 0; i < m_imageViews.size(); i++)
		{
			vkDestroyImageView(m_logicalDevice, m_imageViews[i], nullptr);
		}
		
		Logger::log(LogLevel::Trace, "Swapchain destroyed.");
	}
	
	Swapchain::operator const VkSwapchainKHR& () const
	{
		return m_swapchain;
	}

	void Swapchain::getSwapchainDetails()
	{
		// Get surface capabilities
		vkGetPhysicalDeviceSurfaceCapabilitiesKHR(m_physicalDevice, m_surface, &m_surfaceCapabilities);

		// Check the surface capabilities
		m_imageCount = m_surfaceCapabilities.minImageCount + 1;

		if (m_surfaceCapabilities.maxImageCount > 0 && m_imageCount > m_surfaceCapabilities.maxImageCount)
		{
			m_imageCount = m_surfaceCapabilities.maxImageCount;
		}

		if (m_surfaceCapabilities.supportedTransforms & VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR)
		{
			m_preTransform = VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR;
		}
		else
		{
			m_preTransform = m_surfaceCapabilities.currentTransform;
		}

		for (const VkCompositeAlphaFlagBitsKHR& compositeAlphaFlag : { VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR, VK_COMPOSITE_ALPHA_PRE_MULTIPLIED_BIT_KHR, VK_COMPOSITE_ALPHA_POST_MULTIPLIED_BIT_KHR, VK_COMPOSITE_ALPHA_INHERIT_BIT_KHR })
		{
			if (m_surfaceCapabilities.supportedCompositeAlpha & compositeAlphaFlag)
			{
				m_compositeAlpha = compositeAlphaFlag;
				break;
			}
		}

		// Get the prsent modes
		uint32_t presentModeCount;
		vkGetPhysicalDeviceSurfacePresentModesKHR(m_physicalDevice, m_surface, &presentModeCount, nullptr);
		std::vector<VkPresentModeKHR> presentModes(presentModeCount);
		vkGetPhysicalDeviceSurfacePresentModesKHR(m_physicalDevice, m_surface, &presentModeCount, presentModes.data());

		// Select the present mode
		for (const VkPresentModeKHR& presentMode : presentModes)
		{
			if (presentMode == VK_PRESENT_MODE_MAILBOX_KHR)
			{
				m_presentMode = presentMode;
				break;
			}
			if (presentMode != VK_PRESENT_MODE_MAILBOX_KHR && presentMode == VK_PRESENT_MODE_IMMEDIATE_KHR)
			{
				m_presentMode = presentMode;
			}
		}

		// Get the surface formats
		uint32_t surfaceFormatCount;
		vkGetPhysicalDeviceSurfaceFormatsKHR(m_physicalDevice, m_surface, &surfaceFormatCount, nullptr);
		std::vector<VkSurfaceFormatKHR> surfaceFormats(surfaceFormatCount);
		vkGetPhysicalDeviceSurfaceFormatsKHR(m_physicalDevice, m_surface, &surfaceFormatCount, surfaceFormats.data());

		// Select the surface format
		if (surfaceFormats.size() == 1 && surfaceFormats[0].format == VK_FORMAT_UNDEFINED)
		{
			m_surfaceFormat.format = VK_FORMAT_B8G8R8A8_UNORM;
			m_surfaceFormat.colorSpace = VK_COLOR_SPACE_SRGB_NONLINEAR_KHR;
		}
		else
		{
			for (const VkSurfaceFormatKHR& surfaceFormat : surfaceFormats)
			{
				if (surfaceFormat.format == VK_FORMAT_B8G8R8A8_UNORM && surfaceFormat.colorSpace == VK_COLOR_SPACE_SRGB_NONLINEAR_KHR)
				{
					m_surfaceFormat = surfaceFormat;
					break;
				}
			}
		}
	}

	void Swapchain::createSwapchain()
	{
		// Swapchain create info
		// Documentation: https://registry.khronos.org/vulkan/specs/1.3-khr-extensions/html/chap30.html#VkSwapchainCreateInfoKHR
		VkSwapchainCreateInfoKHR swapchainCreateInfo = {};
		swapchainCreateInfo.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
		swapchainCreateInfo.surface = m_surface;
		swapchainCreateInfo.minImageCount = m_imageCount;
		swapchainCreateInfo.imageFormat = m_surfaceFormat.format;
		swapchainCreateInfo.imageColorSpace = m_surfaceFormat.colorSpace;
		swapchainCreateInfo.imageExtent = m_extent;
		swapchainCreateInfo.imageArrayLayers = 1;
		swapchainCreateInfo.imageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;
		swapchainCreateInfo.preTransform = static_cast<VkSurfaceTransformFlagBitsKHR>(m_preTransform);
		swapchainCreateInfo.compositeAlpha = m_compositeAlpha;
		swapchainCreateInfo.presentMode = m_presentMode;
		swapchainCreateInfo.clipped = VK_TRUE;
		swapchainCreateInfo.oldSwapchain = VK_NULL_HANDLE;

		if (m_surfaceCapabilities.supportedUsageFlags & VK_IMAGE_USAGE_TRANSFER_SRC_BIT)
		{
			swapchainCreateInfo.imageUsage |= VK_IMAGE_USAGE_TRANSFER_SRC_BIT;
		}
		if (m_surfaceCapabilities.supportedUsageFlags & VK_IMAGE_USAGE_TRANSFER_DST_BIT)
		{
			swapchainCreateInfo.imageUsage |= VK_IMAGE_USAGE_TRANSFER_DST_BIT;
		}
		if (m_oldSwapchain != VK_NULL_HANDLE)
		{
			swapchainCreateInfo.oldSwapchain = m_oldSwapchain->m_swapchain;
		}
		// Check if the queue families are the same
		uint32_t queueFamilyIndices[2] = { m_logicalDevice.getGraphicsQueueFamilyIndex(), m_logicalDevice.getPresentQueueFamilyIndex() };
		if (queueFamilyIndices[0] != queueFamilyIndices[1])
		{
			swapchainCreateInfo.imageSharingMode = VK_SHARING_MODE_CONCURRENT;
			swapchainCreateInfo.queueFamilyIndexCount = 2;
			swapchainCreateInfo.pQueueFamilyIndices = queueFamilyIndices;
		}
		else
		{
			swapchainCreateInfo.imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;
			swapchainCreateInfo.queueFamilyIndexCount = 0;
			swapchainCreateInfo.pQueueFamilyIndices = nullptr;
		}
		
		if (vkCreateSwapchainKHR(m_logicalDevice, &swapchainCreateInfo, nullptr, &m_swapchain) != VK_SUCCESS)
		{
			throw std::runtime_error("Failed to create swapchain.");
		}

		// Get the swapchain images
		vkGetSwapchainImagesKHR(m_logicalDevice, m_swapchain, &m_imageCount, nullptr);
		m_images.resize(m_imageCount);
		vkGetSwapchainImagesKHR(m_logicalDevice, m_swapchain, &m_imageCount, m_images.data());
	}
	
	void Swapchain::createImageViews()
	{
		m_imageViews.resize(m_imageCount);
		
		for (uint32_t i = 0; i < m_imageCount; i++)
		{
			// Image view create info
			// Documentation: https://registry.khronos.org/vulkan/specs/1.3-khr-extensions/html/chap12.html#VkImageViewCreateInfo
			VkImageViewCreateInfo imageViewCreateInfo = {};
			imageViewCreateInfo.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
			imageViewCreateInfo.image = m_images[i];
			imageViewCreateInfo.viewType = VK_IMAGE_VIEW_TYPE_2D;
			imageViewCreateInfo.format = m_surfaceFormat.format;
			imageViewCreateInfo.components.r = VK_COMPONENT_SWIZZLE_IDENTITY;
			imageViewCreateInfo.components.g = VK_COMPONENT_SWIZZLE_IDENTITY;
			imageViewCreateInfo.components.b = VK_COMPONENT_SWIZZLE_IDENTITY;
			imageViewCreateInfo.components.a = VK_COMPONENT_SWIZZLE_IDENTITY;
			imageViewCreateInfo.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
			imageViewCreateInfo.subresourceRange.baseMipLevel = 0;
			imageViewCreateInfo.subresourceRange.levelCount = 1;
			imageViewCreateInfo.subresourceRange.baseArrayLayer = 0;
			imageViewCreateInfo.subresourceRange.layerCount = 1;

			if (vkCreateImageView(m_logicalDevice, &imageViewCreateInfo, nullptr, &m_imageViews[i]) != VK_SUCCESS)
			{
				throw std::runtime_error("Failed to create image view.");
			}
		}
	}
	
} // namespace Aminophenol
