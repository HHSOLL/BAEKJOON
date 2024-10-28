#include <iostream>
#include <vector>

int main(void) {
  int n;
  std::cin >> n;

  std::vector<int> dp(n + 1, 0);
  if (n >= 1) dp[1] = 1;
  if (n >= 2) dp[2] = 2;
  if (n >= 3) dp[3] = 3;
  if (n >= 4) {
    for (int i = 4; i <= n; i++) {
      dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
    }
  }
  std::cout << dp[n] << '\n';
  return 0;
}