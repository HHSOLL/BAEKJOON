#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

std::vector<int> arr;
std::vector<int> tmp;
std::vector<bool> visited;
int n, m;

std::set<std::vector<int>> set;

void recur(int depth) {
  if (depth == m) {
    set.insert(tmp);
    return;
  }

  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      visited[i] = true;
      tmp.push_back(arr[i]);
      recur(depth + 1);
      tmp.pop_back();
      visited[i] = false;
    }
  }
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::cin >> n >> m;

  arr.resize(n);
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }

  visited.resize(n, false);

  std::sort(arr.begin(), arr.end());

  recur(0);

  for (const auto& row : set) {
    for (int val : row) {
      std::cout << val << " ";
    }
    std::cout << "\n";
  }

  return 0;
}