#ifndef INPUTSYSTEM_H
#define INPUTSYSTEM_H

#include "pch.h"
#include "Window/Window.h"
#include "Maths/Vector2.h"
#include "InputAxis.h"
#include "KeyCodes.h"

namespace Aminophenol
{
	class AMINOPHENOL_API InputSystem
	{
	public:

		InputSystem(const Window& window);
		~InputSystem() = default;

		void update();

		// Key state methods
		bool isKeyPressed(KeyCode key);
		bool isMouseButtonPressed(MouseButton button);
		Maths::Vector2<double> getMousePosition();
		void setCursorMode(CursorMode mode);

	private:

		const Window& m_window;

		std::vector<std::shared_ptr<InputAxis>> m_axes;
	};

} // namespace Aminophenol

#endif // INPUTSYSTEM_H
