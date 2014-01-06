#ifndef MACH5_BENCHMARK_HPP
#define MACH5_BENCHMARK_HPP

#include <memory>

#include "BenchmarkResult.hpp"

namespace mach5 {
	class Benchmark {
	public:
		virtual void code() = 0;
		double run(int iterations) {
      double total = 0;
      for (int i = 0; i < iterations; i++) {
        auto t1 = std::chrono::high_resolution_clock::now();
        code();
        auto t2 = std::chrono::high_resolution_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
        total += time_span.count();
      }
      return(total/iterations);
    }
	};

	typedef std::shared_ptr<Benchmark> BenchmarkPtr;
}

#endif