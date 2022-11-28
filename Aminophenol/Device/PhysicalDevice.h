
#ifndef PHYSICAL_DEVICE_H
#define PHYSICAL_DEVICE_H

#include "pch.h"

#include "Device/Instance.h"

namespace Aminophenol
{

	class AMINOPHENOL_API PhysicalDevice
	{
	public:

		PhysicalDevice(Instance* instance);
		~PhysicalDevice();

	private:

		VkPhysicalDevice* m_physicalDevice;

		void pickPhysicalDevice(Instance* instance);
		void logPhysicalDeviceProperties(VkPhysicalDeviceProperties& deviceProperties);
		bool checkDeviceExtensionSupport(VkPhysicalDevice& device, const std::vector<const char*>& requiredExtensions);
		int rateDeviceSuitability(VkPhysicalDevice device, const std::vector<const char*>& requiredExtensions);

	};

} // namespace Aminophenol

#endif // PHYSICAL_DEVICE_H
