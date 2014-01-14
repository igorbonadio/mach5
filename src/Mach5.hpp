#ifndef MACH5_HPP
#define MACH5_HPP

#include <iostream>
#include <sstream>

#include "Util.hpp"
#include "Benchmark.hpp"
#include "BenchmarkRunner.hpp"

#define FOR(var_name, start, end) \
  var_name, start, end

#define SINGLE \
  index, 0, 0

// with fixture

#define _BENCHMARK_F_NAME(benchmark_fixture, benchmark_name) \
  benchmark_fixture ## benchmark_name ## Benchmark

#define _BENCHMARK_F_FACTORY_NAME(benchmark_fixture, benchmark_name) \
  _ ## benchmark_fixture ## benchmark_name ## BenchmarkFactory


#define _BENCHMARK_F_CLASS(benchmark_fixture, benchmark_name) \
  class _BENCHMARK_F_NAME(benchmark_fixture, benchmark_name) : public benchmark_fixture { \
  public: \
    virtual void code(int index); \
  };

#define _BENCHMARK_F_FACTORY(benchmark_fixture, benchmark_name, benchmark_runs, benchmark_iterations, start, end) \
  const auto _BENCHMARK_F_FACTORY_NAME(benchmark_fixture, benchmark_name) = ::mach5::BenchmarkRunner::instance().addBenchmark<_BENCHMARK_F_NAME(benchmark_fixture, benchmark_name)>(#benchmark_fixture#benchmark_name, benchmark_runs, benchmark_iterations, start, end);

#define _BENCHMARK_F_CODE(benchmark_fixture, benchmark_name, var_name) \
  void _BENCHMARK_F_NAME(benchmark_fixture, benchmark_name)::code(int var_name)

#define _BENCHMARK_F_FACTORY_AND_CODE(var_name, start, end, benchmark_fixture, benchmark_name, benchmark_runs, benchmark_iterations) \
  _BENCHMARK_F_FACTORY(benchmark_fixture, benchmark_name, benchmark_runs, benchmark_iterations, start, end) \
  _BENCHMARK_F_CODE(benchmark_fixture, benchmark_name, var_name)

#define BENCHMARK_F(benchmark_fixture, benchmark_name, benchmark_runs, benchmark_iterations, type) \
  _BENCHMARK_F_CLASS(benchmark_fixture, benchmark_name) \
  _BENCHMARK_F_FACTORY_AND_CODE(type, benchmark_fixture, benchmark_name, benchmark_runs, benchmark_iterations)

// without fixture

#define _BENCHMARK_NAME(benchmark_name) \
  benchmark_name ## Benchmark

#define _BENCHMARK_FACTORY_NAME(benchmark_name) \
  benchmark_name ## BenchmarkFactory

#define _BENCHMARK_CLASS(benchmark_name) \
  class _BENCHMARK_NAME(benchmark_name) : public ::mach5::Benchmark { \
  public: \
    virtual void code(int index); \
  };

#define _BENCHMARK_FACTORY(benchmark_name, benchmark_runs, benchmark_iterations, start, end) \
  const auto _BENCHMARK_FACTORY_NAME(benchmark_name) = ::mach5::BenchmarkRunner::instance().addBenchmark<_BENCHMARK_NAME(benchmark_name)>(#benchmark_name, benchmark_runs, benchmark_iterations, start, end);

#define _BENCHMARK_CODE(benchmark_name, var_name) \
  void _BENCHMARK_NAME(benchmark_name)::code(int var_name)

#define _BENCHMARK_FACTORY_AND_CODE(var_name, start, end, benchmark_name, benchmark_runs, benchmark_iterations) \
  _BENCHMARK_FACTORY(benchmark_name, benchmark_runs, benchmark_iterations, start, end) \
  _BENCHMARK_CODE(benchmark_name, var_name)

#define BENCHMARK(benchmark_name, benchmark_runs, benchmark_iterations, type) \
  _BENCHMARK_CLASS(benchmark_name) \
  _BENCHMARK_FACTORY_AND_CODE(type, benchmark_name, benchmark_runs, benchmark_iterations)

// main

#define RUN_ALL_BENCHMARKS(argc, argv) \
  std::cout << ::mach5::Util().toJson(::mach5::BenchmarkRunner::instance().runAll()) << std::endl;


#endif