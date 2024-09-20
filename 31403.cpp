#include <iostream>
#include <string>

int main(void) {
  std::string a;
  std::string b;
  std::string c;

  std::cin >> a;
  std::cin >> b;
  std::cin >> c;

  std::cout << stoll(a) + stoll(b) - stoll(c) << '\n';
  std::cout << stoll(a + b) - stoll(c) << '\n';

  return 0;
}