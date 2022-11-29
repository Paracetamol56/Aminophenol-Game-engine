#include "pch.h"
#include "PhysicalDevice.h"

#include "Logging/Logger.h"

namespace Aminophenol
{

	bool QueueFamilyIndices::isComplete()
	{
		return graphicsFamily.has_value() && presentFamily.has_value();
	}

	PhysicalDevice::PhysicalDevice(Instance* instance)
	{
		if (instance == nullptr)
		{
			Logger::log(LogLevel::Error, "Failed to create physical device: instance is null.");
			return;
		}
		
		Logger::log(LogLevel::Trace, "Initializing physical device...");
		
		m_physicalDevice = pickPhysicalDevice(instance);
		findQueueFamilies();
		
		Logger::log(LogLevel::Trace, "Physical device initialized.");
	}

	PhysicalDevice::~PhysicalDevice()
	{
		Logger::log(LogLevel::Trace, "Destroying physical device...");

		// Destroy the physical device

		Logger::log(LogLevel::Trace, "Physical device destroyed.");
	}

	VkPhysicalDevice PhysicalDevice::getPhysicalDevice() const
	{
		return m_physicalDevice;
	}

	QueueFamilyIndices PhysicalDevice::findQueueFamilies() const
	{
		QueueFamilyIndices indices;

		uint32_t queueFamilyPropertiesCount = 0;
		vkGetPhysicalDeviceQueueFamilyProperties(m_physicalDevice, &queueFamilyPropertiesCount, nullptr);
		std::vector<VkQueueFamilyProperties> queueFamiliesProperties(queueFamilyPropertiesCount);
		vkGetPhysicalDeviceQueueFamilyProperties(m_physicalDevice, &queueFamilyPropertiesCount, queueFamiliesProperties.data());

		Logger::log(LogLevel::Info, "%d available queue families on the device.", queueFamiliesProperties.size());

		int i = 0;
		for (const VkQueueFamilyProperties& queueFamilyProperty : queueFamiliesProperties)
		{
			const char* queueFamilyFlags = "";
			if (queueFamilyProperty.queueFlags & VK_QUEUE_GRAPHICS_BIT)
			{
				queueFamilyFlags = "Graphics";
			}
			else if (queueFamilyProperty.queueFlags & VK_QUEUE_COMPUTE_BIT)
			{
				queueFamilyFlags = "Compute";
			}
			else if (queueFamilyProperty.queueFlags & VK_QUEUE_TRANSFER_BIT)
			{
				queueFamilyFlags = "Transfer";
			}
			else if (queueFamilyProperty.queueFlags & VK_QUEUE_SPARSE_BINDING_BIT)
			{
				queueFamilyFlags = "Sparse Binding";
			}
			else if (queueFamilyProperty.queueFlags & VK_QUEUE_PROTECTED_BIT)
			{
				queueFamilyFlags = "Protected";
			}
			else if (queueFamilyProperty.queueFlags == 0)
			{
				queueFamilyFlags = "Unknown";
			}

			Logger::log(
				LogLevel::Info,
				"Queue family %d: \n\tqueue count: %d\n\tflags: %s",
				i,
				queueFamilyProperty.queueCount,
				queueFamilyFlags
			);

			if (queueFamilyProperty.queueFlags & VK_QUEUE_GRAPHICS_BIT)
			{
				indices.graphicsFamily = i;
				indices.presentFamily = i;
			}

			if (indices.isComplete())
			{
				Logger::log(LogLevel::Info, "The queue family %d is complete.", i);
				break;
			}

			i++;
		}

		return indices;
	}

	VkPhysicalDevice PhysicalDevice::pickPhysicalDevice(Instance* instance)
	{
		// Get all physical devices
		uint32_t deviceCount = 0;
		vkEnumeratePhysicalDevices(instance->getInstance(), &deviceCount, nullptr);
		if (deviceCount < 1)
		{
			throw std::runtime_error("Failed to find GPUs with Vulkan support!");
		}
		std::vector<VkPhysicalDevice> devices(deviceCount);
		vkEnumeratePhysicalDevices(instance->getInstance(), &deviceCount, devices.data());
		
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
		
		// Log the device name
		VkPhysicalDeviceProperties deviceProperties;
		vkGetPhysicalDeviceProperties(bestDevice, &deviceProperties);
		Logger::log(LogLevel::Info, "Picked the physical device \"%s\" with a score of %d.", deviceProperties.deviceName, bestScore);

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

		Logger::log(LogLevel::Info, "Available device: \n\tdevice name: %s\n\tdevice type: %s\n\tdriver version: %d.%d.%d",
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

		// Log the available extentions
		for (const auto& extension : availableExtensions)
		{
			Logger::log(LogLevel::Info, "Available device extension: %s", extension.extensionName);
		}

		// Check if all required extentions are available
		for (const char* extension : requiredExtensions)
		{
			Logger::log(LogLevel::Info, "Required device extension: %s", extension);

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
				Logger::log(LogLevel::Error, "Required device extension not found: %s", extension);
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
			Logger::log(LogLevel::Info, "The device \"%s\" does not support geometry shaders.", deviceProperties.deviceName);
			return -1;
		}

		// Check if all required extentions are available
		if (!checkDeviceExtensionSupport(device, requiredExtensions))
		{
			Logger::log(LogLevel::Info, "The device \"%s\" does not support all required extensions.", deviceProperties.deviceName);
			return -1;
		}
		
		int score = 0;

		// Discrete GPUs have a significant performance advantage
		if (deviceProperties.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU) {
			score += 1000;
		}

		// Maximum possible size of textures affects graphics quality
		score += deviceProperties.limits.maxImageDimension2D;

		Logger::log(LogLevel::Info, "The device \"%s\" has a score of %d.", deviceProperties.deviceName, score);

		return score;
	}

} // namespace Aminophenol
