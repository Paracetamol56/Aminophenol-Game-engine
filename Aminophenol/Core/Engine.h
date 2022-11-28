
#ifndef ENGINE_H
#define ENGINE_H

#include "pch.h"

#include "Logging/Logger.h"
#include "Device/Instance.h"
#include "Device/PhysicalDevice.h"

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

		Logger* m_logger = nullptr;
		GLFWwindow* m_window = nullptr;
		Instance* m_instance = nullptr;
		PhysicalDevice* m_physicalDevice = nullptr;

		void initGlfwWindow();
		void initVulkan();

	};

} // namespace Aminophenol

#endif // ENGINE_H
