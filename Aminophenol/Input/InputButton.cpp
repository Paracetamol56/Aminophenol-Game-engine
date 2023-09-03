
#include "pch.h"
#include "InputButton.h"

namespace Aminophenol
{

	InputButton::InputButton(const Window& window, const std::string name)
		: m_window{ window }
		, m_uuid{ Utils::UUIDv4Generator32::getUUID() }
		, m_name{ name }
	{}

	Utils::UUID InputButton::getUUID() const
	{
		return m_uuid;
	}

	std::string InputButton::getName() const
	{
		return m_name;
	}

	bool InputButton::wasPressed()
	{
		bool stillPressed = m_wasPressed && isPressed();
		m_wasPressed = isPressed();
		return m_wasPressed != stillPressed;
	}

} // namespace Aminophenol
