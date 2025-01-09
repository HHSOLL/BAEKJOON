#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N;
  std::cin >> N;

  std::priority_queue<int> pq;
  for (int i = 0; i < N; i++) {
    int tmp;
    std::cin >> tmp;
    pq.push(-tmp);
  }

  long long count = 0;

  while (!(pq.size() == 1)) {
    int t1 = -pq.top();
    pq.pop();
    int t2 = -pq.top();
    pq.pop();

    pq.push(-(t1 + t2));
    count += (t1 + t2);
  }
  std::cout << count << '\n';

  return 0;
}