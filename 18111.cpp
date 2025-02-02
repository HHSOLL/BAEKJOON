#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <vector>

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N, M, B;
  std::cin >> N >> M >> B;

  std::vector<std::vector<int>> ground(N, std::vector<int>(M));
  int minH = 256;
  int maxH = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      std::cin >> ground[i][j];

      minH = std::min(minH, ground[i][j]);
      maxH = std::max(maxH, ground[i][j]);
    }
  }

  const int MAX_HEIGHT = 256;
  int bestTime = INT_MAX;
  int bestHeight = 0;

  for (int h = 0; h <= MAX_HEIGHT; h++) {
    long long removeBlocks = 0;
    long long addBlocks = 0;
    int time = 0;

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        int current = ground[i][j];
        if (current > h) {
          removeBlocks += (current - h);
          time += 2 * (current - h);
        } else if (current < h) {
          addBlocks += (h - current);
          time += (h - current);
        }
      }
    }

    if (removeBlocks + B < addBlocks) continue;

    if (time < bestTime) {
      bestTime = time;
      bestHeight = h;
    } else if (time == bestTime && h > bestHeight) {
      bestHeight = h;
    }
  }

  std::cout << bestTime << " " << bestHeight << '\n';

  return 0;
}
