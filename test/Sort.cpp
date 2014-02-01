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

BENCHMARK_F(Fixture1, Single, 10, 2, SINGLE) {
	std::sort(num.begin(), num.end());
}

BENCHMARK_F(Fixture2, For, 10, 2, FOR(i, 0, 2)) {
	std::sort(num[i].begin(), num[i].end());
}

BENCHMARK(Single, 10, 2, SINGLE) {
	std::vector<int> num = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	std::sort(num.begin(), num.end());
}

BENCHMARK(For, 10, 2, FOR(i, 0, 2)) {
	std::vector<std::vector<int>> num = {
		{0, 9, 8, 7, 6},
		{0, 9, 8, 7, 6, 5, 4},
		{0, 9, 8, 7, 6, 5, 4, 3, 2, 1}
	};
	std::sort(num[i].begin(), num[i].end());
}