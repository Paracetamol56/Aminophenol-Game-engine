
#include "pch.h"
#include "OBJMesh.h"

#include "Logging/Logger.h"

namespace Aminophenol {

	OBJMesh::OBJMesh(LogicalDevice& logicalDevice, std::string filePath)
		: Mesh{ logicalDevice }
		, m_filePath{ filePath }
	{
		Logger::log(LogLevel::Trace, "Loading a mesh from file...");

		loadFromFile();

		createVertexBuffer();
		createIndexBuffer();

		Logger::log(LogLevel::Trace, "Successfully loaded a mesh");
	}

	OBJMesh::~OBJMesh()
	{}

	void OBJMesh::loadFromFile()
	{
		// Open the file and check if it is valid
		std::ifstream file{ m_filePath, std::ios::in };
		if (!file)
		{
			throw std::runtime_error("Cannot open file at path: " + m_filePath);
		}

		m_vertices.clear();
		m_indices.clear();

		// Initialize temporary variables
		std::unordered_map<Vertex, uint32_t> uniqueVertices{};
		std::vector<glm::vec3> vertexPositions;
		std::vector<glm::vec3> vertexColors;
		std::vector<glm::vec3> vertexNormals;
		std::vector<glm::vec2> vertexTexCoords;

		std::string line;

		// Read the file line by line
		while (std::getline(file, line))
		{
			// The line is a vertex position (and maybe color)
			if (line.substr(0, 2) == "v ")
			{
				std::istringstream s{ line.substr(2) };
				glm::vec3 v;
				s >> v.x;
				s >> v.y;
				s >> v.z;
				vertexPositions.push_back(v);

				// If the line is not finished
				if (s.peek() != EOF)
				{
					glm::vec3 c;
					s >> c.x;
					s >> c.y;
					s >> c.z;
					vertexColors.push_back(c);
				}
				else
				{
					vertexColors.push_back(glm::vec3(1.0f, 0.0f, 1.0f));
				}
			}
			// The line is a vertex normal
			else if (line.substr(0, 3) == "vn ")
			{
				std::istringstream s{ line.substr(3) };
				glm::vec3 n;
				s >> n.x;
				s >> n.y;
				s >> n.z;
				vertexNormals.push_back(n);
			}
			// The line is a vertex texture coordinate
			else if (line.substr(0, 3) == "vt ")
			{
				std::istringstream s{ line.substr(3) };
				glm::vec2 t;
				s >> t.x;
				s >> t.y;
				vertexTexCoords.push_back(t);
			}
			// The line is a face
			else if (line.substr(0, 2) == "f ")
			{
				std::istringstream s{ line.substr(2) };
				std::string token;

				std::vector<Vertex> faceVertices;

				while (std::getline(s, token, ' '))
				{
					Vertex v{};

					std::istringstream s2{ token };
					std::string token2;
					std::getline(s2, token2, '/');
					v.position = vertexPositions[std::stoi(token2) - 1];
					v.color = vertexColors[std::stoi(token2) - 1];
					if (std::getline(s2, token2, '/'))
					{
						v.textureCoordinate = vertexTexCoords[std::stoi(token2) - 1];
					}
					if (std::getline(s2, token2, '/'))
					{
						v.normal = vertexNormals[std::stoi(token2) - 1];
					}

					faceVertices.push_back(v);
				}

				// Triangulate the face (just push vertices and indices if the face is a triangle)
				for (size_t i = 1; i < faceVertices.size() - 1; i++)
				{
					m_vertices.push_back(faceVertices[0]);
					m_vertices.push_back(faceVertices[i]);
					m_vertices.push_back(faceVertices[i + 1]);

					if (uniqueVertices.count(faceVertices[0]) == 0)
					{
						uniqueVertices[faceVertices[0]] = static_cast<uint32_t>(m_vertices.size());
						m_vertices.push_back(faceVertices[0]);
					}
					if (uniqueVertices.count(faceVertices[i]) == 0)
					{
						uniqueVertices[faceVertices[i]] = static_cast<uint32_t>(m_vertices.size());
						m_vertices.push_back(faceVertices[i]);
					}
					if (uniqueVertices.count(faceVertices[i + 1]) == 0)
					{
						uniqueVertices[faceVertices[i + 1]] = static_cast<uint32_t>(m_vertices.size());
						m_vertices.push_back(faceVertices[i + 1]);
					}

					m_indices.push_back(uniqueVertices[faceVertices[0]]);
					m_indices.push_back(uniqueVertices[faceVertices[i]]);
					m_indices.push_back(uniqueVertices[faceVertices[i + 1]]);
				}
			}
		}

		file.close();
	}

} // namespace Aminophenol
