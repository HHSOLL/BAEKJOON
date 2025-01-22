#include <algorithm>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>

void findFriends(std::vector<std::vector<char>>& campus, int x, int y) {
  int dx[] = {1, -1, 0, 0};
  int dy[] = {0, 0, 1, -1};
  int N = campus.size();
  int M = campus[0].size();

  std::vector<std::vector<bool>> visited(N, std::vector<bool>(M, false));
  std::queue<std::pair<int, int>> q;
  q.push({x, y});
  visited[x][y] = true;

  int count = 0;

  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx < 0 || ny < 0 || nx >= N || ny >= M || visited[nx][ny] ||
          campus[nx][ny] == 'X') {
        continue;
      }

      visited[nx][ny] = true;

      if (campus[nx][ny] == 'P') {
        count++;
      }

      q.push({nx, ny});
    }
  }
  if (count > 0) {
    std::cout << count << "\n";
  } else {
    std::cout << "TT\n";
  }
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N, M;
  std::cin >> N >> M;

  int startX, startY;
  std::vector<std::vector<char>> campus(N, std::vector<char>(M));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      std::cin >> campus[i][j];

      if (campus[i][j] == 'I') {
        startX = i;
        startY = j;
      }
    }
  }

  findFriends(campus, startX, startY);

  return 0;
}