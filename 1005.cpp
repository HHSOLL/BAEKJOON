#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <queue>
#include <vector>

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int T;
  std::cin >> T;

  while (T--) {
    int N, K;
    int target;

    std::cin >> N >> K;

    std::vector<int> buildTime(N + 1, 0);
    std::vector<std::vector<int>> graph(N + 1);
    std::vector<int> indegree(N + 1, 0);
    std::vector<int> dp(N + 1, 0);

    std::queue<int> q;

    for (int i = 1; i <= N; i++) {
      std::cin >> buildTime[i];
    }

    for (int i = 0; i < K; i++) {
      int X, Y;
      std::cin >> X >> Y;
      graph[X].push_back(Y);
      indegree[Y]++;
    }

    std::cin >> target;

    for (int i = 1; i <= N; i++) {
      dp[i] = buildTime[i];
      if (indegree[i] == 0) {
        q.push(i);
      }
    }

    while (!q.empty()) {
      int curr = q.front();
      q.pop();

      for (int next : graph[curr]) {
        dp[next] = std::max(dp[next], dp[curr] + buildTime[next]);
        indegree[next]--;

        if (indegree[next] == 0) {
          q.push(next);
        }
      }
    }
    std::cout << dp[target] << '\n';
  }

  return 0;
}
