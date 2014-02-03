#ifndef MACH5_BENCHMARK_RESULT_HPP
#define MACH5_BENCHMARK_RESULT_HPP

#include <string>
#include <chrono>
#include <sstream>

namespace mach5 {
	class BenchmarkResult {
	public:
		BenchmarkResult(std::string benchmark_name,
			              int runs,
			              int iterations,
			              int index,
			              double runs_total_time,
			              double runs_average_time,
			              double runs_fastest,
			              double runs_slowest,
			              double iterations_average_time,
			              double iterations_fastest,
			              double iterations_slowest):
		_benchmark_name(benchmark_name),
		_runs(runs),_iterations(iterations),
		_index(index),
		_runs_total_time(runs_total_time),
		_runs_average_time(runs_average_time),
		_runs_fastest(runs_fastest),
		_runs_slowest(runs_slowest),
		_iterations_average_time(iterations_average_time),
		_iterations_fastest(iterations_fastest),
		_iterations_slowest(iterations_slowest) {}

		std::string json() {
			std::ostringstream output;
			output << "{\"runs\": " << _runs << ", ";
			output << "\"iterations\": " << _iterations << ", ";
			output << "\"index\": " << _index << ",";
			output << "\"runs_total_time\": " << _runs_total_time << ", ";
      output << "\"runs_average_time\": " << _runs_average_time << ", ";
      output << "\"runs_fastest\": " << _runs_fastest << ", ";
      output << "\"runs_slowest\": " << _runs_slowest << ", ";
      output << "\"iterations_average_time\": " << _iterations_average_time << ", ";
      output << "\"iterations_fastest\": " << _iterations_fastest << ", ";
      output << "\"iterations_slowest\": " << _iterations_slowest << "}";
			return output.str();
		}

	private:
		std::string _benchmark_name;
		int _runs;
		int _iterations;
		int _index;
		double _runs_total_time;
		double _runs_average_time;
		double _runs_fastest;
		double _runs_slowest;
		double _iterations_average_time;
		double _iterations_fastest;
		double _iterations_slowest;
	};
}

#endif