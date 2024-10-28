#include <iostream>
#include <vector>

int main(void) {
  int n;
  std::cin >> n;

  std::vector<int> t(n, 0);
  int max = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> t[i];
    if (t[i] > max) max = t[i];
  }

  std::vector<int> dp(max + 1, 0);
  if (max >= 1) dp[1] = 1;
  if (max >= 2) dp[2] = 2;
  if (max >= 3) dp[3] = 4;
  if (max >= 4)
    for (int i = 4; i <= max; i++) {
      dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

  for (auto &k : t) {
    std::cout << dp[k] << '\n';
  }

  return 0;
}