#ifndef MACH5_BENCHMARK_DESCRIPTOR_HPP 
#define MACH5_BENCHMARK_DESCRIPTOR_HPP 

#include <string>
#include <memory>

#include "Benchmark.hpp"

namespace mach5 {
	class BenchmarkDescriptor {
	public:
		BenchmarkDescriptor(BenchmarkPtr benchmark, std::string benchmark_name, int runs, int iterations):
			_benchmark(benchmark), _benchmark_name(benchmark_name), _runs(runs), _iterations(iterations) {}
		
		BenchmarkPtr benchmark();
		int runs();
		int terations();
		
	private:
		BenchmarkPtr _benchmark;
		std::string _benchmark_name;
		int _runs;
		int _iterations;
	};
	
	typedef std::shared_ptr<BenchmarkDescriptor> BenchmarkDescriptorPtr;
}

#endif