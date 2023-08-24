
#ifndef FRAME_H
#define FRAME_H

#include "Utils/NonCopyable.h"
#include "Rendering/Buffers/UniformBuffer.h"
#include "Rendering/Commands/CommandBuffer.h"
#include "Rendering/Image/ImageDepth.h"
#include "Rendering/Pipeline/Pipeline.h"

namespace Aminophenol
{

	struct FrameUniformBufferObject
	{
		Maths::Matrix4f projectionMatrix;
		Maths::Matrix4f viewMatrix;
		Maths::Matrix4f modelMatrix;
		Maths::Matrix4f normalMatrix;
	};

	struct Frame
	{

		// Frame size
		uint32_t width;
		uint32_t height;

		// Frame buffer
		VkFramebuffer frameBuffer;

		// Depth buffer
		std::unique_ptr<ImageDepth> depthBuffer;

		// Command buffer
		std::unique_ptr<CommandBuffer> commandBuffer;

		// Frame UBO
		FrameUniformBufferObject uniformBufferData;
		std::unique_ptr<UniformBuffer> uniformBuffer;

		// Attachment
		VkImageView attachment;

		// Syncronization objects
		VkSemaphore imageAvailableSemaphore;
		VkSemaphore renderFinishedSemaphore;
		VkFence inFlightFence;

	};

}

#endif // !FRAME_H
