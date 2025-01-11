#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

std::vector<std::vector<int>> adj;
std::vector<int> count;

int bfs(int node, int N) {
  std::vector<bool> visited(N, 0);
  std::queue<int> q;
  int count = 0;

  q.push(node);
  visited[node] = true;

  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    count++;

    for (auto& next : adj[curr]) {
      if (!visited[next]) {
        visited[next] = true;
        q.push(next);
      }
    }
  }
  return count;
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N, M;
  std::cin >> N >> M;

  adj.assign(N + 1, std::vector<int>());
  count.assign(N + 1, 0);

  for (int i = 0; i < M; i++) {
    int from, to;
    std::cin >> from >> to;

    adj[to].push_back(from);
  }

  int max = 0;
  for (int i = 1; i <= N; i++) {
    count[i] = bfs(i, N);
    max = std::max(max, count[i]);
  }

  for (int i = 1; i <= N; i++) {
    if (count[i] == max) {
      std::cout << i << " ";
    }
  }
  std::cout << '\n';

  return 0;
}