#include <iostream>
#include <string>
#include <unordered_map>

#define MIN_LENGTH 2
#define MAX_LENGTH 20

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int N = 0, M = 0;
  std::cin >> N >> M;

  std::string str;
  std::unordered_map<std::string, int> table(N + 1);
  std::unordered_map<int, std::string> table2(N + 1);
  for (int i = 0; i < N; i++) {
    std::cin >> str;

    if (str.length() < MIN_LENGTH || str.length() > MAX_LENGTH) exit(0);

    table.insert({str, i + 1});
    table2.insert({i + 1, str});
  }

  for (int i = 0; i < M; i++) {
    std::cin >> str;

    auto it = table.find(str);
    if (it != table.end()) {
      std::cout << it->second << '\n';
    } else {
      int k = std::stoi(str) - 1;
      std::cout << table2.find(k)->second << '\n';
    }
  }
  return 0;
}