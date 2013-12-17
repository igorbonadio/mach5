#ifndef MACH5_BENCHMARK_RUNNER_HPP 
#define MACH5_BENCHMARK_RUNNER_HPP 

#include <vector>
#include <string>
#include <memory>

#include "Benchmark.hpp"
#include "BenchmarkDescriptor.hpp"

namespace mach5 {
	class BenchmarkRunner {
	public:
		void addBenchmark(BenchmarkPtr benchmark, std::string benchmark_name, int runs, int iterations);
		std::vector<Result> runAll();
	private:
		Result run(BenchmarkDescriptorPtr descriptor);
		std::vector<BenchmarkDescriptorPtr> _descriptors;
	};
	
	typedef std::shared_ptr<BenchmarkRunner> BenchmarkRunnerPtr;
}

#endif