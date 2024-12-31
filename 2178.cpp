#include <iostream>
#include <queue>
#include <vector>

std::vector<std::vector<int>> maze;
std::vector<std::vector<int>> dist;
int h, w;

void bfs(int sy, int sx) {
  std::queue<std::pair<int, int>> q;
  q.push({sy, sx});
  dist[sy][sx] = 1;

  int dx[4] = {0, 0, 1, -1};
  int dy[4] = {1, -1, 0, 0};

  while (!q.empty()) {
    auto [cy, cx] = q.front();
    q.pop();

    if (cy == h - 1 && cx == w - 1) {
      std::cout << dist[cy][cx] << '\n';
      return;
    }

    for (int i = 0; i < 4; i++) {
      int ny = cy + dy[i];
      int nx = cx + dx[i];

      if (ny >= 0 && ny < h && nx >= 0 && nx < w && maze[ny][nx] == 1 &&
          dist[ny][nx] == 0) {
        dist[ny][nx] = dist[cy][cx] + 1;
        q.push({ny, nx});
      }
    }
  }
}

int main(void) {
  std::cin >> h >> w;

  maze.assign(h, std::vector<int>(w, 0));
  dist.assign(h, std::vector<int>(w, 0));

  for (int i = 0; i < h; i++) {
    std::string tmp;
    std::cin >> tmp;

    for (int j = 0; j < w; j++) {
      maze[i][j] = tmp[j] - '0';
    }
  }

  bfs(0, 0);

  return 0;
}