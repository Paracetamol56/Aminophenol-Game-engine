
#ifndef PHYSICAL_DEVICE_H
#define PHYSICAL_DEVICE_H

#include "pch.h"

#include "Device/Instance.h"

namespace Aminophenol
{
	
	struct QueueFamilyIndices
	{
		std::optional<uint32_t> graphicsFamily;
		std::optional<uint32_t> presentFamily;

		bool isComplete();
	};

	class AMINOPHENOL_API PhysicalDevice
	{
	public:

		PhysicalDevice(Instance* instance);
		~PhysicalDevice();
		
		VkPhysicalDevice getPhysicalDevice() const;
		QueueFamilyIndices findQueueFamilies() const;

	private:

		VkPhysicalDevice m_physicalDevice;

		VkPhysicalDevice pickPhysicalDevice(Instance* instance);
		void logPhysicalDeviceProperties(VkPhysicalDeviceProperties& deviceProperties);
		bool checkDeviceExtensionSupport(VkPhysicalDevice& device, const std::vector<const char*>& requiredExtensions);
		int rateDeviceSuitability(VkPhysicalDevice device, const std::vector<const char*>& requiredExtensions);

	};

} // namespace Aminophenol

#endif // PHYSICAL_DEVICE_H
