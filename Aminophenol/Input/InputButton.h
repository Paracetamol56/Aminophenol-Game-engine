
#ifndef INPUT_BUTTON_H
#define INPUT_BUTTON_H

#include "Utils/UUIDv4Generator.h"
#include "Window/Window.h"
#include "KeyCodes.h"

namespace Aminophenol
{

	class InputButton
	{
	public:

		InputButton(const Window& window, const std::string name, const KeyCode key);
		~InputButton() = default;

		const Utils::UUID getUUID() const;
		const std::string getName() const;
		void setKey(const KeyCode key);
		bool isPressed() const;

	private:

		const Utils::UUID m_uuid;
		const std::string m_name;
		KeyCode m_key;
		const Window& m_window;

	};

} // namespace Aminophenol

#endif // INPUT_BUTTON_H
