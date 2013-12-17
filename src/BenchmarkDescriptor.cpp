#include "BenchmarkDescriptor.hpp"

namespace mach5 {
	BenchmarkPtr BenchmarkDescriptor::benchmark() {
		return _benchmark;
	}
	
	int BenchmarkDescriptor::runs() {
		return _runs;
	}
	
	int BenchmarkDescriptor::terations() {
		return _iterations;
	}
}