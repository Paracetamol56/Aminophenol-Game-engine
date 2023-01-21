
#include "pch.h"
#include "Mesh.h"

#include "Logging/Logger.h"

namespace Aminophenol {

	Mesh::Mesh(const LogicalDevice& logicalDevice)
		: m_logicalDevice(logicalDevice)
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
		VkBuffer vertexBuffers[] = { m_vertexBuffer };
		VkDeviceSize offsets[] = { 0 };
		vkCmdBindVertexBuffers(commandBuffer, 0, 1, vertexBuffers, offsets);
		vkCmdBindIndexBuffer(commandBuffer, m_indexBuffer, 0, VK_INDEX_TYPE_UINT32);
	}

	void Mesh::draw(VkCommandBuffer commandBuffer)
	{
		vkCmdDrawIndexed(commandBuffer, static_cast<uint32_t>(m_indices.size()), 1, 0, 0, 0);
	}

	void Mesh::createVertexBuffer()
	{
		// ToDo
	}

	void Mesh::createIndexBuffer()
	{
		// ToDo
	}

} // namespace Aminophenol
