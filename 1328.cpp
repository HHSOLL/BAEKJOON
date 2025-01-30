#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

const int MOD = 1000000007;

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N, L, R;
  std::cin >> N >> L >> R;

  std::vector<std::vector<std::vector<long long>>> dp(
      N + 1, std::vector<std::vector<long long>>(
                 L + 1, std::vector<long long>(R + 1, 0)));

  dp[1][1][1] = 1;

  for (int n = 2; n <= N; n++) {
    for (int l = 1; l <= L; l++) {
      for (int r = 1; r <= R; r++) {
        dp[n][l][r] = ((dp[n - 1][l - 1][r] + dp[n - 1][l][r - 1]) % MOD +
                       (long long)(n - 2) * dp[n - 1][l][r] % MOD) %
                      MOD;
      }
    }
  }

  std::cout << dp[N][L][R] << '\n';

  return 0;
}