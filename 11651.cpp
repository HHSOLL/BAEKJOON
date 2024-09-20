#include <algorithm>
#include <iostream>

struct dot {
  int x;
  int y;
};

bool xcmp(const dot& a, const dot& b);

int main(void) {
  int num = 0;
  std::cin >> num;

  dot* d = new dot[num];

  for (int i = 0; i < num; i++) {
    std::cin >> d[i].x >> d[i].y;
  }

  std::sort(d, d + num, xcmp);
  //   std::sort(d, d + num, ycmp);

  for (int i = 0; i < num; i++) {
    std::cout << d[i].x << " " << d[i].y << '\n';
  }

  delete[] d;
  return 0;
}

bool xcmp(const dot& a, const dot& b) {
  if (a.y == b.y) {
    return a.x < b.x;
  }
  return a.y < b.y;
}