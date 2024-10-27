#include <iostream>
#include <vector>

int main(void) {
  int n;
  std::cin >> n;

  int max = 0;
  std::vector<int> temp(n, 0);
  for (int i = 0; i < n; i++) {
    std::cin >> temp[i];
    if (temp[i] > max) max = temp[i];
  }

  std::vector<unsigned long long> dp(max, 0);

  if (max >= 1) dp[0] = 1;
  if (max >= 2) dp[1] = 1;
  if (max >= 3) dp[2] = 1;
  if (max >= 4) dp[3] = 2;
  if (max >= 5) dp[4] = 2;
  if (max >= 6)
    for (int i = 5; i < max; i++) {
      dp[i] = dp[i - 1] + dp[i - 5];
    }

  for (auto& k : temp) {
    std::cout << dp[k - 1] << '\n';
  }

  return 0;
}