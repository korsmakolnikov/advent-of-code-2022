#include "calories_counter.hpp"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <ostream>
#include <vector>

int CaloriesCounter::bestCalories() {
  return *std::max_element(this->inventory.begin(), this->inventory.end());
}

int CaloriesCounter::bestThree() {
  std::sort(this->inventory.begin(), this->inventory.end());
  return std::accumulate(this->inventory.end() - 3, this->inventory.end(), 0);
}

void CaloriesCounter::registerInventory(std::vector<int> inventory) {
  int elvesLoad = std::accumulate(inventory.begin(), inventory.end(), 0);
  this->inventory.push_back(elvesLoad);
}
