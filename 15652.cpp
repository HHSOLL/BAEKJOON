#include <iostream>
#include <vector>

void recur(int n, int m, int start, std::vector<int>& v) {
  if (v.size() == m) {
    for (int num : v) std::cout << num << " ";
    std::cout << '\n';
    return;
  }

  for (int i = start; i <= n; i++) {
    v.push_back(i);
    recur(n, m, i, v);
    v.pop_back();
  }
}

int main(void) {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> v;
  recur(n, m, 1, v);
  return 0;
}