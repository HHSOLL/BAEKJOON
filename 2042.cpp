#include <algorithm>
#include <iostream>
#include <vector>

long long buildTree(int start, int end, int n, std::vector<long long>& arr,
                    std::vector<long long>& segTree) {
  if (start == end) {
    segTree[n] = arr[start];
    return segTree[n];
  }

  int mid = (start + end) / 2;
  long long leftSum = buildTree(start, mid, n * 2, arr, segTree);
  long long rightSum = buildTree(mid + 1, end, n * 2 + 1, arr, segTree);
  segTree[n] = leftSum + rightSum;
  return segTree[n];
}

long long query(int start, int end, int n, int l, int r,
                std::vector<long long>& segTree) {
  if (r < start || l > end) {
    return 0;
  }

  if (l <= start && end <= r) {
    return segTree[n];
  }

  int mid = (start + end) / 2;
  long long leftSum = query(start, mid, n * 2, l, r, segTree);
  long long rightSum = query(mid + 1, end, n * 2 + 1, l, r, segTree);
  return leftSum + rightSum;
}

void update(int start, int end, int n, int idx, long long newVal,
            std::vector<long long>& arr, std::vector<long long>& segTree) {
  if (start == end) {
    arr[idx] = newVal;
    segTree[n] = newVal;
    return;
  }

  int mid = (start + end) / 2;

  if (idx <= mid) {
    update(start, mid, n * 2, idx, newVal, arr, segTree);
  } else {
    update(mid + 1, end, n * 2 + 1, idx, newVal, arr, segTree);
  }

  segTree[n] = segTree[n * 2] + segTree[n * 2 + 1];
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N, M, K;
  std::cin >> N >> M >> K;

  std::vector<long long> arr(N);
  std::vector<long long> segTree(4 * N, 0);

  for (int i = 0; i < N; i++) {
    std::cin >> arr[i];
  }

  buildTree(0, N - 1, 1, arr, segTree);

  for (int i = 0; i < M + K; i++) {
    long long a, b, c;
    std::cin >> a >> b >> c;

    if (a == 1) {
      update(0, N - 1, 1, b - 1, c, arr, segTree);
    } else if (a == 2) {
      std::cout << query(0, N - 1, 1, b - 1, c - 1, segTree) << '\n';
    }
  }

  return 0;
}