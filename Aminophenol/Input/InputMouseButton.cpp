#include "pch.h"
#include "InputMouseButton.h"

namespace Aminophenol {

	InputMouseButton::InputMouseButton(const Window& window, const std::string name, const MouseButton button)
		: InputButton(window, name)
		, m_button(button)
	{}

	void InputMouseButton::setButton(const MouseButton button)
	{
		m_button = button;
	}

	bool InputMouseButton::isPressed()
	{
		int state = glfwGetMouseButton(m_window, static_cast<int>(m_button));
		return state == GLFW_PRESS;
	}

} // namespace Aminophenol
