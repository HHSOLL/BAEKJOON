#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int M, N, H;
  std::cin >> M >> N >> H;

  std::vector<std::vector<std::vector<int>>> tomato(
      H, std::vector<std::vector<int>>(N, std::vector<int>(M, 0)));

  int unripe = 0;
  std::queue<std::tuple<int, int, int>> q;

  for (int h = 0; h < H; h++) {
    for (int n = 0; n < N; n++) {
      for (int m = 0; m < M; m++) {
        std::cin >> tomato[h][n][m];

        if (tomato[h][n][m] == 0) {
          unripe++;
        } else if (tomato[h][n][m] == 1) {
          q.push({h, n, m});
        }
      }
    }
  }

  if (unripe == 0) {
    std::cout << 0 << '\n';
    return 0;
  }

  int dh[] = {1, -1, 0, 0, 0, 0};
  int dn[] = {0, 0, 1, -1, 0, 0};
  int dm[] = {0, 0, 0, 0, 1, -1};
  int day = 0;

  while (!q.empty()) {
    int size = q.size();

    for (int i = 0; i < size; i++) {
      auto [h, n, m] = q.front();
      q.pop();

      for (int j = 0; j < 6; j++) {
        int nh = h + dh[j];
        int nn = n + dn[j];
        int nm = m + dm[j];

        if (nh < 0 || nh >= H || nn < 0 || nn >= N || nm < 0 || nm >= M)
          continue;

        if (tomato[nh][nn][nm] == 0) {
          tomato[nh][nn][nm] = 1;
          unripe--;
          q.push({nh, nn, nm});
        }
      }
    }
    day++;
  }

  if (unripe > 0) {
    std::cout << -1 << '\n';
  } else {
    std::cout << day - 1 << '\n';
  }

  return 0;
}