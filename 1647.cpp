#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

struct Edge {
  int u, v, w;
  Edge(int u_, int v_, int w_) : u(u_), v(v_), w(w_) {}
};

bool cmp(const Edge& a, const Edge& b) { return a.w < b.w; }

int findParent(std::vector<int>& parent, int x) {
  if (parent[x] == x) return x;
  return parent[x] = findParent(parent, parent[x]);
}

bool unionNodes(std::vector<int>& parent, int a, int b) {
  a = findParent(parent, a);
  b = findParent(parent, b);

  if (a == b) return false;

  if (a > b)
    parent[a] = b;
  else
    parent[b] = a;

  return true;
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N, M;
  std::cin >> N >> M;

  std::vector<Edge> edges;
  for (int i = 0; i < M; i++) {
    int u, v, w;
    std::cin >> u >> v >> w;

    edges.push_back({u, v, w});
  }

  std::sort(edges.begin(), edges.end(), cmp);

  std::vector<int> parent(N + 1);
  for (int i = 1; i <= N; i++) parent[i] = i;

  int mstCost = 0;
  int maxEdgeCost = 0;

  for (auto& edge : edges) {
    if (unionNodes(parent, edge.u, edge.v)) {
      mstCost += edge.w;

      if (edge.w > maxEdgeCost) {
        maxEdgeCost = edge.w;
      }
    }
  }

  std::cout << (mstCost - maxEdgeCost) << '\n';

  return 0;
}
