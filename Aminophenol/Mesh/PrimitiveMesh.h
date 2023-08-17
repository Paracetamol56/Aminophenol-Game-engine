#ifndef PRIMITIVE_MESH_H
#define PRIMITIVE_MESH_H

#include "Mesh/Mesh.h"

namespace Aminophenol
{

	class PrimitiveMesh
	{
	public:

		static std::shared_ptr<Mesh> createCube(const LogicalDevice& logicalDevice, const std::shared_ptr<CommandPool> commandPool);
		static std::shared_ptr<Mesh> createSphere(const LogicalDevice& logicalDevice, const std::shared_ptr<CommandPool> commandPool, uint32_t rings = 32, uint32_t sectors = 32);
		static std::shared_ptr<Mesh> createPlane(const LogicalDevice& logicalDevice, const std::shared_ptr<CommandPool> commandPool);
		static std::shared_ptr<Mesh> createCylinder(const LogicalDevice& logicalDevice, const std::shared_ptr<CommandPool> commandPool, float radius = 1.0f, float height = 1.0f, uint32_t sectors = 32);
		static std::shared_ptr<Mesh> createCone(const LogicalDevice& logicalDevice, const std::shared_ptr<CommandPool> commandPool, float radius = 1.0f, float height = 1.0f, uint32_t sectors = 32);
		static std::shared_ptr<Mesh> createTorus(const LogicalDevice& logicalDevice, const std::shared_ptr<CommandPool> commandPool, float innerRadius = 0.5f, float outerRadius = 1.0f, uint32_t rings = 32, uint32_t sectors = 32);

	};

}

#endif // !PRIMITIVE_MESH_H
