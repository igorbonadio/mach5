#ifndef MACH5_UTIL_HPP
#define MACH5_UTIL_HPP

#include <string>
#include <vector>
#include <map>

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
  };
}

#endif