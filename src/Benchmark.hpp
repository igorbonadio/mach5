#ifndef MACH5_BENCHMARK_HPP
#define MACH5_BENCHMARK_HPP

#include <memory>
#include <iostream>
#include <vector>

#include "BenchmarkResult.hpp"

namespace mach5 {
	class Benchmark {
	public:
		virtual void code(int i) = 0;
    virtual void setUp() {};
    virtual void tearDown() {};

		std::vector<double> run(int iterations, int index) {
      double total = 0;
      std::vector<double> iteration_times;
      for (int i = 0; i < iterations; i++) {
        setUp();
        auto t1 = std::chrono::high_resolution_clock::now();
        std::cerr << ".";
        code(index);
        auto t2 = std::chrono::high_resolution_clock::now();
        tearDown();
        auto time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
        iteration_times.push_back(time_span.count());
      }
      return(iteration_times);
    }
	};

	typedef std::shared_ptr<Benchmark> BenchmarkPtr;
  typedef Benchmark BenchmarkFixture;
}

#endif