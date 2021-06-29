#include <iostream>
#include "tree.h"
#include <ctime>

int main() {
  std::srand(std::time(nullptr));
  Tree trees[5];

  std::string nameForSearch;
  std::cout << "\t\tenter elf name for search:";
  std::cin >> nameForSearch;
  for (int i = 0; i < 5; ++i) {
    std::cout << "for tree No " << i << std::endl;
    trees[i].findNameNeighbors(nameForSearch);
  }

  return 0;
}
