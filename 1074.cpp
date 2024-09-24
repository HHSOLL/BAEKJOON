#include <cmath>
#include <iostream>

int Z(int n, int r, int c) {
  if (n == 0) return 0;

  int half = pow(2, n - 1);

  if (r < half && c < half)
    return Z(n - 1, r, c);
  else if (r < half && c >= half)
    return pow(2, 2 * n - 2) + Z(n - 1, r, c - half);
  else if (r >= half && c < half)
    return pow(2, 2 * n - 1) + Z(n - 1, r - half, c);

  return 3 * pow(2, 2 * n - 2) + Z(n - 1, r - half, c - half);
}

int main(void) {
  int n, r, c;
  std::cin >> n >> r >> c;

  std::cout << Z(n, r, c) << '\n';

  return 0;
}