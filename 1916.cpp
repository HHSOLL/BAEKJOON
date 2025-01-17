#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

struct CITY {
  int city;
  int weight;
};

void dijkstra(int start, std::vector<std::vector<CITY>>& adj,
              std::vector<int>& dist) {
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                      std::greater<>>
      pq;

  pq.push({0, start});
  dist[start] = 0;

  while (!pq.empty()) {
    int currDist = pq.top().first;
    int currCity = pq.top().second;
    pq.pop();

    if (currDist > dist[currCity]) continue;

    for (auto next : adj[currCity]) {
      int nextCity = next.city;
      int nextWeight = next.weight;

      if (dist[nextCity] > currDist + nextWeight) {
        dist[nextCity] = currDist + nextWeight;
        pq.push({dist[nextCity], nextCity});
      }
    }
  }
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N;
  std::cin >> N;

  int M;
  std::cin >> M;

  std::vector<std::vector<CITY>> adj(N + 1);
  std::vector<int> dist(N + 1, INT32_MAX);
  for (int i = 0; i < M; i++) {
    int from, to, w;
    std::cin >> from >> to >> w;

    adj[from].push_back({to, w});
  }

  int start, end;
  std::cin >> start >> end;

  dijkstra(start, adj, dist);

  std::cout << dist[end] << '\n';

  return 0;
}