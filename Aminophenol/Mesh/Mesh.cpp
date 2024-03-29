
#include "pch.h"
#include "Mesh.h"

#include "Logging/Logger.h"
#include "Rendering/Commands/CommandBuffer.h"

namespace Aminophenol {

	Mesh::Mesh(const LogicalDevice& logicalDevice, const std::shared_ptr<CommandPool> commandPool)
		: m_logicalDevice(logicalDevice)
		, m_commandPool(commandPool)
	{}

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

	void Mesh::recalculateNormals()
	{
		for (size_t i = 0; i < indices.size(); i += 3)
		{

			// The face orientation is clockwise
			Vertex& v0 = vertices[indices[i]];
			Vertex& v1 = vertices[indices[i + 1]];
			Vertex& v2 = vertices[indices[i + 2]];

			Maths::Vector3f edge1 = v1.position - v0.position;
			Maths::Vector3f edge2 = v2.position - v0.position;

			Maths::Vector3f normal = edge1.cross(edge2);
			if (normal != Maths::Vector3f::zero())
				v0.normal = v1.normal = v2.normal = normal.normalize();
		}

		create();
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
		CommandBuffer commandBuffer(m_logicalDevice, m_commandPool);
		commandBuffer.begin();

		// Copy the staging buffer to the vertex buffer
		VkBufferCopy copyRegion = {};
		copyRegion.srcOffset = 0;
		copyRegion.dstOffset = 0;
		copyRegion.size = bufferSize;
		vkCmdCopyBuffer(commandBuffer, stagingBuffer, *m_vertexBuffer, 1, &copyRegion);

		commandBuffer.submitIdle();
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
		CommandBuffer commandBuffer(m_logicalDevice, m_commandPool);
		commandBuffer.begin();

		// Copy the staging buffer to the index buffer
		VkBufferCopy copyRegion = {};
		copyRegion.srcOffset = 0;
		copyRegion.dstOffset = 0;
		copyRegion.size = bufferSize;
		vkCmdCopyBuffer(commandBuffer, stagingBuffer, *m_indexBuffer, 1, &copyRegion);

		commandBuffer.submitIdle();
	}

} // namespace Aminophenol
