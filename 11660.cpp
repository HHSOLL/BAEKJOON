#include <iostream>
#include <vector>

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int n, m;
  std::cin >> n >> m;

  std::vector<std::vector<int>> v(n + 1, std::vector<int>(n + 1, 0));
  std::vector<std::vector<int>> sum(n + 1, std::vector<int>(n + 1, 0));

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      std::cin >> v[i][j];
    }
  }

  // dp table
  {
    sum[1][1] = v[1][1];
    for (int i = 1; i <= n; i++) {
      sum[i][1] = v[i][1] + sum[i - 1][1];
      sum[1][i] = v[1][i] + sum[1][i - 1];
    }

    for (int i = 2; i <= n; i++) {
      for (int j = 2; j <= n; j++) {
        sum[i][j] = v[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
      }
    }
  }

  while (m--) {
    int x1, x2, y1, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;

    int ans =
        sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
    std::cout << ans << '\n';
  }

  return 0;
}