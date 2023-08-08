
#include "pch.h"
#include "Engine.h"

namespace Aminophenol {
	
	Engine::Engine(std::string appName, const unsigned int width, const unsigned int height)
		: _appName{ appName }
		, m_uuidGenerator{}
	{
		try {
			m_window = std::make_unique<Window>(width, height, _appName.c_str());
			Logger::log(LogLevel::Trace, "Window initialized.");

			m_renderingEngine = std::make_unique<RenderingEngine>(*m_window, _appName);
			Logger::log(LogLevel::Trace, "Rendering engine initialized.");

			m_inputSystem = std::make_unique<InputSystem>(*m_window);
			Logger::log(LogLevel::Trace, "Input system initialized.");
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
			m_activeScene.reset();
			m_renderingEngine.reset();
			m_window.reset();
			m_inputSystem.reset();
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
			m_inputSystem->update();
			m_renderingEngine->update();
		}

		Logger::log(LogLevel::Info, "Exiting %s...", _appName.c_str());
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

	InputSystem& Engine::getInputSystem() const
	{
		return *m_inputSystem;
	}

} // namespace Aminophenol
