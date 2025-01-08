#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N, K;
  std::cin >> N >> K;

  int start = 1;
  int end = K;
  int ans = 0;

  while (start <= end) {
    int mid = (start + end) / 2;

    long long sum = 0;
    for (int i = 1; i <= N; i++) {
      sum += std::min(mid / i, N);
    }

    if (sum < K)
      start = mid + 1;
    else {
      end = mid - 1;
      ans = mid;
    }
  }
  std::cout << start << '\n';

  return 0;
}