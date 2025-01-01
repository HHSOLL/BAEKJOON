#include <iostream>
#include <sstream>
#include <vector>

int main(void) {
  std::string expr;
  std::cin >> expr;

  std::vector<std::string> parts;
  std::stringstream ss;
  for (char c : expr) {
    if (c == '-')
      ss << ' ';
    else
      ss << c;
  }

  std::string piece;
  while (ss >> piece) {
    parts.push_back(piece);
  }

  auto sumOf = [&](const std::string& s) {
    int ret = 0;
    std::stringstream ss2;
    for (char c : s) {
      if (c == '+')
        ss2 << ' ';
      else
        ss2 << c;
    }

    int x;
    while (ss2 >> x) {
      ret += x;
    }
    return ret;
  };

  int ans = sumOf(parts[0]);
  for (int i = 1; i < (int)parts.size(); i++) {
    ans -= sumOf(parts[1]);
  }

  std::cout << ans << '\n';

  return 0;
}