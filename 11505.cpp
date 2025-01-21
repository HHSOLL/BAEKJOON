#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

long long buildTree(int node, int start, int end, std::vector<long long>& arr,
                    std::vector<long long>& segTree) {
  if (start == end) {
    segTree[node] = arr[start];
    return segTree[node];
  }

  int mid = (start + end) / 2;
  long long leftMul =
      buildTree(node * 2, start, mid, arr, segTree) % 1000000007;
  long long rightMul =
      buildTree(node * 2 + 1, mid + 1, end, arr, segTree) % 1000000007;
  segTree[node] = leftMul * rightMul % 1000000007;

  return segTree[node];
}

long long query(int node, int start, int end, int l, int r,
                std::vector<long long>& segTree) {
  if (r < start || l > end) return 1;

  if (l <= start && end <= r) return segTree[node];

  int mid = (start + end) / 2;
  long long leftMul = query(node * 2, start, mid, l, r, segTree) % 1000000007;
  long long rightMul =
      query(node * 2 + 1, mid + 1, end, l, r, segTree) % 1000000007;

  return leftMul * rightMul % 1000000007;
}

void update(int node, int start, int end, int idx, int newVal,
            std::vector<long long>& arr, std::vector<long long>& segTree) {
  if (start == end) {
    arr[idx] = newVal;
    segTree[node] = newVal;
    return;
  }

  int mid = (start + end) / 2;

  if (idx <= mid) {
    update(node * 2, start, mid, idx, newVal, arr, segTree);
  } else {
    update(node * 2 + 1, mid + 1, end, idx, newVal, arr, segTree);
  }

  segTree[node] = segTree[node * 2] * segTree[node * 2 + 1] % 1000000007;
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N, M, K;
  std::cin >> N >> M >> K;

  std::vector<long long> arr(N, 0);
  std::vector<long long> segTree(4 * N, 0);

  for (int i = 0; i < N; i++) std::cin >> arr[i];

  buildTree(1, 0, N - 1, arr, segTree);

  for (int i = 0; i < M + K; i++) {
    int a, b, c;
    std::cin >> a >> b >> c;

    if (a == 1) {
      update(1, 0, N - 1, b - 1, c, arr, segTree);
    } else if (a == 2) {
      std::cout << query(1, 0, N - 1, b - 1, c - 1, segTree) << '\n';
    }
  }

  return 0;
}