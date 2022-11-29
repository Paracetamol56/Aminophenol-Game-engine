
#ifndef FRAMEWORK_H
#define FRAMEWORK_H

// Remove unusual windows stuff
#define WIN32_LEAN_AND_MEAN

// Define the export macro
#ifdef AMINOPHENOL_EXPORTS
#define AMINOPHENOL_API __declspec(dllexport)
#else
#define AMINOPHENOL_API __declspec(dllimport)
#endif

// C/C++ headers
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include <chrono>
#include <memory>
#include <optional>

// Vulkan headers
#include <vulkan/vulkan.hpp>

// GLFW headers
#include <GLFW/glfw3.h>

#endif // FRAMEWORK_H
