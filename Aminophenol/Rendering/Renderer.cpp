
#include "pch.h"
#include "Renderer.h"

namespace Aminophenol {

	Renderer::Renderer(const LogicalDevice& logicalDevice, const Swapchain& swapchain, const RenderPass& renderPass)
		: m_logicalDevice(logicalDevice)
		, m_swapchain(swapchain)
		, m_renderPass(renderPass)
		, m_frameBuffers(logicalDevice, swapchain, renderPass)
	{
	}

	Renderer::~Renderer()
	{
	}

	void Renderer::render()
	{
	}

} // namespace Aminophenol
