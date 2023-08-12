
#include <memory>
#include <string>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include "Core/Engine.h"
#include "Logging/Logger.h"
#include "Mesh/OBJLoader.h"

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

	std::shared_ptr<Mesh> mesh = OBJLoader::loadMesh(
		engine.getRenderingEngine().getLogicalDevice(),
		engine.getRenderingEngine().getCommandPool(),
		"C:\\Users\\mathe\\Downloads\\xyzrgb_dragon_normal.obj"
	);

	Node* dragon0 = scene->addChild("Dragon 0");
	dragon0->addComponent<MeshRenderer>(mesh);
	dragon0->transform.position = { 0.0f, 0.5f, 0.0f };
	dragon0->transform.scale = { 0.01f };
	dragon0->addComponent<ObjectRotationController>(-1.0f);

	Node* dragon1 = scene->addChild("Dragon 1");
	dragon1->addComponent<MeshRenderer>(mesh);
	dragon1->transform.position = { 0.0f, -0.5f, 0.0f };
	dragon1->transform.scale = { 0.01f, 0.01, 0.01f };
	dragon1->addComponent<ObjectRotationController>(1.0f);

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
