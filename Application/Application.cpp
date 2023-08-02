
#include <memory>
#include <string>

#include <Core/Engine.h>

using namespace Aminophenol;

int main(int argc, char* argv[])
{
	// Initialize logger
#if _DEBUG
	Logger logger{ LogLevel::Trace };
#else
	Logger logger{ LogLevel::Info };
#endif // _DEBUG

	Engine engine{ "Aminophenol application" };

	// Create a basic scene
	std::shared_ptr<Scene> scene = std::make_shared<Scene>("Basic scene");
	engine.setActiveScene(scene);

	Node* cube = scene->addChild("Cube");
	cube->addComponent<MeshRenderer>(std::make_shared<Mesh>(
		engine.getRenderingEngine().getLogicalDevice(),
		engine.getRenderingEngine().getCommandPool()
	));
	cube->transform.position = { -1.0f, -1.0f, 1.0f };
	cube->transform.scale = { 0.5f, 0.5f, 0.5f };
	Node* camera = scene->addChild("Camera");
	Camera* cameraComponent = camera->addComponent<Camera>();
	cameraComponent->setPerspectiveProjection(45.0f, 1.0f, 0.1f, 100.0f);

	scene->setBackgroundColor({ 0.0f, 0.0f, 0.0f, 1.0f });
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
