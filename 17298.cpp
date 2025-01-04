#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

struct deq {
  int idx;
  int val;
};

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N;
  std::cin >> N;

  std::deque<deq> d;
  std::deque<int> ans(N, 0);

  for (int i = 0; i < N; i++) {
    int val;
    std::cin >> val;

    while (d.size() != 0 && val > d.back().val) {
      deq tmp = d.back();
      d.pop_back();
      ans[tmp.idx] = val;
    }
    d.push_back({i, val});
  }

  for (int i = 0; i < N; i++) {
    if (ans[i] == 0)
      std::cout << -1 << " ";
    else
      std::cout << ans[i] << " ";
  }
  std::cout << '\n';

  return 0;
}