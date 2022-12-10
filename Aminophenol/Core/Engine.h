
#ifndef ENGINE_H
#define ENGINE_H

#include "pch.h"

#include "Window/Window.h"
#include "Logging/Logger.h"
#include "Rendering/Instance.h"
#include "Rendering/PhysicalDevice.h"
#include "Rendering/LogicalDevice.h"
#include "Rendering/Surface.h"
#include "Rendering/Swapchain/Swapchain.h"
#include "Rendering/Pipeline/Pipeline.h"
#include "Rendering/Renderer.h"

namespace Aminophenol
{

	class AMINOPHENOL_API Engine
	{
	public:

		Engine();
		~Engine();

	private:

		const int _WIDTH = 640;
		const int _HEIGHT = 480;

		std::unique_ptr<Window> m_window{ nullptr };
		std::unique_ptr<Logger> m_logger{ nullptr };
		std::unique_ptr<Instance> m_instance{ nullptr };
		std::unique_ptr<PhysicalDevice> m_physicalDevice{ nullptr };
		std::unique_ptr<LogicalDevice> m_logicalDevice{ nullptr };
		std::unique_ptr<Surface> m_surface{ nullptr };
		std::unique_ptr<Swapchain> m_swapchain{ nullptr };

		std::unique_ptr<Pipeline> m_pipeline{ nullptr };
		std::unique_ptr<Renderer> m_renderer{ nullptr };

	};

} // namespace Aminophenol

#endif // ENGINE_H
