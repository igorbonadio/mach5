#include "BenchmarkRunner.hpp"

namespace mach5 {
	void BenchmarkRunner::addBenchmark(BenchmarkPtr benchmark, std::string benchmark_name) {
		_descriptors.push_back(BenchmarkDescriptorPtr(new BenchmarkDescriptor(benchmark, benchmark_name)));
	}
	
	std::vector<Result> BenchmarkRunner::runAll() {
		std::vector<Result> results;
		for (auto _descriptor : _descriptors) {
			results.push_back(_descriptor->benchmark()->run());
		}
		return results;
	}
}