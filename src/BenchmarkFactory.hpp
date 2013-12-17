#ifndef MACH5_BENCHMARK_FACTORY_HPP 
#define MACH5_BENCHMARK_FACTORY_HPP 

#include "Benchmark.hpp"

#include <memory>

namespace mach5 {
	
	class AbstractBenchmarkFactory {
	public:
		virtual BenchmarkPtr build() = 0;
	};
	
	typedef std::shared_ptr<AbstractBenchmarkFactory> AbstractBenchmarkFactoryPtr;
	
	template<class T>
	class BenchmarkFactory : public AbstractBenchmarkFactory {
	public:
		virtual BenchmarkPtr build() {
			return BenchmarkPtr(new T());
		}
	};
}

#endif