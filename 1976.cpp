#include <algorithm>
#include <iostream>
#include <vector>

int find(int k, std::vector<int>& parent) {
  if (k == parent[k]) {
    return k;
  } else {
    return parent[k] = find(parent[k], parent);
  }
}

void Union(int i, int j, std::vector<int>& parent) {
  int a = find(i, parent);
  int b = find(j, parent);

  if (a != b) {
    parent[b] = a;
  }
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N, M;
  std::cin >> N >> M;

  if (M == 1) {
    std::cout << "YES\n";
    return 0;
  }

  std::vector<std::vector<int>> city(N + 1, std::vector<int>(N + 1, 0));
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      std::cin >> city[i][j];
    }
  }

  std::vector<int> parent(N + 1, 0);
  for (int i = 1; i <= N; i++) {
    parent[i] = i;
  }

  std::vector<int> plan(M, 0);
  for (int i = 0; i < M; i++) {
    std::cin >> plan[i];
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (city[i][j] == 1) Union(i, j, parent);
    }
  }

  int idx = find(plan[0], parent);
  for (int i = 1; i < plan.size(); i++) {
    if (idx != find(plan[i], parent)) {
      std::cout << "NO\n";
      return 0;
    }
  }
  std::cout << "YES\n";
  return 0;
}