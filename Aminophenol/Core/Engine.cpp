
#include "pch.h"
#include "Engine.h"

namespace Aminophenol {
	
	Engine::Engine()
		: m_logger{ new Logger(LogLevel::Trace) }
	{
		Logger::log(LogLevel::Trace, "Initializing engine...");

		initGlfwWindow();

		Logger::log(LogLevel::Trace, "Engine initialized.");
	}

	Engine::~Engine()
	{
		Logger::log(LogLevel::Trace, "Destroying engine...");

		// Destroy the window
		glfwDestroyWindow(m_window);
		glfwTerminate();
		
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

} // namespace Aminophenol
