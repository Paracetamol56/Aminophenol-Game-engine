
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

		initGlfwWindow();
		initVulkan();

		Logger::log(LogLevel::Trace, "Engine initialized.");
	}

	Engine::~Engine()
	{
		Logger::log(LogLevel::Trace, "Destroying engine...");

		// Destroy the window
		glfwDestroyWindow(m_window);
		glfwTerminate();
		
		delete m_logicalDevice;
		delete m_physicalDevice;
		delete m_instance;

		Logger::log(LogLevel::Trace, "Engine destroyed.");
		
		delete m_logger;
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
		m_instance = new Instance("Aminophenol app");
		m_physicalDevice = new PhysicalDevice(m_instance);
		m_logicalDevice = new LogicalDevice(m_instance, m_physicalDevice);
	}

} // namespace Aminophenol
