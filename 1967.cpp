#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using ll = long long;
const int INF = INT_MAX;

const int maxN = 10001;

std::vector<std::pair<int, int>> tree[maxN];
bool visited[maxN];
int dist[maxN];
int n;

void dfs(int node, int d) {
  visited[node] = true;
  dist[node] = d;

  for (auto& edge : tree[node]) {
    int next_node = edge.first;
    int weight = edge.second;
    if (!visited[next_node]) {
      dfs(next_node, d + weight);
    }
  }
}

void makeTree(int parent, int child, int weight) {}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  std::cin >> n;

  for (int i = 0; i < n - 1; i++) {
    int p, c, w;
    std::cin >> p >> c >> w;

    tree[p].push_back({c, w});
    tree[c].push_back({p, w});
  }

  std::memset(visited, false, sizeof(visited));
  std::memset(dist, 0, sizeof(dist));
  dfs(1, 0);

  int farthest_node = 1;
  for (int i = 1; i <= n; i++) {
    if (dist[i] > dist[farthest_node]) {
      farthest_node = i;
    }
  }

  std::memset(visited, false, sizeof(visited));
  std::memset(dist, 0, sizeof(dist));
  dfs(farthest_node, 0);

  int max_distance = 0;
  for (int i = 1; i <= n; i++) {
    if (dist[i] > max_distance) {
      max_distance = dist[i];
    }
  }

  std::cout << max_distance << '\n';

  return 0;
}
