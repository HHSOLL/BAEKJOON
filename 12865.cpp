#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N, K;
  std::cin >> N >> K;

  std::vector<int> weight(N + 1, 0);
  std::vector<int> value(N + 1, 0);

  for (int i = 1; i <= N; i++) {
    std::cin >> weight[i] >> value[i];
  }
  // std::vector<std::vector<int>> dp(N + 1, std::vector<int>(K + 1, 0));

  // for (int i = 1; i <= N; i++) {
  //   for (int w = 0; w <= K; w++) {
  //     dp[i][w] = dp[i - 1][w];

  //     if (w >= weight[i]) {
  //       dp[i][w] = std::max(dp[i][w], dp[i - 1][w - weight[i]] + value[i]);
  //     }
  //   }
  // }

  // std::cout << dp[N][K] << '\n';

  std::vector<int> dp2(K + 1, 0);
  for (int i = 1; i <= N; i++) {
    for (int w = K; w >= weight[i]; w--) {
      dp2[w] = std::max(dp2[w], dp2[w - weight[i]] + value[i]);
    }
  }

  std::cout << dp2[K] << '\n';

  return 0;
}
