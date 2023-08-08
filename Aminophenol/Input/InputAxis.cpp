
#include "pch.h"
#include "InputAxis.h"

#include "Maths/Utils.h"

namespace Aminophenol
{

	InputAxis::InputAxis(
		const Window& window, const std::string name,
		const KeyCode keyNegative, const KeyCode keyPositive,
		const float acceleration, const float deceleration
	)
		: m_window{ window }
		, m_uuid { Utils::UUIDv4Generator32::getUUID() }
		, m_name{ name }
		, m_keyNegative{ keyNegative }
		, m_keyPositive{ keyPositive }
		, acceleration{ acceleration }
		, deceleration{ deceleration }
	{}

	void InputAxis::update()
	{
		if (glfwGetKey(m_window, static_cast<int>(m_keyNegative)) == GLFW_PRESS)
		{
			m_value = Maths::lerp(m_value, -1.0f, acceleration);
		}
		else if (glfwGetKey(m_window, static_cast<int>(m_keyPositive)) == GLFW_PRESS)
		{
			m_value = Maths::lerp(m_value, 1.0f, acceleration);
		}
		else
		{
			if (m_value > 0.0f)
			{
				m_value = Maths::lerp(m_value, 0.0f, deceleration);
			}
			else if (m_value < 0.0f)
			{
				m_value = Maths::lerp(m_value, 0.0f, deceleration);
			}
		}
	}

	const Utils::UUID InputAxis::getUUID() const
	{
		return m_uuid;
	}

	const std::string InputAxis::getName() const
	{
		return m_name;
	}

	float InputAxis::getValue() const
	{
		return m_value;
	}

	void InputAxis::setKeyNegative(const KeyCode key)
	{
		m_keyNegative = key;
	}

	void InputAxis::setKeyPositive(const KeyCode key)
	{
		m_keyPositive = key;
	}

} // namespace Aminophenol
