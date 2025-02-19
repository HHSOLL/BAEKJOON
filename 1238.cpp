#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

struct Edge {
  int to, cost;
};

int N, M, X;

std::vector<int> dijkstra(int start, std::vector<std::vector<Edge>>& g) {
  std::vector<int> dist(N + 1, INT_MAX);
  dist[start] = 0;

  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                      std::greater<std::pair<int, int>>>
      pq;

  pq.push({0, start});

  while (!pq.empty()) {
    auto [curDist, curNode] = pq.top();
    pq.pop();

    if (curDist > dist[curNode]) continue;

    for (const auto& edge : g[curNode]) {
      int nextNode = edge.to;
      int nextCost = curDist + edge.cost;

      if (nextCost < dist[nextNode]) {
        dist[nextNode] = nextCost;
        pq.push({nextCost, nextNode});
      }
    }
  }
  return dist;
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  std::cin >> N >> M >> X;

  std::vector<std::vector<Edge>> graph(N + 1, std::vector<Edge>());
  std::vector<std::vector<Edge>> reverseGraph(N + 1, std::vector<Edge>());

  for (int i = 0; i < M; i++) {
    int u, v, t;
    std::cin >> u >> v >> t;

    graph[u].push_back({v, t});
    reverseGraph[v].push_back({u, t});
  }

  std::vector<int> distFromX = dijkstra(X, graph);
  std::vector<int> distToX = dijkstra(X, reverseGraph);

  int ans = 0;
  for (int i = 1; i <= N; i++) {
    if (distFromX[i] == INT_MAX || distToX[i] == INT_MAX) continue;
    ans = std::max(ans, distFromX[i] + distToX[i]);
  }

  std::cout << ans << '\n';

  return 0;
}
