#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

int N, M;
int ans = INT_MAX;
std::vector<std::pair<int, int>> chicken;
std::vector<std::pair<int, int>> house;

void dfs(int idx, int count, std::vector<int>& choice) {
  if (count == M) {
    int sum = 0;

    for (auto& h : house) {
      int d = 1e9;
      for (int i : choice) {
        int dist =
            abs(h.first - chicken[i].first) + abs(h.second - chicken[i].second);
        d = std::min(d, dist);
      }
      sum += d;
    }
    ans = std::min(ans, sum);
    return;
  }

  for (int i = idx; i < chicken.size(); i++) {
    choice.push_back(i);
    dfs(i + 1, count + 1, choice);
    choice.pop_back();
  }
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  std::cin >> N >> M;

  std::vector<std::vector<int>> city(N, std::vector<int>(N));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      std::cin >> city[i][j];

      if (city[i][j] == 1)
        house.push_back({i, j});
      else if (city[i][j] == 2)
        chicken.push_back({i, j});
    }
  }

  std::vector<int> choice;
  dfs(0, 0, choice);

  std::cout << ans << '\n';

  return 0;
}
