#include <cmath>
#include <iostream>
#include <string>
#include <vector>

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N;
  std::cin >> N;

  int range = 1500000;

  std::vector<bool> is_prime(range + 1, true);
  is_prime[0] = false;
  is_prime[1] = false;

  for (long long i = 2; i <= range; i++) {
    if (is_prime[i]) {
      for (long long j = i * i; j <= range; j += i) {
        is_prime[j] = false;
      }
    }
  }

  for (int i = N; i <= range; i++) {
    if (!is_prime[i]) continue;

    std::string str = std::to_string(i);
    int start = 0;
    int end = str.size() - 1;
    bool check = true;

    while (start < end) {
      if (str[start] != str[end]) {
        check = 0;
        break;
      }
      start++;
      end--;
    }

    if (check == 1) {
      std::cout << i << '\n';
      break;
    }
  }

  return 0;
}