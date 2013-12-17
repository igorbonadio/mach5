set(sources
   Benchmark.cpp
	 BenchmarkRunner.cpp
	 BenchmarkResult.cpp
   )

add_library(mach5 SHARED
           ${sources}
           )
