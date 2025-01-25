#include <algorithm>
#include <iostream>
#include <vector>

const int MAX = 100001;
const int LOG = 17;

std::vector<int> tree[MAX];
int depth[MAX];
int parent[MAX][LOG];

void dfs(int node, int par) {
  depth[node] = depth[par] + 1;
  parent[node][0] = par;

  for (int child : tree[node]) {
    if (child != par) {
      dfs(child, node);
    }
  }
}

void preprocess(int N) {
  for (int j = 1; j < LOG; j++) {
    for (int i = 1; i <= N; i++) {
      parent[i][j] = parent[parent[i][j - 1]][j - 1];
    }
  }
}

int lca(int u, int v) {
  if (depth[u] < depth[v]) std::swap(u, v);

  for (int i = LOG - 1; i >= 0; i--) {
    if (depth[u] - depth[v] >= (1 << i)) {
      u = parent[u][i];
    }
  }

  if (u == v) return u;

  for (int i = LOG - 1; i >= 0; i--) {
    if (parent[u][i] != parent[v][i]) {
      u = parent[u][i];
      v = parent[v][i];
    }
  }

  return parent[u][0];
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N;
  std::cin >> N;

  for (int i = 0; i < N - 1; i++) {
    int u, v;
    std::cin >> u >> v;

    tree[u].push_back(v);
    tree[v].push_back(u);
  }

  dfs(1, 0);
  preprocess(N);

  int M;
  std::cin >> M;

  for (int i = 0; i < M; i++) {
    int v1, v2;
    std::cin >> v1 >> v2;
    std::cout << lca(v1, v2) << '\n';
  }

  return 0;
}