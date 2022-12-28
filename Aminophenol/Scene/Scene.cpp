
#include "pch.h"
#include "Scene.h"

namespace Aminophenol {

	Scene::Scene()
	{}

	Scene::~Scene()
	{}

	Node& Scene::addNode(const std::string& name)
	{
		// Generate a new UUID for the node
		Utils::UUIDv4::UUIDGenerator<std::mt19937_64> uuidGenerator;
		Utils::UUIDv4::UUID uuid = uuidGenerator.getUUID();
		
		// Create a new node
		Node node(name);
		m_nodes[uuid] = node;
		
		return m_nodes[uuid];
	}

	void Scene::removeNode(const Utils::UUIDv4::UUID& uuid)
	{
		m_nodes.erase(uuid);
	}

	Node& Scene::getNode(const Utils::UUIDv4::UUID& uuid)
	{
		return m_nodes[uuid];
	}

} // namespace Aminophenol
