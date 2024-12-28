#include <algorithm>
#include <iostream>
#include <vector>

int n, m;
std::vector<int> arr;
std::vector<int> temp;
std::vector<bool> visited;

void dfs(int depth) {
  if (depth == m) {
    for (int i = 0; i < m; i++) {
      std::cout << temp[i] << (i == m - 1 ? '\n' : ' ');
    }
    return;
  }

  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      visited[i] = true;
      temp.push_back(arr[i]);
      dfs(depth + 1);
      temp.pop_back();
      visited[i] = false;
    }
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> n >> m;

  arr.resize(n);
  visited.resize(n, false);
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }

  sort(arr.begin(), arr.end());

  dfs(0);

  return 0;
}