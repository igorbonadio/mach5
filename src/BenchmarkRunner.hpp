#ifndef MACH5_BENCHMARK_RUNNER_HPP 
#define MACH5_BENCHMARK_RUNNER_HPP 

#include <vector>
#include <memory>

#include "Benchmark.hpp"

namespace mach5 {
	class BenchmarkRunner {
	public:
		void addBenchmark(BenchmarkPtr benchmark);
		void runAll();
	private:
		std::vector<BenchmarkPtr> _benchmarks;
	};
	
	typedef std::shared_ptr<BenchmarkRunner> BenchmarkRunnerPtr;
}

#endif