#include <iostream>
#include <queue>
#include <vector>

struct Document {
  int value;
  int prio;
};

int main(void) {
  int t;
  std::cin >> t;

  int num;
  int idx;
  for (int i = 0; i < t; i++) {
    std::cin >> num >> idx;

    std::vector<Document> v(num);
    std::vector<int> priority(10, 0);

    for (int j = 0; j < num; j++) {
      int item;
      std::cin >> item;
      v[j].value = item;
      v[j].prio = 0;
      priority[item]++;
    }

    v[idx].prio = 100;

    int print_count = 0;

    int p = 9;
    while (p > 0) {
      if (priority[p] != 0) {
        for (int x = 0; x < num; x++) {
          int temp_value = v[0].value;
          int temp_prio = v[0].prio;
          if (temp_prio == 100 && p == temp_value) {
            std::cout << print_count + 1 << '\n';
            v.clear();
            priority.clear();
            goto next_case;
          }
          if (temp_value == p) {
            v.erase(v.begin());
            priority[p]--;
            print_count++;

            if (priority[p] == 0) break;
          } else {
            v.erase(v.begin());
            v.push_back({temp_value, temp_prio});
          }
        }
      }
      p--;
    }
  next_case:;
  }
  return 0;
}