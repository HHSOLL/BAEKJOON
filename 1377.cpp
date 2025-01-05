#include <algorithm>
#include <iostream>
#include <vector>

struct vec {
  int idx;
  int val;
};

class BottomupMerge {
 public:
  void Sort(std::vector<vec>& v) {
    int N = v.size();
    aux.resize(N);

    for (int k = 1; k < N; k *= 2) {
      for (int g = 0; g < N - k; g += k * 2) {
        Merge(v, g, g + k - 1, std::min(g + k * 2 - 1, N - 1));
      }
    }
  }

 private:
  void Merge(std::vector<vec>& v, int lo, int mid, int hi) {
    int i = lo;
    int j = mid + 1;

    if (v[mid].val <= v[j].val) return;

    for (int k = lo; k <= hi; k++) {
      aux[k] = v[k];
    }

    for (int k = lo; k <= hi; k++) {
      if (i > mid) {
        v[k] = aux[j++];
      } else if (j > hi) {
        v[k] = aux[i++];
      } else if (aux[i].val > aux[j].val) {
        v[k] = aux[j++];
      } else {
        v[k] = aux[i++];
      }
    }
  }
  std::vector<vec> aux;
};

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N;
  std::cin >> N;

  std::vector<vec> aft(N, {0, 0});
  std::vector<vec> bef(N, {0, 0});

  for (int i = 0; i < N; i++) {
    aft[i].idx = i;
    std::cin >> aft[i].val;
  }

  bef = aft;

  BottomupMerge sorter;
  sorter.Sort(aft);

  int max = 0;
  for (int i = 0; i < N; i++) {
    int tmp = aft[i].idx - bef[i].idx;
    if (tmp > max) max = tmp;
  }

  std::cout << max + 1 << '\n';

  return 0;
}