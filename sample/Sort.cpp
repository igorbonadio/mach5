#include <iostream>
#include <vector>

#include "Benchmark.hpp"

using namespace mach5;

class SelectionSortBenchmark : public Benchmark {
public:
	virtual void run();
};

void SelectionSortBenchmark::run() {
	std::cout << "Running..." << std::endl;
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

int main() {
	BenchmarkPtr bench = BenchmarkPtr(new SelectionSortBenchmark());
	bench->run();
}