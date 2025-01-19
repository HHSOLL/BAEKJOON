#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

void deleteLeafNode(std::vector<std::vector<int>>& tree, int deleteNode) {
  for (auto& child : tree[deleteNode]) {
    deleteLeafNode(tree, child);
  }
  tree[deleteNode].clear();
  tree[deleteNode].push_back(-1);
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N;
  std::cin >> N;

  std::vector<std::vector<int>> tree(N, std::vector<int>());

  int root = -1;
  for (int i = 0; i < N; i++) {
    int parent;
    std::cin >> parent;

    if (parent == -1) {
      root = i;
    } else {
      tree[parent].push_back(i);
    }
  }

  int deleteNode;
  std::cin >> deleteNode;

  if (deleteNode == root) {
    std::cout << 0 << '\n';
    return 0;
  }

  deleteLeafNode(tree, deleteNode);

  for (int i = 0; i < N; i++) {
    tree[i].erase(std::remove(tree[i].begin(), tree[i].end(), deleteNode),
                  tree[i].end());
  }

  int num_leaf = 0;
  for (int i = 0; i < N; i++) {
    if (tree[i].size() == 1 && tree[i][0] == -1) continue;
    if (tree[i].empty()) num_leaf++;
  }

  // if (tree[root].size() == 1 && tree[tree[root][0]][0] == -1) num_leaf++;

  std::cout << num_leaf << '\n';

  return 0;
}