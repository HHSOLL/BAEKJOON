#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

int N;
int ans = 0;

std::vector<bool> col;
std::vector<bool> diag1;
std::vector<bool> diag2;

void dfs(int row) {
  if (row == N) {
    ans++;
    return;
  }

  for (int j = 0; j < N; j++) {
    if (!col[j] && !diag1[row + j] && !diag2[row - j + N - 1]) {
      col[j] = true;
      diag1[row + j] = true;
      diag2[row - j + N - 1] = true;

      dfs(row + 1);

      col[j] = false;
      diag1[row + j] = false;
      diag2[row - j + N - 1] = false;
    }
  }
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  std::cin >> N;

  col.assign(N, false);
  diag1.assign(2 * N - 1, false);
  diag2.assign(2 * N - 1, false);

  dfs(0);

  std::cout << ans << '\n';

  return 0;
}
