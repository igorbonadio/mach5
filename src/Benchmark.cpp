#include "Benchmark.hpp"

#include <chrono>

namespace mach5 {
	Result Benchmark::run() {
		auto t1 = std::chrono::high_resolution_clock::now();
		code();
		auto t2 = std::chrono::high_resolution_clock::now();
		return(Result(t1, t2));
	}
}