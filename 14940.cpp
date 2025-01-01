#include <iostream>
#include <queue>
#include <vector>

int n, m;

std::vector<std::vector<int>> v;
std::vector<std::vector<int>> dist;

void bfs(int sy, int sx) {
  std::queue<std::pair<int, int>> q;
  q.push({sy, sx});
  dist[sy][sx] = 0;

  int dx[4] = {0, 0, 1, -1};
  int dy[4] = {1, -1, 0, 0};

  while (!q.empty()) {
    auto [cy, cx] = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = cy + dy[i];
      int nx = cx + dx[i];

      if (ny >= 0 && ny < n && nx >= 0 && nx < m && v[ny][nx] == 1 &&
          dist[ny][nx] == 0) {
        dist[ny][nx] = dist[cy][cx] + 1;
        q.push({ny, nx});
      }
    }
  }
}

int main(void) {
  std::cin >> n >> m;

  v.assign(n, std::vector<int>(m, 0));
  dist.assign(n, std::vector<int>(m, 0));

  int sx = 0, sy = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> v[i][j];
      if (v[i][j] == 2) {
        sy = i;
        sx = j;
      }
    }
  }

  bfs(sy, sx);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (dist[i][j] == 0 && v[i][j] == 1) dist[i][j] = -1;
      std::cout << dist[i][j] << " ";
    }
    std::cout << '\n';
  }
  std::cout << '\n';

  return 0;
}