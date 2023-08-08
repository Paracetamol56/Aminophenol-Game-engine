
#ifndef KEY_CODES_H
#define KEY_CODES_H

#include "pch.h"

namespace Aminophenol {

	typedef enum class AMINOPHENOL_API KeyCode : uint16_t
	{
		// From glfw3.h (https://github.com/glfw/glfw/blob/master/include/GLFW/glfw3.h)

		Space = 32,
		Apostrophe = 39,	/* ' */
		Comma = 44,			/* , */
		Minus = 45,			/* - */
		Period = 46,		/* . */
		Slash = 47,			/* / */

		D0 = 48,			/* 0 */
		D1 = 49,			/* 1 */
		D2 = 50,			/* 2 */
		D3 = 51,			/* 3 */
		D4 = 52,			/* 4 */
		D5 = 53,			/* 5 */
		D6 = 54,			/* 6 */
		D7 = 55,			/* 7 */
		D8 = 56,			/* 8 */
		D9 = 57,			/* 9 */

		Semicolon = 59,		/* ; */
		Equal = 61,			/* = */

		A = 65,				/* A */
		B = 66,				/* B */
		C = 67,				/* C */
		D = 68,				/* D */
		E = 69,				/* E */
		F = 70,				/* F */
		G = 71,				/* G */
		H = 72,				/* H */
		I = 73,				/* I */
		J = 74,				/* I */
		K = 75,				/* K */
		L = 76,				/* L */
		M = 77,				/* M */
		N = 78,				/* N */
		O = 79,				/* O */
		P = 80,				/* P */
		Q = 81,				/* Q */
		R = 82,				/* R */
		S = 83,				/* S */
		T = 84,				/* T */
		U = 85,				/* U */
		V = 86,				/* V */
		W = 87,				/* W */
		X = 88,				/* X */
		Y = 89,				/* Y */
		Z = 90,				/* Z */

		LeftBracket = 91,	/* [ */
		Backslash = 92,		/* \ */
		RightBracket = 93,	/* ] */
		GraveAccent = 96,	/* ` */

		World1 = 161,		/* non-US #1 */
		World2 = 162,		/* non-US #2 */

		/* Function keys */
		Escape = 256,		/* Esc */
		Enter = 257,		/* Enter */
		Tab = 258,			/* Tab */
		Backspace = 259,	/* Backspace */
		Insert = 260,		/* Insert */
		Delete = 261,		/* Delete */
		Right = 262,		/* Right arrow */
		Left = 263,			/* Left arrow */
		Down = 264,			/* Down arrow */
		Up = 265,			/* Up arrow */
		PageUp = 266,		/* Page up */
		PageDown = 267,		/* Page down */
		Home = 268,			/* Home */
		End = 269,			/* End */
		CapsLock = 280,		/* Caps lock */
		ScrollLock = 281,	/* Scroll lock */
		NumLock = 282,		/* Num lock */
		PrintScreen = 283,	/* Print screen */
		Pause = 284,		/* Pause */
		F1 = 290,			/* F1 */
		F2 = 291,			/* F2 */
		F3 = 292,			/* F3 */
		F4 = 293,			/* F4 */
		F5 = 294,			/* F5 */
		F6 = 295,			/* F6 */
		F7 = 296,			/* F7 */
		F8 = 297,			/* F8 */
		F9 = 298,			/* F9 */
		F10 = 299,			/* F10 */
		F11 = 300,			/* F11 */
		F12 = 301,			/* F12 */
		F13 = 302,			/* F13 */
		F14 = 303,			/* F14 */
		F15 = 304,			/* F15 */
		F16 = 305,			/* F16 */
		F17 = 306,			/* F17 */
		F18 = 307,			/* F18 */
		F19 = 308,			/* F19 */
		F20 = 309,			/* F20 */
		F21 = 310,			/* F21 */
		F22 = 311,			/* F22 */
		F23 = 312,			/* F23 */
		F24 = 313,			/* F24 */
		F25 = 314,			/* F25 */

		/* Numeric keypad */
		KP0 = 320,			/* 0 (numeric keypad) */
		KP1 = 321,			/* 1 (numeric keypad) */
		KP2 = 322,			/* 2 (numeric keypad) */
		KP3 = 323,			/* 3 (numeric keypad) */
		KP4 = 324,			/* 4 (numeric keypad) */
		KP5 = 325,			/* 5 (numeric keypad) */
		KP6 = 326,			/* 6 (numeric keypad) */
		KP7 = 327,			/* 7 (numeric keypad) */
		KP8 = 328,			/* 8 (numeric keypad) */
		KP9 = 329,			/* 9 (numeric keypad) */
		KPDecimal = 330,	/* . (numeric keypad) */
		KPDivide = 331,		/* / (numeric keypad) */
		KPMultiply = 332,	/* * (numeric keypad) */
		KPSubtract = 333,	/* - (numeric keypad) */
		KPAdd = 334,		/* + (numeric keypad) */
		KPEnter = 335,		/* Enter (numeric keypad) */
		KPEqual = 336,		/* = (numeric keypad) */

		LeftShift = 340,	/* Left shift */
		LeftControl = 341,	/* Left control */
		LeftAlt = 342,		/* Left alt */
		LeftSuper = 343,	/* Left super */
		RightShift = 344,	/* Right shift */
		RightControl = 345,	/* Right control */
		RightAlt = 346,		/* Right alt */
		RightSuper = 347,	/* Right super */
		Menu = 348,			/* Menu */
	} Key;

	enum class AMINOPHENOL_API KeyState
	{
		None = -1,
		Pressed = 0,
		Held = 1,
		Released = 2
	};

	enum class AMINOPHENOL_API CursorMode
	{
		Normal = 0,
		Hidden = 1,
		Locked = 2
	};

	typedef enum class AMINOPHENOL_API MouseButton : uint16_t
	{
		Button0 = 0,
		Button1 = 1,
		Button2 = 2,
		Button3 = 3,
		Button4 = 4,
		Button5 = 5,
		Left = Button0,
		Right = Button1,
		Middle = Button2
	} Button;


	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
	{
		os << static_cast<int32_t>(keyCode);
		return os;
	}

	inline std::ostream& operator<<(std::ostream& os, MouseButton button)
	{
		os << static_cast<int32_t>(button);
		return os;
	}
}

#endif // !KEY_CODES_H
