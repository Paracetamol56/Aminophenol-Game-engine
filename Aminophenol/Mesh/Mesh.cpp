
#include "pch.h"
#include "Mesh.h"

#include "Logging/Logger.h"
#include "Rendering/Commands/CommandBuffer.h"

namespace Aminophenol {

	Mesh::Mesh(const LogicalDevice& logicalDevice, const std::shared_ptr<CommandPool> commandPool)
		: m_logicalDevice(logicalDevice)
		, m_commandPool(commandPool)
	{
		// Create a cube
		m_vertices = {
			// Front
			{ { -0.5f, -0.5f,  0.5f }, { 1.0f, 0.0f, 0.0f } },
			{ {  0.5f, -0.5f,  0.5f }, { 0.0f, 1.0f, 0.0f } },
			{ {  0.5f,  0.5f,  0.5f }, { 0.0f, 0.0f, 1.0f } },
			{ { -0.5f,  0.5f,  0.5f }, { 1.0f, 1.0f, 1.0f } },

			// Back
			{ { -0.5f, -0.5f, -0.5f }, { 1.0f, 0.0f, 0.0f } },
			{ {  0.5f, -0.5f, -0.5f }, { 0.0f, 1.0f, 0.0f } },
			{ {  0.5f,  0.5f, -0.5f }, { 0.0f, 0.0f, 1.0f } },
			{ { -0.5f,  0.5f, -0.5f }, { 1.0f, 1.0f, 1.0f } }
		};

		m_indices = {
			// Front
			0, 1, 2, 2, 3, 0,
			// Back
			4, 5, 6, 6, 7, 4,
			// Left
			4, 0, 3, 3, 7, 4,
			// Right
			1, 5, 6, 6, 2, 1,
			// Top
			3, 2, 6, 6, 7, 3,
			// Bottom
			4, 5, 1, 1, 0, 4
		};
	}

	Mesh::~Mesh()
	{}

	void Mesh::bind(VkCommandBuffer commandBuffer)
	{
		VkBuffer vertexBuffers[] = { *m_vertexBuffer };
		VkDeviceSize offsets[] = { 0 };
		vkCmdBindVertexBuffers(commandBuffer, 0, 1, vertexBuffers, offsets);
		vkCmdBindIndexBuffer(commandBuffer, *m_indexBuffer, 0, VK_INDEX_TYPE_UINT32);
	}

	void Mesh::draw(VkCommandBuffer commandBuffer)
	{
		vkCmdDrawIndexed(commandBuffer, static_cast<uint32_t>(m_indices.size()), 1, 0, 0, 0);
	}

	void Mesh::createVertexBuffer()
	{
		VkDeviceSize bufferSize = sizeof(m_vertices[0]) * m_vertices.size();

		Buffer stagingBuffer(m_logicalDevice, bufferSize, VK_BUFFER_USAGE_TRANSFER_SRC_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, m_vertices.data());

		m_vertexBuffer = std::make_unique<Buffer>(m_logicalDevice, bufferSize, VK_BUFFER_USAGE_VERTEX_BUFFER_BIT | VK_IMAGE_USAGE_TRANSFER_SRC_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);

		// Create a command buffer to copy the staging buffer to the vertex buffer
		CommandBuffer commandBuffer(m_logicalDevice, m_commandPool, VK_COMMAND_BUFFER_LEVEL_PRIMARY);
	}

	void Mesh::createIndexBuffer()
	{
		// ToDo
	}

} // namespace Aminophenol
