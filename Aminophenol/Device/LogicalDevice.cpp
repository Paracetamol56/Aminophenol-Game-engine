#include "pch.h"
#include "LogicalDevice.h"

#include "Logging/Logger.h"

namespace Aminophenol
{
	
	LogicalDevice::LogicalDevice(Instance* instance, PhysicalDevice* physicalDevice)
	{
		Logger::log(LogLevel::Trace, "Initializing logical device");

		QueueFamilyIndices indices = physicalDevice->findQueueFamilies();
		
		float queuePriority = 1.0f;
		
		// Documentation: https://registry.khronos.org/vulkan/specs/1.3/html/chap5.html#devsandqueues-queue-creation
		VkDeviceQueueCreateInfo queueCreateInfo{};
		queueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
		queueCreateInfo.flags = VkDeviceQueueCreateFlags();
		queueCreateInfo.queueFamilyIndex = indices.graphicsFamily.value();
		queueCreateInfo.queueCount = 1;
		queueCreateInfo.pQueuePriorities = &queuePriority;
		
		// Documentation: https://registry.khronos.org/vulkan/specs/1.3/html/chap32.html#VkPhysicalDeviceFeatures
		VkPhysicalDeviceFeatures deviceFeatures{};
		deviceFeatures.samplerAnisotropy = VK_TRUE;
		
		std::vector<const char*> extensions; // Empty for now
		std::vector<const char*> layers = instance->getRequiredLayers();
		
		// Documentation: https://registry.khronos.org/vulkan/specs/1.3/html/chap5.html#VkDeviceCreateInfo
		VkDeviceCreateInfo createInfo{};
		createInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
		createInfo.flags = VkDeviceCreateFlags();
		createInfo.queueCreateInfoCount = 1;
		createInfo.pQueueCreateInfos = &queueCreateInfo;
		createInfo.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
		createInfo.ppEnabledExtensionNames = extensions.data();
		createInfo.enabledLayerCount = static_cast<uint32_t>(layers.size());
		createInfo.ppEnabledLayerNames = layers.data();
		createInfo.pEnabledFeatures = &deviceFeatures;

		if (vkCreateDevice(physicalDevice->getPhysicalDevice(), &createInfo, nullptr, &m_device) != VK_SUCCESS)
		{
			throw std::runtime_error("Failed to create logical device!");
		}

		Logger::log(LogLevel::Trace, "Logical device initialized");
	}

	LogicalDevice::~LogicalDevice()
	{
		Logger::log(LogLevel::Trace, "Destroying logical device");
		
		vkDestroyDevice(m_device, nullptr);
		
		Logger::log(LogLevel::Trace, "Logical device destroyed");
	}

} // namespace Aminophenol
