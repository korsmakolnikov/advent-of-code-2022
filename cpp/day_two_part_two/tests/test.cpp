#include <string>
#include <tuple>
#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>

#include "../src/engine.hpp"
#include "../src/tuple_parser.hpp"

TEST_CASE("The match have to end with a draw while the elf plays a Rock") {
  char elf, player;
  elf = 'A';
  player = 'Y';
  auto engine = Engine(elf, player);

  REQUIRE(4 == engine.match());
}

TEST_CASE("The match have to end with a defeat for the player while the elf "
          "plays a Rock") {
  char elf, player;
  elf = 'A';
  player = 'X';
  auto engine = Engine(elf, player);

  REQUIRE(3 == engine.match());
}

TEST_CASE("The match have to end with a victory for the player while the elf "
          "plays a Rock") {
  char elf, player;
  elf = 'A';
  player = 'Z';

  auto engine = Engine(elf, player);
  REQUIRE(8 == engine.match());
}

TEST_CASE("The match have to end with a defeat for the player while the elf "
          "plays the paper") {
  char elf, player;
  elf = 'B';
  player = 'X';

  auto engine = Engine(elf, player);
  REQUIRE(1 == engine.match());
}

TEST_CASE("The match have to end with a draw while the elf "
          "plays the paper") {
  char elf, player;
  elf = 'B';
  player = 'Y';

  auto engine = Engine(elf, player);
  REQUIRE(5 == engine.match());
}

TEST_CASE("The match have to end with a victory for the player while the elf "
          "plays the paper") {
  char elf, player;
  elf = 'B';
  player = 'Z';

  auto engine = Engine(elf, player);
  REQUIRE(9 == engine.match());
}

TEST_CASE("The match have to end with a victory for the player while the elf "
          "plays a scissor") {
  char elf, player;
  elf = 'C';
  player = 'Z';

  auto engine = Engine(elf, player);
  REQUIRE(7 == engine.match());
}

TEST_CASE("The match have to end with a defeat for the player while the elf "
          "plays a scissor") {
  char elf, player;
  elf = 'C';
  player = 'X';

  auto engine = Engine(elf, player);
  REQUIRE(2 == engine.match());
}

TEST_CASE("The match have to end with a draw while the elf "
          "plays a scissor") {
  char elf, player;
  elf = 'C';
  player = 'Y';

  auto engine = Engine(elf, player);
  REQUIRE(6 == engine.match());
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
