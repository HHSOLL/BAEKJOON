#include <iostream>
#include <vector>

void DFS(std::vector<std::vector<int>>& graph, std::vector<bool>& visited,
         int node, int& count) {
  visited[node] = true;
  for (int neighbor : graph[node]) {
    if (!visited[neighbor]) {
      count++;
      DFS(graph, visited, neighbor, count);
    }
  }
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int n, m;
  std::cin >> n >> m;

  std::vector<std::vector<int>> graph(n + 1);
  std::vector<bool> visited(n + 1);

  for (int i = 0; i < m; i++) {
    int u, v;
    std::cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  int count = 0;
  DFS(graph, visited, 1, count);

  std::cout << count << '\n';
  return 0;
}