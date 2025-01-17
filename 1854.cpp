#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

struct CITY {
  int city;
  int weight;
};

void dijkstra(int start, std::vector<std::vector<CITY>>& adj,
              std::vector<std::priority_queue<int>>& dist, int k) {
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                      std::greater<>>
      pq;

  pq.push({0, start});
  dist[start].push(0);

  while (!pq.empty()) {
    int currDist = pq.top().first;
    int currCity = pq.top().second;
    pq.pop();

    for (auto next : adj[currCity]) {
      int nextCity = next.city;
      int nextDist = next.weight + currDist;

      if (dist[nextCity].size() < k) {
        dist[nextCity].push(nextDist);
        pq.push({nextDist, nextCity});
      } else if (dist[nextCity].top() > nextDist) {
        dist[nextCity].pop();
        dist[nextCity].push(nextDist);
        pq.push({nextDist, nextCity});
      }
    }
  }
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  // 도시 , 도로 , k번째
  int n, m, k;
  std::cin >> n >> m >> k;

  // 도로정보 저장할 인접행렬
  std::vector<std::vector<CITY>> adj(n + 1);

  // 인접행렬 채우기
  for (int i = 0; i < m; i++) {
    // a -> b 걸리는 시간 c
    int a, b, c;
    std::cin >> a >> b >> c;

    adj[a].push_back({b, c});
  }

  // 거리배열
  std::vector<std::priority_queue<int>> dist(n + 1);

  dijkstra(1, adj, dist, k);

  for (int i = 1; i <= n; i++) {
    if (dist[i].size() < k)
      std::cout << -1 << '\n';
    else
      std::cout << dist[i].top() << '\n';
  }

  return 0;
}