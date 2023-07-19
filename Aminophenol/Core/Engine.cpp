
#include "pch.h"
#include "Engine.h"

namespace Aminophenol {
	
	Engine::Engine(std::string appName)
		: _appName{ appName }
		, m_uuidGenerator{}
#ifdef _DEBUG
		, m_logger{ LogLevel::Trace }
#else
		, m_logger{ LogLevel::Error }
#endif // _DEBUG
	{
		try {
			m_window = std::make_unique<Window>(_WIDTH, _HEIGHT, _appName.c_str());
			Logger::log(LogLevel::Trace, "Window initialized.");

			m_renderingEngine = std::make_unique<RenderingEngine>(*m_window, _appName);
			Logger::log(LogLevel::Trace, "Rendering engine initialized.");
		}
		catch (const std::exception& e)
		{
			Logger::log(LogLevel::Critical, "Failed to initialize engine.");
			Logger::log(LogLevel::Critical, e.what());
		}
	}

	Engine::~Engine()
	{
		try {
			m_renderingEngine.reset();
			Logger::log(LogLevel::Trace, "Rendering engine destroyed.");

			m_window.reset();
			Logger::log(LogLevel::Trace, "Window destroyed.");
		}
		catch (const std::exception& e)
		{
			Logger::log(LogLevel::Critical, "Failed to destroy engine.");
			Logger::log(LogLevel::Critical, e.what());
		}
	}

	void Engine::run()
	{
		Logger::log(LogLevel::Info, "Running %s...", _appName.c_str());

		while (!m_window->shouldClose())
		{
			glfwPollEvents();
			m_renderingEngine->update();
		}
	}

	void Engine::setActiveScene(const std::shared_ptr<Scene> scene)
	{
		m_activeScene = scene;
		m_renderingEngine->setActiveScene(scene);
		if (!m_activeScene)
		{
			Logger::log(LogLevel::Warning, "Active scene is null.");
		}
		else
		{
			// Call the start method of all components with a quadratic loop
			m_activeScene->onAttach();
		}
	}

	std::string Engine::getAppName() const
	{
		return _appName;
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
