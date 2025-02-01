#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  long long a, b;
  std::cin >> a >> b;

  int count = 1;
  while (b > a) {
    if (b % 10 == 1) {
      b /= 10;
    } else if (b % 2 == 0) {
      b /= 2;
    } else {
      break;
    }
    count++;
  }

  if (a == b)
    std::cout << count << '\n';
  else
    std::cout << -1 << '\n';

  return 0;
}
