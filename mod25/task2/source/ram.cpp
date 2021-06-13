#include "ram.h"

double storedNumbers[8];

void write(double* nums) {
  for (int i = 0; i < 8; ++i) {
    storedNumbers[i] = nums[i];
  }
}

void read(double* nums) {
  for (int i = 0; i < 8; ++i) {
    nums[i] = storedNumbers[i];
  }
}

