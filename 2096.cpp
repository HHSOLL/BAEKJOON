#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N;
  std::cin >> N;

  int a, b, c;
  std::cin >> a >> b >> c;

  int prevMax[3] = {a, b, c};
  int prevMin[3] = {a, b, c};

  for (int i = 1; i < N; i++) {
    std::cin >> a >> b >> c;

    int currMax[3], currMin[3];

    currMax[0] = a + std::max(prevMax[0], prevMax[1]);
    currMax[1] = b + std::max({prevMax[0], prevMax[1], prevMax[2]});
    currMax[2] = c + std::max(prevMax[1], prevMax[2]);

    currMin[0] = a + std::min(prevMin[0], prevMin[1]);
    currMin[1] = b + std::min({prevMin[0], prevMin[1], prevMin[2]});
    currMin[2] = c + std::min(prevMin[1], prevMin[2]);

    for (int j = 0; j < 3; j++) {
      prevMax[j] = currMax[j];
      prevMin[j] = currMin[j];
    }
  }

  std::cout << std::max({prevMax[0], prevMax[1], prevMax[2]}) << " "
            << std::min({prevMin[0], prevMin[1], prevMin[2]}) << '\n';

  return 0;
}
