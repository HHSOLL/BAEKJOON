#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int M, K;

  std::cin >> M;

  std::vector<double> stone(M);
  double sum = 0;

  for (int i = 0; i < M; i++) {
    std::cin >> stone[i];
    sum += stone[i];
  }

  std::cin >> K;

  if (K == 1 || M == 1) {
    std::cout << std::fixed << std::setprecision(1) << 1.0f << '\n';
    return 0;
  }

  double result = 0.0;
  for (int i = 0; i < M; i++) {
    if (stone[i] < K) continue;

    double p = 1.0;
    for (int j = 0; j < K; j++) {
      p *= ((stone[i] - j) / (sum - j));
    }
    result += p;
  }

  std::cout << std::fixed << std::setprecision(15) << result << '\n';

  return 0;
}