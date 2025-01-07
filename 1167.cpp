#include <algorithm>
#include <iostream>
#include <queue>
#include <random>
#include <vector>

struct node {
  int vertex;
  int dist;
};

std::vector<std::vector<node>> tree;
std::vector<bool> visited;
std::vector<int> distArr;
int maxDist;

std::queue<int> q;

void findDist(int s) {
  visited[s] = true;
  q.push(s);

  maxDist = 0;
  while (!q.empty()) {
    int front = q.front();
    q.pop();

    for (int i = 0; i < tree[front].size(); i++) {
      int tmp = tree[front][i].vertex;
      if (!visited[tmp]) {
        visited[tmp] = true;
        q.push(tmp);
        distArr[tmp] = distArr[front] + tree[front][i].dist;
        if (distArr[tmp] > maxDist) maxDist = distArr[tmp];
      }
    }
  }
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int V;
  std::cin >> V;

  tree.assign(V + 1, std::vector<node>());
  visited.assign(V + 1, false);
  distArr.assign(V + 1, 0);

  for (int i = 0; i < V; i++) {
    int currVertex;
    std::cin >> currVertex;

    while (true) {
      int adjVertex;
      std::cin >> adjVertex;

      if (adjVertex == -1) break;

      int dist;
      std::cin >> dist;

      tree[currVertex].push_back({adjVertex, dist});
      tree[adjVertex].push_back({currVertex, dist});
    }
  }

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dist(1, V);
  int randomStart = dist(gen);

  findDist(randomStart);

  int maxVal = -1;
  int maxNode = 1;  // 혹은 0

  for (int i = 1; i <= V; i++) {
    visited[i] = false;
    if (distArr[i] > maxVal) {
      maxVal = distArr[i];
      maxNode = i;
    }
    distArr[i] = 0;
  }

  findDist(maxNode);

  std::cout << maxDist << '\n';

  return 0;
}