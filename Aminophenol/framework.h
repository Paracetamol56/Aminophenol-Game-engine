
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
#include <array>
#include <map>
#include <unordered_map>
#include <string>
#include <sstream>
#include <fstream>
#include <chrono>
#include <random>
#include <memory>
#include <functional>
#include <filesystem>

// Vulkan headers
#include <vulkan/vulkan.hpp>

// GLFW headers
#include <GLFW/glfw3.h>

// GLM headers
#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtx/hash.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>

#endif // FRAMEWORK_H
