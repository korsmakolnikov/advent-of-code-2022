#include <vector>

class CaloriesCounter {

  std::vector<int> inventory;

public:
  int bestCalories();
  int bestThree();
  void registerInventory(std::vector<int> inventory);
};
