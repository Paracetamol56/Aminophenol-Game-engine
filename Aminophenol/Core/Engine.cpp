
#include "pch.h"
#include "Engine.h"

namespace Aminophenol {
	
	Engine* Engine::s_instance = nullptr;

	Engine::Engine(std::string appName, const float maxFPS, const unsigned int width, const unsigned int height)
		:  _appName{ appName }
		, m_maxFrameTime{ 1.0f / maxFPS }
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

		s_instance = this;
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

	Engine* Engine::get()
	{
		return s_instance;
	}

	void Engine::run()
	{
		Logger::log(LogLevel::Info, "Running %s...", _appName.c_str());

		m_activeScene->onStart();

		std::chrono::high_resolution_clock::time_point previousTime = std::chrono::high_resolution_clock::now();
		std::chrono::high_resolution_clock::time_point lastFrameTime = std::chrono::high_resolution_clock::now();
		double accumulatedTime = 0.0;

		while (!m_window->shouldClose())
		{
			std::chrono::high_resolution_clock::time_point currentTime = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> elapsedDuration = currentTime - previousTime;
			previousTime = currentTime;
			accumulatedTime += elapsedDuration.count();

			while (accumulatedTime >= m_maxFrameTime)
			{
				glfwPollEvents();
				m_inputSystem->update();
				m_activeScene->onUpdate();
				m_renderingEngine->update();
				accumulatedTime -= m_maxFrameTime;
				m_deltaTime = std::chrono::duration<float>(currentTime - lastFrameTime).count();
				lastFrameTime = currentTime;
			}
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

	float Engine::getDeltaTime() const
	{
		return m_deltaTime;
	}

	float Engine::getFPS() const
	{
		return 1.0f / m_deltaTime;
	}

	void Engine::setMaxFPS(const float maxFPS)
	{
		m_maxFrameTime = 1.0f / maxFPS;
	}

} // namespace Aminophenol
