
#ifndef FRAME_H
#define FRAME_H

#include "pch.h"
#include "Rendering/Commands/CommandBuffer.h"

namespace Aminophenol
{

	struct AMINOPHENOL_API Frame {

		// Frame buffer
		VkFramebuffer frameBuffer;

		// Depth buffer
		VkImage depthImage;
		VkDeviceMemory depthImageMemory;
		VkImageView depthImageView;

		// Command buffer
		std::unique_ptr<CommandBuffer> commandBuffer;

		// Syncronization objects
		VkSemaphore imageAvailableSemaphore;
		VkSemaphore renderFinishedSemaphore;
		VkFence inFlightFence;

	};

}

#endif // !FRAME_H
