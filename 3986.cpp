#include <iostream>
#include <stack>
#include <string>

int main(void) {
  int n;
  std::cin >> n;

  int count = 0;
  for (int i = 0; i < n; i++) {
    std::string str;
    std::stack<char> s;

    std::cin >> str;

    for (int j = 0; j < str.size(); j++) {
      if (s.empty()) {
        s.push(str[j]);
        continue;
      }

      char top = s.top();
      if (str[j] == top) {
        s.pop();
      } else {
        s.push(str[j]);
      }
    }
    if (s.empty()) count++;
  }

  std::cout << count << '\n';
  return 0;
}