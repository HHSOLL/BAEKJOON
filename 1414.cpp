#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

struct Edge {
  int u, v, w;
  Edge(int u_, int v_, int w_) : u(u_), v(v_), w(w_) {}
};

class UnionFind {
 private:
  std::vector<int> parent, rank;

 public:
  UnionFind(int n) {
    parent.resize(n + 1);
    rank.resize(n + 1);
    for (int i = 0; i <= n; i++) parent[i] = i;
  }

  int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
  }

  bool unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX == rootY) return false;

    if (rank[rootX] > rank[rootY])
      parent[rootY] = rootX;
    else if (rank[rootY] > rank[rootX])
      parent[rootX] = rootY;
    else {
      parent[rootY] = rootX;
      rank[rootX]++;
    }
    return true;
  }
};

int kruskal(int N, std::vector<Edge>& edges) {
  std::sort(edges.begin(), edges.end(),
            [](Edge& a, Edge& b) { return a.w < b.w; });

  UnionFind uf(N);
  int mstWeight = 0;
  int edgeCount = 0;

  std::vector<Edge> mstEdges;

  for (auto& edge : edges) {
    if (uf.unite(edge.u, edge.v)) {
      mstWeight += edge.w;
      mstEdges.push_back(edge);
      edgeCount++;
    }
  }

  return edgeCount == N - 1 ? mstWeight : -1;
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N;
  std::cin >> N;

  std::vector<std::vector<int>> adj(N + 1, std::vector<int>(N + 1, 0));

  int sum = 0;
  for (int i = 1; i <= N; i++) {
    std::string str;
    std::cin >> str;

    for (int j = 0; j < N; j++) {
      int tmp = int(str[j]);
      if (tmp == 48) {
        adj[i][j + 1] = 0;
      } else if (tmp >= 97) {
        adj[i][j + 1] = tmp - 96;
      } else if (tmp < 97) {
        adj[i][j + 1] = tmp - 38;
      }

      sum += adj[i][j + 1];
    }
  }

  std::vector<Edge> edges;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (adj[i][j] != 0) {
        if (i != j && adj[i][j] != 0) {
          edges.push_back({i, j, adj[i][j]});
        }
      }
    }
  }

  int result = kruskal(N, edges);
  if (result == -1) {
    std::cout << -1 << '\n';
  } else {
    std::cout << sum - result << '\n';
  }

  return 0;
}