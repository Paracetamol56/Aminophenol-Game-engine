
#ifndef VERTEX_H
#define VERTEX_H

#include "Utils/HashCombine.h"
#include "Maths/Vector2.h"
#include "Maths/Vector3.h"
#include <vulkan/vulkan.h>

namespace Aminophenol {

	class Vertex
	{
	public:
		
		static VkVertexInputBindingDescription getBindingDescription();
		static std::array<VkVertexInputAttributeDescription, 4> getAttributeDescriptions();

		bool operator==(const Vertex& other) const;
		bool operator!=(const Vertex& other) const;

		// Vertex data
		Maths::Vector3f position;
		Maths::Vector3f color;
		Maths::Vector3f normal;
		Maths::Vector2f textureCoordinate;

	};

} // namespace Aminophenol

namespace std {

	// Overload of the hash function from STD for the Vertex structure
	template <>
	struct hash<Aminophenol::Vertex>
	{
		size_t operator()(const Aminophenol::Vertex& vertex) const noexcept
		{
			size_t seed = 0;
			Aminophenol::Utils::hashCombine(seed, vertex.position, vertex.color, vertex.textureCoordinate, vertex.normal);
			return seed;
		}
	};

} // namespace std

#endif // VERTEX_H
