#include "BenchmarkRunner.hpp"

namespace mach5 {
	void BenchmarkRunner::addBenchmark(BenchmarkPtr benchmark, std::string benchmark_name, int runs, int iterations) {
		_descriptors.push_back(BenchmarkDescriptorPtr(new BenchmarkDescriptor(benchmark, benchmark_name, runs, iterations)));
	}
	
	std::vector<Result> BenchmarkRunner::runAll() {
		std::vector<Result> results;
		for (auto _descriptor : _descriptors) {
			results.push_back(run(_descriptor));
		}
		return results;
	}
	
	Result BenchmarkRunner::run(BenchmarkDescriptorPtr descriptor) {
		double total = 0;
		for (int i = 0; i < descriptor->runs(); i++) {
			Result r = descriptor->benchmark()->run();
			total += r.duration();
		}
		return Result(total/descriptor->runs());
	}
}