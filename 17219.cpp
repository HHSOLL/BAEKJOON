#include <iostream>
#include <string>
#include <unordered_map>

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int N = 0, M = 0;
  std::cin >> N >> M;

  std::string site;
  std::string pw;
  std::unordered_map<std::string, std::string> table;
  for (int i = 0; i < N; i++) {
    std::cin >> site >> pw;
    table.insert({site, pw});
  }

  for (int i = 0; i < M; i++) {
    std::cin >> site;
    if (table.find(site) != table.end()) {
      std::cout << table.find(site)->second << '\n';
    }
  }

  return 0;
}