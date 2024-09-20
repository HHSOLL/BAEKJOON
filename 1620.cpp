#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<std::string>> v(n);

  for (int i = 0; i < n; i++) {
    std::string str;
    std::cin >> str;
    v[i].push_back(str);
  }

  for (int i = 0; i < m; i++) {
    std::string q;
    std::cin >> q;

    bool found = false;
    for (int j = 0; j < n; j++) {
      if (find(v[j].begin(), v[j].end(), q) != v[j].end()) {
        std::cout << j + 1 << '\n';
        found = true;
        break;
      }
    }
    if (!found) {
      int p = stoi(q);
      std::cout << *v[p - 1].begin() << '\n';
      // std::cout << "NOTFOUND" << '\n';
    }
  }
  return 0;
}