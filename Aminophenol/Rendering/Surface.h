
#ifndef SURFACE_H
#define SURFACE_H

#include "pch.h"

#include "Rendering/Instance.h"
#include "Window/Window.h"
#include "Rendering/LogicalDevice.h"
#include "Rendering/PhysicalDevice.h"

namespace Aminophenol
{

	class AMINOPHENOL_API Surface
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
