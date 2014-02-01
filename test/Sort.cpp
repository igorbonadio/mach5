#include <vector>
#include <algorithm>

#include "Mach5.hpp"

class Fixture1 : public ::mach5::BenchmarkFixture {
public:
	std::vector<int> num = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1};
};

class Fixture2 : public ::mach5::BenchmarkFixture {
public:
	std::vector<std::vector<int>> num = {
		{0, 9, 8, 7, 6},
		{0, 9, 8, 7, 6, 5, 4},
		{0, 9, 8, 7, 6, 5, 4, 3, 2, 1}
	};
};

class Fixture1Single : public Fixture1 {
public:
  virtual void code(int index) {
  	std::sort(num.begin(), num.end());
  }
};
const auto FactoryFixture1Single = ::mach5::BenchmarkRunner::instance().addBenchmark<Fixture1Single>("Fixture1.Single", 10, 2, 0, 0);

class Fixture2For : public Fixture2 {
public:
  virtual void code(int index) {
  	std::sort(num[index].begin(), num[index].end());
  }
};
const auto FactoryFixture2For = ::mach5::BenchmarkRunner::instance().addBenchmark<Fixture2For>("Fixture2.For", 10, 2, 0, 2);

class Single : public ::mach5::Benchmark {
public:
  virtual void code(int index) {
  	std::vector<int> num = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1};
		std::sort(num.begin(), num.end());
  }
};
const auto FactorySingle = ::mach5::BenchmarkRunner::instance().addBenchmark<Single>("Single", 10, 2, 0, 0);

class For : public ::mach5::Benchmark {
public:
  virtual void code(int index) {
  	std::vector<std::vector<int>> num = {
			{0, 9, 8, 7, 6},
			{0, 9, 8, 7, 6, 5, 4},
			{0, 9, 8, 7, 6, 5, 4, 3, 2, 1}
		};
		std::sort(num[index].begin(), num[index].end());
  }
};
const auto FactoryFor = ::mach5::BenchmarkRunner::instance().addBenchmark<For>("For", 10, 2, 0, 2);
