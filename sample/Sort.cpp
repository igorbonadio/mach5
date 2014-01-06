#include <iostream>
#include <vector>
#include <algorithm>

#include "Mach5.hpp"

BENCHMARK(SelectionSort, 100, 200) {
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

BENCHMARK(Sort, 100, 100) {
	std::vector<int> num = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	std::sort(num.begin(), num.end());
}

int main() {
	auto results = BenchmarkRunner::instance().runAll();
	for (auto result : results)
		std::cout << result.yaml();
}
