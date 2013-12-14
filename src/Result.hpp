#ifndef MACH5_RESULT_HPP 
#define MACH5_RESULT_HPP 

#include <chrono>

namespace mach5 {
	class Result {
	public:
		Result(std::chrono::high_resolution_clock::time_point t1, std::chrono::high_resolution_clock::time_point t2):_t1(t1),_t2(t2) {}
		void str();
	private:
		std::chrono::high_resolution_clock::time_point _t1;
		std::chrono::high_resolution_clock::time_point _t2;
	};
}

#endif