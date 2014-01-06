#ifndef MACH5_HPP
#define MACH5_HPP

#include "Benchmark.hpp"
#include "BenchmarkRunner.hpp"

using namespace mach5;

#define _BENCHMARK_NAME(benchmark_name) \
  benchmark_name ## Benchmark

#define _BENCHMARK_FACTORY_NAME(benchmark_name) \
  _ ## benchmark_name ## BenchmarkFactory

#define _BENCHMARK_CLASS(benchmark_name) \
  class _BENCHMARK_NAME(benchmark_name) : public Benchmark { \
  public: \
    virtual void code(); \
  };

#define _BENCHMARK_FACTORY(benchmark_name, benchmark_runs, benchmark_iterations) \
  const auto _BENCHMARK_FACTORY_NAME(benchmark_name) = BenchmarkRunner::instance().addBenchmark<_BENCHMARK_NAME(benchmark_name)>(#benchmark_name, benchmark_runs, benchmark_iterations);

#define _BENCHMARK_CODE(benchmark_name) \
  void _BENCHMARK_NAME(benchmark_name)::code()

#define BENCHMARK(benchmark_name, benchmark_runs, benchmark_iterations) \
  _BENCHMARK_CLASS(benchmark_name) \
  _BENCHMARK_FACTORY(benchmark_name, benchmark_runs, benchmark_iterations) \
  _BENCHMARK_CODE(benchmark_name)

#endif