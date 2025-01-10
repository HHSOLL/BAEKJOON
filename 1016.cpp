#include <cmath>
#include <iostream>
#include <string>
#include <vector>

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  long long min, max;
  std::cin >> min >> max;
  long long range = max - min + 1;

  std::vector<bool> is_power(range, false);

  for (long long i = 2; i * i <= max; i++) {
    long long p = i * i;
    long long sIdx = min / p;

    if (min % p != 0) sIdx++;
    for (long long j = sIdx; p * j <= max; j++) {
      is_power[(int)((j * p) - min)] = true;
    }
  }

  long count = 0;
  for (int i = 0; i < range; i++) {
    if (!is_power[i]) count++;
  }
  std::cout << count << '\n';
  return 0;
}