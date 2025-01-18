#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int n;
  std::cin >> n;

  int m;
  std::cin >> m;

  int INF = 100000 * (100 - 1) + 1;
  std::vector<std::vector<int>> adj(n + 1, std::vector<int>(n + 1, INF));
  for (int i = 1; i <= n; i++) adj[i][i] = 0;

  for (int i = 0; i < m; i++) {
    int a, b, c;
    std::cin >> a >> b >> c;

    if (adj[a][b] > c) adj[a][b] = c;
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (adj[i][j] > adj[i][k] + adj[k][j])
          adj[i][j] = adj[i][k] + adj[k][j];
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (adj[i][j] == INF)
        std::cout << 0 << " ";
      else
        std::cout << adj[i][j] << " ";
    }
    std::cout << '\n';
  }

  return 0;
}