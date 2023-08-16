
#include "pch.h"
#include "PrimitiveMesh.h"
#include "Maths/Constant.h"

namespace Aminophenol
{

    std::shared_ptr<Mesh> PrimitiveMesh::createCube(const LogicalDevice& logicalDevice, const std::shared_ptr<CommandPool> commandPool)
    {
        std::shared_ptr<Mesh> mesh = std::make_shared<Mesh>(logicalDevice, commandPool);

        mesh->vertices = {
            // Front (0 - 3)
            { { -0.5f, -0.5f,  0.5f }, { 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, 1.0f } },
            { {  0.5f, -0.5f,  0.5f }, { 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, 1.0f } },
            { {  0.5f,  0.5f,  0.5f }, { 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, 1.0f } },
            { { -0.5f,  0.5f,  0.5f }, { 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, 1.0f } },
            // Back (4 - 7)
            { { -0.5f, -0.5f, -0.5f }, { 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, -1.0f } },
            { {  0.5f, -0.5f, -0.5f }, { 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, -1.0f } },
            { {  0.5f,  0.5f, -0.5f }, { 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, -1.0f } },
            { { -0.5f,  0.5f, -0.5f }, { 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, -1.0f } },
            // Left (8 -11)
            { { -0.5f, -0.5f, -0.5f }, { 1.0f, 1.0f, 1.0f }, { -1.0f, 0.0f, 0.0f } },
			{ { -0.5f, -0.5f,  0.5f }, { 1.0f, 1.0f, 1.0f }, { -1.0f, 0.0f, 0.0f } },
			{ { -0.5f,  0.5f,  0.5f }, { 1.0f, 1.0f, 1.0f }, { -1.0f, 0.0f, 0.0f } },
			{ { -0.5f,  0.5f, -0.5f }, { 1.0f, 1.0f, 1.0f }, { -1.0f, 0.0f, 0.0f } },
        	// Right (12 - 15)
            { {  0.5f, -0.5f, -0.5f }, { 1.0f, 1.0f, 1.0f }, {  1.0f, 0.0f, 0.0f } },
            { {  0.5f, -0.5f,  0.5f }, { 1.0f, 1.0f, 1.0f }, {  1.0f, 0.0f, 0.0f } },
            { {  0.5f,  0.5f,  0.5f }, { 1.0f, 1.0f, 1.0f }, {  1.0f, 0.0f, 0.0f } },
			{ {  0.5f,  0.5f, -0.5f }, { 1.0f, 1.0f, 1.0f }, {  1.0f, 0.0f, 0.0f } },
            // Top (16 - 19)
			{ { -0.5f,  0.5f,  0.5f }, { 1.0f, 1.0f, 1.0f }, {  0.0f, 1.0f, 0.0f } },
			{ {  0.5f,  0.5f,  0.5f }, { 1.0f, 1.0f, 1.0f }, {  0.0f, 1.0f, 0.0f } },
			{ {  0.5f,  0.5f, -0.5f }, { 1.0f, 1.0f, 1.0f }, {  0.0f, 1.0f, 0.0f } },
			{ { -0.5f,  0.5f, -0.5f }, { 1.0f, 1.0f, 1.0f }, {  0.0f, 1.0f, 0.0f } },
            // Bottom (20 - 23)
            { { -0.5f, -0.5f, -0.5f }, { 1.0f, 1.0f, 1.0f }, {  0.0f, -1.0f, 0.0f } },
            { {  0.5f, -0.5f, -0.5f }, { 1.0f, 1.0f, 1.0f }, {  0.0f, -1.0f, 0.0f } },
            { {  0.5f, -0.5f,  0.5f }, { 1.0f, 1.0f, 1.0f }, {  0.0f, -1.0f, 0.0f } },
			{ { -0.5f, -0.5f,  0.5f }, { 1.0f, 1.0f, 1.0f }, {  0.0f, -1.0f, 0.0f } }
        };

        mesh->indices = {
            // Front
            2, 1, 0, 0, 3, 2,
            // Back
            5, 6, 7, 7, 4, 5,
            // Left
            11, 10, 9, 9, 8, 11,
            // Right
            12, 13, 14, 14, 15, 12,
            // Top
            19, 18, 17, 17, 16, 19,
            // Bottom
            22, 21, 20, 20, 23, 22
        };

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

    std::shared_ptr<Mesh> PrimitiveMesh::createPlane(const LogicalDevice& logicalDevice, const std::shared_ptr<CommandPool> commandPool)
    {
        std::shared_ptr<Mesh> mesh = std::make_shared<Mesh>(logicalDevice, commandPool);

        mesh->vertices = {
            { { -0.5f, 0.0f, 0.5f }, { 1.0f, 1.0f, 1.0f }, { 0.0f, 1.0f, 0.0f } },
            { {  0.5f, 0.0f, 0.5f }, { 1.0f, 1.0f, 1.0f }, { 0.0f, 1.0f, 0.0f } },
            { {  0.5f, 0.0f,-0.5f }, { 1.0f, 1.0f, 1.0f }, { 0.0f, 1.0f, 0.0f } },
            { { -0.5f, 0.0f,-0.5f }, { 1.0f, 1.0f, 1.0f }, { 0.0f, 1.0f, 0.0f } }
        };
        mesh->indices = {
			2, 1, 0, 0, 3, 2
		};

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
