#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N, K;
  std::cin >> N >> K;

  if (N >= K) {
    std::cout << N - K << '\n';
    return 0;
  }

  const int MAX_LIMIT = 100000;
  std::vector<int> dist(MAX_LIMIT + 1, -1);
  std::queue<int> q;

  q.push(N);
  dist[N] = 0;

  while (!q.empty()) {
    int curr = q.front();
    q.pop();

    if (curr == K) {
      std::cout << dist[curr] << '\n';
      return 0;
    }

    int nextPos[3] = {curr - 1, curr + 1, curr * 2};
    for (int i = 0; i < 3; i++) {
      int next = nextPos[i];

      if (next >= 0 && next <= MAX_LIMIT && dist[next] == -1) {
        dist[next] = dist[curr] + 1;
        q.push(next);
      }
    }
  }

  return 0;
}
