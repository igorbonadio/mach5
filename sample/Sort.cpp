#include <iostream>
#include <vector>
#include <algorithm>

#include "Benchmark.hpp"
#include "BenchmarkRunner.hpp"

using namespace mach5;

class SelectionSortBenchmark : public Benchmark {
public:
	virtual void code();
};

const auto _SelectionSortBenchmarkFactory = BenchmarkRunner::instance().addBenchmark<SelectionSortBenchmark>("SelectionSort", 100, 100);

void SelectionSortBenchmark::code() {
	std::vector<int> num = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1};
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

class SortBenchmark : public Benchmark {
public:
	virtual void code();
};

const auto _SortBenchmarkFactory = BenchmarkRunner::instance().addBenchmark<SortBenchmark>("Sort", 100, 100);

void SortBenchmark::code() {
	std::vector<int> num = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	std::sort(num.begin(), num.end());
}

int main() {
	auto results = BenchmarkRunner::instance().runAll();
	for (auto result : results)
		std::cout << result.yaml();
}
