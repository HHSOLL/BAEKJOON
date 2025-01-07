#include <algorithm>
#include <iostream>
#include <vector>

std::vector<std::vector<int>> graph;
std::vector<bool> visited;

void dfs(int s) {
  visited[s] = true;

  for (int next : graph[s]) {
    if (!visited[next]) dfs(next);
  }
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N, M;
  std::cin >> N >> M;

  graph.assign(N + 1, std::vector<int>());
  visited.assign(N + 1, false);

  for (int i = 1; i <= M; i++) {
    int v1, v2;
    std::cin >> v1 >> v2;

    graph[v1].push_back(v2);
    graph[v2].push_back(v1);
  }

  int count = 0;
  for (int i = 1; i <= N; i++) {
    if (!visited[i]) {
      dfs(i);
      count++;
    }
  }

  std::cout << count << '\n';

  return 0;
}