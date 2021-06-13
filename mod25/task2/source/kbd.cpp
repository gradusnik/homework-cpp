#include "kbd.h"
#include <iostream>

void inputNumbers(double* nums) {
  for (int i = 0; i < 8; ++i) {
    std::cout << "enter next number: ";
    std::cin >> nums[i];
  }
  std::cout << "numbers are entered" << std::endl;
}
