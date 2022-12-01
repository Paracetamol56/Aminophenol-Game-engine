
#ifndef ENGINE_H
#define ENGINE_H

#include "pch.h"

#include "Logging/Logger.h"
#include "Device/Instance.h"
#include "Device/PhysicalDevice.h"
#include "Device/LogicalDevice.h"
#include "Device/Surface.h"

namespace Aminophenol
{

	class AMINOPHENOL_API Engine
	{
	public:

		Engine();
		~Engine();

	private:

		const int _WIDTH = 640;
		const int _HEIGHT = 480;

		GLFWwindow* m_window{ nullptr };
		std::unique_ptr<Logger> m_logger{ nullptr };
		std::unique_ptr<Instance> m_instance{ nullptr };
		std::unique_ptr<PhysicalDevice> m_physicalDevice{ nullptr };
		std::unique_ptr<LogicalDevice> m_logicalDevice{ nullptr };
		std::unique_ptr<Surface> m_surface{ nullptr };

		void initGlfwWindow();
		void initVulkan();

	};

} // namespace Aminophenol

#endif // ENGINE_H
