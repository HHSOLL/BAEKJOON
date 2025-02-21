#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using ll = long long;
const int INF = INT_MAX;

struct Node {
  int src;
  int dest;
  int time;
};

std::vector<std::vector<Node>> road;
std::vector<std::vector<Node>> hole;

bool bellmanFord(int N, int source, std::vector<int>& dist,
                 std::vector<int>& predecessors) {
  dist.assign(N + 1, INF);
  dist[source] = 0;
  predecessors.assign(N + 1, -1);

  for (int i = 1; i < N; i++) {
    bool updated = false;

    for (int u = 1; u <= N; u++) {
      for (const Node& edge : road[u]) {
        int v = edge.dest;
        int w = edge.time;

        if (dist[u] != INF && dist[u] + w < dist[v]) {
          dist[v] = dist[u] + w;
          predecessors[v] = u;
          updated = true;
        }
      }

      for (const Node& edge : hole[u]) {
        int v = edge.dest;
        int w = edge.time;

        if (dist[u] != INF && dist[u] + w < dist[v]) {
          dist[v] = dist[u] + w;
          predecessors[v] = u;
          updated = true;
        }
      }
    }
    if (!updated) break;
  }

  for (int u = 1; u <= N; u++) {
    for (const Node& edge : road[u]) {
      int v = edge.dest;
      int w = edge.time;

      if (dist[u] != INF && dist[u] + w < dist[v]) {
        return true;
      }
    }

    for (const Node& edge : hole[u]) {
      int v = edge.dest;
      int w = edge.time;

      if (dist[u] != INF && dist[u] + w < dist[v]) {
        return true;
      }
    }
  }

  return false;
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int TC;
  std::cin >> TC;

  while (TC--) {
    int N, M, W;
    std::cin >> N >> M >> W;

    road.assign(N + 1, std::vector<Node>(0));
    hole.assign(N + 1, std::vector<Node>(0));

    int S, E, T;

    while (M--) {
      std::cin >> S >> E >> T;

      road[S].push_back({S, E, T});
      road[E].push_back({E, S, T});
    }

    while (W--) {
      std::cin >> S >> E >> T;

      hole[S].push_back({S, E, -T});
    }

    std::vector<int> dist(N + 1);
    std::vector<int> predecesesors(N + 1);

    bool hasNegativeCycle = false;

    for (int i = 1; i <= N; i++) {
      hasNegativeCycle = bellmanFord(N, i, dist, predecesesors);
      if (hasNegativeCycle) {
        hasNegativeCycle = true;
        break;
      }
    }

    std::cout << (hasNegativeCycle ? "YES" : "NO") << '\n';
  }

  return 0;
}
