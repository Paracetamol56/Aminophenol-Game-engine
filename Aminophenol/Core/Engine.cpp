
#include "pch.h"
#include "Engine.h"

namespace Aminophenol {
	
	Engine::Engine(std::string appName)
		: m_appName{ appName }
	{
#ifdef _DEBUG
		m_logger = std::make_unique<Logger>(LogLevel::Trace);
#else
		m_logger = std::make_unique<Logger>(LogLevel::Error);
#endif // _DEBUG
		
		m_window = std::make_unique<Window>(_WIDTH, _HEIGHT, m_appName.c_str());
		Logger::log(LogLevel::Trace, "Window initialized.");

		m_renderingEngine = std::make_unique<RenderingEngine>(*m_window, m_appName);
		Logger::log(LogLevel::Trace, "Rendering engine initialized.");
	}

	Engine::~Engine()
	{
		m_renderingEngine.reset();
		Logger::log(LogLevel::Trace, "Rendering engine destroyed.");
		
		m_window.reset();
		Logger::log(LogLevel::Trace, "Window destroyed.");

		m_logger.reset();
	}

	void Engine::run()
	{
		Logger::log(LogLevel::Trace, "Running %s...", m_appName.c_str());

		 while (!m_window->shouldClose())
		 {
		 	glfwPollEvents();
		 	m_renderingEngine->update();
		 }
	}

	std::string Engine::getAppName() const
	{
		return m_appName;
	}

	Window& Engine::getWindow() const
	{
		return *m_window;
	}
	
	RenderingEngine& Engine::getRenderingEngine() const
	{
		return *m_renderingEngine;
	}

} // namespace Aminophenol
