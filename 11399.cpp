#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int N;
  std::cin >> N;
  std::vector<int> v(N, 0);
  for (int i = 0; i < N; i++) {
    std::cin >> v[i];
  }

  sort(v.begin(), v.end());

  int sum = v[0];
  for (int i = 1; i < N; i++) {
    v[i] += v[i - 1];
    sum += v[i];
  }

  std::cout << sum << '\n';

  return 0;
}