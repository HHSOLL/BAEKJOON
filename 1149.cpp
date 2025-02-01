#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int n;
  std::cin >> n;

  int minCost = 0;

  std::vector<std::vector<int>> rgb(n, std::vector<int>(3, 0));
  std::vector<std::vector<int>> dp(n, std::vector<int>(3, INT_MAX));

  for (int i = 0; i < n; i++) {
    std::cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
  }

  dp[0] = rgb[0];
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      if (j == 0) {
        dp[i][j] = rgb[i][j] + std::min(dp[i - 1][j + 1], dp[i - 1][j + 2]);
      } else if (j == 1) {
        dp[i][j] = rgb[i][j] + std::min(dp[i - 1][j - 1], dp[i - 1][j + 1]);
      } else if (j == 2) {
        dp[i][j] = rgb[i][j] + std::min(dp[i - 1][j - 1], dp[i - 1][j - 2]);
      }
    }
  }

  int min = INT_MAX;
  for (int i = 0; i < 3; i++) {
    if (dp[n - 1][i] < min) min = dp[n - 1][i];
  }

  std::cout << min << '\n';

  return 0;
}
