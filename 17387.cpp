#include <algorithm>
#include <iostream>
#include <vector>

struct Coordinate {
  long long x, y;
};

int ccw(Coordinate a, Coordinate b, Coordinate c) {
  long long cross = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
  if (cross > 0) return 1;
  if (cross < 0) return -1;
  return 0;
}

bool isOverlapping(Coordinate a, Coordinate b, Coordinate c, Coordinate d) {
  long long aMinX = std::min(a.x, b.x);
  long long aMaxX = std::max(a.x, b.x);

  long long aMinY = std::min(a.y, b.y);
  long long aMaxY = std::max(a.y, b.y);

  long long cMinX = std::min(c.x, d.x);
  long long cMaxX = std::max(c.x, d.x);

  long long cMinY = std::min(c.y, d.y);
  long long cMaxY = std::max(c.y, d.y);

  bool overlapX = (aMinX <= cMaxX) && (cMinX <= aMaxX);
  bool overlapY = (aMinY <= cMaxY) && (cMinY <= aMaxY);

  return (overlapX && overlapY);
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  std::vector<Coordinate> l1(2);
  std::vector<Coordinate> l2(2);

  std::cin >> l1[0].x >> l1[0].y >> l1[1].x >> l1[1].y;
  std::cin >> l2[0].x >> l2[0].y >> l2[1].x >> l2[1].y;

  int ccw1 = ccw(l1[0], l1[1], l2[0]);
  int ccw2 = ccw(l1[0], l1[1], l2[1]);
  int ccw3 = ccw(l2[0], l2[1], l1[0]);
  int ccw4 = ccw(l2[0], l2[1], l1[1]);

  if (ccw1 * ccw2 < 0 && ccw3 * ccw4 < 0) {
    std::cout << 1 << '\n';
  }

  else if (ccw1 == 0 && ccw2 == 0 && ccw3 == 0 && ccw4 == 0) {
    if (isOverlapping(l1[0], l1[1], l2[0], l2[1])) {
      std::cout << 1 << '\n';
    } else {
      std::cout << 0 << '\n';
    }
  }

  else if (ccw1 == 0 && (l2[0].x >= std::min(l1[0].x, l1[1].x) &&
                         l2[0].x <= std::max(l1[0].x, l1[1].x) &&
                         l2[0].y >= std::min(l1[0].y, l1[1].y) &&
                         l2[0].y <= std::max(l1[0].y, l1[1].y))) {
    std::cout << 1 << '\n';
  } else if (ccw2 == 0 && (l2[1].x >= std::min(l1[0].x, l1[1].x) &&
                           l2[1].x <= std::max(l1[0].x, l1[1].x) &&
                           l2[1].y >= std::min(l1[0].y, l1[1].y) &&
                           l2[1].y <= std::max(l1[0].y, l1[1].y))) {
    std::cout << 1 << '\n';
  } else if (ccw3 == 0 && (l1[0].x >= std::min(l2[0].x, l2[1].x) &&
                           l1[0].x <= std::max(l2[0].x, l2[1].x) &&
                           l1[0].y >= std::min(l2[0].y, l2[1].y) &&
                           l1[0].y <= std::max(l2[0].y, l2[1].y))) {
    std::cout << 1 << '\n';
  } else if (ccw4 == 0 && (l1[1].x >= std::min(l2[0].x, l2[1].x) &&
                           l1[1].x <= std::max(l2[0].x, l2[1].x) &&
                           l1[1].y >= std::min(l2[0].y, l2[1].y) &&
                           l1[1].y <= std::max(l2[0].y, l2[1].y))) {
    std::cout << 1 << '\n';
  } else {
    std::cout << 0 << '\n';
  }

  return 0;
}
