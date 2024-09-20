#include <iostream>
#include <queue>
#include <stack>
#include <string>

int prio(char value);
void ToPostfix(std::queue<char> input, std::queue<char> output);

int main(void) {
  std::string str;
  std::cin >> str;

  std::queue<char> input;
  std::queue<char> output;

  for (int i = 0; i < str.size(); i++) {
    input.push(str[i]);
  }

  ToPostfix(input, output);

  return 0;
}

int prio(char value) {
  if (value == '+' || value == '-')
    return 1;
  else if (value == '*' || value == '/')
    return 2;
  else
    return 0;

  return 0;
}

void ToPostfix(std::queue<char> input, std::queue<char> output) {
  std::stack<char> temp;

  while (!input.empty()) {
    char word = input.front();
    input.pop();

    if (65 <= word && word <= 90) {
      output.push(word);
    } else if (word == '+' || word == '-' || word == '*' || word == '/') {
      if (temp.empty())
        temp.push(word);
      else {
        if (prio(temp.top()) >= prio(word)) {
          while (true) {
            if (temp.empty() || prio(temp.top()) < prio(word)) break;
            output.push(temp.top());
            temp.pop();
          }
          temp.push(word);
        } else {
          temp.push(word);
        }
      }
    } else if (word == '(') {
      temp.push(word);
    } else if (word == ')') {
      while (true) {
        if (temp.top() == '(') {
          temp.pop();
          break;
        }
        output.push(temp.top());
        temp.pop();
      }
    }
  }

  while (!temp.empty()) {
    output.push(temp.top());
    temp.pop();
  }

  while (!output.empty()) {
    std::cout << output.front();
    output.pop();
  }
  std::cout << '\n';
}