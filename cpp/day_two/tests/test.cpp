#include <string>
#include <tuple>
#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>

#include "../src/engine.hpp"
#include "../src/tuple_parser.hpp"

TEST_CASE("testing player wins with paper against rock") {
  char elf, player;
  elf = 'A';
  player = 'Y';

  REQUIRE(8 == Engine::match(elf, player));
}

TEST_CASE("testing player lose with rock against paper") {
  char elf, player;
  elf = 'B';
  player = 'X';

  REQUIRE(1 == Engine::match(elf, player));
}

TEST_CASE("testing players draw (scissor vs scissor)") {
  char elf, player;
  elf = 'C';
  player = 'Z';

  REQUIRE(6 == Engine::match(elf, player));
}

TEST_CASE("testing parser to parse A Y line") {

  std::string line = "A Y";
  std::tuple<char, char> wanted{'A', 'Y'};

  REQUIRE(wanted == parseLine<std::tuple<char, char>>(line));
}

TEST_CASE("testing parser to parse B C line") {

  std::string line = "B C";
  std::tuple<char, char> wanted{'B', 'C'};

  REQUIRE(wanted == parseLine<std::tuple<char, char>>(line));
}

TEST_CASE("testing parser to parse C Z line") {

  std::string line = "C Z";
  std::tuple<char, char> wanted{'C', 'Z'};

  REQUIRE(wanted == parseLine<std::tuple<char, char>>(line));
}
