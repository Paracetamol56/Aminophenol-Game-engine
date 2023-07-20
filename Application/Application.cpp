
#include <memory>
#include <string>

#include <Core/Engine.h>

using namespace Aminophenol;

int main(int argc, char* argv[])
{
#if _DEBUG
	Logger logger{ LogLevel::Trace };
#else
	Logger logger{ LogLevel::Info };
#endif // DEBUG

	Engine* engine = new Engine{ "Aminophenol application" };

	// Create a basic scene
	std::shared_ptr<Scene> scene = std::make_shared<Scene>("Basic scene");
	scene->setBackgroundColor({ 0.1f, 0.2f, 0.4f, 1.0f });
	engine->setActiveScene(scene);
	Node& node_1 = scene->addChild("Node 1");
	node_1.addComponent<MeshRenderer>(std::make_shared<Mesh>(
		engine->getRenderingEngine().getLogicalDevice(),
		engine->getRenderingEngine().getCommandPool()
	));
	scene.reset();

	try
	{
		engine->run();
	}
	catch (const std::exception& e)
	{
		Logger::log(LogLevel::Critical, e.what());

		return EXIT_FAILURE;
	}

	delete engine;
	
	return EXIT_SUCCESS;
}
