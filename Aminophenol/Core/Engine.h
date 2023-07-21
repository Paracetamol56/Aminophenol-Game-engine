
#ifndef ENGINE_H
#define ENGINE_H

#include "pch.h"

#include "Window/Window.h"
#include "Logging/Logger.h"
#include "Utils/UUIDv4Generator.h"
#include "Scene/Scene.h"
#include "Rendering/RenderingEngine.h"

namespace Aminophenol
{

	class AMINOPHENOL_API Engine
	{
	public:

		Engine(std::string appName = "Aminophenol");
		~Engine();

		void run();
		void setActiveScene(const std::shared_ptr<Scene> scene);

		std::string getAppName() const;
		Window& getWindow() const;
		RenderingEngine& getRenderingEngine() const;

	private:

		const std::string _appName;
		const int _WIDTH{ 480 };
		const int _HEIGHT{ 480 };

		std::unique_ptr<Window> m_window;
		Utils::UUIDv4Generator32 m_uuidGenerator;
		std::shared_ptr<Scene> m_activeScene{ nullptr };
		std::unique_ptr<RenderingEngine> m_renderingEngine;

	};

} // namespace Aminophenol

#endif // ENGINE_H
