
#include <Core/Engine.h>

using namespace Aminophenol;

int main(int argc, char* argv[])
{
	Engine* engine = new Engine{ "Aminophenol application" };
	Logger::s_minLogLevel = LogLevel::Info;

	// Create a basic scene
	Scene* scene = new Scene{ "Basic scene" };
	Logger::log("Scene name: %s", scene->getName().c_str());
	Node& node_1 = scene->addChild("Node 1");
	Logger::log("Node 1 name: %s", node_1.getName().c_str());
	Logger::log("Node 1 UUID: %s", node_1.getUUID().toString().c_str());
	Node& node_2 = scene->addChild("Node 2");
	Logger::log("Node 2 name: %s", node_2.getName().c_str());
	Logger::log("Node 2 UUID: %s", node_2.getUUID().toString().c_str());

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
