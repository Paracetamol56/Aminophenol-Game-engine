
#include "pch.h"
#include "InputSystem.h"

namespace Aminophenol {

	InputSystem::InputSystem(const Window& window)
		: m_window{ window }
	{}

	void InputSystem::update()
	{
		for (std::vector<std::shared_ptr<InputAxis>>::iterator it = m_axes.begin(); it != m_axes.end(); ++it)
			(*it)->update();
	}

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

	void InputSystem::setMousePosition(const Maths::Vector2<double>& position)
	{
		glfwSetCursorPos(m_window, position.x, position.y);
	}

	void InputSystem::setCursorMode(CursorMode mode)
	{
		glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL + static_cast<int>(mode));
	}

	std::shared_ptr<InputAxis> InputSystem::addAxis(
		const std::string name,
		const KeyCode keyNegative, const KeyCode keyPositive,
		const float acceleration, const float deceleration
	)
	{
		if (keyNegative == keyPositive)
			throw std::runtime_error("InputSystem::addAxis: keyNegative and keyPositive cannot be the same key.");
		m_axes.push_back(std::make_shared<InputAxis>(m_window, name, keyNegative, keyPositive, acceleration, deceleration));
		return m_axes.back();
	}

	std::shared_ptr<InputButton> InputSystem::addButton(const std::string name, const KeyCode key)
	{
		m_buttons.push_back(std::make_shared<InputKeyButton>(m_window, name, key));
		return m_buttons.back();
	}

	std::shared_ptr<InputButton> InputSystem::addButton(const std::string name, const MouseButton button)
	{
		m_buttons.push_back(std::make_shared<InputMouseButton>(m_window, name, button));
		return m_buttons.back();
	}

	float InputSystem::getAxis(const std::string& name) const
	{
		std::shared_ptr<InputAxis> axis = getAxisPtr(name);
		return axis ? axis->getValue() : 0.0f;
	}

	float InputSystem::getAxis(const Utils::UUID& uuid) const
	{
		std::shared_ptr<InputAxis> axis = getAxisPtr(uuid);
		return axis ? axis->getValue() : 0.0f;
	}

	std::shared_ptr<InputAxis> InputSystem::getAxisPtr(const std::string& name) const
	{
		std::vector<std::shared_ptr<InputAxis>>::const_iterator it = findAxis(name);
		if (it != m_axes.end())
			return *it;
		return nullptr;
	}

	std::shared_ptr<InputAxis> InputSystem::getAxisPtr(const Utils::UUID& uuid) const
	{
		std::vector<std::shared_ptr<InputAxis>>::const_iterator it = findAxis(uuid);
		if (it != m_axes.end())
			return *it;
		return nullptr;
	}

	bool InputSystem::isButtonPressed(const std::string& name) const
	{
		std::shared_ptr<InputButton> button = getButtonPtr(name);
		return button ? button->isPressed() : false;
	}

	bool InputSystem::isButtonPressed(const Utils::UUID& uuid) const
	{
		std::shared_ptr<InputButton> button = getButtonPtr(uuid);
		return button ? button->isPressed() : false;
	}

	std::shared_ptr<InputButton> InputSystem::getButtonPtr(const std::string& name) const
	{
		std::vector<std::shared_ptr<InputButton>>::const_iterator it = findButton(name);
		if (it != m_buttons.end())
			return *it;
		return nullptr;
	}

	std::shared_ptr<InputButton> InputSystem::getButtonPtr(const Utils::UUID& uuid) const
	{
		std::vector<std::shared_ptr<InputButton>>::const_iterator it = findButton(uuid);
		if (it != m_buttons.end())
			return *it;
		return nullptr;
	}

	void InputSystem::removeAxis(const std::string& name)
	{
		std::vector<std::shared_ptr<InputAxis>>::const_iterator it = findAxis(name);
		if (it != m_axes.end())
			m_axes.erase(it);
	}

	void InputSystem::removeAxis(const Utils::UUID& uuid)
	{
		std::vector<std::shared_ptr<InputAxis>>::const_iterator it = findAxis(uuid);
		if (it != m_axes.end())
			m_axes.erase(it);
	}

	void InputSystem::removeButton(const std::string& name)
	{
		std::vector<std::shared_ptr<InputButton>>::const_iterator it = findButton(name);
		if (it != m_buttons.end())
			m_buttons.erase(it);
	}

	void InputSystem::removeButton(const Utils::UUID& uuid)
	{
		std::vector<std::shared_ptr<InputButton>>::const_iterator it = findButton(uuid);
		if (it != m_buttons.end())
			m_buttons.erase(it);
	}

	std::vector<std::shared_ptr<InputAxis>>::const_iterator InputSystem::findAxis(const std::string& name) const
	{
		return std::find_if(
			m_axes.begin(), m_axes.end(),
			[&name](const std::shared_ptr<InputAxis>& axis)
			{
				return axis->getName() == name;
			}
		);
	}

	std::vector<std::shared_ptr<InputAxis>>::const_iterator InputSystem::findAxis(const Utils::UUID& uuid) const
	{
		return std::find_if(
			m_axes.begin(), m_axes.end(),
			[&uuid](const std::shared_ptr<InputAxis>& axis)
			{
				return axis->getUUID() == uuid;
			}
		);
	}

	std::vector<std::shared_ptr<InputButton>>::const_iterator InputSystem::findButton(const std::string& name) const
	{
		return std::find_if(
			m_buttons.begin(), m_buttons.end(),
			[&name](const std::shared_ptr<InputButton>& button)
			{
				return button->getName() == name;
			}
		);
	}

	std::vector<std::shared_ptr<InputButton>>::const_iterator InputSystem::findButton(const Utils::UUID& uuid) const
	{
		return std::find_if(
			m_buttons.begin(), m_buttons.end(),
			[&uuid](const std::shared_ptr<InputButton>& button)
			{
				return button->getUUID() == uuid;
			}
		);
	}

} // namespace Aminophenol
