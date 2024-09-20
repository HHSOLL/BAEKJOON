#include <algorithm>
#include <iostream>
#include <vector>

char p1[8][9] = {"BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB",
                 "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB"};
char p2[8][9] = {"WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW",
                 "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW"};

int checkMiss(const char p[8][9], const std::vector<std::string>& v, int x,
              int y);

int main(void) {
  int m, n;
  std::cin >> m >> n;

  std::vector<std::string> v(m);

  for (int i = 0; i < m; i++) {
    std::cin >> v[i];
  }

  int min = 64;
  for (int x = 0; x <= m - 8; x++) {
    for (int y = 0; y <= n - 8; y++) {
      int check1 = checkMiss(p1, v, x, y);
      int check2 = checkMiss(p2, v, x, y);
      int min_check = std::min(check1, check2);
      min = std::min(min, min_check);
    }
  }

  std::cout << min << '\n';

  return 0;
}

int checkMiss(const char p[8][9], const std::vector<std::string>& v, int x,
              int y) {
  int missCount = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (p[i][j] != v[x + i][y + j]) {
        missCount++;
      }
    }
  }
  return missCount;
}