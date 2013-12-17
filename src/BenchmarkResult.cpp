#include "BenchmarkResult.hpp"

#include <iostream>

namespace mach5 {
	double BenchmarkResult::duration() {
		return _duration;
	}
	void BenchmarkResult::str() {
		std::cout << _duration << std::endl;
	}
}