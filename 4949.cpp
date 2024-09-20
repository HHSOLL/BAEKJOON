#include <iostream>
#include <stack>
#include <string>

bool isBalanced(const std::string& s) {
  std::stack<char> st;

  for (char c : s) {
    if (c == '(' || c == '{' || c == '[') {
      st.push(c);
    } else if (c == ')') {
      if (st.empty() || st.top() != '(') return false;
      st.pop();
    } else if (c == '}') {
      if (st.empty() || st.top() != '{') return false;
      st.pop();
    } else if (c == ']') {
      if (st.empty() || st.top() != '[') return false;
      st.pop();
    }
  }
  return st.empty();
}

int main(void) {
  std::string s;
  while (1) {
    std::getline(std::cin, s);
    if (s == ".") break;

    if (isBalanced(s)) {
      std::cout << "yes" << '\n';
    } else {
      std::cout << "no" << '\n';
    }
  }

  return 0;
}