#include "./rucksack_parser.hpp"
#include <sstream>
#include <string>
#include <tuple>

namespace App {

template <> App::Rucksack parseLine(std::string line) {
  u_int32_t length = line.length();
  if (length == 0 || length % 2 != 0)
    throw "Cannot parse the line, the line length is odd or empty";

  int needlePoint = line.length() / 2;

  App::Rucksack sack;
  sack.bagOne = line.substr(0, needlePoint);
  sack.bagTwo = line.substr(needlePoint);

  return sack;
}

} // namespace App
