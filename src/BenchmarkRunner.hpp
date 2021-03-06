#ifndef MACH5_BENCHMARK_RUNNER_HPP
#define MACH5_BENCHMARK_RUNNER_HPP

#include <vector>
#include <map>
#include <string>
#include <memory>
#include <iostream>
#include <stdlib.h>

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
			InputParameters params = Util().inputOptions(argc, argv);

			if (!params.options["color"])
				RED = GREEN = YELLOW = DEFAULT = "";

			switch(params.command){
				case 1: exit(0);
				case 2:
					for (auto _descriptor : _descriptors) {
						std::cout << _descriptor->name() << std::endl;
					}
					break;
				case 3:
					std::cerr << GREEN << "[==========] " << DEFAULT << "Running " << _argnames.size() << " benchmarks" << std::endl << std::endl;
					for (auto _descriptor : _descriptors) {
						if (in(_descriptor->name(), _argnames))
							results[_descriptor->name()] = run(_descriptor);
					}
					std::cerr << GREEN << "[==========] " << DEFAULT << _argnames.size() << " benchmarks ran" << std::endl;
					break;
				default:
					std::cerr << GREEN << "[==========] " << DEFAULT << "Running " << _descriptors.size() << " benchmarks" << std::endl << std::endl;
					for (auto _descriptor : _descriptors) {
						results[_descriptor->name()] = run(_descriptor);
					}
					std::cerr << GREEN << "[==========] " << DEFAULT << _descriptors.size() << " benchmarks ran" << std::endl;
					break;
			}
			return results;
		}

		static BenchmarkRunner& instance() {
			static BenchmarkRunner singleton;
			return singleton;
		}
	private:

		std::string RED = "\x1b[31m";
		std::string GREEN = "\x1b[32m";
		std::string YELLOW = "\x1b[33m";
		std::string DEFAULT = "\x1b[0m";

		std::vector<BenchmarkResult> run(BenchmarkDescriptorPtr descriptor) {
			std::cerr << GREEN << "[----------] " << DEFAULT << "For i = " << descriptor->start() << "..." << descriptor->end() << std::endl;
			std::vector<BenchmarkResult> results;
			double final_time = 0;
			for (int index = descriptor->start(); index <= descriptor->end(); index++) {
				std::cerr << GREEN << "[ RUN      ] " << DEFAULT << descriptor->name() << "[" << index << "]" << std::endl;
				std::cerr << GREEN << "[ PROGRESS ] " << YELLOW;

				std::vector<std::vector<double>> run_times;
				for (int i = 0; i < descriptor->runs(); i++) {
					run_times.push_back(descriptor->benchmarkFactory()->build()->run(descriptor->iterations(), index));
				}


				double total_time = runsTotalTime(run_times);
				final_time += total_time;
				double runs_average_time = runsAverageTime(run_times);
				double runs_fastest = runsFastest(run_times);
				double runs_slowest = runsSlowest(run_times);
				double iterations_average_time = iterationsAverageTime(run_times);
				double iterations_fastest = iterationsFastest(run_times);
				double iterations_slowest = iterationsSlowest(run_times);

				results.push_back(BenchmarkResult(descriptor->name(),
					                                descriptor->runs(),
					                                descriptor->iterations(),
					                                index,
					                                total_time,
					                                runs_average_time,
					                                runs_fastest,
					                                runs_slowest,
					                                iterations_average_time,
					                                iterations_fastest,
					                                iterations_slowest));

				std::cerr << std::endl;
				std::cerr << GREEN << "[     DONE ] " << DEFAULT << descriptor->name() << "[" << index << "]" << " (" << total_time << " s)" << std::endl;
				std::cerr << GREEN << "[ RUNS     ] " << DEFAULT << "Average time: " << runs_average_time << " s" << std::endl;
				std::cerr << DEFAULT << "                  Fastest: " << runs_fastest << " s" << std::endl;
				std::cerr << DEFAULT << "                  Slowest: " << runs_slowest << " s" << std::endl;
				std::cerr << GREEN << "[ITERATIONS] " << DEFAULT << "Average time: " << iterations_average_time << " s" << std::endl;
				std::cerr << DEFAULT << "                  Fastest: " << iterations_fastest << " s" << std::endl;
				std::cerr << DEFAULT << "                  Slowest: " << iterations_slowest << " s" << std::endl;
			}
			std::cerr << GREEN << "[----------] " << DEFAULT << "End (" << final_time << " s)" << std::endl;
			std::cerr << std::endl;
			return results;
		}

		double iterationsAverageTime(std::vector<std::vector<double>> results) {
			double total = 0;
			int num = 0;
			for (auto run : results) {
				for (auto iteration: run) {
					total += iteration;
					num++;
				}
			}
			return total/num;
		}

		double iterationsSlowest(std::vector<std::vector<double>> results) {
			double max = 0;
			for (auto run : results) {
				for (auto iteration: run) {
					if (max < iteration)
						max = iteration;
				}
			}
			return max;
		}

		double iterationsFastest(std::vector<std::vector<double>> results) {
			double min = results[0][0];
			for (auto run : results) {
				for (auto iteration: run) {
					if (min > iteration)
						min = iteration;
				}
			}
			return min;
		}

		double runsTotalTime(std::vector<std::vector<double>> results) {
			double total = 0;
			for (auto run : results) {
				total += runTotalTime(run);
			}
			return total;
		}

		double runsAverageTime(std::vector<std::vector<double>> results) {
			return runsTotalTime(results)/results.size();
		}

		double runsFastest(std::vector<std::vector<double>> results) {
			double max = runTotalTime(results[0]);
			for (auto run : results) {
				auto current = runTotalTime(run);
				if (max > current)
					max = current;
			}
			return max;
		}

		double runsSlowest(std::vector<std::vector<double>> results) {
			double min = 0;
			for (auto run : results) {
				auto current = runTotalTime(run);
				if (min < current)
					min = current;
			}
			return min;
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