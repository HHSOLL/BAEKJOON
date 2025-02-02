#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int n;
  std::cin >> n;

  std::vector<std::vector<int>> rgb(n, std::vector<int>(3));
  for (int i = 0; i < n; i++) {
    std::cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
  }

  const int INF = 1000000000;

  int answer = INF;

  for (int firstColor = 0; firstColor < 3; firstColor++) {
    std::vector<std::vector<int>> dp(n, std::vector<int>(3, INF));

    dp[0][firstColor] = rgb[0][firstColor];

    for (int i = 1; i < n; i++) {
      dp[i][0] = rgb[i][0] + std::min(dp[i - 1][1], dp[i - 1][2]);
      dp[i][1] = rgb[i][1] + std::min(dp[i - 1][0], dp[i - 1][2]);
      dp[i][2] = rgb[i][2] + std::min(dp[i - 1][0], dp[i - 1][1]);
    }

    for (int color = 0; color < 3; color++) {
      if (color == firstColor) continue;
      answer = std::min(answer, dp[n - 1][color]);
    }
  }

  std::cout << answer << "\n";

  return 0;
}
