#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N;
  std::cin >> N;

  std::vector<std::vector<int>> adj(N + 1, std::vector<int>(N + 1, 0));
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      std::cin >> adj[i][j];
    }
  }

  for (int k = 1; k <= N; k++) {
    for (int s = 1; s <= N; s++) {
      for (int e = 1; e <= N; e++) {
        if (adj[s][k] == 1 && adj[k][e] == 1) {
          adj[s][e] = 1;
        }
      }
    }
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      std::cout << adj[i][j] << " ";
    }
    std::cout << '\n';
  }

  return 0;
}