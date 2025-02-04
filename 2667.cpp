#include <algorithm>
#include <climits>
#include <iomanip>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

int bfs(int N, int startX, int startY, std::vector<std::vector<int>>& city,
        int label) {
  int dx[4] = {1, -1, 0, 0};
  int dy[4] = {0, 0, 1, -1};

  std::queue<std::pair<int, int>> q;
  int count = 0;

  q.push({startX, startY});
  city[startX][startY] = label;

  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    count++;

    for (int dir = 0; dir < 4; dir++) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];

      if (nx >= 0 && ny >= 0 && nx < N && ny < N && city[nx][ny] == 1) {
        q.push({nx, ny});
        city[nx][ny] = label;
      }
    }
  }

  return count;
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N;
  std::cin >> N;

  std::vector<std::vector<int>> city(N, std::vector<int>(N, 0));
  for (int i = 0; i < N; i++) {
    std::string str;
    std::cin >> str;

    for (int j = 0; j < N; j++) {
      city[i][j] = int(str[j] - '0');
    }
  }

  std::vector<int> count;
  int label = 2;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (city[i][j] == 1) {
        int cnt = bfs(N, i, j, city, label);
        count.push_back(cnt);
        label++;
      }
    }
  }

  std::sort(count.begin(), count.end());

  std::cout << count.size() << '\n';

  for (int num : count) {
    std::cout << num << '\n';
  }

  return 0;
}
