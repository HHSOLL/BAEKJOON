#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

int N, M;
int ans = 0;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

std::vector<std::vector<int>> paper;
std::vector<std::vector<bool>> visited;

void dfs(int x, int y, int depth, int sum) {
  if (depth == 4) {
    ans = std::max(ans, sum);
    return;
  }

  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (nx >= 0 && ny >= 0 && nx < N && ny < M && !visited[nx][ny]) {
      visited[nx][ny] = true;
      dfs(nx, ny, depth + 1, sum + paper[nx][ny]);
      visited[nx][ny] = false;
    }
  }
}

void checkT(int x, int y) {
  int sum = paper[x][y];
  int min = 1e9;
  int cnt = 0;

  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
    cnt++;
    sum += paper[nx][ny];
    min = std::min(min, paper[nx][ny]);

    if (cnt < 3) continue;

    if (cnt == 4) {
      sum -= min;
    }

    ans = std::max(ans, sum);
  }
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  std::cin >> N >> M;

  paper.assign(N, std::vector<int>(M));
  visited.assign(N, std::vector<bool>(M, false));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      std::cin >> paper[i][j];
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      visited[i][j] = true;
      dfs(i, j, 1, paper[i][j]);
      visited[i][j] = false;
      checkT(i, j);
    }
  }

  std::cout << ans << '\n';

  return 0;
}
