#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

void preorder(char node,
              std::unordered_map<char, std::pair<char, char>>& tree) {
  if (node == '.') return;
  std::cout << node;
  preorder(tree[node].first, tree);
  preorder(tree[node].second, tree);
}
void inorder(char node, std::unordered_map<char, std::pair<char, char>>& tree) {
  if (node == '.') return;
  inorder(tree[node].first, tree);
  std::cout << node;
  inorder(tree[node].second, tree);
}
void postorder(char node,
               std::unordered_map<char, std::pair<char, char>>& tree) {
  if (node == '.') return;
  postorder(tree[node].first, tree);
  postorder(tree[node].second, tree);
  std::cout << node;
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N;
  std::cin >> N;

  std::unordered_map<char, std::pair<char, char>> tree;

  for (int i = 0; i < N; i++) {
    char parent, left, right;
    std::cin >> parent >> left >> right;
    tree[parent] = {left, right};
  }

  preorder('A', tree);
  std::cout << '\n';
  inorder('A', tree);
  std::cout << '\n';
  postorder('A', tree);
  std::cout << '\n';

  return 0;
}