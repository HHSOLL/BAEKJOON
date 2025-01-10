#include <cmath>
#include <iostream>
#include <vector>

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  long long A, B;
  std::cin >> A >> B;

  long long end = sqrt(B);
  std::vector<bool> is_prime(end + 1, true);
  is_prime[0] = is_prime[1] = false;

  for (long long i = 2; i * i <= end; ++i) {
    if (is_prime[i]) {
      for (long long j = i * i; j <= end; j += i) {
        is_prime[j] = false;
      }
    }
  }

  int count = 0;
  for (long long i = 2; i <= end; ++i) {
    if (is_prime[i]) {
      long long tmp = i * i;
      while (tmp <= B) {
        if (tmp >= A) count++;
        if (tmp > B / i) break;
        tmp *= i;
      }
    }
  }

  std::cout << count << '\n';
  return 0;
}