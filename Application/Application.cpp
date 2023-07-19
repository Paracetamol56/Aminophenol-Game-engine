
#include <memory>
#include <string>

#include <Core/Engine.h>

using namespace Aminophenol;

int main(int argc, char* argv[])
{
	Engine* engine = new Engine{ "Aminophenol application" };
	Logger::s_minLogLevel = LogLevel::Info;

	// Create a basic scene
	std::shared_ptr<Scene> scene = std::make_shared<Scene>("Basic scene");
	engine->setActiveScene(scene);
	Node& node_1 = scene->addChild("Node 1");
	node_1.addComponent<MeshRenderer>(std::make_shared<Mesh>(
		engine->getRenderingEngine().getLogicalDevice(),
		engine->getRenderingEngine().getCommandPool()
	));

	try
	{
		engine->run();
		scene.reset();
	}
	catch (const std::exception& e)
	{
		Logger::log(LogLevel::Critical, e.what());

		return EXIT_FAILURE;
	}

	delete engine;
	
	return EXIT_SUCCESS;
}
