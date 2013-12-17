#include "BenchmarkRunner.hpp"

namespace mach5 {
	std::vector<BenchmarkResult> BenchmarkRunner::runAll() {
		std::vector<BenchmarkResult> results;
		for (auto _descriptor : _descriptors) {
			results.push_back(run(_descriptor));
		}
		return results;
	}
	
	BenchmarkResult BenchmarkRunner::run(BenchmarkDescriptorPtr descriptor) {
		double total = 0;
		for (int i = 0; i < descriptor->runs(); i++) {
			BenchmarkResult r = descriptor->benchmarkFactory()->build()->run();
			total += r.duration();
		}
		return BenchmarkResult(total/descriptor->runs());
	}
}