#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int n, m;
  std::cin >> n;
  std::cin >> m;

  std::vector<int> v(n, 0);
  for (int i = 0; i < n; i++) {
    std::cin >> v[i];
  }

  std::sort(v.begin(), v.end());

  int pointer_1st = 0;
  int pointer_2nd = v.size() - 1;
  int sum = v[pointer_1st] + v[pointer_2nd];
  int count = 0;

  while (pointer_2nd != pointer_1st) {
    if (sum == m) {
      count++;
      pointer_2nd--;
      sum = v[pointer_1st] + v[pointer_2nd];
    } else if (sum < m) {
      pointer_1st++;
      sum = v[pointer_1st] + v[pointer_2nd];
    } else {
      pointer_2nd--;
      sum = v[pointer_1st] + v[pointer_2nd];
    }
  }

  std::cout << count << '\n';

  return 0;
}