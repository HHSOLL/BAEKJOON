#include <iostream>
#include <vector>

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int n, m;
  std::cin >> n >> m;

  std::vector<long> v(n, 0);
  std::vector<long> remainder(m, 0);

  long long ans = 0;

  std::cin >> v[0];
  v[0] %= m;
  if (v[0] == 0) ans++;
  remainder[v[0]]++;

  for (int i = 1; i < n; i++) {
    long tmp;
    std::cin >> tmp;
    v[i] = (tmp % m + v[i - 1] % m) % m;
    if (v[i] == 0) ans++;
    remainder[v[i]]++;
  }

  for (int i = 0; i < m; i++) {
    if (remainder[i] >= 2) ans += (remainder[i] * (remainder[i] - 1) / 2);
  }

  std::cout << ans << '\n';

  return 0;
}