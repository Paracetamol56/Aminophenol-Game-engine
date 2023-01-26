
#ifndef OBJ_MESH_H
#define OBJ_MESH_H

#include "pch.h"
#include "Mesh/Mesh.h"

#include "Rendering/Device/LogicalDevice.h"

namespace Aminophenol {

	class OBJMesh
		: public Mesh
	{
	public:

		OBJMesh(LogicalDevice& logicalDevice, const std::shared_ptr<CommandPool> commandPool, std::string filePath);
		~OBJMesh();

	private:

		const std::string m_filePath;

		void loadFromFile();

	};

} // namespace Aminophenol

#endif // OBJ_MESH_H
