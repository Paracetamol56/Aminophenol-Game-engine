#pragma once

namespace Aminophenol
{

	enum class LogLevel
	{
		Trace,
		Info,
		Warning,
		Error,
		Critical
	};

	class Logger
	{
	public:
		
		Logger(LogLevel level = LogLevel::Info);
		~Logger();

		static inline LogLevel s_minLogLevel;
		
		/// <summary>
		/// Logs a message to the console.
		/// </summary>
		/// <param name="level">The log level of the message.</param>
		/// <param name="message">The message to log.</param>
		static void log(LogLevel level, const char* message, ...);

		/// <summary>
		/// Logs a message to the console at the Info level (default).
		/// </summary>
		/// <param name="message">The message to log.</param>
		static void log(const char* message, ...);
		
	};
	
} // namespace Aminophenol
