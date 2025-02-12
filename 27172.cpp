#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N;
  std::cin >> N;

  std::vector<int> num(N);
  int maxVal = 0;
  for (int i = 0; i < N; i++) {
    std::cin >> num[i];

    maxVal = std::max(maxVal, num[i]);
  }

  std::vector<int> freq(maxVal + 1, 0);
  for (int x : num) {
    freq[x]++;
  }

  std::vector<int> multiples(maxVal + 1, 0);
  for (int x = 1; x <= maxVal; x++) {
    for (int m = x; m <= maxVal; m += x) {
      multiples[x] += freq[m];
    }
  }

  std::vector<int> divisors(maxVal + 1, 0);
  for (int d = 1; d <= maxVal; d++) {
    if (freq[d] > 0) {
      for (int m = d; m <= maxVal; m += d) {
        divisors[m] += freq[d];
      }
    }
  }

  for (int x : num) {
    std::cout << (multiples[x] - divisors[x]) << " ";
  }
  std::cout << '\n';

  return 0;
}
