
#ifndef VERTEX_H
#define VERTEX_H

#include "pch.h"

#include "Utils/HashCombine.h"
#include "Maths/Vector2.h"
#include "Maths/Vector3.h"

namespace Aminophenol {

	class AMINOPHENOL_API Vertex
	{
	public:
		
		static VkVertexInputBindingDescription getBindingDescription();
		static std::array<VkVertexInputAttributeDescription, 3> getAttributeDescriptions();

		bool operator==(const Vertex& other) const;
		bool operator!=(const Vertex& other) const;

		// Vertex data
		Maths::Vector3f position;
		Maths::Vector3f color;
		Maths::Vector2f textureCoordinate;
		Maths::Vector3f normal;

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
