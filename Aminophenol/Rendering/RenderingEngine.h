
#ifndef RENDERING_ENGINE_H
#define RENDERING_ENGINE_H

#include "Utils/NonCopyable.h"
#include "Window/Window.h"
#include "Scene/Scene.h"
#include "Rendering/Buffers/UniformBuffer.h"
#include "Rendering/Device/Instance.h"
#include "Rendering/Device/PhysicalDevice.h"
#include "Rendering/Device/LogicalDevice.h"
#include "Rendering/Device/Surface.h"
#include "Rendering/Swapchain/Swapchain.h"
#include "Rendering/Pipeline/Pipeline.h"
#include "Rendering/Descriptors/DescriptorPool.h"
#include "Rendering/Descriptors/DescriptorSetLayout.h"
#include "Rendering/Commands/CommandPool.h"
#include "Rendering/Commands/CommandBuffer.h"
#include "Rendering/Image/ImageDepth.h"
#include "Rendering/Image/Texture.h"
#include "Mesh/Mesh.h"

#include "Maths/Vector2.h"
#include "Maths/Color.h"

namespace Aminophenol {

	struct FrameUniformBufferObject
	{
		Maths::Matrix4f projectionMatrix;
		Maths::Matrix4f viewMatrix;
	};

	struct PushConstantData
	{
		alignas(0) Maths::Matrix4f modelMatrix;
		alignas(0) Maths::Matrix4f normalMatrix;
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
		std::unique_ptr<Instance> m_instance;
		std::unique_ptr<PhysicalDevice> m_physicalDevice;
		std::unique_ptr<LogicalDevice> m_logicalDevice;
		std::unique_ptr<Surface> m_surface;
		
		// Swapchain
		std::unique_ptr<Swapchain> m_swapchain;
		size_t m_currentFrame{ 0 };
		size_t m_maxFramesInFlight{ 0 };
		
		// Pipeline
		std::unique_ptr<Pipeline> m_pipeline;
		
		// Global objects (CommandPool, DescriptorPool, DescriptorSetLayout, CommandBuffer)
		std::shared_ptr<CommandPool> m_commandPool;
		std::unique_ptr<CommandBuffer> m_globalCommandBuffer;
		std::unique_ptr<DescriptorPool> m_globalDescriptorPool;
		std::unique_ptr<DescriptorPool> m_imguiDescriptorPool;
		std::unique_ptr<DescriptorSetLayout> m_globalDescriptorSetLayout;
		// TMP
		std::unique_ptr<DescriptorPool> m_textureDescriptorPool;
		std::unique_ptr<DescriptorSetLayout> m_textureDescriptorSetLayout;
		std::unique_ptr<Texture> m_texture;
		VkDescriptorSet m_textureDescriptorSet;
		
		// Frames
		FrameUniformBufferObject m_uniformBufferData;
		struct Frame
		{
			VkFramebuffer frameBuffer;
			std::unique_ptr<ImageDepth> depthBuffer;

			VkSemaphore imageAvailableSemaphore;
			VkSemaphore renderFinishedSemaphore;
			VkFence inFlightFence;

			std::unique_ptr<CommandBuffer> commandBuffer;
			std::unique_ptr<UniformBuffer> uniformBuffer;
			VkDescriptorSet descriptorSet;
		};
		std::vector<Frame> m_frames{};
		
		void initFrameObjects();
		void destroyFrameObjects();
		void recordDrawCommand(uint32_t imageIndex);
		void recreateSwapchain();

		void initImGui();

	};

} // namespace Aminophenol

#endif // RENDERING_ENGINE_H
