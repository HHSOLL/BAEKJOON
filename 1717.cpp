#include <algorithm>
#include <iostream>
#include <vector>

void checkUnion(std::vector<int>& v, int a, int b) {
  if (a == b) {
    std::cout << "YES" << '\n';
    return;
  }

  if (v[b] == a || v[a] == b)
    std::cout << "YES" << '\n';
  else
    std::cout << "NO" << '\n';
}

int find(int x, std::vector<int>& parents) {
  if (x != parents[x]) {
    parents[x] = find(parents[x], parents);
  }
  return parents[x];
}

void makeUnion(int a, int b, std::vector<int>& rank,
               std::vector<int>& parents) {
  int rootA = find(a, parents);
  int rootB = find(b, parents);

  if (rootA != rootB) {
    if (rank[rootA] > rank[rootB]) {
      parents[rootB] = rootA;
    } else if (rank[rootA < rank[rootB]]) {
      parents[rootA] = rootB;
    } else {
      parents[rootB] = rootA;
      rank[rootA]++;
    }
  }
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int n, m;
  std::cin >> n >> m;

  std::vector<int> parents(n + 1);
  std::vector<int> rank(n + 1, 0);
  for (int i = 0; i <= n; i++) {
    parents[i] = i;
  }

  for (int i = 0; i < m; i++) {
    int check, a, b;
    std::cin >> check >> a >> b;

    if (check == 0) {
      makeUnion(a, b, rank, parents);
    } else if (check == 1) {
      if (find(a, parents) == find(b, parents)) {
        std::cout << "YES\n";
      } else {
        std::cout << "NO\n";
      }
    }
  }

  return 0;
}