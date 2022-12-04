
#include "pch.h"
#include "Surface.h"

#include "Logging/Logger.h"

namespace Aminophenol
{

	Surface::Surface(const Instance& instance, const Window& window, const LogicalDevice& logicalDevice, const PhysicalDevice& physicalDevice)
		: m_instance{ instance }
		, m_window{ window }
	{
		Logger::log(LogLevel::Trace, "Creating surface...");

		if (glfwCreateWindowSurface(m_instance, m_window, nullptr, &m_surface) != VK_SUCCESS)
		{
			throw std::runtime_error("Failed to create window surface!");
		}

		// Check if a queue family supports compute
		VkBool32 presentSupport{ false };
		vkGetPhysicalDeviceSurfaceSupportKHR(physicalDevice, logicalDevice.getPresentQueueFamilyIndex(), m_surface, &presentSupport);
		if (!presentSupport)
		{
			throw std::runtime_error("No queue family supports presentation!");
		}

		// Get surface capabilities
		VkSurfaceCapabilitiesKHR surfaceCapabilities{};
		vkGetPhysicalDeviceSurfaceCapabilitiesKHR(physicalDevice, m_surface, &surfaceCapabilities);
		
		// Get surface formats
		uint32_t surfaceFormatCount{ 0 };
		vkGetPhysicalDeviceSurfaceFormatsKHR(physicalDevice, m_surface, &surfaceFormatCount, nullptr);
		std::vector<VkSurfaceFormatKHR> surfaceFormats(surfaceFormatCount);
		vkGetPhysicalDeviceSurfaceFormatsKHR(physicalDevice, m_surface, &surfaceFormatCount, surfaceFormats.data());

		Logger::log(LogLevel::Trace, "Successfully created surface.");
	}

	Surface::~Surface()
	{
		Logger::log(LogLevel::Trace, "Destroying surface...");
		
		vkDestroySurfaceKHR(m_instance, m_surface, nullptr);
		
		Logger::log(LogLevel::Trace, "Surface destroyed.");
	}

	Surface::operator const VkSurfaceKHR& () const
	{
		return m_surface;
	}

} // namespace Aminophenol