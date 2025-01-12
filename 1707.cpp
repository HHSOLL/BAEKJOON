#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

bool dfs(int node, int color, std::vector<std::vector<int>>& adj,
         std::vector<int>& colors) {
  colors[node] = color;
  for (auto& next : adj[node]) {
    if (colors[next] == -1) {
      if (!dfs(next, 1 - color, adj, colors)) {
        return false;
      }
    } else if (colors[next] == color) {
      return false;
    }
  }
  return true;
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int K;
  std::cin >> K;

  for (int i = 0; i < K; i++) {
    int V, E;
    std::cin >> V >> E;

    std::vector<std::vector<int>> adj(V + 1, std::vector<int>());
    std::vector<int> colors(V + 1, -1);

    for (int j = 1; j <= E; j++) {
      int from, to;
      std::cin >> from >> to;

      if (from != to) {
        adj[from].push_back(to);
        adj[to].push_back(from);
      }
    }

    bool check = true;
    for (int k = 1; k <= V; k++) {
      if (colors[k] == -1) {
        if (!dfs(k, 0, adj, colors)) {
          check = false;
          break;
        }
      }
    }
    if (check)
      std::cout << "YES" << '\n';
    else
      std::cout << "NO" << '\n';
  }

  return 0;
}