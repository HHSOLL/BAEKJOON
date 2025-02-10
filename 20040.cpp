#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

int findParent(std::vector<int>& parent, int x) {
  if (parent[x] == x) {
    return x;
  }
  return parent[x] = findParent(parent, parent[x]);
}

bool unionNodes(std::vector<int>& parent, int a, int b) {
  a = findParent(parent, a);
  b = findParent(parent, b);

  if (a == b) return false;
  if (a < b)
    parent[b] = a;
  else
    parent[a] = b;

  return true;
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int n, m;
  std::cin >> n >> m;

  std::vector<int> parent(n);
  for (int i = 0; i < n; i++) parent[i] = i;

  int ans = 0;
  for (int i = 0; i < m; i++) {
    int u, v;
    std::cin >> u >> v;

    if (!unionNodes(parent, u, v) && ans == 0) {
      ans = i + 1;
      break;
    }
  }

  std::cout << ans << '\n';

  return 0;
}
