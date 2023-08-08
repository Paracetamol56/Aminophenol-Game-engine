
#include "pch.h"
#include "InputButton.h"

namespace Aminophenol
{

	InputButton::InputButton(const Window& window, const std::string name, const KeyCode key)
		: m_window{ window }
		, m_uuid{ Utils::UUIDv4Generator32::getUUID() }
		, m_name{ name }
		, m_key{ key }
	{}

	const Utils::UUID InputButton::getUUID() const
	{
		return m_uuid;
	}

	const std::string InputButton::getName() const
	{
		return m_name;
	}

	void InputButton::setKey(const KeyCode key)
	{
		m_key = key;
	}

	bool InputButton::isPressed() const
	{
		int state = glfwGetKey(m_window, static_cast<int>(m_key));
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

} // namespace Aminophenol
