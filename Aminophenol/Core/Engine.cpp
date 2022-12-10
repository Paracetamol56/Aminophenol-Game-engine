
#include "pch.h"
#include "Engine.h"

namespace Aminophenol {
	
	Engine::Engine()
#ifdef _DEBUG
		: m_logger{ new Logger(LogLevel::Trace) }
#else
		: m_logger{ new Logger(LogLevel::Error) }
#endif // _DEBUG
	{
		Logger::log(LogLevel::Trace, "Initializing engine...");

		// Device
		m_window = std::make_unique<Window>(_WIDTH, _HEIGHT, "Aminophenol");
		m_instance = std::make_unique<Instance>("Aminophenol app");
		m_physicalDevice = std::make_unique<PhysicalDevice>(*m_instance);
		m_logicalDevice = std::make_unique<LogicalDevice>(*m_instance, *m_physicalDevice);
		m_surface = std::make_unique<Surface>(*m_instance, *m_window, *m_logicalDevice, *m_physicalDevice);
		m_swapchain = std::make_unique<Swapchain>(*m_logicalDevice, *m_physicalDevice, *m_surface, m_window->getExtent());

		// Pipeline
		m_pipeline = std::make_unique<Pipeline>(
			*m_logicalDevice, m_swapchain->getExtent(), m_swapchain->getFormat(),
			"../Aminophenol/Shaders/shader.vert.spv", "../Aminophenol/Shaders/shader.frag.spv"
		);
		m_renderer = std::make_unique<Renderer>(*m_logicalDevice, *m_swapchain, m_pipeline->getRenderPass());
		
		Logger::log(LogLevel::Trace, "Engine initialized.");
	}

	Engine::~Engine()
	{
		Logger::log(LogLevel::Trace, "Destroying engine...");

		// Destroy the pipeline
		m_renderer.reset();
		m_pipeline.reset();
		
		// Destroy the window
		m_window.reset();

		// Destroy the device (not literally)
		m_swapchain.reset();
		m_surface.reset();
		m_logicalDevice.reset();
		m_physicalDevice.reset();
		m_instance.reset();

		Logger::log(LogLevel::Trace, "Engine destroyed.");

		m_logger.reset();
	}

} // namespace Aminophenol
