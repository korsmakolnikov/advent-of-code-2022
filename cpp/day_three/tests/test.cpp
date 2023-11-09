#include <string>
#include <tuple>
#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>

#include "../src/domain/engine.hpp"

TEST_CASE("Test basic characters: both bags contain 'a'") {

  Domain::Rucksack sack;
  sack.bagOne = "a";
  sack.bagTwo = "a";

  REQUIRE(1 == prioritizeSack(sack));
}

TEST_CASE("Test basic characters: both bags contain 'z'") {

  Domain::Rucksack sack;
  sack.bagOne = "z";
  sack.bagTwo = "z";

  REQUIRE(26 == prioritizeSack(sack));
}

TEST_CASE("Test basic characters: both bags contain 'A'") {

  Domain::Rucksack sack;
  sack.bagOne = "A";
  sack.bagTwo = "A";

  REQUIRE(27 == prioritizeSack(sack));
}

TEST_CASE("Test basic characters: both bags contain 'Z'") {

  Domain::Rucksack sack;
  sack.bagOne = "Z";
  sack.bagTwo = "Z";

  REQUIRE(52 == prioritizeSack(sack));
}

TEST_CASE("Test a sample from puzzle 1") {

  Domain::Rucksack sack;
  sack.bagOne = "vJrwpWtwJgWr";
  sack.bagTwo = "hcsFMMfFFhFp";

  REQUIRE(16 == prioritizeSack(sack));
}

TEST_CASE("Test a sample from puzzle 2") {

  Domain::Rucksack sack;
  sack.bagOne = "wMqvLMZHhHMvwLH";
  sack.bagTwo = "jbvcjnnSBnvTQFn";

  REQUIRE(22 == prioritizeSack(sack));
}

TEST_CASE("Test a sample from puzzle 3") {

  Domain::Rucksack sack;
  sack.bagOne = "CrZsJsPPZsGz";
  sack.bagTwo = "wwsLwLmpwMDw";

  REQUIRE(19 == prioritizeSack(sack));
}
