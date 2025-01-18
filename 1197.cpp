#include <algorithm>
#include <iostream>
#include <vector>

struct Edges {
  int u, v;
  long long w;

  Edges(int u_, int v_, long long w_) : u(u_), v(v_), w(w_) {}
};

bool compareEdges(Edges& e1, Edges& e2) { return e1.w < e2.w; }

class UnionFind {
 private:
  std::vector<int> parent, rank;

 public:
  UnionFind(int n) {
    parent.resize(n + 1);
    rank.resize(n + 1, 0);
    for (int i = 0; i < +n; ++i) parent[i] = i;
  }

  ~UnionFind() {}

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
    else if (rank[rootX] < rank[rootY])
      parent[rootX] = rootY;
    else {
      parent[rootY] = rootX;
      rank[rootX]++;
    }
    return true;
  }
};

long long kruskal(int n, std::vector<Edges>& edges) {
  sort(edges.begin(), edges.end(), compareEdges);
  UnionFind uf(n);

  long long mstWeight = 0;
  std::vector<Edges> mstEdges;

  for (auto& edge : edges) {
    if (uf.unite(edge.u, edge.v)) {
      mstWeight += edge.w;
      mstEdges.push_back(edge);
    }
  }
  return mstWeight;
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int V, E;
  std::cin >> V >> E;

  std::vector<Edges> edge;

  for (int i = 1; i <= E; i++) {
    int A, B;
    long long C;
    std::cin >> A >> B >> C;

    edge.push_back({A, B, C});
  }

  int mstWeight = kruskal(V, edge);
  std::cout << mstWeight << '\n';

  return 0;
}