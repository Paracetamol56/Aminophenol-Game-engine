
#include "pch.h"
#include "OBJLoader.h"

#include "Mesh/Vertex.h"
#include "Maths/Vector2.h"
#include "Maths/Vector3.h"

// For benchmarking purposes
#include "Utils/ExecutionTimingBenchmark.h"

namespace Aminophenol {

    std::shared_ptr<Mesh> OBJLoader::loadMesh(const LogicalDevice& logicalDevice, const std::shared_ptr<CommandPool> commandPool, const std::string& filename)
    {
        ExecutionTimingBenchmark bench0{ "OBJLoader::loadMesh()" };
        
        std::ifstream fileStream{ filename };
        if (!fileStream.is_open())
        {
			throw std::runtime_error{ "Failed to open file: " + filename };
		}

        std::shared_ptr<Mesh> mesh = std::make_shared<Mesh>(logicalDevice, commandPool);

        std::unordered_map<Vertex, uint32_t> uniqueVertices{};
        std::vector<float> vertexPositions{};
        std::vector<float> vertexColors{};
        std::vector<float> vertexNormals{};
        std::vector<float> vertexTextureCoordinates{};

        std::string line;
        while (std::getline(fileStream, line))
        {
            // Trim newline
            if (line.size() > 0)
                if (line[line.size() - 1] == '\n')
					line.erase(line.size() - 1);

			// Trim carriage return
			if (line.size() > 0)
				if (line[line.size() - 1] == '\r')

            // Skip comment and empty lines
            if (line[0] == '#' || line.empty())
				continue;

            // Get the line token (first character(s) before the first space) and erase it from the line
            size_t spaceIndex = line.find(' ');
            std::string token = line.substr(0, spaceIndex);
            line.erase(0, spaceIndex + 1);
            
            // CASE: Vertex
            if (token == "v")
            {
				std::istringstream iss{ line };
                float x, y, z;
				iss >> x >> y >> z;
				vertexPositions.push_back(x);
                vertexPositions.push_back(y);
                vertexPositions.push_back(z);

                // If the line contains more than 3 values, then it also contains a color
                if (iss.rdbuf()->in_avail() > 0)
				{
                    float r, g, b;
					iss >> r >> g >> b;
					vertexColors.push_back(r);
					vertexColors.push_back(g);
					vertexColors.push_back(b);
				}
                else
                {
                    vertexColors.push_back(0.0f);
                    vertexColors.push_back(1.0f);
                    vertexColors.push_back(1.0f);
                }
			}

            // CASE: Vertex normal
            else if (token == "vn")
            {
                std::istringstream iss{ line };
                float x, y, z;
                iss >> x >> y >> z;
                vertexNormals.push_back(x);
                vertexNormals.push_back(y);
                vertexNormals.push_back(z);
            }

            // CASE: Vertex texture coordinate
            else if (token == "vt")
            {
				std::istringstream iss{ line };
				float x, y;
				iss >> x >> y;
				vertexTextureCoordinates.push_back(x);
                vertexTextureCoordinates.push_back(y);
			}

            // CASE: Face
            else if (token == "f")
            {
				std::istringstream iss{ line };
				std::vector<Vertex> faceVertices{};

                while (std::getline(iss, line, ' '))
                {
                    Vertex vertex{};

                    std::istringstream vertexIss{ line };
                    std::string vertexToken{};
                    std::getline(vertexIss, vertexToken, '/');
                    vertex.position = {
                        vertexPositions[(std::stoi(vertexToken) - 1) * 3],
                        vertexPositions[(std::stoi(vertexToken) - 1) * 3 + 1],
                        vertexPositions[(std::stoi(vertexToken) - 1) * 3 + 2]
                    };
                    vertex.color = {
                        vertexColors[(std::stoi(vertexToken) - 1) * 3],
						vertexColors[(std::stoi(vertexToken) - 1) * 3 + 1],
						vertexColors[(std::stoi(vertexToken) - 1) * 3 + 2]
					};
                    // Texture coordinates
                    if (std::getline(vertexIss, vertexToken, '/'))
                    {
                        vertex.textureCoordinate = {
							vertexTextureCoordinates[(std::stoi(vertexToken) - 1) * 2],
							vertexTextureCoordinates[(std::stoi(vertexToken) - 1) * 2 + 1]
						};
					}
                    // Vertex normal
                    if (std::getline(vertexIss, vertexToken, '/'))
                    {
                        vertex.normal = {
                            vertexNormals[(std::stoi(vertexToken) - 1) * 3],
                            vertexNormals[(std::stoi(vertexToken) - 1) * 3 + 1],
                            vertexNormals[(std::stoi(vertexToken) - 1) * 3 + 2]
                        };
                    }

                    faceVertices.push_back(vertex);
                }

                // Face triangulation
                for (size_t i = 1; i < faceVertices.size() - 1; ++i)
                {
					mesh->vertices.push_back(faceVertices[0]);
                    mesh->vertices.push_back(faceVertices[i]);
                    mesh->vertices.push_back(faceVertices[i + 1]);

                    if (uniqueVertices.count(faceVertices[0]) == 0)
                    {
                        uniqueVertices[faceVertices[0]] = static_cast<uint32_t>(mesh->vertices.size() - 3);
                        mesh->vertices.push_back(faceVertices[0]);
                    }
                    if (uniqueVertices.count(faceVertices[i]) == 0)
                    {
						uniqueVertices[faceVertices[i]] = static_cast<uint32_t>(mesh->vertices.size() - 2);
						mesh->vertices.push_back(faceVertices[i]);
					}
                    if (uniqueVertices.count(faceVertices[i + 1]) == 0)
                    {
						uniqueVertices[faceVertices[i + 1]] = static_cast<uint32_t>(mesh->vertices.size() - 1);
						mesh->vertices.push_back(faceVertices[i + 1]);
					}

					mesh->indices.push_back(uniqueVertices[faceVertices[0]]);
					mesh->indices.push_back(uniqueVertices[faceVertices[i]]);
					mesh->indices.push_back(uniqueVertices[faceVertices[i + 1]]);
				}
            }

			// CASE: Unknown token
			else
			{
				throw std::runtime_error{ "Unknown token: " + token };
			}

        }
        
        fileStream.close();

        mesh->create();

        return mesh;
    }

} // namespace Aminophenol
