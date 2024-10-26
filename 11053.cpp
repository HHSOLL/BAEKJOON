#include <algorithm>
#include <iostream>
#include <vector>

int longestIncreaseSubset(std::vector<int>& v) {
  if (v.size() == 0) return 0;

  int n = v.size();
  std::vector<int> dp(n, 1);

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (v[i] > v[j]) dp[i] = std::max(dp[i], dp[j] + 1);
    }
  }
  return *max_element(dp.begin(), dp.end());
}

int main(void) {
  int n;
  std::cin >> n;
  std::vector<int> v(n, 0);
  for (int i = 0; i < n; i++) {
    std::cin >> v[i];
  }

  std::cout << longestIncreaseSubset(v) << '\n';
  return 0;
}