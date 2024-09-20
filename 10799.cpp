#include <iostream>
#include <stack>
#include <string>

int main(void) {
  std::string str;
  std::cin >> str;

  std::stack<char> s;

  int count = 0;
  int num_stick = 0;
  for (int i = 0; i < str.size(); i++) {
    if (s.empty()) {
      s.push(str[i]);
      count++;
      continue;
    }

    char top = s.top();
    if (top == '(' && str[i] == ')') {
      count--;
      s.push(str[i]);
      num_stick += count;
    } else if (str[i] == '(') {
      s.push(str[i]);
      count++;
    } else {
      count--;
      num_stick++;
      s.push(str[i]);
    }
  }

  std::cout << num_stick << '\n';

  return 0;
}