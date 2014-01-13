#include <vector>
#include <algorithm>

#include "Mach5.hpp"

// class SortingNumberWith : public ::mach5::BenchmarkFixture {
// public:
// 	std::vector<int> num = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1};
// };

// // Benchmark using a fixture class
// BENCHMARK_F(SortingNumberWith, SelectionSort, 100, 200, SINGLE) {
// 	int tam = num.size();
// 	for (int i = 0; i < (tam-1); i++) {
// 		int min = i;
// 		for (int j = (i+1); j < tam; j++) {
// 			if(num[j] < num[min]) {
// 				min = j;
// 			}
// 		}
// 		if (i != min) {
// 			int swap = num[i];
// 			num[i] = num[min];
// 			num[min] = swap;
// 		}
// 	}
// }

// // A single and simple benchmark
// BENCHMARK(DefaultCppSort, 100, 100, FOR(i, 0, 2)) {
// 	std::vector<int> num = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1};
// 	std::sort(num.begin(), num.end());
// }

class SelectionSortBenchmark : public ::mach5::BenchmarkFixture {
public:
        virtual void code(int i);
};

const auto _SelectionSortBenchmarkFactory = ::mach5::BenchmarkRunner::instance().addBenchmark<SelectionSortBenchmark>("SelectionSort", 100, 100, 0, 0);

void SelectionSortBenchmark::code(int i) {
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

class SortBenchmark : public ::mach5::BenchmarkFixture {
public:
        virtual void code(int i);
};

const auto _SortBenchmarkFactory = ::mach5::BenchmarkRunner::instance().addBenchmark<SortBenchmark>("Sort", 100, 100, 0, 2);

void SortBenchmark::code(int i) {
        std::vector<int> num = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        std::sort(num.begin(), num.end());
}

