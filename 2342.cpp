#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <vector>

int movecost(int from, int to) {
  if (from == 0) return 2;
  if (from == to) return 1;
  if (abs(from - to) == 1 || abs(from - to) == 3) {
    return 3;
  }
  return 4;
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  std::vector<int> steps;
  while (true) {
    int step;
    std::cin >> step;

    if (step == 0) break;

    steps.push_back(step);
  }

  int N = steps.size();
  if (N == 0) {
    std::cout << 0 << '\n';
    return 0;
  }

  std::vector<std::vector<std::vector<int>>> dp(
      N + 1, std::vector<std::vector<int>>(5, std::vector<int>(5, INT_MAX)));

  dp[0][0][0] = 0;

  for (int i = 0; i < N; i++) {
    int next = steps[i];
    for (int l = 0; l < 5; l++) {
      for (int r = 0; r < 5; r++) {
        if (dp[i][l][r] == INT_MAX) continue;

        if (next != r) {
          dp[i + 1][next][r] =
              std::min(dp[i + 1][next][r], dp[i][l][r] + movecost(l, next));
        }

        if (next != l) {
          dp[i + 1][l][next] =
              std::min(dp[i + 1][l][next], dp[i][l][r] + movecost(r, next));
        }
      }
    }
  }

  int result = INT_MAX;
  for (int l = 0; l < 5; l++) {
    for (int r = 0; r < 5; r++) {
      result = std::min(result, dp[N][l][r]);
    }
  }

  std::cout << result << '\n';

  return 0;
}