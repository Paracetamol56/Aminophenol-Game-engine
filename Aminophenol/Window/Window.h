
#ifndef WINDOW_H
#define WINDOW_H

#include "Maths/Vector2.h"

#include <vulkan/vulkan.hpp>
#include <GLFW/glfw3.h>

namespace Aminophenol {

	class Window
	{
	public:

		Window(uint32_t width, uint32_t height, const char* title);
		~Window();

		operator GLFWwindow* () const;
		
		GLFWwindow* getGLFWwindow() const;
		VkExtent2D getExtent() const;
		uint32_t getWidth() const;
		uint32_t getHeight() const;
		Maths::Vector2<double> getSizeVector() const;

		bool shouldClose() const;
		bool isMinimized() const;

		void setWidth(uint32_t width);
		void setHeight(uint32_t height);
		void setSize(uint32_t width, uint32_t height);
		void setMaximized(bool maximized);
		void setTitle(const char* title);
		void setIcon(const char* iconPath);
		
	private:

		uint32_t m_width;
		uint32_t m_height;
		const char* m_title;
		GLFWwindow* m_window{ nullptr };

		static void framebufferResizeCallback(GLFWwindow* window, int width, int height);
		
	};

} // namespace Aminophenol

#endif // WINDOW_H
