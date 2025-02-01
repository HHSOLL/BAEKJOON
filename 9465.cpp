#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int T;
  std::cin >> T;

  while (T--) {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> s(2, std::vector<int>(n));
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < n; j++) {
        std::cin >> s[i][j];
      }
    }

    std::vector<std::vector<int>> dp(n, std::vector<int>(3, 0));

    dp[0][0] = 0;
    dp[0][1] = s[0][0];
    dp[0][2] = s[1][0];

    for (int i = 1; i < n; i++) {
      dp[i][0] = std::max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
      dp[i][1] = std::max(dp[i - 1][0], dp[i - 1][2]) + s[0][i];
      dp[i][2] = std::max(dp[i - 1][0], dp[i - 1][1]) + s[1][i];
    }

    int ans = std::max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
    std::cout << ans << '\n';
  }

  return 0;
}
