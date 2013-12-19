#include "BenchmarkResult.hpp"

#include <iostream>

namespace mach5 {
	void BenchmarkResult::yaml() {
		std::cout << _benchmark_name << ":" << std::endl;
		std::cout << "\truns: " << _runs << std::endl;
		std::cout << "\titerations: " << _iterations << std::endl;
		std::cout << "\tduration: " << _duration << std::endl;
	}
}