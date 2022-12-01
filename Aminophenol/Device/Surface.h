
#ifndef SURFACE_H
#define SURFACE_H

#include "pch.h"

#include "Device/Instance.h"
#include "Device/LogicalDevice.h"
#include "Device/PhysicalDevice.h"

namespace Aminophenol
{

	class Surface
	{

	public:
	
		Surface(const Instance& instance, GLFWwindow* window, const LogicalDevice& logicalDevice, const PhysicalDevice& physicalDevice);
		~Surface();

		operator const VkSurfaceKHR& () const;

	private:
	
		const Instance& m_instance;
		VkSurfaceKHR m_surface{ VK_NULL_HANDLE };
	
	};

} // namespace Aminophenol

#endif // SURFACE_H
