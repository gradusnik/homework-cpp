#include <iostream>
#include <vector>

void swapvec(std::vector<int> &vec, int arr[]) {
  for (int i = 0; i < 5; ++i) {
    int t = arr[i];
    arr[i] = vec[i];
    vec[i] = t;
  }
}

int main() {
  std::vector<int> a = {1, 2, 3, 4, 5};
  int b[] = {6, 7, 8, 9, 10};
  swapvec(a, b);
  for (int i = 0; i < 5; ++i) {
    std::cout << a[i] << " ";
  }
  std::cout << std::endl;
  for (int i = 0; i < 5; ++i) {
    std::cout << b[i] << " ";
  }
  std::cout << std::endl;
  return 0;
}
