#include <iostream>
#include <stack>
#include <vector>

std::stack<int> s[4];
std::vector<std::vector<int> > v;
int count = 0;

void MoveDisk(int from, int to) {
  if (s[from].empty()) {
    std::cout << "TOWER IS EMPTY" << '\n';
    exit(0);
  }

  int temp = s[from].top();

  if (!s[to].empty() && s[to].top() < temp) {
    std::cout << "DISK IS TOO BIG" << '\n';
    exit(0);
  }

  s[to].push(temp);
  //   std::cout << from << " " << to << '\n';

  std::vector<int> v2;
  v.push_back(v2);
  v[count].push_back(from);
  v[count].push_back(to);
  count++;
};

void RecurMoveDisk(int num_disks, int from, int temp, int to) {
  if (num_disks == 0) return;

  RecurMoveDisk(num_disks - 1, from, to, temp);
  MoveDisk(from, to);
  RecurMoveDisk(num_disks - 1, temp, from, to);
}

int main(void) {
  int n;
  std::cin >> n;

  for (int i = n; i > 0; i--) s[1].push(i);

  RecurMoveDisk(n, 1, 2, 3);

  std::cout << count << '\n';
  for (int i = 0; i < count; i++) {
    std::cout << v[i][0] << " " << v[i][1] << '\n';
  }

  return 0;
}