
#include "pch.h"
#include "Logger.h"

// C/C++ headers
#include <stdio.h>
#include <windows.h>

namespace Aminophenol
{

	Logger::Logger(LogLevel level)
	{
		s_minLogLevel = level;

		std::cout << "\033[1;33m---------------- STARTING LOGGING SESSION ----------------\033[0m" << std::endl;
	}

	Logger::~Logger()
	{
		std::cout << "\033[1;33m----------------- ENDING LOGGING SESSION -----------------\033[0m" << std::endl;
	}

	void Logger::log(LogLevel level, const char* message, ...)
	{
		if (level >= s_minLogLevel)
		{
			std::string logLevel = "";
			std::string color = "";
			std::string timestamp = "";
			switch (level)
			{
			case LogLevel::Trace:
				logLevel = "TRACE";
				color = "\033[1;37m";
				break;
			case LogLevel::Info:
				logLevel = "INFO";
				color = "\033[1;36m";
				break;
			case LogLevel::Warning:
				logLevel = "WARNING";
				color = "\033[1;33m";
				break;
			case LogLevel::Error:
				logLevel = "ERROR";
				color = "\033[1;31m";
				break;
			case LogLevel::Critical:
				logLevel = "CRITICAL";
				color = "\033[1;35m";
				break;
			}

			// Get timestamp
			SYSTEMTIME st;
			GetLocalTime(&st);
			timestamp = std::to_string(st.wHour) + ":" + std::to_string(st.wMinute) + ":" + std::to_string(st.wSecond) + "." + std::to_string(st.wMilliseconds);

			std::cout << "[\033[1;37m" << timestamp << "\033[0m] [" << color << logLevel << "\033[0m" << "] ";
			
			va_list args;
			va_start(args, message);
			vprintf(message, args);
			va_end(args);
			
			std::cout << std::endl;
		}
	}

} // namespace Aminophenol
