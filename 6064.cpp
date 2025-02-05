#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int T;
  std::cin >> T;

  while (T--) {
    int M, N, x, y;
    std::cin >> M >> N >> x >> y;

    int ans = -1;
    for (int k = x; k <= M * N; k += M) {
      int currY = (k % N == 0 ? N : k % N);
      if (currY == y) {
        ans = k;
        break;
      }
    }
    std::cout << ans << '\n';
  }

  return 0;
}
