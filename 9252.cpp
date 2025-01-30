#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  std::string str1;
  std::string str2;

  std::cin >> str1;
  std::cin >> str2;

  int n = str1.length();
  int m = str2.length();

  std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (str1[i - 1] == str2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  std::cout << dp[n][m] << '\n';

  int i = n;
  int j = m;
  std::string lcs;

  while (i > 0 && j > 0) {
    if (str1[i - 1] == str2[j - 1]) {
      lcs += str1[i - 1];
      i--;
      j--;
    } else if (dp[i - 1][j] > dp[i][j - 1]) {
      i--;
    } else {
      j--;
    }
  }

  std::reverse(lcs.begin(), lcs.end());
  std::cout << lcs << '\n';

  return 0;
}