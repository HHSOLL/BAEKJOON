#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

struct City {
  int city;
  int time;
};

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  // 도시의 개수
  int n;
  std::cin >> n;
  std::vector<std::vector<City>> c(n + 1, std::vector<City>());
  std::vector<std::vector<City>> rc(n + 1, std::vector<City>());
  std::vector<int> inDegree(n + 1, 0);

  // 도로 정보
  int m;
  std::cin >> m;

  for (int i = 1; i <= m; i++) {
    int from, to;
    int time;

    std::cin >> from >> to >> time;

    c[from].push_back({to, time});
    rc[to].push_back({from, time});
    inDegree[to]++;
  }

  // 위상정렬 이용해 정방향 그래프에서 목적지까지의 최대 시간 구하기
  std::vector<int> dist(n + 1, 0);
  std::queue<int> q;

  for (int i = 1; i <= n; i++) {
    if (inDegree[i] == 0) q.push(i);
  }

  while (!q.empty()) {
    int curr = q.front();
    q.pop();

    for (auto next : c[curr]) {
      int nextCity = next.city;
      int travelTime = next.time;

      if (dist[nextCity] < dist[curr] + travelTime)
        dist[nextCity] = dist[curr] + travelTime;

      if (--inDegree[nextCity] == 0) q.push(nextCity);
    }
  }

  int startCity, destCity;
  std::cin >> startCity >> destCity;

  int maxTime = dist[destCity];
  std::cout << maxTime << '\n';

  // 역방향 그래프에서 필수적으로 지나야 하는 도로 추적
  int roads = 0;
  std::vector<bool> visited(n + 1, false);
  std::queue<int> rq;
  rq.push(destCity);
  visited[destCity] = true;

  while (!rq.empty()) {
    int curr = rq.front();
    rq.pop();

    for (auto prev : rc[curr]) {
      int prevCity = prev.city;
      int travelTime = prev.time;

      if (dist[prevCity] + travelTime == dist[curr]) {
        roads++;
        if (!visited[prevCity]) {
          rq.push(prevCity);
          visited[prevCity] = true;
        }
      }
    }
  }

  std::cout << roads << '\n';

  return 0;
}