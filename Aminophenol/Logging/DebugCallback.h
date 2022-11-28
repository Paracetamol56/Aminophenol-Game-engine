
#ifndef DEBUG_CALLBACK_H
#define DEBUG_CALLBACK_H

#include "pch.h"

// C/C++ headers
#include <windows.h>

namespace Aminophenol
{

    // Callback functions for validation layers
    static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
        VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
        VkDebugUtilsMessageTypeFlagsEXT messageType,
        const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
        void* pUserData
    )
    {
		std::cout << "[\033[1;31mVALIDATION LAYER\033[0m] " << pCallbackData->pMessage << std::endl;

		return VK_FALSE;
    }

	// Create a debug messenger
	VkResult CreateDebugUtilsMessengerEXT(
		VkInstance instance,
		const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,
		const VkAllocationCallbacks* pAllocator,
		VkDebugUtilsMessengerEXT* pDebugMessenger
	);

	// Destroy a debug messenger
	void DestroyDebugUtilsMessengerEXT(
		VkInstance instance,
		VkDebugUtilsMessengerEXT debugMessenger,
		const VkAllocationCallbacks* pAllocator
	);

} // namespace Aminophenol

#endif // DEBUG_CALLBACK_H
