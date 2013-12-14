#ifndef MACH5_BENCHMARK_HPP 
#define MACH5_BENCHMARK_HPP 

#include <memory>

#include "Result.hpp"

namespace mach5 {
	class Benchmark {
	public:
		virtual void code() = 0;
		Result run();
	};
	
	typedef std::shared_ptr<Benchmark> BenchmarkPtr;
}

#endif