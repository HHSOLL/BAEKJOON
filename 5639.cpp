#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

std::vector<int> pre;

void postorder(int start, int end) {
  if (start > end) return;

  int root = pre[start];

  int mid = start + 1;

  while (mid <= end && pre[mid] < root) {
    mid++;
  }

  postorder(start + 1, mid - 1);
  postorder(mid, end);

  std::cout << root << '\n';
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int num;
  while (std::cin >> num) {
    pre.push_back(num);
  }

  postorder(0, pre.size() - 1);

  return 0;
}
