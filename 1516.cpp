#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

struct building {
  int structure;
  int time;
};

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N;
  std::cin >> N;

  std::vector<int> build_time(N + 1, 0);
  std::vector<std::vector<building>> v(N + 1);
  std::vector<int> d(N + 1, 0);

  // 건설시간, 선수건물 입력받아 초기화
  for (int i = 1; i <= N; i++) {
    int t;
    std::cin >> t;
    build_time[i] = t;

    int pre;
    while (true) {
      std::cin >> pre;
      if (pre == -1) break;

      v[pre].push_back({i, build_time[pre]});
      d[i]++;
    }
  }

  // 차수가 0인 것 먼저 큐에 삽입
  std::vector<int> result(N + 1, 0);
  std::queue<int> q;
  for (int i = 1; i <= N; i++) {
    if (d[i] == 0) {
      q.push(i);
    }
  }

  // 큐가 빌 때까지 과정 반복
  while (!q.empty()) {
    int curr = q.front();
    q.pop();

    for (building& next : v[curr]) {
      result[next.structure] =
          std::max(result[next.structure], result[curr] + build_time[curr]);
      d[next.structure]--;

      if (d[next.structure] == 0) q.push(next.structure);
    }
  }

  for (int i = 1; i <= N; i++) {
    result[i] += build_time[i];
    std::cout << result[i] << '\n';
  }

  return 0;
}