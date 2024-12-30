#include <iostream>
#include <vector>

int whiteCount = 0;
int blueCount = 0;

std::vector<std::vector<int>> v;

bool check(int x, int y, int size) {
  int color = v[x][y];
  for (int i = x; i < x + size; i++) {
    for (int j = y; j < y + size; j++) {
      if (v[i][j] != color) return false;
    }
  }
  return true;
}

void recurCube(int x, int y, int size) {
  if (check(x, y, size)) {
    if (v[x][y] == 0)
      whiteCount++;
    else
      blueCount++;
  } else {
    int half = size / 2;
    recurCube(x, y, half);
    recurCube(x, y + half, half);
    recurCube(x + half, y, half);
    recurCube(x + half, y + half, half);
  }
}

int main(void) {
  int n;
  std::cin >> n;

  v.resize(n, std::vector<int>(n, 0));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cin >> v[i][j];
    }
  }

  recurCube(0, 0, n);

  std::cout << whiteCount << '\n' << blueCount << '\n';

  return 0;
}