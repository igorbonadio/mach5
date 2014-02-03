#ifndef MACH5_BENCHMARK_RUNNER_HPP
#define MACH5_BENCHMARK_RUNNER_HPP

#include <vector>
#include <map>
#include <string>
#include <memory>
#include <iostream>

#include "Benchmark.hpp"
#include "BenchmarkDescriptor.hpp"
#include "BenchmarkFactory.hpp"
#include "Util.hpp"

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

		std::map<std::string, std::vector<BenchmarkResult>> runAll(int argc, char** argv) {
			std::map<std::string, std::vector<BenchmarkResult>> results;
			std::vector<std::string> _argnames = argnames(argc, argv);
			switch(Util().inputOptions(argc, argv)){
				case 1: exit(0);
				case 2:
					for (auto _descriptor : _descriptors) {
						std::cout << _descriptor->name() << std::endl;
					}
					break;
				case 3:
					std::cerr << "[==========] Running " << _argnames.size() << " benchmarks" << std::endl << std::endl;
					for (auto _descriptor : _descriptors) {
						if (in(_descriptor->name(), _argnames))
							results[_descriptor->name()] = run(_descriptor);
					}
					std::cerr << "[==========] " << _argnames.size() << " benchmarks ran (TODO s)" << std::endl;
					break;
				default:
					std::cerr << "[==========] Running " << _descriptors.size() << " benchmarks" << std::endl << std::endl;
					for (auto _descriptor : _descriptors) {
						results[_descriptor->name()] = run(_descriptor);
					}
					std::cerr << "[==========] " << _descriptors.size() << " benchmarks ran (TODO s)" << std::endl;
					break;
			}
			return results;
		}

		static BenchmarkRunner& instance() {
			static BenchmarkRunner singleton;
			return singleton;
		}
	private:
		std::vector<BenchmarkResult> run(BenchmarkDescriptorPtr descriptor) {
			std::cerr << "[----------] For i = " << descriptor->start() << "..." << descriptor->end() << std::endl;
			std::vector<BenchmarkResult> results;
			for (int index = descriptor->start(); index <= descriptor->end(); index++) {
				std::cerr << "[ RUN      ] " << descriptor->name() << "[" << index << "]" << std::endl;
				std::cerr << "[ PROGRESS ] ";
				double total = 0;
				std::vector<std::vector<double>> run_times;
				for (int i = 0; i < descriptor->runs(); i++) {
					run_times.push_back(descriptor->benchmarkFactory()->build()->run(descriptor->iterations(), index));
				}
				std::cerr << std::endl;
				std::cerr << "[     DONE ] " << descriptor->name() << "[" << index << "]" << " (TODO s)" << std::endl;
				results.push_back(BenchmarkResult(descriptor->name(), descriptor->runs(), descriptor->iterations(), total/descriptor->runs(), index));
				std::cerr << "[ RUNS     ] Average time: " << runsAverageTime(run_times) << " s" << std::endl;
				std::cerr << "                  Fastest: TODO s" << std::endl;
				std::cerr << "                  Slowest: TODO s" << std::endl;
				std::cerr << "[ITERATIONS] Average time: TODO s" << std::endl;
				std::cerr << "                  Fastest: TODO s" << std::endl;
				std::cerr << "                  Slowest: TODO s" << std::endl;
			}
			std::cerr << "[----------] End (TODO s)" << std::endl;
			std::cerr << std::endl;
			return results;
		}

		double runsAverageTime(std::vector<std::vector<double>> results) {
			double total = 0;
			for (auto run : results) {
				total += runTotalTime(run);
			}
			return total/results.size();
		}

		double runTotalTime(std::vector<double> run) {
			double total;
			for(auto iteration : run) {
				total += iteration;
			}
			return total;
		}

		std::vector<std::string> argnames(int argc, char** argv) {
			std::vector<std::string> names;
			for (int i = 2; i < argc; i++) {
				names.push_back(std::string(argv[i]));
			}
			return names;
		}

		bool in(std::string name, std::vector<std::string> names) {
			for (auto n : names) {
				if (name == n) return true;
			}
			return false;
		}

		std::vector<BenchmarkDescriptorPtr> _descriptors;
	};

	typedef std::shared_ptr<BenchmarkRunner> BenchmarkRunnerPtr;
}

#endif