#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N;
  std::cin >> N;

  std::vector<std::vector<char>> rgb(N, std::vector<char>(N));
  for (int i = 0; i < N; i++) {
    std::string s;
    std::cin >> s;

    for (int j = 0; j < N; j++) {
      rgb[i][j] = s[j];
    }
  }

  std::vector<std::vector<bool>> visitedNormal(N, std::vector<bool>(N, false));
  std::vector<std::vector<bool>> visitedBlind(N, std::vector<bool>(N, false));

  int dx[4] = {1, -1, 0, 0};
  int dy[4] = {0, 0, 1, -1};

  auto dfs = [&](int i, int j, std::vector<std::vector<bool>>& visited,
                 const std::function<bool(char, char)>& compare) {
    std::function<void(int, int)> dfsRec = [&](int x, int y) {
      visited[x][y] = true;
      for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny] &&
            compare(rgb[x][y], rgb[nx][ny])) {
          dfsRec(nx, ny);
        }
      }
    };
    dfsRec(i, j);
  };

  auto normalCompare = [&](char a, char b) -> bool { return a == b; };

  auto blindCompare = [&](char a, char b) -> bool {
    if (a == b) return true;
    if ((a == 'R' || a == 'G') && (b == 'R' || b == 'G')) return true;
    return false;
  };

  int countNormal = 0;
  int countBlind = 0;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (!visitedNormal[i][j]) {
        dfs(i, j, visitedNormal, normalCompare);
        countNormal++;
      }
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (!visitedBlind[i][j]) {
        dfs(i, j, visitedBlind, blindCompare);
        countBlind++;
      }
    }
  }

  std::cout << countNormal << " " << countBlind << '\n';

  return 0;
}
