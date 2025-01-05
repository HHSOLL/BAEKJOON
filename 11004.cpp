#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N, K;
  std::cin >> N >> K;

  std::vector<int> v(N, 0);
  for (int i = 0; i < N; i++) {
    std::cin >> v[i];
  }

  std::sort(v.begin(), v.end());

  std::cout << v[K - 1] << '\n';

  return 0;
}