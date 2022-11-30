#include "pch.h"
#include "LogicalDevice.h"

#include "Logging/Logger.h"

namespace Aminophenol
{
	
	LogicalDevice::LogicalDevice(const Instance& instance, const PhysicalDevice& physicalDevice)
		: m_instance(instance)
		, m_physicalDevice(physicalDevice)
	{
		Logger::log(LogLevel::Trace, "Initializing logical device");

		findQueueFamilyIndices();
		
		std::vector<VkDeviceQueueCreateInfo> queueCreateInfos;
		float queuePriority = 1.0f;
		
		// Graphics queue create info
		if (m_supportedQueues & VK_QUEUE_GRAPHICS_BIT)
		{
			// Documentation: https://registry.khronos.org/vulkan/specs/1.3/html/chap5.html#devsandqueues-queue-creation
			VkDeviceQueueCreateInfo queueCreateInfo{};
			queueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
			queueCreateInfo.flags = VkDeviceQueueCreateFlags();
			queueCreateInfo.queueFamilyIndex = m_graphicsFamilyIndex;
			queueCreateInfo.queueCount = 1;
			queueCreateInfo.pQueuePriorities = &queuePriority;
			queueCreateInfos.push_back(queueCreateInfo);
		}
		else
		{
			throw std::runtime_error("No graphics queue family index found");
		}

		// Compute queue create info
		if (m_supportedQueues & VK_QUEUE_COMPUTE_BIT && m_computeFamilyIndex != m_graphicsFamilyIndex)
		{
			// Documentation: https://registry.khronos.org/vulkan/specs/1.3/html/chap5.html#devsandqueues-queue-creation
			VkDeviceQueueCreateInfo queueCreateInfo{};
			queueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
			queueCreateInfo.flags = VkDeviceQueueCreateFlags();
			queueCreateInfo.queueFamilyIndex = m_computeFamilyIndex;
			queueCreateInfo.queueCount = 1;
			queueCreateInfo.pQueuePriorities = &queuePriority;
			queueCreateInfos.push_back(queueCreateInfo);
		}
		// Optional

		// Transfer queue create info
		if (m_supportedQueues & VK_QUEUE_TRANSFER_BIT && m_transferFamilyIndex != m_graphicsFamilyIndex && m_transferFamilyIndex != m_computeFamilyIndex)
		{
			// Documentation: https://registry.khronos.org/vulkan/specs/1.3/html/chap5.html#devsandqueues-queue-creation
			VkDeviceQueueCreateInfo queueCreateInfo{};
			queueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
			queueCreateInfo.flags = VkDeviceQueueCreateFlags();
			queueCreateInfo.queueFamilyIndex = m_transferFamilyIndex;
			queueCreateInfo.queueCount = 1;
			queueCreateInfo.pQueuePriorities = &queuePriority;
			queueCreateInfos.push_back(queueCreateInfo);
		}
		// Optional
		
		// Documentation: https://registry.khronos.org/vulkan/specs/1.3/html/chap32.html#VkPhysicalDeviceFeatures
		VkPhysicalDeviceFeatures deviceFeatures{};
		deviceFeatures.samplerAnisotropy = VK_TRUE;
		
		std::vector<const char*> extensions; // Empty for now
		std::vector<const char*> layers = m_instance.getRequiredLayers();
		
		// Documentation: https://registry.khronos.org/vulkan/specs/1.3/html/chap5.html#VkDeviceCreateInfo
		VkDeviceCreateInfo createInfo{};
		createInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
		createInfo.flags = VkDeviceCreateFlags();
		createInfo.queueCreateInfoCount = static_cast<uint32_t>(queueCreateInfos.size());
		createInfo.pQueueCreateInfos = queueCreateInfos.data();
		createInfo.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
		createInfo.ppEnabledExtensionNames = extensions.data();
		createInfo.enabledLayerCount = static_cast<uint32_t>(layers.size());
		createInfo.ppEnabledLayerNames = layers.data();
		createInfo.pEnabledFeatures = &deviceFeatures;

		if (vkCreateDevice(m_physicalDevice, &createInfo, nullptr, &m_device) != VK_SUCCESS)
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

	LogicalDevice::operator const VkDevice& () const
	{
		return m_device;
	}

	void Aminophenol::LogicalDevice::findQueueFamilyIndices()
	{
		// Get the queue family properties from the physical device
		uint32_t queueFamilyPropertyCount = 0;
		vkGetPhysicalDeviceQueueFamilyProperties(m_physicalDevice, &queueFamilyPropertyCount, nullptr);
		std::vector<VkQueueFamilyProperties> queueFamilyProperties(queueFamilyPropertyCount);
		vkGetPhysicalDeviceQueueFamilyProperties(m_physicalDevice, &queueFamilyPropertyCount, queueFamilyProperties.data());
		
		// Find the queue family indices

		for (uint32_t i = 0; i < queueFamilyPropertyCount; i++)
		{
			const VkQueueFamilyProperties& queueFamilyProperty = queueFamilyProperties[i];

			// Check if the queue family supports graphics
			if (queueFamilyProperty.queueFlags & VK_QUEUE_GRAPHICS_BIT)
			{
				m_graphicsFamilyIndex = i;
				m_supportedQueues |= VK_QUEUE_GRAPHICS_BIT;
			}

			// Check if the queue family supports presentation
			// VkBool32 presentationSupport = false;
			// vkGetPhysicalDeviceSurfaceSupportKHR(m_physicalDevice, i, m_instance.getSurface(), &presentationSupport);
			// if (presentationSupport)
			// {
			// 	m_presentationFamilyIndex = i;
			// 	m_supportedQueues |= VK_QUEUE_GRAPHICS_BIT;
			// }
			
			// Check if the queue family supports compute
			if (queueFamilyProperty.queueFlags & VK_QUEUE_COMPUTE_BIT)
			{
				m_computeFamilyIndex = i;
				m_supportedQueues |= VK_QUEUE_COMPUTE_BIT;
			}
			
			// Check if the queue family supports transfer
			if (queueFamilyProperty.queueFlags & VK_QUEUE_TRANSFER_BIT)
			{
				m_transferFamilyIndex = i;
				m_supportedQueues |= VK_QUEUE_TRANSFER_BIT;
			}
		}
	}

} // namespace Aminophenol
