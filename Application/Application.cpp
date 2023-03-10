
#include <Core/Engine.h>

int main(int argc, char* argv[])
{
	try
	{
		Aminophenol::Engine* engine = new Aminophenol::Engine{ "Aminophenol application" };

		engine->run();
		
		delete engine;
	}
	catch (const std::exception& e)
	{
		Aminophenol::Logger::log(Aminophenol::LogLevel::Critical, e.what());

		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
