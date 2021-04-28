#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

int main() {
  std::srand(std::time(nullptr));
  std::ofstream pic("picture.txt");
  if (pic.is_open()) {
    int r_num;
    int width(0), height(0);
    std::cout << "enter the width of picture: ";
    std::cin >> width;
    std::cout << "enter the height of picture: ";
    std::cin >> height;
    for (int i = 0; i < height; ++i) {
      for (int j = 0; j < width; ++j) {
        pic << (r_num = std::rand() % 2);
      }
      pic << '\n';
    }
    pic.close();
  } else std::cerr << "failure of opening file\n";
  return 0;
}
