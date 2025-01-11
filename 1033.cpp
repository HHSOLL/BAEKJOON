#include <algorithm>
#include <iostream>
#include <vector>

struct Node {
  int neighbor;
  int p;
  int q;
};

std::vector<std::vector<Node>> adj;
std::vector<long long> ans;
std::vector<bool> visited;

long long gcd(long long a, long long b) {
  if (b == 0) return a;

  return gcd(b, a % b);
}

long long lcm(long long a, long b) { return (a * b) / gcd(a, b); }

void dfs(int node) {
  visited[node] = true;
  for (auto& next : adj[node]) {
    if (!visited[next.neighbor]) {
      ans[next.neighbor] = ans[node] * next.q / next.p;
      dfs(next.neighbor);
    }
  }
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N;
  std::cin >> N;

  adj.assign(N, std::vector<Node>());
  ans.assign(N, 1);
  visited.assign(N, false);

  long long LCM = 1;
  for (int i = 0; i < N - 1; i++) {
    int a, b, p, q;
    std::cin >> a >> b >> p >> q;

    adj[a].push_back({b, p, q});
    adj[b].push_back({a, q, p});
    long long tmp = lcm(p, q);
    LCM *= tmp;
  }

  ans[0] = LCM;
  dfs(0);

  long long last_gcd = ans[0];
  for (int i = 0; i < N; i++) {
    last_gcd = gcd(last_gcd, ans[i]);
  }

  for (int i = 0; i < N; i++) {
    std::cout << ans[i] / last_gcd << " ";
  }
  std::cout << '\n';

  return 0;
}