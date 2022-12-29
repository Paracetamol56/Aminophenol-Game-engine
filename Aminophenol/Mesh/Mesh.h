
#ifndef MESH_H
#define MESH_H

#include "pch.h"

#include "Mesh/Vertex.h"

namespace Aminophenol {
	
	class AMINOPHENOL_API Mesh
	{
	public:
		
		Mesh();
		~Mesh();

	private:
		
		VkBuffer vertexBuffer;
		VkDeviceMemory vertexBufferMemory;
		VkBuffer indexBuffer;
		VkDeviceMemory indexBufferMemory;
		
		std::vector<Vertex> vertices;
		std::vector<uint32_t> indices;

	};
	
} // namespace Aminophenol

#endif MESH_H