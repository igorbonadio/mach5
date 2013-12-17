#include "Benchmark.hpp"

#include <chrono>

namespace mach5 {
	BenchmarkResult Benchmark::run() {
		auto t1 = std::chrono::high_resolution_clock::now();
		code();
		auto t2 = std::chrono::high_resolution_clock::now();
		auto time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
		return(BenchmarkResult(time_span.count()));
	}
}