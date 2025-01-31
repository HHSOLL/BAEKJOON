#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N;
  std::cin >> N;

  std::vector<int> v(N + 1, 0);
  std::vector<std::vector<int>> dp(N + 1, std::vector<int>(N + 1, 0));
  for (int i = 1; i <= N; i++) {
    int r, c;
    std::cin >> r >> c;

    v[i - 1] = r;
    v[i] = c;
  }

  for (int len = 2; len <= N; len++) {
    for (int i = 1; i + len - 1 <= N; i++) {
      int j = i + len - 1;
      dp[i][j] = INT_MAX;
      for (int k = i; k < j; k++) {
        dp[i][j] = std::min(dp[i][j],
                            dp[i][k] + dp[k + 1][j] + v[i - 1] * v[k] * v[j]);
      }
    }
  }

  std::cout << dp[1][N] << '\n';

  return 0;
}