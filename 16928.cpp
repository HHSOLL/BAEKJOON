#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N, M;
  std::cin >> N >> M;

  std::vector<int> board(101);

  for (int i = 1; i <= 100; i++) {
    board[i] = i;
  }

  for (int i = 0; i < N; i++) {
    int ladderFrom, ladderTo;
    std::cin >> ladderFrom >> ladderTo;
    board[ladderFrom] = ladderTo;
  }

  for (int i = 0; i < M; i++) {
    int snakeFrom, snakeTo;
    std::cin >> snakeFrom >> snakeTo;
    board[snakeFrom] = snakeTo;
  }

  std::queue<std::pair<int, int>> q;
  std::vector<bool> visited(101, false);

  q.push({1, 0});
  visited[1] = true;

  while (!q.empty()) {
    auto [curr, count] = q.front();
    q.pop();

    for (int i = 1; i <= 6; i++) {
      int next = curr + i;

      if (next > 100) continue;

      int nextPos = board[next];

      if (!visited[nextPos]) {
        visited[nextPos] = true;
        if (nextPos == 100) {
          std::cout << count + 1 << '\n';
          return 0;
        }
        q.push({nextPos, count + 1});
      }
    }
  }

  return 0;
}
