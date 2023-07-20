
#include "pch.h"
#include "Scene.h"

namespace Aminophenol {

	Scene::Scene(const std::string name, const glm::vec4 backgroundColor)
		: Node{ name, nullptr }
		, m_backgroundColor{ backgroundColor }
	{}

	Scene::~Scene()
	{}

	const glm::vec4& Scene::getBackgroundColor() const
	{
		return m_backgroundColor;
	}

	void Scene::setBackgroundColor(const glm::vec4& backgroundColor)
	{
		m_backgroundColor = backgroundColor;
	}

} // namespace Aminophenol
