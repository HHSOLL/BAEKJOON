#include <iostream>
#include <vector>

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int n, m;
  std::cin >> n >> m;

  std::vector<int> v(n, 0);

  for (int i = 0; i < n; i++) {
    std::cin >> v[i];
  }

  for (int i = 1; i < n; i++) {
    v[i] += v[i - 1];
  }

  for (int i = 0; i < m; i++) {
    int from = 0, to = 0;
    std::cin >> from >> to;

    int tmp = 0;
    if (from - 2 < 0)
      tmp = 0;
    else
      tmp = v[from - 2];

    std::cout << v[to - 1] - tmp << '\n';
  }

  return 0;
}