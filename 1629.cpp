#include <iostream>

long long cal(long long int a, long long int b, long long int c) {
  if (b == 1) {
    return a % c;
  } else {
    if (b % 2 == 0) {
      return cal(((a % c) * (a % c)) % c, b / 2, c);
    } else {
      return (cal(((a % c) * (a % c)) % c, (b / 2), c) * a) % c;
    }
  }
}

int main(void) {
  long long int a, b, c;
  std::cin >> a >> b >> c;

  std::cout << cal(a, b, c) << '\n';

  return 0;
}