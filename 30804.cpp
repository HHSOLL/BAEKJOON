#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <queue>
#include <vector>

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N;
  std::cin >> N;

  std::vector<int> fruits(N);
  for (int i = 0; i < N; i++) {
    std::cin >> fruits[i];
  }

  std::vector<int> freq(10, 0);
  int dist = 0;
  int left = 0;
  int maxLength = 0;

  for (int right = 0; right < N; right++) {
    int fruit = fruits[right];
    if (freq[fruit] == 0) {
      dist++;
    }
    freq[fruit]++;

    while (dist > 2) {
      int leftFruit = fruits[left];
      freq[leftFruit]--;
      if (freq[leftFruit] == 0) {
        dist--;
      }
      left++;
    }

    maxLength = std::max(maxLength, right - left + 1);
  }
  std::cout << maxLength << '\n';

  return 0;
}
