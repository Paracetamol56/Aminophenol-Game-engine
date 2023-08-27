
#include "pch.h"
#include "Pipeline.h"

#include "Logging/Logger.h"
#include "Mesh/Mesh.h"
#include "Rendering/RenderingEngine.h"

namespace Aminophenol {
	
	Pipeline::Pipeline(
		const LogicalDevice& logicalDevice, const DescriptorSetLayout& descriptorSetLayout,
		const VkExtent2D& swapchainExtent, const VkFormat& swapchainImageFormat,
		const std::filesystem::path& vertShaderPath, const std::filesystem::path& fragShaderPath
	)
		: m_logicalDevice{ logicalDevice }
		, m_swapchainExtent{ swapchainExtent }
		, m_swapchainImageFormat{ swapchainImageFormat }
	{
		Logger::log(LogLevel::Trace, "Creating pipeline...");
		
		// Push constant range
		VkPushConstantRange pushConstantRange{};
		pushConstantRange.stageFlags = VK_SHADER_STAGE_VERTEX_BIT;
		pushConstantRange.offset = 0;
		pushConstantRange.size = sizeof(PushConstantData);

		// Descriptor set layout vector
		std::vector<VkDescriptorSetLayout> descriptorSetLayouts{ descriptorSetLayout };

		// Create the pipeline layout
		VkPipelineLayoutCreateInfo pipelineLayoutInfo{};
		pipelineLayoutInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
		pipelineLayoutInfo.setLayoutCount = static_cast<uint32_t>(descriptorSetLayouts.size());
		pipelineLayoutInfo.pSetLayouts = descriptorSetLayouts.data();
		pipelineLayoutInfo.pushConstantRangeCount = 1;
		pipelineLayoutInfo.pPushConstantRanges = &pushConstantRange;

		if (vkCreatePipelineLayout(m_logicalDevice, &pipelineLayoutInfo, nullptr, &m_pipelineLayout) != VK_SUCCESS) {
			throw std::runtime_error("Failed to create pipeline layout!");
		}

		// Create the render pass
		m_renderPass = std::make_unique<RenderPass>(m_logicalDevice, m_swapchainImageFormat);
		
		// Create the shader modules
		createShaderModule(m_logicalDevice, readFile("../Aminophenol/Shaders/shader.vert.spv"), m_vertShaderModule);
		createShaderModule(m_logicalDevice, readFile("../Aminophenol/Shaders/shader.frag.spv"), m_fragShaderModule);
		
		// Create the graphics pipeline
		createGraphicsPipeline();
	
		Logger::log(LogLevel::Trace, "Successfully created pipeline.");
	}

	Pipeline::~Pipeline()
	{
		Logger::log(LogLevel::Trace, "Destroying pipeline...");

		vkDestroyPipeline(m_logicalDevice, m_graphicsPipeline, nullptr);
		
		vkDestroyShaderModule(m_logicalDevice, m_vertShaderModule, nullptr);
		vkDestroyShaderModule(m_logicalDevice, m_fragShaderModule, nullptr);
		
		vkDestroyPipelineLayout(m_logicalDevice, m_pipelineLayout, nullptr);

		Logger::log(LogLevel::Trace, "Pipeline destroyed.");
	}

	Pipeline::operator const VkPipeline& () const
	{
		return m_graphicsPipeline;
	}

	const VkPipelineLayout& Pipeline::getPipelineLayout() const
	{
		return m_pipelineLayout;
	}

	const RenderPass& Pipeline::getRenderPass() const
	{
		return *m_renderPass;
	}
	
