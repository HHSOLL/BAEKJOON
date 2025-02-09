#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N;
  std::cin >> N;

  std::vector<long long> liquid(N);
  for (int i = 0; i < N; i++) {
    std::cin >> liquid[i];
  }

  int left = 0, right = N - 1;
  long long best_sum = __LONG_LONG_MAX__;
  std::pair<long long, long long> ans;

  while (left < right) {
    long long sum = liquid[left] + liquid[right];

    if (llabs(sum) < best_sum) {
      best_sum = llabs(sum);
      ans = {liquid[left], liquid[right]};
      if (sum == 0) break;
    }
    if (sum < 0)
      left++;
    else
      right--;
  }

  std::cout << ans.first << " " << ans.second << '\n';

  return 0;
}
