
#ifndef VERTEX_H
#define VERTEX_H

#include "pch.h"

namespace Aminophenol {

	class AMINOPHENOL_API Vertex
	{
	public:
		
		static VkVertexInputBindingDescription getBindingDescription();
		static std::array<VkVertexInputAttributeDescription, 3> getAttributeDescriptions();

		bool operator==(const Vertex& other) const;
		bool operator!=(const Vertex& other) const;

		// Vertex data
		glm::vec3 pos;
		glm::vec3 color;
		glm::vec2 texCoord;
		glm::vec3 normal;

	};

} // namespace Aminophenol

#endif // VERTEX_H
