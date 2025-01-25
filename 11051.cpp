#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N, K;
  std::cin >> N >> K;

  std::vector<std::vector<int>> dp(N + 1, std::vector<int>(N + 1, 0));

  for (int i = 0; i <= N; i++) {
    dp[i][1] = i;
    dp[i][0] = 1;
    dp[i][i] = 1;
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= K; j++) {
      dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007;
    }
  }

  std::cout << dp[N][K] << '\n';

  return 0;
}