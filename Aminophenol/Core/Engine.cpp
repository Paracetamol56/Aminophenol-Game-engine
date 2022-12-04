
#include "pch.h"
#include "Engine.h"

namespace Aminophenol {
	
	Engine::Engine()
#ifdef _DEBUG
		: m_logger{ new Logger(LogLevel::Trace) }
#else
		: m_logger{ new Logger(LogLevel::Error) }
#endif // _DEBUG
	{
		Logger::log(LogLevel::Trace, "Initializing engine...");

		m_window = std::make_unique<Window>(_WIDTH, _HEIGHT, "Aminophenol");
		m_instance = std::make_unique<Instance>("Aminophenol app");
		m_physicalDevice = std::make_unique<PhysicalDevice>(*m_instance);
		m_logicalDevice = std::make_unique<LogicalDevice>(*m_instance, *m_physicalDevice);
		m_surface = std::make_unique<Surface>(*m_instance, *m_window, *m_logicalDevice, *m_physicalDevice);

		Logger::log(LogLevel::Trace, "Engine initialized.");
	}

	Engine::~Engine()
	{
		Logger::log(LogLevel::Trace, "Destroying engine...");

		// Destroy the window
		m_window.reset();
		glfwTerminate();

		m_surface.reset();
		m_logicalDevice.reset();
		m_physicalDevice.reset();
		m_instance.reset();

		Logger::log(LogLevel::Trace, "Engine destroyed.");

		m_logger.reset();
	}

	void Engine::initGlfwWindow()
	{
		glfwInit();

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		m_window = glfwCreateWindow(_WIDTH, _HEIGHT, "Aminophenol", nullptr, nullptr);
	}

	void Engine::initVulkan()
	{
		m_instance = std::make_unique<Instance>("Aminophenol app");
		m_physicalDevice = std::make_unique<PhysicalDevice>(*m_instance);
		m_logicalDevice = std::make_unique<LogicalDevice>(*m_instance, *m_physicalDevice);
		m_surface = std::make_unique<Surface>(*m_instance, m_window, *m_logicalDevice, *m_physicalDevice);
	}

} // namespace Aminophenol
