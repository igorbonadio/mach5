#include "Benchmark.hpp"

#include <chrono>

namespace mach5 {
	BenchmarkResult Benchmark::run(int iterations) {
		double total = 0;
		for (int i = 0; i < iterations; i++) {
			auto t1 = std::chrono::high_resolution_clock::now();
			code();
			auto t2 = std::chrono::high_resolution_clock::now();
			auto time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
			total += time_span.count();
		}
		return(BenchmarkResult(total/iterations));
	}
}