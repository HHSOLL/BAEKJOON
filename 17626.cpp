#include <cmath>
#include <iostream>
#include <vector>

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int n;
  std::cin >> n;

  std::vector<int> num(n + 1, 0);

  for (int i = 1; i < n + 1; ++i) {
    num[i] = i;

    for (int j = 1; j * j <= i; ++j) {
      num[i] = std::min(num[i], num[i - j * j] + 1);
    }
  }

  std::cout << num[n] << '\n';

  return 0;
}