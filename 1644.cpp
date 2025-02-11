#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

std::vector<int> generatePrimes(int N) {
  std::vector<bool> isPrime(N + 1, true);
  std::vector<int> primes;

  if (N < 2) return primes;

  isPrime[0] = isPrime[1] = false;

  for (int i = 2; i * i <= N; i++) {
    if (isPrime[i]) {
      for (int j = i * i; j <= N; j += i) {
        isPrime[j] = false;
      }
    }
  }

  for (int i = 2; i <= N; i++) {
    if (isPrime[i]) primes.push_back(i);
  }
  return primes;
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N;
  std::cin >> N;

  std::vector<int> primes = generatePrimes(N);

  int count = 0;
  int start = 0;
  int end = 0;
  int sum = (primes.empty() ? 0 : primes[0]);

  while (start < primes.size() && end < primes.size()) {
    if (sum < N) {
      end++;
      if (end < primes.size()) {
        sum += primes[end];
      }
    } else {
      if (sum == N) {
        count++;
      }
      sum -= primes[start];
      start++;
    }
  }

  std::cout << count << '\n';

  return 0;
}
