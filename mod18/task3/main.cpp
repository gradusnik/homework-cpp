#include <iostream>

int functn(int n, int k = 3) {
  int sum(0), quan(0);
  if (n == 1) return 1;
  else {
    int step(1);
    while (step <= k) {
      sum += step;
      if (sum == n) {
        ++quan; break;
      }
      else if (sum < n) {
        quan += functn(k,n - step);
        ++step;
      }
      else break;
      sum = 0;
    }
  }
  return quan;
}

int main() {
  int n, k;
  std::cout << "enter the N.. ";
  std::cin >> n;
  std::cout << "enter the K (K should be less then N).. ";
  std::cin >> k;
  (k <= n) ? std::cout << functn(n , k) : std::cout << "try another time\n";
  return 0;
}

