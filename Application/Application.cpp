
#include <Core/Engine.h>

int main(int argc, char* argv[])
{
	try
	{
		Aminophenol::Engine* engine = new Aminophenol::Engine{ "Aminophenol application" };
		Aminophenol::Logger::s_minLogLevel = Aminophenol::LogLevel::Trace;

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
