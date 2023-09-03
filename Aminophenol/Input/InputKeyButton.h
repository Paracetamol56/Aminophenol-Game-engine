
#ifndef INPUT_KEY_BUTTON_H
#define INPUT_KEY_BUTTON_H

#include "Window/Window.h"
#include "InputButton.h"
#include "KeyCodes.h"

namespace Aminophenol
{

	class InputKeyButton final
		: public InputButton
	{
	public:

		InputKeyButton(const Window& window, const std::string name, const KeyCode key);
		~InputKeyButton() = default;

		void setKey(const KeyCode key);
		bool isPressed() override;

	private:

		KeyCode m_key;

	};

} // namespace Aminophenol

#endif // !INPUT_KEY_BUTTON_H