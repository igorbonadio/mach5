#include "BenchmarkDescriptor.hpp"

namespace mach5 {
	AbstractBenchmarkFactoryPtr BenchmarkDescriptor::benchmarkFactory() {
		return _benchmarkFactory;
	}
	
	int BenchmarkDescriptor::runs() {
		return _runs;
	}
	
	int BenchmarkDescriptor::iterations() {
		return _iterations;
	}
}