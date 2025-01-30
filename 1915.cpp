#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int n, m;
  std::cin >> n >> m;

  std::vector<std::vector<int>> grid(n, std::vector<int>(m));
  for (int i = 0; i < n; i++) {
    std::string row;
    std::cin >> row;
    for (int j = 0; j < m; j++) {
      grid[i][j] = row[j] - '0';
    }
  }

  int max = 0;
  std::vector<std::vector<int>> dp(n, std::vector<int>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 1) {
        if (i == 0 || j == 0) {
          dp[i][j] = 1;
        } else {
          int tmp = std::min(dp[i - 1][j], dp[i][j - 1]);
          tmp = std::min(tmp, dp[i - 1][j - 1]);
          dp[i][j] = tmp + 1;
        }
        max = std::max(max, dp[i][j]);
      }
    }
  }

  std::cout << max * max << '\n';
  return 0;
}