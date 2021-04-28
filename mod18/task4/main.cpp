#include <iostream>

void evendigits(long long n, int &ans) {
  int cur_digit;
  if (n > 0) {
    cur_digit = n % 10;
    if (cur_digit % 2 == 0) ++ans;
    n /= 10;
    evendigits(n, ans);
  }

}

int main() {
  int ans(0);
  evendigits(9223372036854775806, ans);
  std::cout << "num of even digits from N is " << ans;
  return 0;
}
