#ifndef MACH5_BENCHMARK_DESCRIPTOR_HPP 
#define MACH5_BENCHMARK_DESCRIPTOR_HPP 

#include <string>
#include <memory>

#include "BenchmarkFactory.hpp"

namespace mach5 {
	class BenchmarkDescriptor {
	public:
		BenchmarkDescriptor(AbstractBenchmarkFactoryPtr benchmarkFactory, std::string benchmark_name, int runs, int iterations):
			_benchmarkFactory(benchmarkFactory), _benchmark_name(benchmark_name), _runs(runs), _iterations(iterations) {}
		
		AbstractBenchmarkFactoryPtr benchmarkFactory();
		int runs();
		int terations();
		
	private:
		AbstractBenchmarkFactoryPtr _benchmarkFactory;
		std::string _benchmark_name;
		int _runs;
		int _iterations;
	};
	
	typedef std::shared_ptr<BenchmarkDescriptor> BenchmarkDescriptorPtr;
}

#endif