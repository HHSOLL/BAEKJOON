#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int n;
  std::cin >> n;

  std::vector<int> v(n, 0);
  for (int i = 0; i < n; i++) std::cin >> v[i];

  std::sort(v.begin(), v.end());

  int first_num = 0;
  int second_num = 0;
  int good_number_count = 0;

  for (int i = 0; i < n; i++) {
    first_num = 0;
    second_num = n - 1;

    int target = v[i];
    while (first_num < second_num) {
      int sum = v[first_num] + v[second_num];

      if (sum == target) {
        if (first_num == i) {
          first_num++;
        } else if (second_num == i) {
          second_num--;
        } else {
          good_number_count++;
          break;
        }
      } else if (sum < target) {
        first_num++;
      } else {
        second_num--;
      }
    }
  }
  std::cout << good_number_count << '\n';

  return 0;
}