#include "./rucksack.hpp"

namespace Domain {

Domain::Rucksack from(App::Rucksack sack) {
  Domain::Rucksack newSack;
  newSack.bagOne = sack.bagOne;
  newSack.bagTwo = sack.bagTwo;

  return newSack;
}

} // namespace Domain
