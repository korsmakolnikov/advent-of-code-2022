#include <iostream>
#include <string>
#include <vector>

#include "calories_counter.hpp"

int main() {
  CaloriesCounter cc;
  std::vector<int> bag;
  std::string snack;

  bag.reserve(20);

  while (std::getline(std::cin, snack)) {
    if (!snack.empty()) {
      bag.push_back(std::stoi(snack));
    } else {
      cc.registerInventory(bag);
      bag.clear();
    }
  }

  std::cout << "the winner is " << cc.bestCalories() << std::endl;
  std::cout << "the three best are " << cc.bestThree() << std::endl;

  return 0;
}
