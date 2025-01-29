#include <algorithm>
#include <iostream>
#include <vector>

const int DIV = 1000000000;

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N;
  std::cin >> N;

  std::vector<std::vector<int>> dp(N + 1, std::vector<int>(10, 0));

  for (int i = 1; i <= 9; i++) dp[1][i] = 1;

  for (int i = 2; i <= N; i++) {
    for (int j = 0; j <= 9; j++) {
      if (j > 0) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % DIV;
      if (j < 9) dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % DIV;
    }
  }

  long long result = 0;
  for (int i = 0; i <= 9; i++) {
    result = (result + dp[N][i]) % DIV;
  }

  std::cout << result << '\n';

  return 0;
}