set(sources
   Benchmark.cpp
	 BenchmarkRunner.cpp
	 BenchmarkResult.cpp
	 BenchmarkDescriptor.cpp
	 BenchmarkFactory.cpp
   )

add_library(mach5 SHARED
           ${sources}
           )
