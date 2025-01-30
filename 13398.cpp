#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N;
  std::cin >> N;

  std::vector<int> v(N, 0);
  for (int i = 0; i < N; i++) std::cin >> v[i];

  std::vector<int> dp(N, 0);
  std::vector<int> dp2(N, 0);

  dp[0] = v[0];
  dp2[0] = 0;

  int result = v[0];

  for (int i = 1; i < N; i++) {
    dp[i] = std::max(dp[i - 1] + v[i], v[i]);
    dp2[i] = std::max(dp2[i - 1] + v[i], dp[i - 1]);

    int max = std::max(dp[i], dp2[i]);
    result = std::max(result, max);
  }

  std::cout << result << '\n';

  return 0;
}