//#include "cpu.h"
#include <iostream>

void compute(double* nums) {
  double sum = 0.;
  for (int i = 0; i < 8; i++) {
    sum += nums[i];
  }
  std::cout << "sum is " << sum << std::endl;
}