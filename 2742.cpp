#include <iostream>

int main(void) {
  int num = 0;
  std::cin >> num;

  for (int i = num; i > 0; i--) {
    std::cout << i << '\n';
  }
  return 0;
}