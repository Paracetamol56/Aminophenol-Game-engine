
#include "pch.h"
#include "InputKeyButton.h"

namespace Aminophenol
{

	InputKeyButton::InputKeyButton(const Window& window, const std::string name, const KeyCode key)
		: InputButton(window, name)
		, m_key(key)
	{}

	void InputKeyButton::setKey(const KeyCode key)
	{
		m_key = key;
	}

	bool InputKeyButton::isPressed()
	{
		int state = glfwGetKey(m_window, static_cast<int>(m_key));
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

} // namespace Aminophenol
