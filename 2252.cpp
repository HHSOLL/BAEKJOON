#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N, M;
  std::cin >> N >> M;

  std::vector<std::vector<int>> v(N + 1, std::vector<int>());
  std::vector<int> d(N + 1, 0);

  for (int i = 0; i < M; i++) {
    int a, b;
    std::cin >> a >> b;

    v[a].push_back(b);

    d[b]++;
  }

  std::queue<int> q;
  for (int i = 1; i <= N; i++) {
    if (d[i] == 0) {
      q.push(i);
    }
  }

  while (!q.empty()) {
    int curr = q.front();
    q.pop();

    std::cout << curr << " ";

    for (int& next : v[curr]) {
      d[next]--;
      if (d[next] == 0) {
        q.push(next);
      }
    }
  }
  std::cout << '\n';

  return 0;
}