#include <cmath>
#include <iostream>
#include <vector>

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int N, K;
  std::cin >> N >> K;
  std::vector<int> coin(N, 0);

  for (int i = 0; i < N; i++) {
    std::cin >> coin[i];
  }

  int count = 0;
  for (int i = N - 1; i >= 0; i--) {
    if (coin[i] <= K) {
      count += (K / coin[i]);
      K %= coin[i];
    }

    if (K == 0) {
      std::cout << count << '\n';
      break;
    }
  }

  return 0;
}