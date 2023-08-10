
#ifndef FRAME_H
#define FRAME_H

#include "Rendering/Commands/CommandBuffer.h"
#include "Rendering/Image/ImageDepth.h"

namespace Aminophenol
{

	struct Frame {

		// Frame size
		uint32_t width;
		uint32_t height;

		// Frame buffer
		VkFramebuffer frameBuffer;

		// Depth buffer
		std::unique_ptr<ImageDepth> depthBuffer;

		// Command buffer
		std::unique_ptr<CommandBuffer> commandBuffer;

		// Syncronization objects
		VkSemaphore imageAvailableSemaphore;
		VkSemaphore renderFinishedSemaphore;
		VkFence inFlightFence;

	};

}

#endif // !FRAME_H
