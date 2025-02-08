#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

int bfs(int start, int goal) {
  std::vector<bool> visited(10000, false);
  std::vector<int> dist(10000, 0);
  std::queue<int> q;

  std::vector<int> parent(10000, -1);
  std::vector<char> op(10000, ' ');
  std::vector<char> ans;

  q.push(start);
  visited[start] = true;

  while (!q.empty()) {
    int curr = q.front();
    q.pop();

    if (curr == goal) {
      for (int cur = goal; cur != start; cur = parent[cur]) {
        ans.push_back(op[cur]);
      }
      std::reverse(ans.begin(), ans.end());

      for (char a : ans) std::cout << a;
      return 1;
    }

    int D = curr * 2 % 10000;
    int S = curr == 0 ? 9999 : curr - 1;
    int L = (curr % 1000) * 10 + (curr / 1000);
    int R = (curr % 10) * 1000 + (curr / 10);

    if (!visited[D]) {
      visited[D] = true;
      parent[D] = curr;
      op[D] = 'D';
      dist[D] = dist[curr] + 1;
      q.push(D);
    }
    if (!visited[S]) {
      visited[S] = true;
      parent[S] = curr;
      op[S] = 'S';
      dist[S] = dist[curr] + 1;
      q.push(S);
    }
    if (!visited[L]) {
      visited[L] = true;
      parent[L] = curr;
      op[L] = 'L';
      dist[L] = dist[curr] + 1;
      q.push(L);
    }
    if (!visited[R]) {
      visited[R] = true;
      parent[R] = curr;
      op[R] = 'R';
      dist[R] = dist[curr] + 1;
      q.push(R);
    }
  }
  return -1;
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int T;
  std::cin >> T;

  while (T--) {
    int A, B;
    std::cin >> A >> B;

    bfs(A, B);
    std::cout << '\n';
  }

  return 0;
}
