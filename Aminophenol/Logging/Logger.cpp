
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

		std::cout << "\033[1;36m---------------- STARTING LOGGING SESSION ----------------\033[0m" << std::endl;
	}

	Logger::~Logger()
	{
		std::cout << "\033[1;36m----------------- ENDING LOGGING SESSION -----------------\033[0m" << std::endl;
	}

	void Logger::log(LogLevel level, const char* message, ...)
	{
		if (level >= s_minLogLevel)
		{
			std::string logLevel = "";
			std::string color = "";
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

			std::cout
				// Timestamp
				<< "[\033[1;37m"
				<< std::setw(2) << std::setfill('0') << st.wHour << ":"
				<< std::setw(2) << std::setfill('0') << st.wMinute << ":"
				<< std::setw(2) << std::setfill('0') << st.wSecond << "."
				<< std::setw(3) << std::setfill('0') << st.wMilliseconds
				<< "\033[0m] ["
				// Log level
				<< color << logLevel << "\033[0m" << "] ";
			
			// Message
			va_list args;
			va_start(args, message);
			vprintf(message, args);
			va_end(args);
			
			std::cout << std::endl;
		}
	}

	void Logger::log(const char* message, ...)
	{
		if (LogLevel::Info < s_minLogLevel)
		{
			return;
		}

		// Get timestamp
		SYSTEMTIME st;
		GetLocalTime(&st);

		std::cout
			// Timestamp & Log level
			<< "[\033[1;37m"
			<< std::to_string(st.wHour) + ":" + std::to_string(st.wMinute) + ":" + std::to_string(st.wSecond) + "." + std::to_string(st.wMilliseconds)
			<< "\033[0m] [\033[1;36mINFO\033[0m] ";

		// Message
		va_list args;
		va_start(args, message);
		vprintf(message, args);
		va_end(args);

		std::cout << std::endl;
	}

} // namespace Aminophenol
