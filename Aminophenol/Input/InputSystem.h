#ifndef INPUTSYSTEM_H
#define INPUTSYSTEM_H

#include "pch.h"
#include "Window/Window.h"
#include "Maths/Vector2.h"
#include "KeyCodes.h"

namespace Aminophenol
{
	class InputSystem
	{
	public:

		InputSystem(const Window& window);
		~InputSystem() = default;

		// Key state functions
		bool isKeyPressed(KeyCode key);
		bool isMouseButtonPressed(MouseButton button);
		Maths::Vector2<double> getMousePosition();
		void setCursorMode(CursorMode mode);

	private:

		const Window& m_window;

	};

} // namespace Aminophenol

#endif // INPUTSYSTEM_H
