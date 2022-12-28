
#include "pch.h"
#include "Scene.h"

namespace Aminophenol {

	Scene::Scene(const std::string name)
		: Node{ name, nullptr }
	{}

	Scene::~Scene()
	{}

} // namespace Aminophenol
