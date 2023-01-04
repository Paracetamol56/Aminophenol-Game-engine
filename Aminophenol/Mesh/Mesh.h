
#ifndef MESH_H
#define MESH_H

#include "pch.h"

#include "Mesh/Vertex.h"
#include "Rendering/Device/LogicalDevice.h"

namespace Aminophenol {
	
	class AMINOPHENOL_API Mesh
	{
	public:
		
		Mesh(LogicalDevice& logicalDevice);
		~Mesh();

		void bind(VkCommandBuffer commandBuffer);
		void draw(VkCommandBuffer commandBuffer);

	private:
		
		LogicalDevice& m_logicalDevice;

		VkBuffer m_vertexBuffer;
		VkDeviceMemory m_vertexBufferMemory;
		VkBuffer m_indexBuffer;
		VkDeviceMemory m_indexBufferMemory;
		
	protected:

		std::vector<Vertex> m_vertices;
		std::vector<uint32_t> m_indices;

		void createVertexBuffer();
		void createIndexBuffer();

	};
	
} // namespace Aminophenol

#endif MESH_H
