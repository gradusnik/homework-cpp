#include <iostream>

#define HANDLER(func) for (int i = 0; i < 10; ++i) { func }

void inputNumPassengers(int& n) {
  std::cout << "enter number of passengers in next carriage: ";
  std::cin >> n;
  if (n < 0) {
    std::cout << "you entered negative number, it will be replaced by 0\n";
    n = 0;
  }
}

void overfullCarriages(int i, int n) {
  if (n > 20) {
    std::cout << "carriage " << i << " is overfull by " << n - 20 << " passengers";
    std::cout << std::endl;
  }
}

void freeCarriages(int i, int n) {
  if (n < 20) {
    std::cout << "carriage " << i << " has " << 20 - n << " empty seats";
    std::cout << std::endl;
  }
}

int main() {
  int carriage[10] = {0};
  int sum(0);
  HANDLER(inputNumPassengers(carriage[i]);)
  HANDLER(overfullCarriages(i, carriage[i]);)
  HANDLER(freeCarriages(i, carriage[i]);)
  HANDLER(sum += carriage[i];)
  std::cout << "sum of passengers is " << sum << std::endl;
  return 0;
}
