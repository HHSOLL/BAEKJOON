#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

struct bottle {
  int cap;
  int water;
  bottle(int c, int w) : cap(c), water(w) {}
};

std::tuple<int, int, int> pour(int x, int y, int z, int from, int to,
                               std::vector<bottle>& bottles) {
  std::vector<int> curr = {x, y, z};
  int amount = std::min(curr[from], bottles[to].cap - curr[to]);
  curr[from] -= amount;
  curr[to] += amount;

  return {curr[0], curr[1], curr[2]};
}

void bfs(int node, std::vector<bottle>& bottles, std::vector<int>& ans) {
  std::queue<std::tuple<int, int, int>> q;
  std::set<std::tuple<int, int, int>> visited;

  q.push({0, 0, bottles[2].water});
  visited.insert({0, 0, bottles[2].water});
  ans.push_back(bottles[2].water);

  while (!q.empty()) {
    auto [x, y, z] = q.front();
    q.pop();

    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (i != j) {
          auto next = pour(x, y, z, i, j, bottles);

          if (visited.find(next) == visited.end()) {
            visited.insert(next);
            q.push(next);

            if (std::get<0>(next) == 0) {
              ans.push_back(std::get<2>(next));
            }
          }
        }
      }
    }
  }
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int A, B, C;
  std::cin >> A >> B >> C;

  std::vector<bottle> bottles;
  std::vector<int> ans;

  bottles.emplace_back(A, 0);
  bottles.emplace_back(B, 0);
  bottles.emplace_back(C, C);

  bfs(2, bottles, ans);

  std::sort(ans.begin(), ans.end());
  ans.erase(std::unique(ans.begin(), ans.end()), ans.end());
  for (int x : ans) std::cout << x << " ";
  std::cout << '\n';

  return 0;
}