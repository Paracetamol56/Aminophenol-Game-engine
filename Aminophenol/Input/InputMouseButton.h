
#ifndef INPUT_MOUSE_BUTTON_H
#define INPUT_MOUSE_BUTTON_H

#include "Window/Window.h"
#include "InputButton.h"
#include "KeyCodes.h"

namespace Aminophenol {

	class InputMouseButton final
		: public InputButton
	{
	public:

		InputMouseButton(const Window& window, const std::string name, const MouseButton button);
		~InputMouseButton() = default;

		void setButton(const MouseButton button);
		bool isPressed() override;

	private:

		MouseButton m_button;

	};

} // namespace Aminophenol

#endif // !INPUT_MOUSE_BUTTON_H
