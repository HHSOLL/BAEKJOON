#include <algorithm>
#include <iostream>
#include <vector>

void findPrime(int val, int n, int digit);
bool checkPrime(int val);

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N;
  std::cin >> N;

  findPrime(2, 1, N);
  findPrime(3, 1, N);
  findPrime(5, 1, N);
  findPrime(7, 1, N);

  return 0;
}

void findPrime(int val, int n, int digit) {
  if (digit == n) {
    if (checkPrime(val)) {
      std::cout << val << '\n';
      return;
    }
  }

  for (int i = 1; i < 10; i += 2) {
    if (checkPrime(val * 10 + i)) {
      findPrime(val * 10 + i, n + 1, digit);
    }
  }
}

bool checkPrime(int val) {
  for (int i = 2; i < val; i++) {
    if (val % i == 0) return false;
  }
  return true;
}