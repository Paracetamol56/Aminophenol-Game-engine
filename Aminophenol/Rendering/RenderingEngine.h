
#ifndef RENDERING_ENGINE_H
#define RENDERING_ENGINE_H

#include "Utils/NonCopyable.h"
#include "Window/Window.h"
#include "Scene/Scene.h"
#include "Rendering/Device/Instance.h"
#include "Rendering/Device/PhysicalDevice.h"
#include "Rendering/Device/LogicalDevice.h"
#include "Rendering/Device/Surface.h"
#include "Rendering/Swapchain/Swapchain.h"
#include "Rendering/Pipeline/Pipeline.h"
#include "Rendering/Commands/CommandPool.h"
#include "Rendering/Commands/CommandBuffer.h"
#include "Rendering/Frame.h"
#include "Mesh/Mesh.h"

#include "Maths/Vector2.h"
#include "Maths/Color.h"

namespace Aminophenol {

	struct PushConstantData
	{
		alignas(0) Maths::Matrix4f modelTransform;
	};

	/// <summary>
	/// This class handles the rendering engine.
	/// It holds all the necessary objects to render :
	/// Instance, PhysicalDevice, LogicalDevice, Surface, Swapchain, Pipeline, CommandPool
	/// </summary>
	class RenderingEngine : NonCopyable
	{
	public:

		RenderingEngine(const Window& window, const std::string& appName);
		~RenderingEngine();
		
		void update();

		Instance& getInstance() const;
		PhysicalDevice& getPhysicalDevice() const;
		LogicalDevice& getLogicalDevice() const;
		Surface& getSurface() const;
		Swapchain& getSwapchain() const;
		Pipeline& getPipeline() const;
		const std::shared_ptr<CommandPool> getCommandPool() const;

		void setActiveScene(const std::shared_ptr<Scene> scene);
		std::shared_ptr<Scene> getActiveScene() const;

	private:

		// Window
		const Window& m_window;

		// Scene
		std::shared_ptr<Scene> m_activeScene{ nullptr };
		
		// Device
		std::unique_ptr<Instance> m_instance{ nullptr };
		std::unique_ptr<PhysicalDevice> m_physicalDevice{ nullptr };
		std::unique_ptr<LogicalDevice> m_logicalDevice{ nullptr };
		std::unique_ptr<Surface> m_surface{ nullptr };
		
		// Swapchain
		std::unique_ptr<Swapchain> m_swapchain{ nullptr };
		size_t m_currentFrame{ 0 };
		size_t m_maxFramesInFlight{ 0 };
		
		// Pipeline
		std::unique_ptr<Pipeline> m_pipeline{ nullptr };
		
		// Command Pool
		std::shared_ptr<CommandPool> m_commandPool{ nullptr };
		
		// Frames
		std::vector<Frame> m_frames{};
		
		// Global command buffer
		std::unique_ptr<CommandBuffer> m_globalCommandBuffer;

		// Attachments
		std::vector<VkImageView> m_attachments{};
		
		void initFrameObjects();
		void destroyFrameObjects();
		void recordDrawCommand(uint32_t imageIndex);
		void recreateSwapchain();

	};

} // namespace Aminophenol

#endif // RENDERING_ENGINE_H
