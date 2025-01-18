#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

void dfs(int s, std::vector<std::vector<int>>& adj, std::vector<bool>& visited,
         std::vector<int>& result) {
  visited[s] = true;

  for (auto& next : adj[s]) {
    if (!visited[next]) {
      result[next] = s;
      dfs(next, adj, visited, result);
    }
  }
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N;
  std::cin >> N;

  std::vector<std::vector<int>> adj(N + 1, std::vector<int>());
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    std::cin >> a >> b;

    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  std::vector<int> result(N + 1, 0);
  std::vector<bool> visited(N + 1, 0);
  dfs(1, adj, visited, result);

  for (int i = 2; i <= N; i++) {
    std::cout << result[i] << '\n';
  }

  return 0;
}