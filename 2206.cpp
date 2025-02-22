#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using ll = long long;
const int INF = INT_MAX;

int N, M;

std::vector<std::vector<int>> maze;
std::vector<std::vector<std::vector<bool>>> visited;

int bfs() {
  std::queue<std::tuple<int, int, int, int>> q;
  q.push({0, 0, 0, 1});
  visited[0][0][0] = true;

  int dx[4] = {1, -1, 0, 0};
  int dy[4] = {0, 0, 1, -1};

  while (!q.empty()) {
    auto [x, y, broke, dist] = q.front();
    q.pop();

    if (x == N - 1 && y == M - 1) {
      return dist;
    }

    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
        if (maze[nx][ny] == 0 && !visited[nx][ny][broke]) {
          visited[nx][ny][broke] = true;
          q.push({nx, ny, broke, dist + 1});
        } else if (maze[nx][ny] == 1 && broke == 0 && !visited[nx][ny][1]) {
          visited[nx][ny][1] = true;
          q.push({nx, ny, 1, dist + 1});
        }
      }
    }
  }
  return -1;
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  std::cin >> N >> M;

  maze.assign(N, std::vector<int>(M));
  visited.assign(
      N, std::vector<std::vector<bool>>(M, std::vector<bool>(2, false)));

  for (int i = 0; i < N; i++) {
    std::string str;
    std::cin >> str;

    for (int j = 0; j < M; j++) {
      maze[i][j] = str[j] - '0';
    }
  }

  std::cout << bfs() << '\n';

  return 0;
}
