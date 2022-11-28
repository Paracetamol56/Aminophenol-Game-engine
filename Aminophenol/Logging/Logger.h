#pragma once

#include "pch.h"

namespace Aminophenol
{

	enum class AMINOPHENOL_API LogLevel
	{
		Trace,
		Info,
		Warning,
		Error,
		Critical
	};

	class AMINOPHENOL_API Logger
	{
	public:
		
		Logger(LogLevel level = LogLevel::Info);
		~Logger();

		static inline LogLevel s_minLogLevel;
		static void log(LogLevel level, const char* message, ...);
		
	};
	
} // namespace Aminophenol
