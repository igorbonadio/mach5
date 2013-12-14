#include "Result.hpp"

#include <iostream>

namespace mach5 {
	void Result::str() {
		auto time_span = std::chrono::duration_cast<std::chrono::duration<double>>(_t2 - _t1);
		std::cout << time_span.count() << std::endl;
	}
}