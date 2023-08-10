
#ifndef SUB_RENDERER_H
#define SUB_RENDERER_H

#include "Utils/NonCopyable.h"
#include "Rendering/Commands/CommandBuffer.h"
#include "Rendering/Device/LogicalDevice.h"
#include "Rendering/Pipeline/Pipeline.h"

namespace Aminophenol {

	// ToDo: Make this class abstract and derive from it
	class SubRenderer : NonCopyable
	{
	public:

		SubRenderer(const LogicalDevice& logicalDevice, VkRenderPass renderPass, std::vector<VkDescriptorSetLayout> descriptorSetLayouts);
		~SubRenderer();

		virtual void render(const CommandBuffer& commandBuffer);

	protected:

		const LogicalDevice& m_logicalDevice;

		VkPipelineLayout m_pipelineLayout;
		std::unique_ptr<Pipeline> m_pipeline;
		
	private:
		
		virtual void createPipelineLayout(std::vector<VkDescriptorSetLayout> descriptorSetLayouts);
		virtual void createPipeline(VkRenderPass renderPass);
		
	};

} // namespace Aminophenol

#endif // SUB_RENDERER_H
