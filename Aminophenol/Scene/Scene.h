
#ifndef SCENE_H
#define SCENE_H

#include "pch.h"

#include "Utils/uuid_v4.h"
#include "Scene/Node.h"

namespace Aminophenol {

	class AMINOPHENOL_API Scene
	{
	public:

		Scene();
		~Scene();

		Node& addNode(const std::string& name);
		void removeNode(const Utils::UUIDv4::UUID& uuid);
		Node& getNode(const Utils::UUIDv4::UUID& uuid);

	private:

		// Store a map of nodes and their UUIDs
		std::map<Utils::UUIDv4::UUID, Node> m_nodes;

	};

} // namespace Aminophenol

#endif // SCENE_H
