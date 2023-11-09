#include "engine.hpp"
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <set>

namespace Domain {

char findObjectAppearingTwice(std::set<char> bagOne, std::set<char> bagTwo) {
  std::set<char> intersection;
  std::set_intersection(bagOne.begin(), bagOne.end(), bagTwo.begin(),
                        bagTwo.end(),
                        std::inserter(intersection, intersection.begin()));

  std::set<char>::iterator i = intersection.begin();
  if (intersection.begin() != intersection.end()) {
    return *i;
  }

  throw "Something unexpected happend while analyzing sack";
}

Priority prioritizeSack(Rucksack sack) {
  std::set<char> bagOne;
  std::set<char> bagTwo;

  for (char &c : sack.bagOne) {
    bagOne.insert(c);
  }

  for (char &c : sack.bagTwo) {
    bagTwo.insert(c);
  }

  char appearingTwice = findObjectAppearingTwice(bagOne, bagTwo);
  if (appearingTwice < 96) {
    return appearingTwice - 38;
  } else {
    return appearingTwice - 96;
  }
}

} // namespace Domain
