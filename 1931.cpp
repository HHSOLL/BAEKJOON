#include <algorithm>
#include <iostream>
#include <vector>

struct t {
  int sTime;
  int eTime;
};

bool cmp(const t& a, const t& b) {
  if (a.eTime != b.eTime) return a.eTime < b.eTime;

  return a.sTime < b.sTime;
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N;
  std::cin >> N;

  std::vector<t> v(N, {0, 0});

  for (int i = 0; i < N; i++) {
    std::cin >> v[i].sTime >> v[i].eTime;
  }

  std::sort(v.begin(), v.end(), cmp);

  int count = 0;
  int end = 0;

  for (int i = 0; i < N; i++) {
    if (v[i].sTime >= end) {
      count++;
      end = v[i].eTime;
    }
  }

  std::cout << count << '\n';

  return 0;
}