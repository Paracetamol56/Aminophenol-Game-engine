
#ifndef ENGINE_H
#define ENGINE_H

#include "pch.h"

#include "Window/Window.h"
#include "Logging/Logger.h"
#include "Utils/UUIDv4Generator.h"
#include "Scene/Scene.h"
#include "Rendering/RenderingEngine.h"
#include "Input/InputSystem.h"

namespace Aminophenol
{

	class AMINOPHENOL_API Engine : public NonCopyable
	{
	public:

		Engine(std::string appName = "Aminophenol", const unsigned int width = 800, const unsigned int height = 800);
		~Engine();

		static Engine* get();

		void run();
		void setActiveScene(const std::shared_ptr<Scene> scene);

		std::string getAppName() const;
		Window& getWindow() const;
		RenderingEngine& getRenderingEngine() const;
		InputSystem& getInputSystem() const;

	private:

		static Engine* s_instance;
		const std::string _appName;

		std::unique_ptr<Window> m_window;
		Utils::UUIDv4Generator32 m_uuidGenerator;
		std::shared_ptr<Scene> m_activeScene{ nullptr };
		std::unique_ptr<RenderingEngine> m_renderingEngine;
		std::unique_ptr<InputSystem> m_inputSystem;

	};

} // namespace Aminophenol

#endif // ENGINE_H
