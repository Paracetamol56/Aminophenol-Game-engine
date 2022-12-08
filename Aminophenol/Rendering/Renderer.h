
#ifndef RENDERER_H
#define RENDERER_H

#include "pch.h"

#include "Rendering/LogicalDevice.h"
#include "Rendering/Swapchain/Swapchain.h"
#include "Rendering/Swapchain/RenderPass.h"
#include "Rendering/Swapchain/FrameBuffers.h"

namespace Aminophenol {

	class AMINOPHENOL_API Renderer
	{
	public:

		Renderer(const LogicalDevice& logicalDevice, const Swapchain& swapchain, const RenderPass& renderPass);
		~Renderer();

		void render();

	private:

		const LogicalDevice& m_logicalDevice;
		const Swapchain& m_swapchain;
		const RenderPass& m_renderPass;

		FrameBuffers m_frameBuffers;

	};

} // namespace Aminophenol

#endif // RENDERER_H