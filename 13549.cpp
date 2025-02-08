#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

void find(int start, int end) {}

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

  const int range = 100001;
  std::vector<int> pos(range, -1);
  std::deque<int> dq;

  dq.push_back(N);
  pos[N] = 0;

  while (!dq.empty()) {
    int curr = dq.front();
    dq.pop_front();

    if (curr == K) {
      std::cout << pos[curr] << '\n';
      return 0;
    }

    int next = curr * 2;
    if (next < range && pos[next] == -1) {
      pos[next] = pos[curr];
      dq.push_front(next);
    }

    next = curr - 1;
    if (next >= 0 && pos[next] == -1) {
      pos[next] = pos[curr] + 1;
      dq.push_back(next);
    }

    next = curr + 1;
    if (next < range && pos[next] == -1) {
      pos[next] = pos[curr] + 1;
      dq.push_back(next);
    }
  }

  return 0;
}
