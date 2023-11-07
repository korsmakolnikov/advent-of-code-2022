#include "parser.hpp"
#include <sstream>
#include <string>
#include <tuple>

template <> std::tuple<char, char> parseLine(std::string line) {
  std::stringstream ss(line);
  std::string elf, player;
  ss >> elf >> player;
  return std::tuple<char, char>{elf[0], player[0]};
}
