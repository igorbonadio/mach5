#ifndef MACH5_BENCHMARK_RESULT_HPP
#define MACH5_BENCHMARK_RESULT_HPP

#include <string>
#include <chrono>
#include <sstream>

namespace mach5 {
	class BenchmarkResult {
	public:
		BenchmarkResult(std::string benchmark_name, int runs, int iterations, double duration, int index):
			_benchmark_name(benchmark_name),_runs(runs),_iterations(iterations),_duration(duration), _index(index) {}

		std::string json() {
			std::ostringstream output;
			output << "{\"runs\": " << _runs << ", ";
			output << "\"iterations\": " << _iterations << ", ";
			output << "\"duration\": " << _duration << ", ";
			output << "\"index\": " << _index << "}";
			return output.str();
		}

	private:
		std::string _benchmark_name;
		int _runs;
		int _iterations;
		int _index;
		double _duration;
	};
}

#endif