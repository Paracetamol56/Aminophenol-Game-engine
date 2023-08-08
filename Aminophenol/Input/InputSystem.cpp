
#include "pch.h"
#include "InputSystem.h"

namespace Aminophenol {

	InputSystem::InputSystem(const Window& window)
		: m_window{ window }
	{}

	bool InputSystem::isKeyPressed(KeyCode keycode)
	{
		int state = glfwGetKey(m_window, static_cast<int>(keycode));
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool InputSystem::isMouseButtonPressed(MouseButton button)
	{
		int state = glfwGetMouseButton(m_window, static_cast<int>(button));
		return state == GLFW_PRESS;
	}

	Maths::Vector2<double> InputSystem::getMousePosition()
	{
		double x, y;
		glfwGetCursorPos(m_window, &x, &y);
		return Maths::Vector2<double>{ x, y };
	}

	void InputSystem::setCursorMode(CursorMode mode)
	{
		glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL + static_cast<int>(mode));
	}

} // namespace Aminophenol
