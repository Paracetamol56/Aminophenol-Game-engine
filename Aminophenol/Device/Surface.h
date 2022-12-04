
#ifndef SURFACE_H
#define SURFACE_H

#include "pch.h"

#include "Device/Instance.h"
#include "Window/Window.h"
#include "Device/LogicalDevice.h"
#include "Device/PhysicalDevice.h"

namespace Aminophenol
{

	class Surface
	{

	public:
	
		Surface(const Instance& instance, const Window& window, const LogicalDevice& logicalDevice, const PhysicalDevice& physicalDevice);
		~Surface();

		operator const VkSurfaceKHR& () const;

	private:
	
		VkSurfaceKHR m_surface{ VK_NULL_HANDLE };
		
		const Instance& m_instance;
		const Window& m_window;
		
	};

} // namespace Aminophenol

#endif // SURFACE_H
