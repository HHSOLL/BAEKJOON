#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

struct Point {
  double x, y;
};

double polygonArea(const std::vector<Point>& vertices) {
  double sum = 0;
  int n = vertices.size();

  for (int i = 0; i < n; i++) {
    int j = (i + 1) % n;
    sum += (vertices[i].x * vertices[j].y) - (vertices[i].y * vertices[j].x);
  }

  return fabs(sum) / 2.0;
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N;
  std::cin >> N;

  std::vector<Point> c(N);
  for (int i = 0; i < N; i++) {
    std::cin >> c[i].x >> c[i].y;
  }

  std::cout << std::fixed << std::setprecision(1) << polygonArea(c) << '\n';

  return 0;
}
