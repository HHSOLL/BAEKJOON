#include <iostream>
#include <vector>

int Count(std::vector<int>& v) {
  int n = v.size();
  std::vector<int> dp(n, 0);

  dp[0] = v[0];
  dp[1] = v[0] + v[1];
  dp[2] = v[2] + std::max(v[1], v[0]);

  for (int i = 3; i < n; i++) {
    dp[i] = v[i] + std::max(dp[i - 2], dp[i - 3] + v[i - 1]);
  }
  return dp[n - 1];
}

int main(void) {
  int n;
  std::cin >> n;

  std::vector<int> v(n, 0);
  for (int i = 0; i < n; i++) {
    std::cin >> v[i];
  }

  std::cout << Count(v) << '\n';

  return 0;
}