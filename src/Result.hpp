#ifndef MACH5_RESULT_HPP 
#define MACH5_RESULT_HPP 

#include <chrono>

namespace mach5 {
	class Result {
	public:
		Result(double duration):_duration(duration) {}
		double duration();
		void str();
	private:
		double _duration;
	};
}

#endif