#ifndef MACH5_BENCHMARK_DESCRIPTOR_HPP 
#define MACH5_BENCHMARK_DESCRIPTOR_HPP 

#include <string>
#include <memory>

#include "Benchmark.hpp"

namespace mach5 {
	class BenchmarkDescriptor {
	public:
		BenchmarkDescriptor(BenchmarkPtr benchmark, std::string benchmark_name):_benchmark(benchmark), _benchmark_name(benchmark_name) {}
		
		BenchmarkPtr benchmark() {
			return _benchmark;
		}
		
	private:
		BenchmarkPtr _benchmark;
		std::string _benchmark_name;
	};
	
	typedef std::shared_ptr<BenchmarkDescriptor> BenchmarkDescriptorPtr;
}

#endif