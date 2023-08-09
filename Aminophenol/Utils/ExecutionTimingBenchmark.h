
#ifndef EXECUTION_TIMING_BENCHMARK_H
#define EXECUTION_TIMING_BENCHMARK_H

namespace Aminophenol {

	class ExecutionTimingBenchmark
	{
	public:
		
		ExecutionTimingBenchmark(const std::string& name);
		~ExecutionTimingBenchmark();

	private:
		
		std::string m_name;
		std::chrono::time_point<std::chrono::steady_clock> m_startTimePoint;

	};

} // namespace Aminophenol

#endif // EXECUTION_TIMING_BENCHMARK_H
