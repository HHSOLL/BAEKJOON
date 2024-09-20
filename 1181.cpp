#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

bool cmp(const std::string s1, const std::string s2) {
  if (s1.length() == s2.length()) return s1 < s2;
  return s1.length() < s2.length();
}

int main(void) {
  int n;
  std::cin >> n;

  std::vector<std::string> word;

  for (int i = 0; i < n; i++) {
    std::string s;
    std::cin >> s;

    word.push_back(s);
  }

  std::sort(word.begin(), word.end(), cmp);
  word.erase(unique(word.begin(), word.end()), word.end());

  for (int i = 0; i < word.size(); i++) {
    std::cout << word[i] << '\n';
  }

  return 0;
}