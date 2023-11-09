#pragma once
#include "../app/rucksack_parser.hpp"
#include <string>

namespace Domain {

struct Rucksack {
  std::string bagOne;
  std::string bagTwo;
};

Domain::Rucksack from(App::Rucksack sack);
} // namespace Domain
