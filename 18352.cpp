#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

struct Node {};

std::vector<std::vector<int>> adj;
std::vector<int> visited;
std::vector<int> ans;

void bfs(int node) {
  std::queue<int> q;
  q.push(node);
  visited[node]++;

  while (!q.empty()) {
    int currNode = q.front();
    q.pop();
    for (int i : adj[currNode]) {
      if (visited[i] == -1) {
        visited[i] = visited[currNode] + 1;
        q.push(i);
      }
    }
  }
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N, M, K, X;
  std::cin >> N >> M >> K >> X;

  adj.assign(N + 1, std::vector<int>());
  visited.assign(N + 1, -1);

  for (int i = 0; i < M; i++) {
    int from, to;
    std::cin >> from >> to;

    adj[from].push_back(to);
  }

  bfs(X);

  for (int i = 1; i <= N; i++) {
    if (visited[i] == K) ans.push_back(i);
  }

  if (ans.size())
    for (int i = 0; i < ans.size(); i++) std::cout << ans[i] << '\n';
  else
    std::cout << -1 << '\n';

  return 0;
}