#include <iostream>

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int n;
  std::cin >> n;

  int start_idx = 0;
  int end_idx = 0;
  int count = 1;
  int sum = 0;

  while (end_idx != n) {
    if (sum == n) {
      count++;
      end_idx++;
      sum = sum + end_idx;
    } else if (sum < n) {
      end_idx++;
      sum = sum + end_idx;
    } else {
      sum = sum - start_idx;
      start_idx++;
    }
  }

  std::cout << count << '\n';

  return 0;
}