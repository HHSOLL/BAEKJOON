#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N, M;
  std::cin >> N;
  std::cin >> M;

  std::string s;
  std::cin >> s;

  int ans = 0;
  int i = 0;

  while (i < M) {
    if (s[i] == 'I') {
      int cnt = 0;

      while (i + 2 < M && s[i + 1] == 'O' && s[i + 2] == 'I') {
        cnt++;
        i += 2;
      }

      if (cnt >= N) {
        ans += (cnt - N + 1);
      }
    }
    i++;
  }

  std::cout << ans << '\n';

  return 0;
}
