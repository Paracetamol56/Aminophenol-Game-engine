
#include "pch.h"
#include "SubRenderer.h"

#include "Maths/Matrix4.h"

namespace Aminophenol {

	struct GameObjectPushConstantData {
		Maths::Matrix4f modelMatrix{ 1.f };
		Maths::Matrix4f normalMatrix{ 1.f };
	};

	SubRenderer::SubRenderer(const LogicalDevice& logicalDevice, VkRenderPass renderPass, std::vector<VkDescriptorSetLayout> descriptorSetLayouts)
		: NonCopyable()
		, m_logicalDevice{ logicalDevice }
		, m_pipelineLayout{ VK_NULL_HANDLE }
		, m_pipeline{ nullptr }
	{
		createPipelineLayout(descriptorSetLayouts);
		createPipeline(renderPass);
	}

	SubRenderer::~SubRenderer()
	{
	}

	void SubRenderer::render(const CommandBuffer& commandBuffer)
	{
	}
	
	void SubRenderer::createPipelineLayout(std::vector<VkDescriptorSetLayout> descriptorSetLayouts)
	{
		// Create push constant range
		VkPushConstantRange pushConstantRange{};
		pushConstantRange.stageFlags = VK_SHADER_STAGE_VERTEX_BIT | VK_SHADER_STAGE_FRAGMENT_BIT;
		pushConstantRange.offset = 0;
		pushConstantRange.size = sizeof(GameObjectPushConstantData);

		// Create pipeline layout info
		VkPipelineLayoutCreateInfo pipelineLayoutInfo{};
		pipelineLayoutInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
		pipelineLayoutInfo.setLayoutCount = static_cast<uint32_t>(descriptorSetLayouts.size());
		pipelineLayoutInfo.pSetLayouts = descriptorSetLayouts.data();
		pipelineLayoutInfo.pushConstantRangeCount = 1;
		pipelineLayoutInfo.pPushConstantRanges = &pushConstantRange;

		// Create pipeline layout
		if (vkCreatePipelineLayout(m_logicalDevice.getDevice(), &pipelineLayoutInfo, nullptr, &m_pipelineLayout) != VK_SUCCESS)
		{
			throw std::runtime_error("failed to create pipeline layout!");
		}
	}
	
	void SubRenderer::createPipeline(VkRenderPass renderPass)
	{
		// Check if the layout was created
		if (m_pipelineLayout == VK_NULL_HANDLE)
		{
			throw std::runtime_error("failed to create pipeline because the pipeline layout was not created!");
		}

		// Create pipeline
		
	}

} // namespace Aminophenol