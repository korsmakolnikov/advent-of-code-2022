#pragma once
#include "parser.hpp"
#include <sstream>
#include <string>
#include <tuple>

namespace App {

struct Rucksack {
  std::string bagOne;
  std::string bagTwo;
};

template <> App::Rucksack parseLine(std::string line);

} // namespace App
