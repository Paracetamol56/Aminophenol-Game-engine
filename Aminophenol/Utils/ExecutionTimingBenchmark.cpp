
#include "pch.h"
#include "ExecutionTimingBenchmark.h"

// C/C++ headers
#include <stdio.h>
#include <windows.h>

namespace Aminophenol {

	ExecutionTimingBenchmark::ExecutionTimingBenchmark(const std::string& name)
		: m_name(name)
	{
		m_startTimePoint = std::chrono::high_resolution_clock::now();
	}

	ExecutionTimingBenchmark::~ExecutionTimingBenchmark()
	{
		std::chrono::steady_clock::time_point endTimePoint = std::chrono::high_resolution_clock::now();

		const long long start = std::chrono::time_point_cast<std::chrono::microseconds>(m_startTimePoint).time_since_epoch().count();
		const long long end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimePoint).time_since_epoch().count();

		const long long duration = end - start;
		double ms = duration * 0.001;

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
			<< "\033[0m] [\033[1;33mBENCHMARK\033[0m] "
			<< m_name << ": " << duration << "us (" << ms << "ms)" << std::endl;
	}

} // namespace Aminophenol