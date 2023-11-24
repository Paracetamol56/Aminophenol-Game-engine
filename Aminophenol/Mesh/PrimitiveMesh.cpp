
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
            { { -0.5f, -0.5f,  0.5f }, { 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, 1.0f }, { 0.0f, 0.0f } },
            { {  0.5f, -0.5f,  0.5f }, { 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, 1.0f }, { 1.0f, 0.0f } },
			{ {  0.5f,  0.5f,  0.5f }, { 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, 1.0f }, { 1.0f, 1.0f } },
			{ { -0.5f,  0.5f,  0.5f }, { 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, 1.0f }, { 0.0f, 1.0f } },
            // Back (4 - 7)
            { { -0.5f, -0.5f, -0.5f }, { 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, -1.0f }, { 0.0f, 0.0f } },
            { {  0.5f, -0.5f, -0.5f }, { 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, -1.0f }, { 1.0f, 0.0f } },
            { {  0.5f,  0.5f, -0.5f }, { 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, -1.0f }, { 1.0f, 1.0f } },
            { { -0.5f,  0.5f, -0.5f }, { 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, -1.0f }, { 0.0f, 1.0f } },
            // Left (8 -11)
            { { -0.5f, -0.5f, -0.5f }, { 1.0f, 1.0f, 1.0f }, { -1.0f, 0.0f, 0.0f }, { 0.0f, 0.0f } },
			{ { -0.5f, -0.5f,  0.5f }, { 1.0f, 1.0f, 1.0f }, { -1.0f, 0.0f, 0.0f }, { 1.0f, 0.0f } },
			{ { -0.5f,  0.5f,  0.5f }, { 1.0f, 1.0f, 1.0f }, { -1.0f, 0.0f, 0.0f }, { 1.0f, 1.0f } },
			{ { -0.5f,  0.5f, -0.5f }, { 1.0f, 1.0f, 1.0f }, { -1.0f, 0.0f, 0.0f }, { 0.0f, 1.0f } },
        	// Right (12 - 15)
            { {  0.5f, -0.5f, -0.5f }, { 1.0f, 1.0f, 1.0f }, {  1.0f, 0.0f, 0.0f }, { 0.0f, 0.0f } },
            { {  0.5f, -0.5f,  0.5f }, { 1.0f, 1.0f, 1.0f }, {  1.0f, 0.0f, 0.0f }, { 1.0f, 0.0f } },
            { {  0.5f,  0.5f,  0.5f }, { 1.0f, 1.0f, 1.0f }, {  1.0f, 0.0f, 0.0f }, { 1.0f, 1.0f } },
			{ {  0.5f,  0.5f, -0.5f }, { 1.0f, 1.0f, 1.0f }, {  1.0f, 0.0f, 0.0f }, { 0.0f, 1.0f } },
            // Top (16 - 19)
			{ { -0.5f,  0.5f,  0.5f }, { 1.0f, 1.0f, 1.0f }, {  0.0f, 1.0f, 0.0f }, { 0.0f, 0.0f } },
			{ {  0.5f,  0.5f,  0.5f }, { 1.0f, 1.0f, 1.0f }, {  0.0f, 1.0f, 0.0f }, { 1.0f, 0.0f } },
			{ {  0.5f,  0.5f, -0.5f }, { 1.0f, 1.0f, 1.0f }, {  0.0f, 1.0f, 0.0f }, { 1.0f, 1.0f } },
			{ { -0.5f,  0.5f, -0.5f }, { 1.0f, 1.0f, 1.0f }, {  0.0f, 1.0f, 0.0f }, { 0.0f, 1.0f } },
            // Bottom (20 - 23)
            { { -0.5f, -0.5f, -0.5f }, { 1.0f, 1.0f, 1.0f }, {  0.0f, -1.0f, 0.0f }, { 0.0f, 0.0f } },
            { {  0.5f, -0.5f, -0.5f }, { 1.0f, 1.0f, 1.0f }, {  0.0f, -1.0f, 0.0f }, { 1.0f, 0.0f } },
            { {  0.5f, -0.5f,  0.5f }, { 1.0f, 1.0f, 1.0f }, {  0.0f, -1.0f, 0.0f }, { 1.0f, 1.0f } },
            { { -0.5f, -0.5f,  0.5f }, { 1.0f, 1.0f, 1.0f }, {  0.0f, -1.0f, 0.0f }, { 0.0f, 1.0f } }
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

		for (size_t i = 0; i <= sectors; ++i)
		{
			float thetai = static_cast<float>(i) * 2.0f * Maths::Constant::pi<float>() / static_cast<float>(sectors);
			float cosThetai = cos(thetai);
			float sinThetai = sin(thetai);
			for (size_t j = 1; j <= rings; ++j)
			{
				float phij = static_cast<float>(j) * Maths::Constant::pi<float>() / (static_cast<float>(rings) + 1);
				float cosPhij = cos(phij);
				float sinPhij = sin(phij);

		        mesh->vertices.push_back({
					{ cosThetai * sinPhij * 0.5f, cosPhij * 0.5f, sinThetai * sinPhij * 0.5f },
					{ 1.0f, 1.0f, 1.0f },
					{ cosThetai * sinPhij, cosPhij, sinThetai * sinPhij }
				});
			}
		}

        // South pole
        mesh->vertices.push_back({
            { 0.0f, -0.5f, 0.0f },
            { 1.0f, 1.0f, 1.0f },
            { 0.0f, -1.0f, 0.0f }
        });
        // North pole
        mesh->vertices.push_back({
			{ 0.0f, 0.5f, 0.0f },
			{ 1.0f, 1.0f, 1.0f },
			{ 0.0f, 1.0f, 0.0f }
		});

        // Indices
        for (size_t i = 0; i < sectors; ++i)
        {
            for (size_t j = 1; j < rings; ++j)
            {
                // Triangle 1
                mesh->indices.push_back((i + 1) * rings + j - 1);
                mesh->indices.push_back((i + 1) * rings + j);
                mesh->indices.push_back(i * rings + j);
                // Triangle 2
                mesh->indices.push_back(i * rings + j - 1);
                mesh->indices.push_back((i + 1) * rings + j - 1);
                mesh->indices.push_back(i * rings + j);
            }
        }

        // South pole indices
        for (size_t i = 0; i < sectors; ++i)
        {
            mesh->indices.push_back((sectors + 1) * rings);
            mesh->indices.push_back((i + 1) * rings - 1);
            mesh->indices.push_back((i + 2) * rings - 1);
        }

        // North pole indices
        for (size_t i = 0; i < sectors; ++i)
        {
			mesh->indices.push_back((sectors + 1) * rings + 1);
			mesh->indices.push_back((i + 1) * rings);
			mesh->indices.push_back(i * rings);
		}

        mesh->create();

        return mesh;
    }

    std::shared_ptr<Mesh> PrimitiveMesh::createPlane(const LogicalDevice& logicalDevice, const std::shared_ptr<CommandPool> commandPool)
    {
        std::shared_ptr<Mesh> mesh = std::make_shared<Mesh>(logicalDevice, commandPool);

        mesh->vertices = {
            Vertex{ { -0.5f, 0.0f, 0.5f }, { 1.0f, 1.0f, 1.0f }, { 0.0f, 1.0f, 0.0f }, { 0.0f, 0.0f } },
            Vertex{ {  0.5f, 0.0f, 0.5f }, { 1.0f, 1.0f, 1.0f }, { 0.0f, 1.0f, 0.0f }, { 1.0f, 0.0f } },
            Vertex{ {  0.5f, 0.0f,-0.5f }, { 1.0f, 1.0f, 1.0f }, { 0.0f, 1.0f, 0.0f }, { 1.0f, 1.0f } },
            Vertex{ { -0.5f, 0.0f,-0.5f }, { 1.0f, 1.0f, 1.0f }, { 0.0f, 1.0f, 0.0f }, { 0.0f, 1.0f } }
        };
        mesh->indices = {
			2, 1, 0, 0, 3, 2
		};

        mesh->create();

        return mesh;
    }

    std::shared_ptr<Mesh> PrimitiveMesh::createCylinder(const LogicalDevice& logicalDevice, const std::shared_ptr<CommandPool> commandPool, uint32_t sectors)
    {
        std::shared_ptr<Mesh> mesh = std::make_shared<Mesh>(logicalDevice, commandPool);

        for (size_t i = 0; i <= sectors; ++i)
        {
            float thetai = static_cast<float>(i) * 2.0f * Maths::Constant::pi<float>() / static_cast<float>(sectors);
            float cosThetai = cos(thetai);
            float sinThetai = sin(thetai);

            // Top side vertices
            mesh->vertices.push_back({
                { cosThetai * 0.5f, -0.5f, sinThetai * 0.5f },
                { 1.0f, 1.0f, 1.0f },
                { cosThetai, 0.0f, sinThetai}
            });
            // Bottom side vertices
            mesh->vertices.push_back({
                { cosThetai * 0.5f, 0.5f, sinThetai * 0.5f },
                { 1.0f, 1.0f, 1.0f },
                { cosThetai, 0.0f, sinThetai }
            });
		}

        for (size_t i = 0; i <= sectors; ++i)
        {
            float thetai = static_cast<float>(i) * 2.0f * Maths::Constant::pi<float>() / static_cast<float>(sectors);
            float cosThetai = cos(thetai);
            float sinThetai = sin(thetai);

            // Top side vertices
            mesh->vertices.push_back({
                { cosThetai * 0.5f, -0.5f, sinThetai * 0.5f },
                { 1.0f, 1.0f, 1.0f },
                { 0.0f, -1.0f, 0.0f}
            });
            // Bottom side vertices
            mesh->vertices.push_back({
                { cosThetai * 0.5f, 0.5f, sinThetai * 0.5f },
                { 1.0f, 1.0f, 1.0f },
                { 0.0f, 1.0f, 0.0f }
            });
        }

        // Indices
        for (size_t i = 0; i < sectors * 2; i += 2)
        {
            mesh->indices.push_back(i);
            mesh->indices.push_back(i + 2);
			mesh->indices.push_back(i + 1);
			mesh->indices.push_back(i + 1);
			mesh->indices.push_back(i + 2);
			mesh->indices.push_back(i + 3);
		}

        // Top face indices
        for (size_t i = 0; i < sectors * 2; i += 2)
        {
			mesh->indices.push_back(sectors * 4 + 2);
			mesh->indices.push_back(sectors * 2 + i + 2);
			mesh->indices.push_back(sectors * 2 + i);

            mesh->indices.push_back(sectors * 4 + 3);
            mesh->indices.push_back(sectors * 2 + i + 1);
            mesh->indices.push_back(sectors * 2 + i + 3);
		}

        mesh->create();

        return mesh;
    }

    std::shared_ptr<Mesh> PrimitiveMesh::createCone(const LogicalDevice& logicalDevice, const std::shared_ptr<CommandPool> commandPool, float radius, float height, uint32_t sectors)
    {
        std::shared_ptr<Mesh> mesh = std::make_shared<Mesh>(logicalDevice, commandPool);

        for (size_t i = 0; i <= sectors; ++i)
        {
            float thetai = static_cast<float>(i) * 2.0f * Maths::Constant::pi<float>() / static_cast<float>(sectors);
            float cosThetai = cos(thetai);
            float sinThetai = sin(thetai);
            
            // Side vertices
            mesh->vertices.push_back({
                { cosThetai * 0.5f, -0.5f, sinThetai * 0.5f },
                { 1.0f, 1.0f, 1.0f },
                { cosThetai, 1.0f, sinThetai }
            });
            // Top vertex
            mesh->vertices.push_back({
				{ 0.0f, 0.5f, 0.0f },
				{ 1.0f, 1.0f, 1.0f },
                { cosThetai, 1.0f, sinThetai }
			});
            // Bottom vertex
            mesh->vertices.push_back({
                { cosThetai * 0.5f, -0.5f, sinThetai * 0.5f },
                { 1.0f, 1.0f, 1.0f },
				{ 0.0f, -1.0f, 0.0f }
            });
        }

        for (size_t i = 0; i < sectors * 3; i += 3)
        {
            // Side face indices
            mesh->indices.push_back(i);
            mesh->indices.push_back(i + 3);
            mesh->indices.push_back(i + 1);
            // Bottom face indices
            mesh->indices.push_back(sectors * 3 + 2);
            mesh->indices.push_back(i + 5);
            mesh->indices.push_back(i + 2);
        }

        mesh->create();

        return mesh;
    }

} // namespace Aminophenol
