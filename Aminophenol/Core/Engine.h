
#ifndef ENGINE_H
#define ENGINE_H

#include "pch.h"

#include "Window/Window.h"
#include "Logging/Logger.h"
#include "Rendering/RenderingEngine.h"

namespace Aminophenol
{

	class AMINOPHENOL_API Engine
	{
	public:

		Engine(std::string appName = "Aminophenol");
		~Engine();

		void run();

		std::string getAppName() const;
		Window& getWindow() const;
		RenderingEngine& getRenderingEngine() const;

	private:

		const std::string m_appName;
		const int _WIDTH{ 640 };
		const int _HEIGHT{ 480 };

		std::unique_ptr<Window> m_window;
		std::unique_ptr<Logger> m_logger;
		std::unique_ptr<RenderingEngine> m_renderingEngine;

	};

} // namespace Aminophenol

#endif // ENGINE_H
