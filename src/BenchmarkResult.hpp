#ifndef MACH5_BENCHMARK_RESULT_HPP 
#define MACH5_BENCHMARK_RESULT_HPP 

#include <chrono>

namespace mach5 {
	class BenchmarkResult {
	public:
		BenchmarkResult(double duration):_duration(duration) {}
		double duration();
		void str();
	private:
		double _duration;
	};
}

#endif