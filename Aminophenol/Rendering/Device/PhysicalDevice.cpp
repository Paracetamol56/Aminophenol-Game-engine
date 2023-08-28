#include "pch.h"
#include "PhysicalDevice.h"

#include "Logging/Logger.h"

namespace Aminophenol
{

	PhysicalDevice::PhysicalDevice(const Instance& instance)
		: m_instance(instance)
	{
		
		Logger::log(LogLevel::Trace, "Initializing physical device...");
		
		m_physicalDevice = pickPhysicalDevice();
		
		Logger::log(LogLevel::Trace, "Physical device initialized.");
	}

	PhysicalDevice::~PhysicalDevice()
	{
		Logger::log(LogLevel::Trace, "Destroying physical device...");

		// Destroy the physical device

		Logger::log(LogLevel::Trace, "Physical device destroyed.");
	}

	PhysicalDevice::operator const VkPhysicalDevice& () const
	{
		return m_physicalDevice;
	}

	const VkPhysicalDevice PhysicalDevice::getPhysicalDevice() const
	{
		return m_physicalDevice;
	}

	const VkPhysicalDeviceProperties PhysicalDevice::getProperties() const
	{
		return m_properties;
	}

	VkPhysicalDevice PhysicalDevice::pickPhysicalDevice()
	{
		// Get all physical devices
		uint32_t deviceCount = 0;
		vkEnumeratePhysicalDevices(m_instance, &deviceCount, nullptr);
		if (deviceCount < 1)
		{
			throw std::runtime_error("Failed to find GPUs with Vulkan support!");
		}
		std::vector<VkPhysicalDevice> devices(deviceCount);
		vkEnumeratePhysicalDevices(m_instance, &deviceCount, devices.data());
		
		// Get all required extensions
		std::vector<const char*> requiredExtensions = { VK_KHR_SWAPCHAIN_EXTENSION_NAME };
		
		// Score each device and pick the best one
		VkPhysicalDevice bestDevice = VK_NULL_HANDLE;
		int bestScore = 0;
		for (const auto& device : devices)
		{
			int score = rateDeviceSuitability(device, requiredExtensions);
			if (score > bestScore)
			{
				bestDevice = device;
				bestScore = score;
			}
		}
		
		if (bestScore < 0)
		{
			throw std::runtime_error("Failed to find a suitable GPU!");
		}
		
		// Get the properties of the best device
		vkGetPhysicalDeviceProperties(bestDevice, &m_properties);

		// Log the device name
		Logger::log(LogLevel::Trace, "Picked the physical device \"%s\" with a score of %d.", m_properties.deviceName, bestScore);

		return bestDevice;
	}

	void PhysicalDevice::logPhysicalDeviceProperties(VkPhysicalDeviceProperties& deviceProperties)
	{
		// Log the device name, type, driver version and score
		// Get the device type as a string
		const char* deviceType;
		switch (deviceProperties.deviceType)
		{
		case VK_PHYSICAL_DEVICE_TYPE_OTHER:
			deviceType = "Other";
			break;
		case VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU:
			deviceType = "Integrated GPU";
			break;
		case VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU:
			deviceType = "Discrete GPU";
			break;
		case VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU:
			deviceType = "Virtual GPU";
			break;
		case VK_PHYSICAL_DEVICE_TYPE_CPU:
			deviceType = "CPU";
			break;
		default:
			deviceType = "Unknown";
			break;
		}

		Logger::log(LogLevel::Trace, "Available device: \"%s\", type: \"%s\", driver version: %d.%d.%d",
			deviceProperties.deviceName,
			deviceType,
			VK_API_VERSION_MAJOR(deviceProperties.driverVersion),
			VK_API_VERSION_MINOR(deviceProperties.driverVersion),
			VK_API_VERSION_PATCH(deviceProperties.driverVersion)
		);
	}

	bool PhysicalDevice::checkDeviceExtensionSupport(VkPhysicalDevice& device, const std::vector<const char*>& requiredExtensions)
	{
		// Get the available extentions
		uint32_t extensionCount{ 0 };
		vkEnumerateDeviceExtensionProperties(device, nullptr, &extensionCount, nullptr);
		std::vector<VkExtensionProperties> availableExtensions(extensionCount);
		vkEnumerateDeviceExtensionProperties(device, nullptr, &extensionCount, availableExtensions.data());
		
		/*
		// Log the available extentions
		for (const auto& extension : availableExtensions)
		{
			Logger::log(LogLevel::Trace, "Available device extension: %s", extension.extensionName);
		}
		*/

		// Check if all required extentions are available
		for (const char* extension : requiredExtensions)
		{
			Logger::log(LogLevel::Trace, "Required device extension: %s", extension);

			bool found{ false };
			for (const VkExtensionProperties& availableExtension : availableExtensions)
			{
				if (strcmp(extension, availableExtension.extensionName) == 0)
				{
					found = true;
					break;
				}
			}

			if (!found)
			{
				Logger::log(LogLevel::Trace, "Required device extension not found: %s", extension);
				return false;
			}
		}

		return true;
	}

	int PhysicalDevice::rateDeviceSuitability(VkPhysicalDevice device, const std::vector<const char*>& requiredExtensions)
	{
		// Get the device properties and features
		VkPhysicalDeviceProperties deviceProperties;
		vkGetPhysicalDeviceProperties(device, &deviceProperties);

		VkPhysicalDeviceFeatures deviceFeatures;
		vkGetPhysicalDeviceFeatures(device, &deviceFeatures);

		logPhysicalDeviceProperties(deviceProperties);

		// Application can't function without geometry shaders
		if (!deviceFeatures.geometryShader) {
			Logger::log(LogLevel::Trace, "The device \"%s\" does not support geometry shaders.", deviceProperties.deviceName);
			return -1;
		}

		// Check if all required extentions are available
		if (!checkDeviceExtensionSupport(device, requiredExtensions))
		{
			Logger::log(LogLevel::Trace, "The device \"%s\" does not support all required extensions.", deviceProperties.deviceName);
			return -1;
		}
		
		int score = 0;

		// Discrete GPUs have a significant performance advantage
		if (deviceProperties.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU) {
			score += 1000;
		}

		// Maximum possible size of textures affects graphics quality
		score += deviceProperties.limits.maxImageDimension2D;

		Logger::log(LogLevel::Trace, "The device \"%s\" has a score of %d.", deviceProperties.deviceName, score);

		return score;
	}

	VkSampleCountFlagBits PhysicalDevice::getMaxUsableSampleCount()
	{
		VkSampleCountFlags counts = m_properties.limits.framebufferColorSampleCounts & m_properties.limits.framebufferDepthSampleCounts;

		if (counts & VK_SAMPLE_COUNT_64_BIT) return VK_SAMPLE_COUNT_64_BIT;
		if (counts & VK_SAMPLE_COUNT_32_BIT) return VK_SAMPLE_COUNT_32_BIT;
		if (counts & VK_SAMPLE_COUNT_16_BIT) return VK_SAMPLE_COUNT_16_BIT;
		if (counts & VK_SAMPLE_COUNT_8_BIT) return VK_SAMPLE_COUNT_8_BIT;
		if (counts & VK_SAMPLE_COUNT_4_BIT) return VK_SAMPLE_COUNT_4_BIT;
		if (counts & VK_SAMPLE_COUNT_2_BIT) return VK_SAMPLE_COUNT_2_BIT;

		return VK_SAMPLE_COUNT_1_BIT;
	}

} // namespace Aminophenol
