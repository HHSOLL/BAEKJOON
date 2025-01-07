#include <algorithm>
#include <iostream>
#include <vector>

std::vector<std::vector<int>> adj;
std::vector<bool> visited;
bool arrive;

void dfs(int s, int depth) {
  if (depth == 5 || arrive) {
    arrive = true;
    return;
  }

  visited[s] = true;

  for (int next : adj[s]) {
    if (!visited[next]) dfs(next, depth + 1);
  }
  visited[s] = false;
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N, M;
  std::cin >> N >> M;

  adj.assign(N, std::vector<int>());
  visited.assign(N, false);
  arrive = false;

  for (int i = 0; i < M; i++) {
    int v1, v2;
    std::cin >> v1 >> v2;

    adj[v1].push_back(v2);
    adj[v2].push_back(v1);
  }

  for (int i = 0; i < N; i++) {
    dfs(i, 1);

    if (arrive) break;
  }

  if (arrive)
    std::cout << 1 << '\n';
  else
    std::cout << 0 << '\n';

  return 0;
}