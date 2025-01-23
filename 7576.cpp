#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

int searchTomato(std::vector<std::vector<int>>& tomato) {
  int N = tomato.size();
  int M = tomato[0].size();
  int dx[] = {1, -1, 0, 0};
  int dy[] = {0, 0, 1, -1};

  std::queue<std::pair<int, int>> q;
  int day = 0;
  int unripe = 0;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (tomato[i][j] == 1) {
        q.push({i, j});
      } else if (tomato[i][j] == 0) {
        unripe++;
      }
    }
  }

  if (unripe == 0) return 0;

  while (!q.empty()) {
    int size = q.size();

    for (int i = 0; i < size; i++) {
      auto [x, y] = q.front();
      q.pop();

      for (int j = 0; j < 4; j++) {
        int nx = x + dx[j];
        int ny = y + dy[j];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M || tomato[nx][ny] != 0) {
          continue;
        }

        tomato[nx][ny] = 1;
        unripe--;
        q.push({nx, ny});
      }
    }

    day++;
  }

  if (unripe > 0) {
    return -1;
  }
  return day - 1;
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N, M;
  std::cin >> M >> N;

  std::vector<std::vector<int>> tomato(N, std::vector<int>(M, 0));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      std::cin >> tomato[i][j];
    }
  }

  std::cout << searchTomato(tomato) << '\n';

  return 0;
}