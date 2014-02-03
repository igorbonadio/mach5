#ifndef MACH5_UTIL_HPP
#define MACH5_UTIL_HPP

#include <string>
#include <vector>
#include <map>
#include <iostream>

#include "BenchmarkResult.hpp"
#include "BenchmarkRunner.hpp"

namespace mach5 {
  class Util {
  public:
    std::string toJson(std::map<std::string, std::vector<BenchmarkResult>> results) {
      std::ostringstream str;
      str << "{";
      for (auto kv = results.begin(); kv != results.end(); ++kv) {
        str << "\"" << kv->first << "\": [";
        for (auto it = kv->second.begin(); it != kv->second.end(); ++it) {
          str << it->json();
          if (std::next(it) != kv->second.end())
            str << ",";
        }
        str << "]";
        if (std::next(kv) != results.end())
          str << ",";
      }
      str << "}";
      return str.str();
    }

    int inputOptions(int argc, char** argv) {
      if (argc < 2) return 0;
      auto command = std::string(argv[1]);
      if (command == "help") {
        help();
        return 1;
      } else if (command == "list") {
        return 2;
      } else if (command == "run") {
        if (argc > 2) return 3;
      }
      return 0;
    }

    void help() {
      std::cout << "Usage: ./yourbinary [command] [argments*]" << std::endl;
      std::cout << "  help             shows this message" << std::endl;
      std::cout << "  list             lists all benchmarks names" << std::endl;
      std::cout << "  run              runs a list of benchmarks" << std::endl;
    }
  };
}

#endif