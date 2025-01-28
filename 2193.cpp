#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N;
  std::cin >> N;

  std::vector<std::vector<long long>> dp(N + 1, std::vector<long long>(2, 0));
  dp[1][0] = 0;
  dp[1][1] = 1;

  for (int i = 2; i <= N; i++) {
    dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
    dp[i][1] = dp[i - 1][0];
  }

  std::cout << dp[N][0] + dp[N][1] << '\n';

  return 0;
}