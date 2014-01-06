#ifndef MACH5_HPP
#define MACH5_HPP

#include "Benchmark.hpp"
#include "BenchmarkRunner.hpp"

#define _BENCHMARK_F_NAME(benchmark_fixture, benchmark_name) \
  benchmark_fixture ## benchmark_name ## Benchmark

#define _BENCHMARK_F_FACTORY_NAME(benchmark_fixture, benchmark_name) \
  _ ## benchmark_fixture ## benchmark_name ## BenchmarkFactory


#define _BENCHMARK_F_CLASS(benchmark_fixture, benchmark_name) \
  class _BENCHMARK_F_NAME(benchmark_fixture, benchmark_name) : public benchmark_fixture { \
  public: \
    virtual void code(); \
  };

#define _BENCHMARK_F_FACTORY(benchmark_fixture, benchmark_name, benchmark_runs, benchmark_iterations) \
  const auto _BENCHMARK_F_FACTORY_NAME(benchmark_fixture, benchmark_name) = ::mach5::BenchmarkRunner::instance().addBenchmark<_BENCHMARK_F_NAME(benchmark_fixture, benchmark_name)>(#benchmark_fixture#benchmark_name, benchmark_runs, benchmark_iterations);

#define _BENCHMARK_F_CODE(benchmark_fixture, benchmark_name) \
  void _BENCHMARK_F_NAME(benchmark_fixture, benchmark_name)::code()

#define BENCHMARK_F(benchmark_fixture, benchmark_name, benchmark_runs, benchmark_iterations) \
  _BENCHMARK_F_CLASS(benchmark_fixture, benchmark_name) \
  _BENCHMARK_F_FACTORY(benchmark_fixture, benchmark_name, benchmark_runs, benchmark_iterations) \
  _BENCHMARK_F_CODE(benchmark_fixture, benchmark_name)

#define _BENCHMARK_NAME(benchmark_name) \
  benchmark_name ## Benchmark

#define _BENCHMARK_FACTORY_NAME(benchmark_name) \
  benchmark_name ## BenchmarkFactory

#define _BENCHMARK_CLASS(benchmark_name) \
  class _BENCHMARK_NAME(benchmark_name) : public ::mach5::Benchmark { \
  public: \
    virtual void code(); \
  };

#define _BENCHMARK_FACTORY(benchmark_name, benchmark_runs, benchmark_iterations) \
  const auto _BENCHMARK_FACTORY_NAME(benchmark_name) = ::mach5::BenchmarkRunner::instance().addBenchmark<_BENCHMARK_NAME(benchmark_name)>(#benchmark_name, benchmark_runs, benchmark_iterations);

#define _BENCHMARK_CODE(benchmark_name) \
  void _BENCHMARK_NAME(benchmark_name)::code()

#define BENCHMARK(benchmark_name, benchmark_runs, benchmark_iterations) \
  _BENCHMARK_CLASS(benchmark_name) \
  _BENCHMARK_FACTORY(benchmark_name, benchmark_runs, benchmark_iterations) \
  _BENCHMARK_CODE(benchmark_name)

#endif