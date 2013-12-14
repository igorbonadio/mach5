#include "BenchmarkRunner.hpp"

namespace mach5 {
	void BenchmarkRunner::addBenchmark(BenchmarkPtr benchmark) {
		_benchmarks.push_back(benchmark);
	}
	
	void BenchmarkRunner::runAll() {
		for (auto benchmark : _benchmarks) {
			auto result = benchmark->run();
			result.str();
		}
	}
}