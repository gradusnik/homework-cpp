#include <iostream>

int functn(int k) {
  int sum(0), quan(0);
  if (k == 1) return 1;
  else {
    int step(1);
    while (step <= 3) {
      sum += step;
      if (sum == k) {
        ++quan; break;
      }
      else if (sum < k) {
        quan += functn(k - step);
        ++step;
      }
      else break;
      sum = 0;
    }
  }
  return quan;
}

int main() {
  int n;
  std::cout << "enter the N.. ";
  std::cin >> n;
  std::cout << functn(n);
  return 0;
}
