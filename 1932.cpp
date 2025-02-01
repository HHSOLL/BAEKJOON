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

  std::vector<std::vector<int>> dp(n);
  for (int i = 0; i < n; i++) {
    int tmp = i + 1;
    for (int j = 0; j < tmp; j++) {
      int num;
      std::cin >> num;
      dp[i].push_back(num);
    }
  }

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < dp[i].size(); j++) {
      if (j == 0) {
        dp[i][j] += dp[i - 1][j];
      } else if (j == dp[i].size() - 1) {
        dp[i][j] += dp[i - 1][j - 1];
      } else {
        dp[i][j] += std::max(dp[i - 1][j - 1], dp[i - 1][j]);
      }
    }
  }

  std::cout << *std::max_element(dp[n - 1].begin(), dp[n - 1].end()) << '\n';

  return 0;
}
