#ifndef MACH5_BENCHMARK_RUNNER_HPP 
#define MACH5_BENCHMARK_RUNNER_HPP 

#include <vector>
#include <string>
#include <memory>

#include "Benchmark.hpp"
#include "BenchmarkDescriptor.hpp"
#include "BenchmarkFactory.hpp"

namespace mach5 {
	class BenchmarkRunner {
	public:
		// void addBenchmark(AbstractBenchmarkFactory benchmark, std::string benchmark_name, int runs, int iterations);
		template <class T>
		void addBenchmark(std::string benchmark_name, int runs, int iterations) {
			AbstractBenchmarkFactoryPtr benchmarkFactory = AbstractBenchmarkFactoryPtr(new BenchmarkFactory<T>());
			_descriptors.push_back(BenchmarkDescriptorPtr(new BenchmarkDescriptor(benchmarkFactory, benchmark_name, runs, iterations)));
		}
		std::vector<BenchmarkResult> runAll();
	private:
		BenchmarkResult run(BenchmarkDescriptorPtr descriptor);
		std::vector<BenchmarkDescriptorPtr> _descriptors;
	};
	
	typedef std::shared_ptr<BenchmarkRunner> BenchmarkRunnerPtr;
}

#endif