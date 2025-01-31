#include <algorithm>
#include <iostream>
#include <vector>

struct coordinate {
  int x;
  int y;
};

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  std::vector<coordinate> v(3);

  for (int i = 0; i < 3; i++) {
    std::cin >> v[i].x >> v[i].y;
  }

  int cross = (v[1].x - v[0].x) * (v[2].y - v[1].y) -
              (v[1].y - v[0].y) * (v[2].x - v[1].x);

  if (cross > 0) {
    std::cout << "1\n";
  } else if (cross < 0) {
    std::cout << "-1\n";
  } else {
    std::cout << "0\n";
  }

  return 0;
}
