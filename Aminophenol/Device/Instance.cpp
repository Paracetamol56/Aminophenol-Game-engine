
#include "pch.h"
#include "Instance.h"

#include "Logging/Logger.h"

namespace Aminophenol
{

	Instance::Instance(std::string appName)
	{
		Logger::log(LogLevel::Trace, "Creating Vulkan instance...");

		// Get the maximum supported Vulkan version
		uint32_t version{ 0 };
		vkEnumerateInstanceVersion(&version);
		Logger::log(
			LogLevel::Info,
			"Maximum supported Vulkan version: %d.%d.%d",
			VK_API_VERSION_MAJOR(version),
			VK_API_VERSION_MINOR(version),
			VK_API_VERSION_PATCH(version)
		);

		// Zero out the patch version to support more vulkan versions
		version &= ~(0xFFFU);

		Logger::log(
			LogLevel::Info,
			"Selected Vulkan version: %d.%d.%d",
			VK_API_VERSION_MAJOR(version),
			VK_API_VERSION_MINOR(version),
			VK_API_VERSION_PATCH(version)
		);

		// Create the application info
		VkApplicationInfo appInfo{};
		appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
		appInfo.pApplicationName = appName.c_str();
		appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
		appInfo.pEngineName = "Aminophenol";
		appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
		appInfo.apiVersion = version;
		
		// Get the required extentions
		std::vector<const char*> extensions = getRequiredExtensions();
		
		if (Logger::s_minLogLevel >= LogLevel::Trace)
		{
			for (const char* extension : extensions)
			{
				Logger::log(LogLevel::Info, "Required extention: %s", extension);
			}
		}

		// Create the instance create info
		VkInstanceCreateInfo createInfo{};
		createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		createInfo.pApplicationInfo = &appInfo;
		createInfo.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
		createInfo.ppEnabledExtensionNames = extensions.data();
		createInfo.enabledLayerCount = 0;
		createInfo.ppEnabledLayerNames = nullptr;

		// Create the instance
		if (vkCreateInstance(&createInfo, nullptr, &m_instance) != VK_SUCCESS)
		{
			throw std::runtime_error("Failed to create Vulkan instance.");
		}

		Logger::log(LogLevel::Trace, "Successfully created Vulkan instance.");
	}

	Instance::~Instance()
	{
		vkDestroyInstance(m_instance, nullptr);

		Logger::log(LogLevel::Trace, "Vulkan instance destroyed");
	}

	std::vector<const char*> Instance::getRequiredExtensions()
	{
		uint32_t glfwExtensionCount = 0;
		const char** glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

		std::vector<const char*> extensions(glfwExtensions, glfwExtensions + glfwExtensionCount);

		return extensions;
	}

} // namespace Aminophenol
