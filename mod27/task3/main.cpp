#include <iostream>
#include "hierarchy.h"

int main() {
  int n;
  std::cout << "how many managers we have: ";
  std::cin >> n;
  Chief chief1(n);

  int seed(0);
  while (chief1.getAvailableEmpls()) {
    std::cout << "we have " << chief1.getAvailableEmpls()
              << " available employees" << std::endl;
    std::cout << "enter the integer(seed for task): ";
    std::cin >> seed;
    chief1.taskSeed(seed);
  }
  std::cout << "all employees are busy" << std::endl;
  return 0;
}
