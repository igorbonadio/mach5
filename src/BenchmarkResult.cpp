#include "BenchmarkResult.hpp"

#include <iostream>

namespace mach5 {
	void BenchmarkResult::str() {
		std::cout << _duration << std::endl;
	}
}