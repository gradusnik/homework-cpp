#include <iostream>
#include <string>
#include <fstream>

int main() {
  std::string path;
  std::cout << "enter the file path ";
  std::cin >> path;
  if (path.substr(path.length() - 4,4) != ".png") {
    std::cout << "file is not a .png";
    return 0;
  }

  std::ifstream assumedPNG;
  assumedPNG.open(path, std::ios::binary);
  if (!assumedPNG.is_open()) {
    std::cerr << "invalid file path";
    return 1;
  }

  char initBytes[5]; initBytes[4] = 0;
  assumedPNG.read(initBytes, 4);
  if (int(initBytes[0]) == -119 && initBytes[1] == 'P' &&
      initBytes[2] == 'N' && initBytes[3] == 'G') {
    std::cout << "it is likely .png file" << std::endl;
  } else std::cout << "it is not .png file" << std::endl;
  return 0;
}
