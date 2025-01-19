#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N, M;
  std::cin >> N >> M;

  std::unordered_set<std::string> s;

  for (int i = 0; i < N; i++) {
    std::string str;
    std::cin >> str;
    s.insert(str);
  }

  int count = 0;
  for (int i = 0; i < M; i++) {
    std::string query;
    std::cin >> query;
    if (s.find(query) != s.end()) {
      count++;
    }
  }

  std::cout << count << '\n';

  return 0;
}