//#include "ram.h"
#include <iostream>

void write(double* nums) {
  for (int i = 0; i < 8; ++i) {
    std::cout << "enter next number: ";
    std::cin >> nums[i];
  }
}

void read(double* nums) {
  std::cout << "numbers is ";
  for (int i = 0; i < 8; ++i) {
    std::cout << nums[i] << " // ";
  }
  std::cout << std::endl;
}

