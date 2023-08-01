
#include "pch.h"
#include "Scene.h"

#include "Logging/Logger.h"

namespace Aminophenol {

	Scene::Scene(const std::string name, const Maths::Color backgroundColor)
		: Node{ name, nullptr }
		, m_backgroundColor{ backgroundColor }
	{}

	Scene::~Scene()
	{}

	Camera* Scene::getActiveCamera() const
	{
		return m_activeCamera;
	}

	const Maths::Color& Scene::getBackgroundColor() const
	{
		return m_backgroundColor;
	}

	void Scene::setActiveCamera(Camera* camera)
	{
		m_activeCamera = camera;
	}

	void Scene::setBackgroundColor(const Maths::Color& backgroundColor)
	{
		m_backgroundColor = backgroundColor;
	}

} // namespace Aminophenol
