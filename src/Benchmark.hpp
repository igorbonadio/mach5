#ifndef MACH5_BENCHMARK_HPP 
#define MACH5_BENCHMARK_HPP 

#include <memory>

namespace mach5 {
	class Benchmark {
	public:
		virtual void code() = 0;
		void run();
	};
	
	typedef std::shared_ptr<Benchmark> BenchmarkPtr;
}

#endif