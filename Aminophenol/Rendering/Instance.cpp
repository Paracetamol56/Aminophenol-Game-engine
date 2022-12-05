
#include "pch.h"
#include "Instance.h"

#include "Logging/Logger.h"
#include "Logging/DebugCallback.h"

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

		// Check if all required extensions are available
		std::vector<const char*> requiredExtensions = getRequiredExtensions();
		if (!checkExtentionSupport(requiredExtensions))
		{
			throw std::runtime_error("All required extentions are not supported!");
		}
		
		// Check if all required layers are available
		std::vector<const char*> requiredLayers = getRequiredLayers();
		if (!checkLayerSupport(requiredLayers))
		{
			throw std::runtime_error("All required layers are not supported!");
		}
				
		// Create the instance create info
		VkInstanceCreateInfo createInfo{};
		createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		createInfo.pApplicationInfo = &appInfo;
		createInfo.enabledExtensionCount = static_cast<uint32_t>(requiredExtensions.size());
		createInfo.ppEnabledExtensionNames = requiredExtensions.data();
		createInfo.enabledLayerCount = static_cast<uint32_t>(requiredLayers.size());
		createInfo.ppEnabledLayerNames = requiredLayers.data();

		// Create the instance
		if (vkCreateInstance(&createInfo, nullptr, &m_instance) != VK_SUCCESS)
		{
			throw std::runtime_error("Failed to create Vulkan instance.");
		}

#ifdef _DEBUG
		// Create a debug messenger
		VkDebugUtilsMessengerCreateInfoEXT debugCreateInfo{};
		debugCreateInfo.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
		debugCreateInfo.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
		debugCreateInfo.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
		debugCreateInfo.pfnUserCallback = debugCallback;
		debugCreateInfo.pUserData = nullptr;

		if (CreateDebugUtilsMessengerEXT(m_instance, &debugCreateInfo, nullptr, &m_debugMessenger) != VK_SUCCESS)
		{
			throw std::runtime_error("Failed to create debug messenger!");
		}
#endif // _DEBUG

		Logger::log(LogLevel::Trace, "Successfully created Vulkan instance.");
	}

	Instance::~Instance()
	{
		Logger::log(LogLevel::Trace, "Destroying Vulkan instance...");

#ifdef _DEBUG
		DestroyDebugUtilsMessengerEXT(m_instance, m_debugMessenger, nullptr);
#endif // _DEBUG
		
		vkDestroyInstance(m_instance, nullptr);

		Logger::log(LogLevel::Trace, "Vulkan instance destroyed");
	}

	Instance::operator const VkInstance& () const
	{
		return m_instance;
	}

	std::vector<const char*> Instance::getRequiredExtensions() const
	{
		uint32_t glfwExtensionCount = 0;
		const char** glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

		std::vector<const char*> requiredExtensions(glfwExtensions, glfwExtensions + glfwExtensionCount);

#ifdef _DEBUG
		requiredExtensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
#endif

		return requiredExtensions;
	}

	std::vector<const char*> Instance::getRequiredLayers() const
	{
		std::vector<const char*> requiredLayers;
		
#ifdef _DEBUG
		requiredLayers.push_back("VK_LAYER_KHRONOS_validation");
#endif // _DEBUG
		
		return requiredLayers;
	}
	
	bool Instance::checkExtentionSupport(const std::vector<const char*>& requiredExtensions)
	{
		// Get the available extentions
		uint32_t extensionCount{ 0 };
		vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
		std::vector<VkExtensionProperties> availableExtensions(extensionCount);
		vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, availableExtensions.data());

		// Log the available extentions
		for (const auto& extension : availableExtensions)
		{
			Logger::log(LogLevel::Info, "Available extension: %s", extension.extensionName);
		}

		// Check if all required extentions are available
		for (const char* extension : requiredExtensions)
		{
			Logger::log(LogLevel::Info, "Required extension: %s", extension);

			bool found{ false };
			for (const VkExtensionProperties& availableExtension : availableExtensions)
			{
				if (strcmp(extension, availableExtension.extensionName) == 0)
				{
					found = true;
					break;
				}
			}

			if (!found)
			{
				Logger::log(LogLevel::Error, "Required extension not found: %s", extension);
				return false;
			}
		}

		return true;
	}

	bool Instance::checkLayerSupport(const std::vector<const char*>& requiredLayers)
	{
		// Get the available layers
		uint32_t layerCount{ 0 };
		vkEnumerateInstanceLayerProperties(&layerCount, nullptr);
		std::vector<VkLayerProperties> availableLayers(layerCount);
		vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

		// Log the available layers
		for (const VkLayerProperties& layer : availableLayers)
		{
			Logger::log(LogLevel::Info, "Available layer: %s", layer.layerName);
		}
		
		// Check if all required layers are available
		for (const char* layer : requiredLayers)
		{
			Logger::log(LogLevel::Info, "Required layer: %s", layer);

			bool found{ false };
			for (const VkLayerProperties& availableLayer : availableLayers)
			{
				if (strcmp(layer, availableLayer.layerName) == 0)
				{
					found = true;
					break;
				}
			}

			if (!found)
			{
				Logger::log(LogLevel::Error, "Required layer not found: %s", layer);
				return false;
			}
		}

		return true;
	}

} // namespace Aminophenol
