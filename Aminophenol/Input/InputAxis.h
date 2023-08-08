
#ifndef INPUT_AXIS_H
#define INPUT_AXIS_H

#include "pch.h"
#include "Utils/UUIDv4Generator.h"
#include "Window/Window.h"
#include "KeyCodes.h"

namespace Aminophenol
{

	class AMINOPHENOL_API InputAxis
	{
	public:

		InputAxis(
			const Window& window, const std::string name,
			const KeyCode keyNegative, const KeyCode keyPositive,
			const float acceleration = 0.1f, const float deceleration = 0.1f
		);
		~InputAxis() = default;

		void update();

		const Utils::UUID getUUID() const;
		const std::string getName() const;
		float getValue() const;
		void setKeyNegative(const KeyCode key);
		void setKeyPositive(const KeyCode key);

	private:

		const Utils::UUID m_uuid;
		const std::string m_name;
		const Window& m_window;

		KeyCode m_keyNegative;
		KeyCode m_keyPositive;

		float m_value = 0.0f;
		float acceleration;
		float deceleration;

	};

} // namespace Aminophenol

#endif // INPUT_AXIS_H
