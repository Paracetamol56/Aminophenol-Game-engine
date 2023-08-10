
#ifndef SWAPCHAIN_H
#define SWAPCHAIN_H

#include "Rendering/Device/LogicalDevice.h"
#include "Rendering/Device/PhysicalDevice.h"
#include "Rendering/Device/Surface.h"

namespace Aminophenol {

	class Swapchain
	{
	public:
			
		Swapchain(const LogicalDevice& logicalDevice, const PhysicalDevice& physicalDevice, const Surface& surface, const VkExtent2D& extent, const Swapchain* previousSwapchain = VK_NULL_HANDLE);
		~Swapchain();

		operator const VkSwapchainKHR& () const;

		const std::vector<VkImage>& getImages() const;
		const std::vector<VkImageView>& getImageViews() const;
		const VkExtent2D& getExtent() const;
		const VkFormat& getFormat() const;

	private:
		
		VkSwapchainKHR m_swapchain{ VK_NULL_HANDLE };
		std::vector<VkImage> m_images;
		std::vector<VkImageView> m_imageViews;

		const LogicalDevice& m_logicalDevice;
		const PhysicalDevice& m_physicalDevice;
		const VkExtent2D m_extent;
		const Surface& m_surface;
		const Swapchain* m_oldSwapchain;

		VkSurfaceCapabilitiesKHR m_surfaceCapabilities;
		uint32_t m_imageCount;
		VkPresentModeKHR m_presentMode;
		VkSurfaceFormatKHR m_surfaceFormat;
		VkSurfaceTransformFlagsKHR m_preTransform;
		VkCompositeAlphaFlagBitsKHR m_compositeAlpha;
		
		void getSwapchainDetails();
		void createSwapchain();
		void createImageViews();
		
	};

} // namespace Aminophenol
	
#endif // SWAPCHAIN_H
