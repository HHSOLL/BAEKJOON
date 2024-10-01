// #include <bits/stdc++.h>

#include <algorithm>
#include <deque>
#include <iostream>
#include <string>

void PrintDeque(std::deque<int> d, bool IsReverse) {
  std::cout << '[';

  if (IsReverse) {
    for (auto i = d.rbegin(); i != d.rend(); i++) {
      if (i != d.rbegin()) std::cout << ',';
      std::cout << *i;
    }
  } else {
    for (int i = 0; i < d.size(); i++) {
      if (i != 0) std::cout << ',';
      std::cout << d[i];
    }
  }

  std::cout << ']' << '\n';
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int N;
  std::cin >> N;

  std::string str;
  std::deque<int> d;
  for (int i = 0; i < N; i++) {
    std::cin >> str;

    int len;
    std::cin >> len;

    bool IsReverse = false;
    bool IsError = false;

    std::string tmp;
    if (len == 0) {
      std::cin >> tmp;
    } else {
      std::cin >> tmp;

      tmp = tmp.substr(1, tmp.size() - 2);

      size_t pos = 0;
      size_t start = 0;
      while (true) {
        pos = tmp.find(',', start);
        if (pos == std::string::npos) break;

        int token = stoi(tmp.substr(start, pos - start));
        d.push_back(token);
        start = pos + 1;
      }

      if (start < tmp.size()) {
        d.push_back(stoi(tmp.substr(start)));
      }
    }

    for (auto k : str) {
      if (k == 'R') {
        IsReverse = !(IsReverse);
      } else if (k == 'D' && d.empty()) {
        IsError = true;
        break;
      } else if (k == 'D' && IsReverse) {
        d.pop_back();
      } else {
        d.pop_front();
      }
    }

    if (IsError) {
      std::cout << "error" << '\n';
      d.clear();
    } else if (d.empty()) {
      std::cout << "[]" << '\n';
    } else {
      PrintDeque(d, IsReverse);
      d.clear();
    }
  }
}