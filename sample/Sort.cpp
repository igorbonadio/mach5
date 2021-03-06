#include <vector>
#include <algorithm>

#include "Mach5.hpp"

class SortingNumberWith : public ::mach5::BenchmarkFixture {
public:
	std::vector<int> num = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1};
};

// Benchmark using a fixture class
BENCHMARK_F(SortingNumberWith, SelectionSort, 10, 2, SINGLE) {
	int tam = num.size();
	for (int i = 0; i < (tam-1); i++) {
		int min = i;
		for (int j = (i+1); j < tam; j++) {
			if(num[j] < num[min]) {
				min = j;
			}
		}
		if (i != min) {
			int swap = num[i];
			num[i] = num[min];
			num[min] = swap;
		}
	}
}

// A single and simple benchmark
BENCHMARK(DefaultCppSort, 10, 10, FOR(i, 0, 2)) {
	std::vector<int> num = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	std::sort(num.begin(), num.end());
}
