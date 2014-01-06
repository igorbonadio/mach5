#ifndef MACH5_BENCHMARK_RESULT_HPP
#define MACH5_BENCHMARK_RESULT_HPP

#include <string>
#include <chrono>
#include <sstream>

namespace mach5 {
	class BenchmarkResult {
	public:
		BenchmarkResult(std::string benchmark_name, int runs, int iterations, double duration):_benchmark_name(benchmark_name),_runs(runs),_iterations(iterations),_duration(duration) {}

		std::string yaml() {
			std::ostringstream output;
			output << _benchmark_name << ":" << std::endl;
			output << "\truns: " << _runs << std::endl;
			output << "\titerations: " << _iterations << std::endl;
			output << "\tduration: " << _duration << std::endl;
			return output.str();
		}

	private:
		std::string _benchmark_name;
		int _runs;
		int _iterations;
		double _duration;
	};
}

#endif