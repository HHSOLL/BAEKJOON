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

  int N, L;
  std::cin >> N >> L;

  std::vector<int> v(N, 0);
  for (int i = 0; i < N; i++) {
    std::cin >> v[i];
  }

  std::deque<deq> d;
  std::vector<int> ans(N, 0);

  for (int i = 0; i < N; i++) {
    while (!d.empty() && v[i] < d.back().val) d.pop_back();

    d.push_back({i, v[i]});

    if (d.front().idx <= i - L) d.pop_front();

    ans[i] = d.front().val;
  }

  for (int i = 0; i < N; i++) {
    std::cout << ans[i] << ' ';
  }
  std::cout << '\n';

  return 0;
}