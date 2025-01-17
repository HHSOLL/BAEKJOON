#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

const int INF = INT32_MAX;

void bellmanFord(int V, int E, int start,
                 std::vector<std::tuple<int, int, int>>& edges) {
  std::vector<long long> dist(V + 1, INF);
  dist[start] = 0;

  for (int i = 1; i <= V; i++) {
    for (auto [u, v, w] : edges) {
      if (dist[u] != INF && dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
      }
    }
  }

  for (auto [u, v, w] : edges) {
    if (dist[u] != INF && dist[u] + w < dist[v]) {
      std::cout << -1 << '\n';
      return;
    }
  }

  for (int i = 1; i <= V; i++) {
    if (i == start)
      continue;
    else if (dist[i] == INF)
      std::cout << -1 << '\n';
    else
      std::cout << dist[i] << '\n';
  }
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N, M;
  std::cin >> N >> M;

  std::vector<std::tuple<int, int, int>> edges;
  for (int i = 0; i < M; i++) {
    int A, B, C;
    std::cin >> A >> B >> C;

    edges.push_back({A, B, C});
  }

  bellmanFord(N, M, 1, edges);

  return 0;
}