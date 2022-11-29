
#ifndef LOGICAL_DEVICE_H
#define LOGICAL_DEVICE_H

#include "pch.h"

#include "Device/PhysicalDevice.h"

namespace Aminophenol
{

	class AMINOPHENOL_API LogicalDevice
	{
	public:

		LogicalDevice(Instance* instance, PhysicalDevice* physicalDevice);
		~LogicalDevice();

	private:

		VkDevice m_device;

	};

} // namespace Aminophenol

#endif // LOGICAL_DEVICE_H
