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
    if (parent[x] != x) {
      parent[x] = find(parent[x]);
    }
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

int bfs(int N, int M, std::vector<std::vector<int>>& country) {
  int islandId = 2;

  std::vector<std::vector<bool>> visited(N + 1,
                                         std::vector<bool>(M + 1, false));
  std::queue<std::pair<int, int>> q;

  int dx[] = {1, -1, 0, 0};
  int dy[] = {0, 0, 1, -1};

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (country[i][j] == 1 && visited[i][j] == false) {
        q.push({i, j});
        visited[i][j] = true;
        country[i][j] = islandId;

        while (!q.empty()) {
          auto [x, y] = q.front();
          q.pop();

          for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx >= 0 && ny >= 0 && nx < N && ny < M && !visited[nx][ny] &&
                country[nx][ny] == 1) {
              q.push({nx, ny});
              country[nx][ny] = islandId;
            }
          }
        }
        islandId++;
      }
    }
  }
  return islandId;
}

void findIsland(int N, int M, std::vector<std::vector<int>>& island,
                std::vector<Edge>& edges) {
  int dx[] = {1, -1, 0, 0};
  int dy[] = {0, 0, 1, -1};

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (island[i][j] > 1) {
        int currIsland = island[i][j];

        for (int dir = 0; dir < 4; dir++) {
          int x = i;
          int y = j;
          int dist = 0;

          while (true) {
            x += dx[dir];
            y += dy[dir];

            if (x < 0 || y < 0 || x >= N || y >= M ||
                island[x][y] == currIsland) {
              break;
            }

            if (island[x][y] > 1) {
              if (dist > 1) {
                edges.emplace_back(currIsland, island[x][y], dist);
              }
              break;
            }
            dist++;
          }
        }
      }
    }
  }
}

int kruskal(int numIslands, std::vector<Edge>& edges) {
  std::sort(edges.begin(), edges.end(),
            [](const Edge& a, const Edge& b) { return a.w < b.w; });

  UnionFind uf(numIslands);
  int mstWeight = 0;
  int numEdges = 0;

  for (auto& edge : edges) {
    if (uf.unite(edge.u, edge.v)) {
      mstWeight += edge.w;
      numEdges++;
      if (numEdges == numIslands - 2) break;
    }
  }

  return numEdges == numIslands - 2 ? mstWeight : -1;
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N, M;
  std::cin >> N >> M;

  std::vector<std::vector<int>> country(N + 1, std::vector<int>(M + 1, 0));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      std::cin >> country[i][j];
    }
  }

  int numIslands = bfs(N, M, country) - 1;

  std::vector<Edge> edges;
  findIsland(N, M, country, edges);

  std::cout << kruskal(numIslands, edges) << '\n';

  return 0;
}