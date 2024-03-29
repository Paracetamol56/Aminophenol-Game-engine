#ifndef INPUTSYSTEM_H
#define INPUTSYSTEM_H

#include "Window/Window.h"
#include "Maths/Vector2.h"
#include "InputAxis.h"
#include "InputButton.h"
#include "InputKeyButton.h"
#include "InputMouseButton.h"
#include "KeyCodes.h"

namespace Aminophenol
{
	class InputSystem
	{
	public:

		InputSystem(const Window& window);
		~InputSystem() = default;

		void update();

		// Key state methods
		bool isKeyPressed(KeyCode key);
		bool isMouseButtonPressed(MouseButton button);
		Maths::Vector2<double> getMousePosition();
		void setMousePosition(const Maths::Vector2<double>& position);
		void setCursorMode(CursorMode mode);

		// Axis & buttons methods
		std::shared_ptr<InputAxis> addAxis(
			const std::string name,
			const KeyCode keyNegative, const KeyCode keyPositive,
			const float acceleration = 0.1f, const float deceleration = 0.1f
		);
		std::shared_ptr<InputButton> addButton(
			const std::string name, const KeyCode key
		);
		std::shared_ptr<InputButton> addButton(
			const std::string name, const MouseButton button
		);
		float getAxis(const std::string& name) const;
		float getAxis(const Utils::UUID& uuid) const;
		std::shared_ptr<InputAxis> getAxisPtr(const std::string& name) const;
		std::shared_ptr<InputAxis> getAxisPtr(const Utils::UUID& uuid) const;
		bool isButtonPressed(const std::string& name) const;
		bool isButtonPressed(const Utils::UUID& uuid) const;
		std::shared_ptr<InputButton> getButtonPtr(const std::string& name) const;
		std::shared_ptr<InputButton> getButtonPtr(const Utils::UUID& uuid) const;
		void removeAxis(const std::string& name);
		void removeAxis(const Utils::UUID& uuid);
		void removeButton(const std::string& name);
		void removeButton(const Utils::UUID& uuid);

	private:

		const Window& m_window;

		std::vector<std::shared_ptr<InputAxis>> m_axes;
		std::vector<std::shared_ptr<InputButton>> m_buttons;

		std::vector<std::shared_ptr<InputAxis>>::const_iterator findAxis(const std::string& name) const;
		std::vector<std::shared_ptr<InputAxis>>::const_iterator findAxis(const Utils::UUID& uuid) const;
		std::vector<std::shared_ptr<InputButton>>::const_iterator findButton(const std::string& name) const;
		std::vector<std::shared_ptr<InputButton>>::const_iterator findButton(const Utils::UUID& uuid) const;

	};

} // namespace Aminophenol

#endif // INPUTSYSTEM_H
