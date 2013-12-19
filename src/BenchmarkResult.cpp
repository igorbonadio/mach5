#include "BenchmarkResult.hpp"

#include <sstream>

namespace mach5 {
	std::string BenchmarkResult::yaml() {
		std::ostringstream output;
		output << _benchmark_name << ":" << std::endl;
		output << "\truns: " << _runs << std::endl;
		output << "\titerations: " << _iterations << std::endl;
		output << "\tduration: " << _duration << std::endl;
		return output.str();
	}
}