
#ifndef OBJLOADER_H
#define OBJLOADER_H

#include "pch.h"
#include "Mesh/Mesh.h"

namespace Aminophenol {

	class AMINOPHENOL_API OBJLoader
	{
	public:
		
		OBJLoader() = default;
		~OBJLoader() = default;

		static std::shared_ptr<Mesh> loadMesh(const LogicalDevice& logicalDevice, const std::shared_ptr<CommandPool> commandPool, const std::string& filename);
		
	};
	
} // namespace Aminophenol

#endif OBJLOADER_H
