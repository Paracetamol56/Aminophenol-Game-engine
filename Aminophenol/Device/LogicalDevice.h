
#ifndef LOGICAL_DEVICE_H
#define LOGICAL_DEVICE_H

#include "pch.h"

#include "Device/PhysicalDevice.h"

namespace Aminophenol
{

	class AMINOPHENOL_API LogicalDevice
	{
	public:

		LogicalDevice(const Instance& instance, const PhysicalDevice& physicalDevice);
		~LogicalDevice();

		operator const VkDevice& () const;

	private:

		VkDevice m_device{ VK_NULL_HANDLE };

		const Instance& m_instance;
		const PhysicalDevice& m_physicalDevice;
		
		VkQueueFlags m_supportedQueues{};
		uint32_t m_graphicsFamilyIndex{ 0 };
		uint32_t m_presentFamilyIndex{ 0 };
		uint32_t m_computeFamilyIndex{ 0 };
		uint32_t m_transferFamilyIndex{ 0 };

		VkQueue m_graphicsQueue{ VK_NULL_HANDLE };
		VkQueue m_presentQueue{ VK_NULL_HANDLE };
		VkQueue m_computeQueue{ VK_NULL_HANDLE };
		VkQueue m_transferQueue{ VK_NULL_HANDLE };
		
		void findQueueFamilyIndices();

	};

} // namespace Aminophenol

#endif // LOGICAL_DEVICE_H
