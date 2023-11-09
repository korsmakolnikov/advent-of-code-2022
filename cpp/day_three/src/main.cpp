#include "domain/engine.hpp"
#include <iostream>
#include <string>
#include <tuple>

int main() {
  std::string line;
  std::tuple<char, char> match;

  int playerScore = 0;

  try {

    while (std::getline(std::cin, line)) {
      auto sack = App::parseLine<App::Rucksack>(line);
      auto score = Domain::prioritizeSack(Domain::from(sack));

      playerScore += score;
    }

    std::cout << "The score of the player is: " << playerScore << std::endl;

  } catch (const char *e) {
    std::cout << "The program terminate with an exception: " << e << std::endl;
    return 100;
  }

  return 0;
}
