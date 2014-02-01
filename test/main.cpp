#include "Mach5.hpp"

int main(int argc, char** argv) {
  std::cout << ::mach5::Util().toJson(::mach5::BenchmarkRunner::instance().runAll(argc, argv)) << std::endl;
  return 0;
}