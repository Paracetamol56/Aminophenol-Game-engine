
#include "pch.h"
#include "Mesh.h"

#include "Logging/Logger.h"
#include "Rendering/Commands/CommandBuffer.h"

namespace Aminophenol {

	Mesh::Mesh(const LogicalDevice& logicalDevice, const std::shared_ptr<CommandPool> commandPool)
		: m_logicalDevice(logicalDevice)
		, m_commandPool(commandPool)
	{
		/*
		// Create a cube
		vertices = {
			// Front
			{ { -0.5f, -0.5f,  0.5f }, { 1.0f, 1.0f, 0.0f } },
			{ {  0.5f, -0.5f,  0.5f }, { 0.0f, 1.0f, 1.0f } },
			{ {  0.5f,  0.5f,  0.5f }, { 1.0f, 0.0f, 1.0f } },
			{ { -0.5f,  0.5f,  0.5f }, { 1.0f, 1.0f, 1.0f } },

			// Back
			{ { -0.5f, -0.5f, -0.5f }, { 1.0f, 0.0f, 0.0f } },
			{ {  0.5f, -0.5f, -0.5f }, { 0.0f, 1.0f, 0.0f } },
			{ {  0.5f,  0.5f, -0.5f }, { 0.0f, 0.0f, 1.0f } },
			{ { -0.5f,  0.5f, -0.5f }, { 1.0f, 1.0f, 1.0f } }
		};

		indices = {
			// Front
			0, 1, 2, 2, 3, 0,
			// Back
			7, 6, 5, 5, 4, 7,
			// Left
			4, 0, 3, 3, 7, 4,
			// Right
			1, 5, 6, 6, 2, 1,
			// Top
			3, 2, 6, 6, 7, 3,
			// Bottom
			4, 5, 1, 1, 0, 4
		};
		*/
	}

	Mesh::~Mesh()
	{
		m_vertexBuffer.reset();
		m_indexBuffer.reset();
	}

	void Mesh::create()
	{
		createVertexBuffer();
		createIndexBuffer();
	}

	void Mesh::bind(VkCommandBuffer commandBuffer)
	{
		VkBuffer vertexBuffers[] = { *m_vertexBuffer };
		VkDeviceSize offsets[] = { 0 };
		vkCmdBindVertexBuffers(commandBuffer, 0, 1, vertexBuffers, offsets);
		vkCmdBindIndexBuffer(commandBuffer, *m_indexBuffer, 0, VK_INDEX_TYPE_UINT32);
	}

	void Mesh::draw(VkCommandBuffer commandBuffer)
	{
		vkCmdDrawIndexed(commandBuffer, static_cast<uint32_t>(indices.size()), 1, 0, 0, 0);
	}

	void Mesh::createVertexBuffer()
	{
		// Assert that the size is at least 3
		if (vertices.size() < 3)
		{
			Logger::log(LogLevel::Error, "The size of the vertices is less than 3.");
			return;
		}
		VkDeviceSize bufferSize = sizeof(vertices[0]) * vertices.size();

		Buffer stagingBuffer(m_logicalDevice, bufferSize, VK_BUFFER_USAGE_TRANSFER_SRC_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, vertices.data());

		m_vertexBuffer = std::make_unique<Buffer>(m_logicalDevice, bufferSize, VK_BUFFER_USAGE_VERTEX_BUFFER_BIT | VK_IMAGE_USAGE_TRANSFER_SRC_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);

		// Create a command buffer to copy the staging buffer to the vertex buffer
		CommandBuffer commandBuffer(m_logicalDevice, m_commandPool, VK_COMMAND_BUFFER_LEVEL_PRIMARY);

		// Begin
		VkCommandBufferBeginInfo beginInfo{};
		beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
		beginInfo.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;
		vkBeginCommandBuffer(commandBuffer, &beginInfo);

		// Copy the staging buffer to the vertex buffer
		VkBufferCopy copyRegion = {};
		copyRegion.srcOffset = 0;
		copyRegion.dstOffset = 0;
		copyRegion.size = bufferSize;
		vkCmdCopyBuffer(commandBuffer, stagingBuffer, *m_vertexBuffer, 1, &copyRegion);

		// End the command buffer
		vkEndCommandBuffer(commandBuffer);

		// Sumbit
		VkSubmitInfo submitInfo = {};
		submitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
		submitInfo.commandBufferCount = 1;
		submitInfo.pCommandBuffers = &commandBuffer.getCommandBuffer();

		vkQueueSubmit(m_logicalDevice.getGraphicsQueue(), 1, &submitInfo, VK_NULL_HANDLE);
		vkQueueWaitIdle(m_logicalDevice.getGraphicsQueue());
	}

	void Mesh::createIndexBuffer()
	{
		// Assert that the size is at least 3
		if (indices.size() < 3)
		{
			Logger::log(LogLevel::Error, "The size of the indices is less than 3.");
			return;
		}
		VkDeviceSize bufferSize = sizeof(indices[0]) * indices.size();

		Buffer stagingBuffer(m_logicalDevice, bufferSize, VK_BUFFER_USAGE_TRANSFER_SRC_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, indices.data());

		m_indexBuffer = std::make_unique<Buffer>(m_logicalDevice, bufferSize, VK_BUFFER_USAGE_INDEX_BUFFER_BIT | VK_IMAGE_USAGE_TRANSFER_SRC_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);

		// Create a command buffer to copy the staging buffer to the index buffer
		CommandBuffer commandBuffer(m_logicalDevice, m_commandPool, VK_COMMAND_BUFFER_LEVEL_PRIMARY);

		// Begin
		VkCommandBufferBeginInfo beginInfo{};
		beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
		beginInfo.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;
		vkBeginCommandBuffer(commandBuffer, &beginInfo);

		// Copy the staging buffer to the index buffer
		VkBufferCopy copyRegion = {};
		copyRegion.srcOffset = 0;
		copyRegion.dstOffset = 0;
		copyRegion.size = bufferSize;
		vkCmdCopyBuffer(commandBuffer, stagingBuffer, *m_indexBuffer, 1, &copyRegion);

		// End the command buffer
		if (vkEndCommandBuffer(commandBuffer) != VK_SUCCESS)
		{
			Logger::log(LogLevel::Error, "Failed to end the command buffer.");
			return;
		}

		// Sumbit
		VkSubmitInfo submitInfo = {};
		submitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
		submitInfo.commandBufferCount = 1;
		submitInfo.pCommandBuffers = &commandBuffer.getCommandBuffer();

		vkQueueSubmit(m_logicalDevice.getGraphicsQueue(), 1, &submitInfo, VK_NULL_HANDLE);
		vkQueueWaitIdle(m_logicalDevice.getGraphicsQueue());
	}

} // namespace Aminophenol
