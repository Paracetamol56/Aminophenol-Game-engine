
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

		InputButton(const Window& window, const std::string name);
		~InputButton() = default;

		Utils::UUID getUUID() const;
		std::string getName() const;
		virtual bool isPressed() = 0;
		virtual bool wasPressed();

	private:

		const Utils::UUID m_uuid;
		const std::string m_name;
		bool m_wasPressed = false;

	protected:

		const Window& m_window;

	};

} // namespace Aminophenol

#endif // INPUT_BUTTON_H
