#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N, M;
  std::cin >> N >> M;

  const int INF = 1000000;
  std::vector<std::vector<int>> adj(N + 1, std::vector<int>(N + 1, INF));
  for (int i = 0; i <= N; i++) adj[i][i] = 0;

  for (int i = 1; i <= M; i++) {
    int a, b;
    std::cin >> a >> b;
    adj[a][b] = 1;
    adj[b][a] = 1;
  }

  for (int k = 1; k <= N; k++) {
    for (int s = 1; s <= N; s++) {
      for (int e = 1; e <= N; e++) {
        adj[s][e] = std::min(adj[s][k] + adj[k][e], adj[s][e]);
      }
    }
  }

  // for (int i = 1; i <= N; i++) {
  //   for (int j = 1; j <= N; j++) {
  //     std::cout << adj[i][j] << " ";
  //   }
  //   std::cout << '\n';
  // }

  int smallest = INF;
  int p = 0;
  for (int i = 1; i <= N; i++) {
    int sum = 0;
    for (int j = 1; j <= N; j++) {
      sum += adj[i][j];
    }
    if (sum < smallest) {
      smallest = sum;
      p = i;
    }
  }

  std::cout << p << '\n';

  return 0;
}