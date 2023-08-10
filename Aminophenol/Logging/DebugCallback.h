
#ifndef DEBUG_CALLBACK_H
#define DEBUG_CALLBACK_H

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
		// Get timestamp
		SYSTEMTIME st;
		GetLocalTime(&st);

		// Timestamp
		std::cout
			<< "[\033[1;37m"
			<< std::setw(2) << std::setfill('0') << st.wHour << ":"
			<< std::setw(2) << std::setfill('0') << st.wMinute << ":"
			<< std::setw(2) << std::setfill('0') << st.wSecond << "."
			<< std::setw(3) << std::setfill('0') << st.wMilliseconds
			<< "\033[0m] ["
			<< "\033[1;31mVALIDATION LAYER\033[0m] " << pCallbackData->pMessage << std::endl;

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
