#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

int makeTree(int node, int start, int end, std::vector<int>& arr,
             std::vector<int>& segTree) {
  if (start == end) {
    segTree[node] = arr[start];
    return segTree[node];
  }

  int mid = (start + end) / 2;
  int leftMin = makeTree(node * 2, start, mid, arr, segTree);
  int rightMin = makeTree(node * 2 + 1, mid + 1, end, arr, segTree);
  segTree[node] = std::min(leftMin, rightMin);
  return segTree[node];
}

int query(int node, int start, int end, int l, int r,
          std::vector<int>& segTree) {
  if (r < start || l > end) return std::numeric_limits<int>::max();

  if (l <= start && end <= r) return segTree[node];

  int mid = (start + end) / 2;
  int leftMin = query(node * 2, start, mid, l, r, segTree);
  int rightMin = query(node * 2 + 1, mid + 1, end, l, r, segTree);
  return std::min(leftMin, rightMin);
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N, M;
  std::cin >> N >> M;

  std::vector<int> arr(N, 0);
  std::vector<int> segTree(N * 4, 0);

  for (int i = 0; i < N; i++) std::cin >> arr[i];

  makeTree(1, 0, N - 1, arr, segTree);

  for (int i = 0; i < M; i++) {
    int a, b;
    std::cin >> a >> b;

    std::cout << query(1, 0, N - 1, a - 1, b - 1, segTree) << '\n';
  }

  return 0;
}