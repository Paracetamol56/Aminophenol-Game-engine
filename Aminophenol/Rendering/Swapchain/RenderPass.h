
#ifndef RENDERPASS_H
#define RENDERPASS_H

#include "pch.h"

#include "Rendering/LogicalDevice.h"

namespace Aminophenol {

	class AMINOPHENOL_API RenderPass
	{
	public:

		RenderPass(const LogicalDevice& logicalDevice, const VkFormat& format);
		~RenderPass();

		operator const VkRenderPass& () const;

	private:

		VkRenderPass m_renderPass{ VK_NULL_HANDLE };

		const LogicalDevice& m_logicalDevice;

	};

} // namespace Aminophenol

#endif // RENDERPASS_H
