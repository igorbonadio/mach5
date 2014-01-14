# Mach 5

Mach 5 is a minimalist C++11 benchmarking framework.

# Usage

In fact, Mach 5 is just a collection of .hpp and all you need to do is include the Mach5.hpp file.

``` c++
#include "Mach5.hpp"

BENCHMARK(DefaultCppSort, 100, 100, SINGLE) {
  std::vector<int> num = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  std::sort(num.begin(), num.end());
}
```

Pay attention to the parameter list of BENCHMARK macro. The frist is the name of the benchmark, the second is the number of runs, the third is the number of iterations and the last one is the type.

But, the previous benchmark also mensures the creation of the vector num. So, the solution to this problem is create a fixture:

``` c++
#include "Mach5.hpp"

class SortingNumberWith : public ::mach5::BenchmarkFixture {
public:
  std::vector<int> num = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1};
};

BENCHMARK_F(SortingNumberWith, DefaultCppSort, 100, 100, SINGLE) {
  std::sort(num.begin(), num.end());
}
```

Now, it is used the BENCHMARK_F macro, that receives a Fixture class.

But... what is the type parameter?

Currently we have 2 different types:

- SINGLE: It is a single benchmark
- FOR(var_name, start, and): It enables you  to test the same peace of code with diferent inputs, for example:

``` c++
class SortingNumberWith : public ::mach5::BenchmarkFixture {
public:
  std::vector<std::vector<int>> nums = {
    {0, 9, 8, 7, 6, 5},
    {0, 9, 8, 7, 6, 5, 4},
    {0, 9, 8, 7, 6, 5, 4, 3},
    {0, 9, 8, 7, 6, 5, 4, 3, 2},
    {0, 9, 8, 7, 6, 5, 4, 3, 2, 1}
  };
};

BENCHMARK_F(SortingNumberWith, DefaultCppSort, 100, 100, FOR(i, 0, 4)) {
  std::sort(nums[i].begin(), nums[i].end());
}
```

It will mensure the time that std::sort takes to sort each vector of nums.

