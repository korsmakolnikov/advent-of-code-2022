#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <sstream>
#include <string>

#include "../src/app/rucksack_parser.hpp"

std::string puzzle = "vJrwpWtwJgWrhcsFMMfFFhFp"
                     "jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL"
                     "PmmdzqPrVvPwwTWBwg"
                     "wMqvLMZHhHMvwLHjbvcjnnSBnvTQFn"
                     "ttgJtRGJQctTZtZT"
                     "CrZsJsPPZsGzwwsLwLmpwMDw";
std::stringstream puzzleStream(puzzle);

TEST_CASE("testing parser to parse A Y line") {

  std::string line;
  while (std::getline(puzzleStream, line)) {
    App::Rucksack sack;
    CHECK_NOTHROW(sack = App::parseLine<App::Rucksack>(line));
    REQUIRE(sack.bagOne + sack.bagTwo == line);
  }
}

TEST_CASE("testing parser throw exception with empty or odd strings") {

  std::string line{"eee"};

  REQUIRE_THROWS(App::parseLine<App::Rucksack>(line));

  line = "";

  REQUIRE_THROWS(App::parseLine<App::Rucksack>(line));
}
