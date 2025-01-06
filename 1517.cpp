#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> v;
std::vector<int> tmp;
long long count;

void mergeSort(int s, int e) {
  if (e - s < 1) return;

  int m = (s + e) / 2;

  mergeSort(s, m);
  mergeSort(m + 1, e);

  for (int i = s; i <= e; i++) tmp[i] = v[i];

  int k = s;
  int idx1 = s;
  int idx2 = m + 1;

  while (idx1 <= m && idx2 <= e) {
    if (tmp[idx1] > tmp[idx2]) {
      v[k] = tmp[idx2];
      count += (m - idx1 + 1);
      k++;
      idx2++;
    } else {
      v[k] = tmp[idx1];
      k++;
      idx1++;
    }
  }

  while (idx1 <= m) {
    v[k] = tmp[idx1];
    k++;
    idx1++;
  }

  while (idx2 <= e) {
    v[k] = tmp[idx2];
    k++;
    idx2++;
  }
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N;
  std::cin >> N;

  v.assign(N + 1, 0);
  tmp.assign(N + 1, 0);

  for (int i = 1; i <= N; i++) std::cin >> v[i];

  count = 0;
  mergeSort(1, N);

  std::cout << count << '\n';

  return 0;
}