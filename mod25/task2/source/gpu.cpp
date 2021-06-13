#include "gpu.h"
#include <iostream>

void display(double* nums) {
  std::cout << "we have next numbers: " << std::endl;
  for (int i = 0; i < 8; ++i) {
    std::cout << nums[i] << " // ";
  }
  std::cout << std::endl;
}
