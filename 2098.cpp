#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

const int INF = 1e9;
int N;
std::vector<std::vector<int>> w;
std::vector<std::vector<int>> dp;

int tsp(int curr, int visited) {
  if (visited == (1 << N) - 1) {
    return (w[curr][0] > 0) ? w[curr][0] : INF;
  }

  if (dp[curr][visited] != -1) return dp[curr][visited];

  int minCost = INF;
  for (int next = 0; next < N; next++) {
    if ((visited & (1 << next)) || w[curr][next] == 0) continue;
    int newCost = w[curr][next] + tsp(next, visited | (1 << next));
    minCost = std::min(minCost, newCost);
  }

  return dp[curr][visited] = minCost;
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  std::cin >> N;

  w.assign(N, std::vector<int>(N, 0));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      std::cin >> w[i][j];
    }
  }

  dp.assign(N, std::vector<int>(1 << N, -1));
  int result = tsp(0, 1);

  if (result == INF) {
    std::cout << -1 << '\n';
  } else {
    std::cout << result << '\n';
  }

  return 0;
}
