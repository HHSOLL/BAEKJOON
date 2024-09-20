#include <iostream>
#include <string>
#include <vector>

struct con {
  std::string name;
  std::string condition;
};

int main(void) {
  int n;
  std::cin >> n;

  con* c = new con[n];

  for (int i = 0; i < n; i++) {
    std::cin >> c[i].name >> c[i].condition;
  }
}