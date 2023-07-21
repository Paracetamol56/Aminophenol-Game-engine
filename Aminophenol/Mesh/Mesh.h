
#ifndef MESH_H
#define MESH_H

#include "pch.h"

#include "Mesh/Vertex.h"
#include "Rendering/Device/LogicalDevice.h"
#include "Rendering/Commands/CommandPool.h"
#include "Rendering/Buffers/Buffer.h"

namespace Aminophenol {
	
	class AMINOPHENOL_API Mesh
	{
	public:
		
		Mesh(const LogicalDevice& logicalDevice, const std::shared_ptr<CommandPool> commandPool);
		~Mesh();

		void bind(VkCommandBuffer commandBuffer);
		void draw(VkCommandBuffer commandBuffer);

	private:
		
		const LogicalDevice& m_logicalDevice;

		std::unique_ptr<Buffer> m_vertexBuffer;
		std::unique_ptr<Buffer> m_indexBuffer;
		
	protected:

		std::vector<Vertex> m_vertices;
		std::vector<uint32_t> m_indices;

		std::shared_ptr<CommandPool> m_commandPool;

		void createVertexBuffer();
		void createIndexBuffer();

	};
	
} // namespace Aminophenol

#endif MESH_H
