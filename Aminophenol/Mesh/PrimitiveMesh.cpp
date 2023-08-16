
#include "pch.h"
#include "PrimitiveMesh.h"
#include "Maths/Constant.h"

namespace Aminophenol
{

    std::shared_ptr<Mesh> PrimitiveMesh::createCube(const LogicalDevice& logicalDevice, const std::shared_ptr<CommandPool> commandPool)
    {
        std::shared_ptr<Mesh> mesh = std::make_shared<Mesh>(logicalDevice, commandPool);

        // TODO: Implement cube mesh creation

        mesh->create();

        return mesh;
    }

    std::shared_ptr<Mesh> PrimitiveMesh::createSphere(const LogicalDevice& logicalDevice, const std::shared_ptr<CommandPool> commandPool, uint32_t rings, uint32_t sectors)
    {
        std::shared_ptr<Mesh> mesh = std::make_shared<Mesh>(logicalDevice, commandPool);

        // TODO: Implement sphere mesh creation

        mesh->create();

        return mesh;
    }

    std::shared_ptr<Mesh> PrimitiveMesh::createPlane(const LogicalDevice& logicalDevice, const std::shared_ptr<CommandPool> commandPool, float width, float height)
    {
        std::shared_ptr<Mesh> mesh = std::make_shared<Mesh>(logicalDevice, commandPool);

        // TODO: Implement plane mesh creation

        mesh->create();

        return mesh;
    }

    std::shared_ptr<Mesh> PrimitiveMesh::createCylinder(const LogicalDevice& logicalDevice, const std::shared_ptr<CommandPool> commandPool, float radius, float height, uint32_t sectors)
    {
        std::shared_ptr<Mesh> mesh = std::make_shared<Mesh>(logicalDevice, commandPool);

        // TODO: Implement cylinder mesh creation

        mesh->create();

        return mesh;
    }

    std::shared_ptr<Mesh> PrimitiveMesh::createCone(const LogicalDevice& logicalDevice, const std::shared_ptr<CommandPool> commandPool, float radius, float height, uint32_t sectors)
    {
        std::shared_ptr<Mesh> mesh = std::make_shared<Mesh>(logicalDevice, commandPool);

        // TODO: Implement cone mesh creation

        mesh->create();

        return mesh;
    }

    std::shared_ptr<Mesh> PrimitiveMesh::createTorus(const LogicalDevice& logicalDevice, const std::shared_ptr<CommandPool> commandPool, float innerRadius, float outerRadius, uint32_t rings, uint32_t sectors)
    {
        std::shared_ptr<Mesh> mesh = std::make_shared<Mesh>(logicalDevice, commandPool);

        // TODO: Implement torus mesh creation

        mesh->create();

        return mesh;
    }

} // namespace Aminophenol
