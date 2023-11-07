#include "engine.hpp"
#include "tuple_parser.hpp"
#include <iostream>
#include <string>
#include <tuple>

int main() {
  std::string line;
  std::tuple<char, char> match;

  int playerScore = 0;

  while (std::getline(std::cin, line)) {
    auto t = parseLine<std::tuple<char, char>>(line);
    // auto score = Engine::match();
    auto engine = Engine(std::get<0>(t), std::get<1>(t));
    auto score = engine.match();

    std::cout << "the score is: " << score << std::endl;

    playerScore += score;
  }

  std::cout << "The score of the player is: " << playerScore << std::endl;

  return 0;
}
