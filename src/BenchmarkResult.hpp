#ifndef MACH5_BENCHMARK_RESULT_HPP 
#define MACH5_BENCHMARK_RESULT_HPP 

#include <string>
#include <chrono>

namespace mach5 {
	class BenchmarkResult {
	public:
		BenchmarkResult(std::string benchmark_name, int runs, int iterations, double duration):_benchmark_name(benchmark_name),_runs(runs),_iterations(iterations),_duration(duration) {}
		void str();
	private:
		std::string _benchmark_name;
		int _runs;
		int _iterations;
		double _duration;
	};
}

#endif