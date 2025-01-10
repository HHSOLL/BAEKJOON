#include <cmath>
#include <iostream>
#include <string>
#include <vector>

long long euler_totient(long long n) {
  long long result = n;

  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      while (n % i == 0) {
        n /= i;
      }
      result -= result / i;
    }
  }

  if (n > 1) {
    result -= result / n;
  }

  return result;
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  long long n;
  std::cin >> n;

  std::cout << euler_totient(n) << '\n';
  return 0;
}