#include <iostream>
#include <vector>

int main(void) {
  int n = 0;
  std::cin >> n;

  std::vector<int> v1(n, 0);
  for (int i = 0; i < n; i++) {
    std::cin >> v1[i];
  }
}