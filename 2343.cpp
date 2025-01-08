#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> record;

void binarySearch(int s, int e, int mid, int num) {}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N, M;
  std::cin >> N >> M;

  record.assign(N, 0);

  int start = 0;
  int end = 0;
  for (int i = 0; i < N; i++) {
    std::cin >> record[i];
    if (start < record[i]) start = record[i];
    end += record[i];
  }

  while (start <= end) {
    int mid = (start + end) / 2;
    int sum = 0;
    int count = 0;

    for (int i = 0; i < N; i++) {
      if (sum + record[i] > mid) {
        count++;
        sum = 0;
      }
      sum = sum + record[i];
    }

    if (sum != 0) count++;

    if (count > M) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  std::cout << start << '\n';

  return 0;
}