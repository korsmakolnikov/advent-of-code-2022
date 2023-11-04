#include <vector>
#define CATCH_CONFIG_MAIN

#include "../src/calories_counter.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Feed with one inventory and calculate the calories", "[lib]") {
  CaloriesCounter cc;

  std::vector<int> fixture{1000, 2000, 3000};

  cc.registerInventory(fixture);
  REQUIRE(6000 == cc.bestCalories());
}

TEST_CASE("Feed with mutlple inventory and calculate the best calories",
          "[lib]") {
  CaloriesCounter cc;

  std::vector<int> elves_one{1000, 2000, 3000};
  std::vector<int> elves_two{4000};
  std::vector<int> elves_three{5000, 6000};
  std::vector<int> elves_four{7000, 8000, 9000};
  std::vector<int> elves_five{10000};

  cc.registerInventory(elves_one);
  cc.registerInventory(elves_two);
  cc.registerInventory(elves_three);
  cc.registerInventory(elves_four);
  cc.registerInventory(elves_five);
  REQUIRE(24000 == cc.bestCalories());
}

TEST_CASE("Feed with mutlple inventory and calculate the three best", "[lib]") {
  CaloriesCounter cc;

  std::vector<int> elves_one{1000, 2000, 3000};
  std::vector<int> elves_two{4000};
  std::vector<int> elves_three{5000, 6000};
  std::vector<int> elves_four{7000, 8000, 9000};
  std::vector<int> elves_five{10000};

  cc.registerInventory(elves_one);
  cc.registerInventory(elves_two);
  cc.registerInventory(elves_three);
  cc.registerInventory(elves_four);
  cc.registerInventory(elves_five);
  REQUIRE(45000 == cc.bestThree());
}
