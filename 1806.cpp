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

  int N, S;
  std::cin >> N >> S;

  std::vector<int> arr(N);
  for (int i = 0; i < N; i++) {
    std::cin >> arr[i];
  }

  int start = 0;
  int end = 0;
  int sum = 0;
  int min_length = N + 1;

  while (end < N) {
    sum += arr[end];

    while (sum >= S) {
      min_length = std::min(min_length, end - start + 1);

      sum -= arr[start];
      start++;
    }

    end++;
  }

  if (min_length == N + 1)
    std::cout << 0 << '\n';
  else
    std::cout << min_length << '\n';

  return 0;
}
