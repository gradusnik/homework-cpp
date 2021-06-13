#include "disk.h"
#include <fstream>
#include <iostream>

void save(double* nums) {
  std::ofstream file("data.txt");
  if (file.is_open()) {
    for (int i = 0; i < 8; ++i) {
      file << nums[i];
      file << " ";
    }
    file.close();
    std::cout << "numbers are saved if file \'data.txt\'" << std::endl;
  } else std::cerr << "file not found" << std::endl;
}

void load(double* nums) {
  std::ifstream file("data.txt");
  if (file.is_open()) {
    for (int i = 0; i < 8; ++i) {
      file >> nums[i];
    }
    file.close();
    std::cout << "numbers are loaded from file \'data.txt\'" << std::endl;
  } else std::cerr << "file not found" << std::endl;
}
