#include <iostream>
#include <fstream>

int main() {
  std::ifstream river("river.txt");
  std::ofstream basket("basket.txt", std::ios::app);
  if (river.is_open() && basket.is_open()) {
    int fishAmount(0);
    std::string wantedFish, riverFish;
    std::cout << "what kind of fish you will be catching: ";
    std::cin >> wantedFish;
    while (!river.eof()) {
      river >> riverFish;
      if (riverFish == wantedFish) {
        ++fishAmount;
        basket << wantedFish << '\n';
      }
    }
    std::cout << "today you catch " << fishAmount << " pisces" << std::endl;
  }
  return 0;
}
