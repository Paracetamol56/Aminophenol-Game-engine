
#include "pch.h"
#include "Window.h"
#include <stb_image.h>
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

		// Set GLFW window hints
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

	void Window::setWidth(uint32_t width)
	{
		m_width = width;
		glfwSetWindowSize(m_window, m_width, m_height);
	}

	void Window::setHeight(uint32_t height)
	{
		m_height = height;
		glfwSetWindowSize(m_window, m_width, m_height);
	}

	void Window::setSize(uint32_t width, uint32_t height)
	{
		m_width = width;
		m_height = height;
		glfwSetWindowSize(m_window, m_width, m_height);
	}

	void Window::setMaximized(bool maximized)
	{
		if (maximized)
			glfwMaximizeWindow(m_window);
		else
			glfwRestoreWindow(m_window);
	}

	void Window::setTitle(const char* title)
	{
		m_title = title;
		glfwSetWindowTitle(m_window, m_title);
	}

	void Window::setIcon(const char* iconPath)
	{
		// Check if path is valid
		std::filesystem::path path = iconPath;
		if (!std::filesystem::exists(path))
		{
			Logger::log(LogLevel::Error, "Icon path is invalid: %s", iconPath);
			return;
		}

		GLFWimage images[1];
		images[0].pixels = stbi_load(iconPath, &images[0].width, &images[0].height, 0, 4);
		glfwSetWindowIcon(m_window, 1, images);
		stbi_image_free(images[0].pixels);
	}

	GLFWwindow* Window::getGLFWwindow() const
	{
		return m_window;
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