	void Pipeline::createGraphicsPipeline()
	{
		VkGraphicsPipelineCreateInfo pipelineInfo{};
		pipelineInfo.sType = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;
		
		std::vector<VkPipelineShaderStageCreateInfo> shaderStages;

		// Vertex input
		VkVertexInputBindingDescription bindingDescription = Vertex::getBindingDescription();
		std::array<VkVertexInputAttributeDescription, 4> attributeDescriptions = Vertex::getAttributeDescriptions();
		
		VkPipelineVertexInputStateCreateInfo vertexInputInfo{};
		vertexInputInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO;
		vertexInputInfo.vertexBindingDescriptionCount = 1;
		vertexInputInfo.pVertexBindingDescriptions = &bindingDescription;
		vertexInputInfo.vertexAttributeDescriptionCount = static_cast<uint32_t>(attributeDescriptions.size());
		vertexInputInfo.pVertexAttributeDescriptions = attributeDescriptions.data();
		
		pipelineInfo.pVertexInputState = &vertexInputInfo;
		
		// Input assembly
		VkPipelineInputAssemblyStateCreateInfo inputAssembly{};
		inputAssembly.sType = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO;
		inputAssembly.topology = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;
		inputAssembly.primitiveRestartEnable = VK_FALSE;
		
		pipelineInfo.pInputAssemblyState = &inputAssembly;

		// Vertex shader stage
		VkPipelineShaderStageCreateInfo vertShaderStageInfo{};
		vertShaderStageInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
		vertShaderStageInfo.stage = VK_SHADER_STAGE_VERTEX_BIT;
		vertShaderStageInfo.module = m_vertShaderModule;
		vertShaderStageInfo.pName = "main";
		shaderStages.push_back(vertShaderStageInfo);

		// Viewport state
		VkPipelineViewportStateCreateInfo viewportState{};
		viewportState.sType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO;
		viewportState.viewportCount = 1;
		viewportState.pViewports = nullptr;
		viewportState.scissorCount = 1;
		viewportState.pScissors = nullptr;
		
		pipelineInfo.pViewportState = &viewportState;

		// Rasterizer
		VkPipelineRasterizationStateCreateInfo rasterizer{};
		rasterizer.sType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO;
		rasterizer.depthClampEnable = VK_FALSE;
		rasterizer.rasterizerDiscardEnable = VK_FALSE;
		rasterizer.polygonMode = VK_POLYGON_MODE_FILL;
		rasterizer.lineWidth = 1.0f;
		rasterizer.cullMode = VK_CULL_MODE_BACK_BIT;
		rasterizer.frontFace = VK_FRONT_FACE_CLOCKWISE;
		rasterizer.depthBiasEnable = VK_FALSE;
		rasterizer.depthBiasConstantFactor = 0.0f;
		rasterizer.depthBiasClamp = 0.0f;
		rasterizer.depthBiasSlopeFactor = 0.0f;
		
		pipelineInfo.pRasterizationState = &rasterizer;
		
		// Fragment shader stage
		VkPipelineShaderStageCreateInfo fragShaderStageInfo{};
		fragShaderStageInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
		fragShaderStageInfo.stage = VK_SHADER_STAGE_FRAGMENT_BIT;
		fragShaderStageInfo.module = m_fragShaderModule;
		fragShaderStageInfo.pName = "main";
		shaderStages.push_back(fragShaderStageInfo);

		pipelineInfo.stageCount = static_cast<uint32_t>(shaderStages.size());
		pipelineInfo.pStages = shaderStages.data();

		// Multisampling
		VkPipelineMultisampleStateCreateInfo multisampling{};
		multisampling.sType = VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO;
		multisampling.sampleShadingEnable = VK_FALSE;
		multisampling.rasterizationSamples = VK_SAMPLE_COUNT_1_BIT;
		multisampling.minSampleShading = 1.0f;
		multisampling.pSampleMask = nullptr;
		multisampling.alphaToCoverageEnable = VK_FALSE;
		multisampling.alphaToOneEnable = VK_FALSE;
		
		pipelineInfo.pMultisampleState = &multisampling;

		// Color blending
		VkPipelineColorBlendAttachmentState colorBlendAttachment{};
		colorBlendAttachment.colorWriteMask = VK_COLOR_COMPONENT_R_BIT | VK_COLOR_COMPONENT_G_BIT | VK_COLOR_COMPONENT_B_BIT | VK_COLOR_COMPONENT_A_BIT;
		colorBlendAttachment.blendEnable = VK_FALSE;
		colorBlendAttachment.srcColorBlendFactor = VK_BLEND_FACTOR_ONE;
		colorBlendAttachment.dstColorBlendFactor = VK_BLEND_FACTOR_ZERO;
		colorBlendAttachment.colorBlendOp = VK_BLEND_OP_ADD;
		colorBlendAttachment.srcAlphaBlendFactor = VK_BLEND_FACTOR_ONE;
		colorBlendAttachment.dstAlphaBlendFactor = VK_BLEND_FACTOR_ZERO;
		colorBlendAttachment.alphaBlendOp = VK_BLEND_OP_ADD;

		VkPipelineColorBlendStateCreateInfo colorBlending{};
		colorBlending.sType = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO;
		colorBlending.logicOpEnable = VK_FALSE;
		colorBlending.logicOp = VK_LOGIC_OP_COPY;
		colorBlending.attachmentCount = 1;
		colorBlending.pAttachments = &colorBlendAttachment;
		colorBlending.blendConstants[0] = 0.0f;
		colorBlending.blendConstants[1] = 0.0f;
		colorBlending.blendConstants[2] = 0.0f;
		colorBlending.blendConstants[3] = 0.0f;
		
		pipelineInfo.pColorBlendState = &colorBlending;
		
		// Depth stencil
		VkPipelineDepthStencilStateCreateInfo depthStencil{};
		depthStencil.sType = VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO;
		depthStencil.depthTestEnable = VK_TRUE;
		depthStencil.depthWriteEnable = VK_TRUE;
		depthStencil.depthCompareOp = VK_COMPARE_OP_LESS_OR_EQUAL;
		depthStencil.depthBoundsTestEnable = VK_FALSE;
		depthStencil.minDepthBounds = 0.0f;
		depthStencil.maxDepthBounds = 1.0f;
		depthStencil.stencilTestEnable = VK_FALSE;
		depthStencil.front = {};
		depthStencil.back = {};

		pipelineInfo.pDepthStencilState = &depthStencil;

		// Dynamic state
		std::vector<VkDynamicState> dynamicStatesEnables = {
			VK_DYNAMIC_STATE_VIEWPORT,
			VK_DYNAMIC_STATE_SCISSOR
		};

		VkPipelineDynamicStateCreateInfo dynamicStates{};
		dynamicStates.sType = VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO;
		dynamicStates.pDynamicStates = dynamicStatesEnables.data();
		dynamicStates.dynamicStateCount = static_cast<uint32_t>(dynamicStatesEnables.size());
		dynamicStates.flags = 0;

		pipelineInfo.pDynamicState = &dynamicStates;

		pipelineInfo.layout = m_pipelineLayout;
		pipelineInfo.renderPass = *m_renderPass;
		pipelineInfo.subpass = 0;
		pipelineInfo.basePipelineHandle = VK_NULL_HANDLE;
		pipelineInfo.basePipelineIndex = -1;
		
		if (vkCreateGraphicsPipelines(m_logicalDevice, VK_NULL_HANDLE, 1, &pipelineInfo, nullptr, &m_graphicsPipeline) != VK_SUCCESS) {
			throw std::runtime_error("Failed to create graphics pipeline!");
		}
	}
	
	std::vector<char> Pipeline::readFile(const std::filesystem::path& filePath)
	{
		std::ifstream file(filePath, std::ios::ate | std::ios::binary);
		
		if (!file.is_open())
		{
			throw std::runtime_error("Failed to open file: " + filePath.string());
		}
		
		size_t fileSize = (size_t)file.tellg();
		std::vector<char> buffer(fileSize);
		
		file.seekg(0);
		file.read(buffer.data(), fileSize);
		
		file.close();
		
		return buffer;
	}
	
	void Pipeline::createShaderModule(const VkDevice& device, const std::vector<char>& code, VkShaderModule& shaderModule)
	{
		// Documentation: https://registry.khronos.org/vulkan/specs/1.3/html/chap9.html#VkShaderModuleCreateInfo
		VkShaderModuleCreateInfo createInfo{};
		createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
		createInfo.codeSize = code.size();
		createInfo.pCode = reinterpret_cast<const uint32_t*>(code.data());

		if (vkCreateShaderModule(device, &createInfo, nullptr, &shaderModule) != VK_SUCCESS)
		{
			throw std::runtime_error("Failed to create shader module.");
		}
	}
	
} // namespace Aminophenol
