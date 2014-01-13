#ifndef MACH5_BENCHMARK_RUNNER_HPP
#define MACH5_BENCHMARK_RUNNER_HPP

#include <vector>
#include <map>
#include <string>
#include <memory>

#include "Benchmark.hpp"
#include "BenchmarkDescriptor.hpp"
#include "BenchmarkFactory.hpp"

namespace mach5 {
	class BenchmarkRunner {
	public:
		// void addBenchmark(AbstractBenchmarkFactory benchmark, std::string benchmark_name, int runs, int iterations);
		template <class T>
		AbstractBenchmarkFactoryPtr addBenchmark(std::string benchmark_name, int runs, int iterations, int start, int end) {
			AbstractBenchmarkFactoryPtr benchmarkFactory = AbstractBenchmarkFactoryPtr(new BenchmarkFactory<T>());
			_descriptors.push_back(BenchmarkDescriptorPtr(new BenchmarkDescriptor(benchmarkFactory, benchmark_name, runs, iterations, start, end)));
			return benchmarkFactory;
		}

		std::map<std::string, std::vector<BenchmarkResult>> runAll() {
			std::map<std::string, std::vector<BenchmarkResult>> results;
			for (auto _descriptor : _descriptors) {
				results[_descriptor->name()] = run(_descriptor);
			}
			return results;
		}

		static BenchmarkRunner& instance() {
			static BenchmarkRunner singleton;
			return singleton;
		}
	private:
		std::vector<BenchmarkResult> run(BenchmarkDescriptorPtr descriptor) {
			std::vector<BenchmarkResult> results;
			for (int i = descriptor->start(); i <= descriptor->end(); i++) {
				double total = 0;
				for (int i = 0; i < descriptor->runs(); i++) {
					total += descriptor->benchmarkFactory()->build()->run(descriptor->iterations(), i);
				}
				results.push_back(BenchmarkResult(descriptor->name(), descriptor->runs(), descriptor->iterations(), total/descriptor->runs(), i));
			}
			return results;
		}

		std::vector<BenchmarkDescriptorPtr> _descriptors;
	};

	typedef std::shared_ptr<BenchmarkRunner> BenchmarkRunnerPtr;
}

#endif