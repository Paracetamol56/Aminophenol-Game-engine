
#ifndef PHYSICAL_DEVICE_H
#define PHYSICAL_DEVICE_H

#include "pch.h"

#include "Rendering/Device/Instance.h"

namespace Aminophenol
{

	class AMINOPHENOL_API PhysicalDevice
	{
	public:

		PhysicalDevice(const Instance& instance);
		~PhysicalDevice();
		
		operator const VkPhysicalDevice& () const;

	private:

		const Instance& m_instance;
		VkPhysicalDevice m_physicalDevice{ VK_NULL_HANDLE };

		VkPhysicalDevice pickPhysicalDevice();
		void logPhysicalDeviceProperties(VkPhysicalDeviceProperties& deviceProperties);
		bool checkDeviceExtensionSupport(VkPhysicalDevice& device, const std::vector<const char*>& requiredExtensions);
		int rateDeviceSuitability(VkPhysicalDevice device, const std::vector<const char*>& requiredExtensions);

	};

} // namespace Aminophenol

#endif // PHYSICAL_DEVICE_H
