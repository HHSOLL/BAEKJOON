#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N;
  std::cin >> N;

  std::vector<int> arr(N + 1, 0);
  for (int i = 1; i <= N; i++) {
    std::cin >> arr[i];
  }

  int M;
  std::cin >> M;

  std::vector<std::vector<int>> dp(N + 1, std::vector<int>(N + 1, 0));

  for (int i = 1; i <= N; i++) {
    dp[i][i] = 1;
  }

  for (int i = 1; i < N; i++) {
    dp[i][i + 1] = (arr[i] == arr[i + 1]) ? 1 : 0;
  }

  for (int L = 3; L <= N; L++) {
    for (int i = 1; i <= N - L + 1; i++) {
      int j = i + L - 1;

      dp[i][j] = (arr[i] == arr[j]) && dp[i + 1][j - 1];
    }
  }

  for (int i = 0; i < M; i++) {
    int s, e;
    std::cin >> s >> e;

    std::cout << dp[s][e] << '\n';
  }

  return 0;
}
