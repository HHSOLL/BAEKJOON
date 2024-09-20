#include <algorithm>
#include <iostream>
#include <vector>

struct info {
  int kg;
  int cm;
  int idx;
  int prio;
};

int main(void) {
  int n;
  std::cin >> n;

  std::vector<info> v(n);

  for (int i = 0; i < n; i++) {
    std::cin >> v[i].kg >> v[i].cm;
    v[i].prio = 1;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j && v[i].kg < v[j].kg && v[i].cm < v[j].cm) {
        v[i].prio++;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    std::cout << v[i].prio << " ";
  }
  std::cout << '\n';

  return 0;
}