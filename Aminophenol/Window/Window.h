
#ifndef WINDOW_H
#define WINDOW_H

#include "pch.h"

namespace Aminophenol {

	class AMINOPHENOL_API Window
	{
	public:

		Window(uint32_t width, uint32_t height, const char* title);
		~Window();

		operator GLFWwindow* () const;
		
		bool shouldClose() const;
		bool isMinimized() const;

		VkExtent2D getExtent() const;
		
	private:

		uint32_t m_width;
		uint32_t m_height;
		const char* m_title;
		GLFWwindow* m_window{ nullptr };

		static void framebufferResizeCallback(GLFWwindow* window, int width, int height);
		
	};

} // namespace Aminophenol

#endif // WINDOW_H
