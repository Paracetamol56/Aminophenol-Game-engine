
#ifndef ENGINE_H
#define ENGINE_H

#include "pch.h"

#include "Logging/Logger.h"

namespace Aminophenol
{

	class AMINOPHENOL_API Engine
	{
	public:

		Engine();
		~Engine();

	private:

		const int _WIDTH = 640;
		const int _HEIGHT = 480;

		Logger* m_logger = nullptr;
		GLFWwindow* m_window = nullptr;

		void initGlfwWindow();

	};

} // namespace Aminophenol

#endif // ENGINE_H
