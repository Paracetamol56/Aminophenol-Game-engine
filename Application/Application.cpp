
#include <memory>
#include <string>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include "Core/Engine.h"
#include "Logging/Logger.h"
#include "Mesh/OBJLoader.h"
#include "Mesh/PrimitiveMesh.h"

#include "CustomComponents/ObjectRotationController.h"

using namespace Aminophenol;

int main(int argc, char* argv[])
{
	// Initialize logger
#if _DEBUG
	Logger logger{ LogLevel::Trace };
#else
	Logger logger{ LogLevel::Info };
#endif // _DEBUG

	Engine engine{ "Aminophenol application", 60.0, 800, 800 };

	// Create a basic scene
	std::shared_ptr<Scene> scene = std::make_shared<Scene>("Basic scene");
	engine.setActiveScene(scene);

	Node* object = scene->addChild("object");
	MeshRenderer* objectMeshRenderer = object->addComponent<MeshRenderer>(PrimitiveMesh::createCylinder(
		engine.getRenderingEngine().getLogicalDevice(),
		engine.getRenderingEngine().getCommandPool()
	));
	object->addComponent<ObjectRotationController>(1.0f);

	Node* camera = scene->addChild("Camera");
	camera->transform.position = { 0.0f, 0.0f, -3.0f };
	// OrthographicCamera* cameraComponent = camera->addComponent<OrthographicCamera>(1.0, -1.0, 1.0, 0.0, 100.0);
	PerspectiveCamera* cameraComponent = camera->addComponent<PerspectiveCamera>(Maths::degreesToRadians(45.0f), 1.0f, 0.1f, 100.0f);
	cameraComponent->setViewDirection({ 0.0f, 0.0f, 1.0f }, { 0.0f, -1.0f, 0.0f });

	scene->setBackgroundColor(Maths::Color{0.21f, 0.35f, 0.45f, 1.0f});
	scene->setActiveCamera(cameraComponent);
	scene.reset();

	try
	{
		engine.run();
	}
	catch (const std::exception& e)
	{
		Logger::log(LogLevel::Critical, e.what());

		return EXIT_FAILURE;
	}
	
	return EXIT_SUCCESS;
}
