#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

const int MAX = 201;
long long dp[MAX][MAX];
const int INF = 1000000000;

long long combination(int n, int r) {
  if (n < r) return 0;
  if (r == 0 || n == r) return 1;
  if (dp[n][r] > INF) dp[n][r] = INF + 1;
  if (dp[n][r] != 0) return dp[n][r];
  return dp[n][r] = combination(n - 1, r - 1) + combination(n - 1, r);
}

void findKthString(int n, int m, long long k, std::string& result) {
  if (n == 0) {
    result.append(m, 'z');
    return;
  }

  if (m == 0) {
    result.append(n, 'a');
    return;
  }

  long long aCount = combination(n + m - 1, n - 1);

  if (k <= aCount) {
    result.push_back('a');
    findKthString(n - 1, m, k, result);
  } else {
    result.push_back('z');
    findKthString(n, m - 1, k - aCount, result);
  }
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N, M;
  long long K;
  std::cin >> N >> M >> K;

  if (K > combination(N + M, N)) {
    std::cout << -1 << '\n';
    return 0;
  }

  std::string result;
  findKthString(N, M, K, result);
  std::cout << result << '\n';

  return 0;
}