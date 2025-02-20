#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using ll = long long;

const ll MOD = 1000000007;

std::pair<ll, ll> fibPair(ll n) {
  if (n == 0) return {0, 1};

  auto p = fibPair(n / 2);
  ll a = p.first;
  ll b = p.second;
  ll c = (a * ((2 * b % MOD - a + MOD) % MOD)) % MOD;
  ll d = (a * a % MOD + b * b % MOD) % MOD;

  if (n % 2 == 0)
    return {c, d};
  else
    return {d, (c + d) % MOD};
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  ll n;
  std::cin >> n;
  std::cout << fibPair(n).first % MOD << '\n';

  return 0;
}
