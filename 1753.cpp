#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

struct Vertex {
  int vertex;
  int weight;
};

void dijkstra(int start, std::vector<std::vector<Vertex>>& adj,
              std::vector<int>& dist) {
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                      std::greater<>>
      pq;

  pq.push({0, start});
  dist[start] = 0;

  while (!pq.empty()) {
    int currDist = pq.top().first;
    int currVertex = pq.top().second;
    pq.pop();

    if (currDist > dist[currVertex]) continue;

    for (auto next : adj[currVertex]) {
      int nextVertex = next.vertex;
      int nextWeight = next.weight;

      if (dist[nextVertex] > currDist + nextWeight) {
        dist[nextVertex] = currDist + nextWeight;
        pq.push({dist[nextVertex], nextVertex});
      }
    }
  }
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int V, E;
  std::cin >> V >> E;

  int start_vertex;
  std::cin >> start_vertex;

  std::vector<std::vector<Vertex>> adj(V + 1);
  std::vector<int> dist(V + 1, INT32_MAX);

  for (int i = 1; i <= E; i++) {
    int u, v, w;
    std::cin >> u >> v >> w;

    adj[u].push_back({v, w});
  }

  dijkstra(start_vertex, adj, dist);

  for (int i = 1; i <= V; i++) {
    if (dist[i] == INT32_MAX)
      std::cout << "INF\n";
    else
      std::cout << dist[i] << '\n';
  }

  return 0;
}