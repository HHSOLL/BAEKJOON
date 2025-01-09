#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
#include <vector>

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N;
  std::cin >> N;

  std::vector<int> negatives;
  std::vector<int> positives;
  int zeroCount = 0;
  long long oneCount = 0;

  for (int i = 0; i < N; i++) {
    int x;
    std::cin >> x;

    if (x == 0) {
      zeroCount++;
    } else if (x == 1) {
      oneCount++;
    } else if (x < 0) {
      negatives.push_back(x);
    } else {
      positives.push_back(x);
    }
  }

  sort(negatives.begin(), negatives.end());
  sort(positives.begin(), positives.end(), std::greater<int>());

  long long sum = oneCount;

  int negSize = (int)negatives.size();
  for (int i = 0; i + 1 < negSize; i += 2) {
    sum += (long long)negatives[i] * negatives[i + 1];
  }
  if (negSize % 2 == 1) {
    if (zeroCount == 0) {
      sum += negatives.back();
    }
  }

  int posSize = (int)positives.size();
  for (int i = 0; i + 1 < posSize; i += 2) {
    sum += (long long)positives[i] * positives[i + 1];
  }
  if (posSize % 2 == 1) {
    sum += positives.back();
  }

  std::cout << sum << "\n";
  return 0;
}