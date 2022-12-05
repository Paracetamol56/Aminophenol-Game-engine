
#ifndef SWAPCHAIN_H
#define SWAPCHAIN_H

#include "pch.h"

#include "Rendering/LogicalDevice.h"
#include "Rendering/PhysicalDevice.h"
#include "Rendering/Surface.h"

namespace Aminophenol {

	class Swapchain
	{
	public:
			
		Swapchain(const LogicalDevice& logicalDevice, const PhysicalDevice& physicalDevice, const Surface& surface, const VkExtent2D& extent, const Swapchain* previousSwapchain = VK_NULL_HANDLE);
		~Swapchain();

		operator const VkSwapchainKHR& () const;

	private:
		
		VkSwapchainKHR m_swapchain{ VK_NULL_HANDLE };
		std::vector<VkImage> m_images;
		std::vector<VkImageView> m_imageViews;

		const LogicalDevice& m_logicalDevice;
		const PhysicalDevice& m_physicalDevice;
		const VkExtent2D& m_extent;
		const Surface& m_surface;
		const Swapchain* m_oldSwapchain;

		VkSurfaceCapabilitiesKHR m_surfaceCapabilities;
		uint32_t m_imageCount;
		VkPresentModeKHR m_presentMode;
		VkSurfaceFormatKHR m_surfaceFormat;
		VkSurfaceTransformFlagsKHR m_preTransform;
		VkCompositeAlphaFlagBitsKHR m_compositeAlpha;
		std::vector<VkImage> images;
		std::vector<VkImageView> imageViews;
		VkFence fenceImage{ VK_NULL_HANDLE };
		uint32_t activeImageIndex;
		
		void getSwapchainDetails();
		void createSwapchain();
		void createImageViews();
		
	};

} // namespace Aminophenol
	
#endif // SWAPCHAIN_H
