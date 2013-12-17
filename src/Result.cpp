#include "Result.hpp"

#include <iostream>

namespace mach5 {
	double Result::duration() {
		return _duration;
	}
	void Result::str() {
		std::cout << _duration << std::endl;
	}
}