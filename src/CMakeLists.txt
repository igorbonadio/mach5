set(sources
   Benchmark.cpp
	 BenchmarkRunner.cpp
   )

add_library(mach5 SHARED
           ${sources}
           )
