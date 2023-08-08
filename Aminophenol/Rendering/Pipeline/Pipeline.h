
#ifndef PIPELINE_H
#define PIPELINE_H

#include "pch.h"

#include "Rendering/Device/LogicalDevice.h"
#include "Rendering/Swapchain/RenderPass.h"

namespace Aminophenol {

	class AMINOPHENOL_API Pipeline
	{
	public:

		Pipeline(
			const LogicalDevice& logicalDevice, const VkExtent2D& swapchainExtent, const VkFormat& swapchainImageFormat,
			const std::filesystem::path& vertShaderPath, const std::filesystem::path& fragShaderPath
		);
		~Pipeline();

		operator const VkPipeline& () const;
		
		const VkPipelineLayout& getPipelineLayout() const;
		const RenderPass& getRenderPass() const;

	private:

		VkPipeline m_graphicsPipeline;
		VkPipelineLayout m_pipelineLayout;
		std::unique_ptr<RenderPass> m_renderPass;
		VkShaderModule m_vertShaderModule;
		VkShaderModule m_fragShaderModule;
		
		const LogicalDevice& m_logicalDevice;
		const VkExtent2D& m_swapchainExtent;
		const VkFormat& m_swapchainImageFormat;
		
		void createGraphicsPipeline();
		std::vector<char> readFile(const std::filesystem::path& filePath);
		void createShaderModule(const VkDevice& device, const std::vector<char>& code, VkShaderModule& shaderModule);
				
	};

} // namespace Aminophenol

#endif // PIPELINE_H
