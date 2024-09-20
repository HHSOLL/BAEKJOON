#include <iostream>
using namespace std;

int main(void) {
  int n = 0;
  int s, m, l, xl, xxl, xxxl;
  int t, p;

  cin >> n;
  cin >> s >> m >> l >> xl >> xxl >> xxxl;
  cin >> t >> p;

  int tsum =
      (s % t == 0 ? s / t : s / t + 1) + (m % t == 0 ? m / t : m / t + 1) +
      (l % t == 0 ? l / t : l / t + 1) + (xl % t == 0 ? xl / t : xl / t + 1) +
      (xxl % t == 0 ? xxl / t : xxl / t + 1) +
      (xxxl % t == 0 ? xxxl / t : xxxl / t + 1);

  cout << tsum << '\n' << n / p << " " << n % p << '\n';

  return 0;
}