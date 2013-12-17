set(sources
   Benchmark.cpp
	 BenchmarkRunner.cpp
	 BenchmarkResult.cpp
	 BenchmarkDescriptor.cpp
   )

add_library(mach5 SHARED
           ${sources}
           )
