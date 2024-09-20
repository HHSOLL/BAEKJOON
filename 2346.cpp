#include <iostream>
#include <vector>

struct balloon {
  int value;
  int num;
};

int main(void) {
  int n;
  std::cin >> n;

  std::vector<balloon> v(n);
  for (int i = 0; i < n; i++) {
    std::cin >> v[i].value;
    v[i].num = i + 1;
  }

  int idx = 0;
  std::vector<int> result;

  while (!(v.empty())) {
    result.push_back(v[idx].num);

    int temp_value = v[idx].value;
    v.erase(v.begin() + idx);

    if (v.empty()) break;

    if (temp_value > 0) {
      idx = (idx + temp_value - 1) % v.size();
    } else {
      temp_value = -temp_value % v.size();
      idx = (idx - temp_value + v.size()) % v.size();
    }
  }

  for (int i = 0; i < result.size(); i++) {
    std::cout << result[i] << " ";
  }
  std::cout << '\n';
  return 0;
}