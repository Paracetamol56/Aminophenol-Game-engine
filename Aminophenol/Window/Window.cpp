
#include "pch.h"
#include "Window.h"
#include "Logging/Logger.h"

namespace Aminophenol
{
	
	Window::Window(uint32_t width, uint32_t height, const char* title)
		: m_width(width)
		, m_height(height)
		, m_title(title)
	{
		Logger::log(LogLevel::Trace, "Creating window...");
		
		// Init GLFW
		glfwInit();

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

		// Create the window
		m_window = glfwCreateWindow(m_width, m_height, m_title, nullptr, nullptr);
		glfwSetWindowUserPointer(m_window, this);
		glfwSetFramebufferSizeCallback(m_window, framebufferResizeCallback);
		
		Logger::log(LogLevel::Trace, "Successfully created window.");
	}

	Window::~Window()
	{	
		glfwDestroyWindow(m_window);
		glfwTerminate();
		
		Logger::log(LogLevel::Trace, "Window destroyed.");
	}

	Window::operator GLFWwindow* () const
	{
		return m_window;
	}
	
	bool Window::shouldClose() const
	{
		return glfwWindowShouldClose(m_window);
	}

	bool Window::isMinimized() const
	{
		int width, height;
		glfwGetFramebufferSize(m_window, &width, &height);
		return width == 0 || height == 0;
	}

	VkExtent2D Window::getExtent() const
	{
		return { m_width, m_height };
	}
	
	void Window::framebufferResizeCallback(GLFWwindow* window, int width, int height)
	{
		auto app = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));
		app->m_width = width;
		app->m_height = height;
	}
	
}