#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

const int INF = INT32_MAX;

bool isReachable(int V, int start, int end,
                 const std::vector<std::vector<int>>& adj) {
  std::vector<bool> visited(V, false);
  std::queue<int> q;
  q.push(start);
  visited[start] = true;

  while (!q.empty()) {
    int curr = q.front();
    q.pop();

    if (curr == end) return true;

    for (int next : adj[curr]) {
      if (!visited[next]) {
        visited[next] = true;
        q.push(next);
      }
    }
  }
  return false;
}

void bellmanFord(int V, int E, int start, int end,
                 std::vector<std::tuple<int, int, int>>& edges,
                 std::vector<int>& profit) {
  std::vector<long long> dist(V, -INF);
  dist[start] = profit[start];

  for (int i = 0; i < V - 1; i++) {
    for (auto [u, v, w] : edges) {
      if (dist[u] != -INF && dist[u] - w + profit[v] > dist[v]) {
        dist[v] = dist[u] - w + profit[v];
      }
    }
  }

  std::vector<std::vector<int>> adj(V);
  for (auto [u, v, w] : edges) {
    adj[u].push_back(v);
  }

  std::vector<bool> inPositiveCycle(V, false);
  for (auto [u, v, w] : edges) {
    if (dist[u] != -INF && dist[u] - w + profit[v] > dist[v]) {
      inPositiveCycle[v] = true;
    }
  }

  bool positiveCycleAffectsEnd = false;
  for (int i = 0; i < V; i++) {
    if (inPositiveCycle[i] && isReachable(V, i, end, adj)) {
      positiveCycleAffectsEnd = true;
      break;
    }
  }

  if (positiveCycleAffectsEnd) {
    std::cout << "Gee" << '\n';
  } else if (dist[end] == -INF) {
    std::cout << "gg" << '\n';
  } else {
    std::cout << dist[end] << '\n';
  }
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N, start, end, M;
  std::cin >> N >> start >> end >> M;

  std::vector<std::tuple<int, int, int>> edges;
  for (int i = 0; i < M; i++) {
    int from, to, cost;
    std::cin >> from >> to >> cost;

    edges.push_back({from, to, cost});
  }

  std::vector<int> profit(N);
  for (int i = 0; i < N; i++) {
    std::cin >> profit[i];
  }

  bellmanFord(N, M, start, end, edges, profit);

  return 0;
}