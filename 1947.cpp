#include <algorithm>
#include <iostream>
#include <vector>

const int MOD = 1000000000;
std::vector<unsigned long long> dp;

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N;
  std::cin >> N;

  dp.assign(N + 1, 0);
  dp[1] = 0;
  dp[2] = 1;

  for (int i = 3; i <= N; i++) {
    dp[i] = ((i - 1) % MOD) * ((dp[i - 1] + dp[i - 2]) % MOD) % MOD;
  }

  std::cout << dp[N] << '\n';

  return 0;
}