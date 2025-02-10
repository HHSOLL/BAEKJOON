#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

std::vector<std::vector<int>> adj;
std::vector<int> subTreeSize;

void dfs(int curr, int parent) {
  subTreeSize[curr] = 1;
  for (int next : adj[curr]) {
    if (next == parent) continue;

    dfs(next, curr);
    subTreeSize[curr] += subTreeSize[next];
  }
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N, R, Q;
  std::cin >> N >> R >> Q;

  adj.assign(N + 1, std::vector<int>());
  subTreeSize.assign(N + 1, 1);

  for (int i = 0; i < N - 1; i++) {
    int U, V;
    std::cin >> U >> V;

    adj[U].push_back(V);
    adj[V].push_back(U);
  }

  dfs(R, -1);

  for (int i = 0; i < Q; i++) {
    int query;
    std::cin >> query;

    std::cout << subTreeSize[query] << '\n';
  }

  return 0;
}
