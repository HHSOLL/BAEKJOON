#include <iostream>
#include <queue>
#include <vector>

std::vector<std::vector<int>> baechu;
int w, h, num;
int bugCount = 0;

void bfs(int sy, int sx) {
  std::queue<std::pair<int, int>> q;
  q.push({sy, sx});
  baechu[sy][sx] = 0;

  int dx[4] = {0, 0, 1, -1};
  int dy[4] = {1, -1, 0, 0};

  while (!q.empty()) {
    auto [cy, cx] = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = cy + dy[i];
      int nx = cx + dx[i];

      if (ny >= 0 && ny < h && nx >= 0 && nx < w && baechu[ny][nx] == 1) {
        baechu[ny][nx] = 0;
        q.push({ny, nx});
      }
    }
  }
}

int main(void) {
  int n;
  std::cin >> n;

  for (int i = 0; i < n; i++) {
    std::cin >> w >> h >> num;

    baechu.assign(h, std::vector<int>(w, 0));

    for (int j = 0; j < num; j++) {
      int x, y;
      std::cin >> x >> y;
      baechu[y][x] = 1;
    }

    bugCount = 0;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (baechu[i][j] == 1) {
          bfs(i, j);
          bugCount++;
        }
      }
    }
    std::cout << bugCount << '\n';
  }

  return 0;
}