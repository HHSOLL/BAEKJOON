#include <algorithm>
#include <iostream>
#include <vector>

long long gcd(long long max, long long min) {
  if (min == 0) return max;

  return gcd(min, max % min);
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  long long A, B;
  std::cin >> A >> B;

  long long max = std::max(A, B);
  long long min = std::min(A, B);

  long long res = gcd(max, min);

  for (int i = 0; i < res; i++) {
    std::cout << 1;
  }
  std::cout << '\n';
  return 0;
}