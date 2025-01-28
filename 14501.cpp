#include <algorithm>
#include <iostream>
#include <vector>

struct work {
  int t, p;
};

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N;
  std::cin >> N;

  std::vector<work> work(N + 1);

  for (int i = 1; i <= N; i++) {
    std::cin >> work[i].t >> work[i].p;
  }

  std::vector<int> dp(N + 2, 0);

  for (int i = 1; i <= N; i++) {
    dp[i] = std::max(dp[i], dp[i - 1]);

    if (i + work[i].t <= N + 1) {
      dp[i + work[i].t] = std::max(dp[i + work[i].t], dp[i] + work[i].p);
    }
  }

  std::cout << *std::max_element(dp.begin(), dp.end()) << '\n';

  return 0;
}