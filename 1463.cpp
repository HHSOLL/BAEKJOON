#include <iostream>
#include <vector>

int main(void) {
  int n;
  std::cin >> n;

  std::vector<int> dp(n + 1, 0);

  if (n >= 1) dp[1] = 0;
  if (n >= 2) dp[2] = 1;
  if (n >= 3) dp[3] = 1;

  for (int i = 4; i <= n; i++) {
    if (i % 3 == 0 && i % 2 == 0)
      dp[i] = std::min(dp[i / 3], std::min(dp[i / 2], dp[i - 1])) + 1;
    else if (i % 3 == 0)
      dp[i] = std::min(dp[i / 3], dp[i - 1]) + 1;
    else if (i % 2 == 0)
      dp[i] = std::min(dp[i / 2], dp[i - 1]) + 1;
    else
      dp[i] = dp[i - 1] + 1;
  }

  std::cout << dp[n] << '\n';
  return 0;
}