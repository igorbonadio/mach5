set(sources
   Benchmark.cpp
	 BenchmarkRunner.cpp
	 Result.cpp
   )

add_library(mach5 SHARED
           ${sources}
           )
