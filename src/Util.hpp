#ifndef MACH5_UTIL_HPP
#define MACH5_UTIL_HPP

#include <string>
#include <vector>
#include <map>
#include <iostream>

#include "BenchmarkResult.hpp"
#include "BenchmarkRunner.hpp"

namespace mach5 {
  class InputParameters {
  public:
    InputParameters(int _command, std::vector<std::string> _benchmarks, std::map<std::string, bool> _options):
      command(_command), benchmarks(_benchmarks), options(_options) {}
    int command;
    std::vector<std::string> benchmarks;
    std::map<std::string, bool> options;
  };

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

    InputParameters inputOptions(int argc, char** argv) {
      std::map<std::string, bool> options;
      options["color"] = false;
      options["json"]   = false;
      int command = 0;
      std::vector<std::string> benchmarks;

      for (int i = 1; i < argc; i++) {
        auto option = std::string(argv[i]);
        if (option == "-c" || option == "--color") {
          options["color"] = true;
        } else if (option == "-j" || option == "--json") {
          options["json"] = true;
        } if (option == "run") {
          command = 3;
          i++;
          for (; i < argc; i++) {
            benchmarks.push_back(std::string(argv[i]));
          }
        } else if (option == "list") {
          command = 2;
        } else if (option == "help") {
          command = 1;
        }
      }

      return InputParameters(command, benchmarks, options);
    }

    void help() {
      std::cout << "Usage: ./yourbinary [options] [command] [argments*]" << std::endl;
      std::cout << "options:" << std::endl;
      std::cout << "  -c, --color     Shows messages with colors" << std::endl;
      std::cout << "  -j, --json       Outputs a json" << std::endl;
      std::cout << "commands:" << std::endl;
      std::cout << "  help             shows this message" << std::endl;
      std::cout << "  list             lists all benchmarks names" << std::endl;
      std::cout << "  run              runs a list of benchmarks" << std::endl;
    }
  };
}

#endif