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
		else
		{
			m_computeFamilyIndex = m_graphicsFamilyIndex;
		}

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
		else
		{
			m_transferFamilyIndex = m_graphicsFamilyIndex;
		}
		
		// Documentation: https://registry.khronos.org/vulkan/specs/1.3/html/chap32.html#VkPhysicalDeviceFeatures
		VkPhysicalDeviceFeatures deviceFeatures{};
		deviceFeatures.samplerAnisotropy = VK_TRUE;
		
		std::vector<const char*> extensions = { VK_KHR_SWAPCHAIN_EXTENSION_NAME };
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

		// Get queues
		vkGetDeviceQueue(m_device, m_graphicsFamilyIndex, 0, &m_graphicsQueue);
		vkGetDeviceQueue(m_device, m_presentFamilyIndex, 0, &m_presentQueue);
		vkGetDeviceQueue(m_device, m_computeFamilyIndex, 0, &m_computeQueue);
		vkGetDeviceQueue(m_device, m_transferFamilyIndex, 0, &m_transferQueue);

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

	const VkDevice& LogicalDevice::getDevice() const
	{
		return m_device;
	}

	const Instance& LogicalDevice::getInstance() const
	{
		return m_instance;
	}

	const PhysicalDevice& LogicalDevice::getPhysicalDevice() const
	{
		return m_physicalDevice;
	}

	const uint32_t LogicalDevice::getGraphicsQueueFamilyIndex() const
	{
		return m_graphicsFamilyIndex;
	}

	const uint32_t LogicalDevice::getPresentQueueFamilyIndex() const
	{
		return m_presentFamilyIndex;
	}

	const uint32_t LogicalDevice::getComputeQueueFamilyIndex() const
	{
		return m_computeFamilyIndex;
	}
	
	const uint32_t LogicalDevice::getTransferQueueFamilyIndex() const
	{
		return m_transferFamilyIndex;
	}

	const VkQueue& LogicalDevice::getGraphicsQueue() const
	{
		return m_graphicsQueue;
	}

	const VkQueue& LogicalDevice::getPresentQueue() const
	{
		return m_presentQueue;
	}
	
	const VkQueue& LogicalDevice::getComputeQueue() const
	{
		return m_computeQueue;
	}
	
	const VkQueue& LogicalDevice::getTransferQueue() const
	{
		return m_transferQueue;
	}

	uint32_t LogicalDevice::findMemoryType(uint32_t typeFilter, const VkMemoryPropertyFlags &properties) const
	{
		VkPhysicalDeviceMemoryProperties memProperties;
		vkGetPhysicalDeviceMemoryProperties(m_physicalDevice, &memProperties);

		for (uint32_t i = 0; i < memProperties.memoryTypeCount; i++)
		{
			if ((typeFilter & (1 << i)) && (memProperties.memoryTypes[i].propertyFlags & properties) == properties)
			{
				return i;
			}
		}

		throw std::runtime_error("Failed to find suitable memory type!");
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
			if (queueFamilyProperty.queueCount > 0)
			{
				m_presentFamilyIndex = i;
			}
			
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
			
			// Break if all queues are found
			if (m_supportedQueues == (VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT | VK_QUEUE_TRANSFER_BIT))
			{
				break;
			}
		}
	}

} // namespace Aminophenol
