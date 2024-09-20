#include <iostream>
#include <queue>
#include <stack>

template <typename T>
class AdjMatGraph {
 public:
  struct Vertex {
    T item = T();
  };

  AdjMatGraph(int max_vertices) {
    max_vertices_ = max_vertices;

    matrix_ = new int*[max_vertices_];
    for (int i = 0; i < max_vertices_; i++) {
      matrix_[i] = new int[max_vertices_];
      for (int j = 0; j < max_vertices_; j++) {
        matrix_[i][j] = 0;
      }
    }
    vertices_ = new Vertex[max_vertices_];
  }

  ~AdjMatGraph() {
    delete[] vertices_;

    for (int i = 0; i < max_vertices_; i++) {
      delete[] matrix_[i];
    }
    delete[] matrix_;

    if (visited_) delete[] visited_;
  }

  void PrintMatrix() {
    if (!n_) {
      std::cout << "Empty" << '\n';
      return;
    }

    for (int i = 0; i < n_; i++) {
      for (int j = 0; j < n_; j++) {
        std::cout << matrix_[i][j] << " ";
      }
      std::cout << '\n';
    }
    std::cout << '\n';
  }

  void InsertVertex(T item) {
    vertices_[n_].item = item;
    n_++;
  }

  void ResetVisited() {
    if (!visited_) visited_ = new bool[max_vertices_];

    for (int i = 0; i < max_vertices_; i++) {
      visited_[i] = false;
    }
  }

  void InsertEdge(int u, int v) {
    matrix_[u - 1][v - 1] = 1;
    matrix_[v - 1][u - 1] = 1;
  }

  void DFS(int V) {
    if (!visited_) ResetVisited();
    std::stack<int> s;
    s.push(V - 1);

    while (!s.empty()) {
      int temp = s.top();
      s.pop();

      if (!visited_[temp]) {
        std::cout << temp + 1 << " ";
        visited_[temp] = true;
      } else {
        continue;
      }

      for (int i = n_ - 1; i >= 0; i--) {
        if (matrix_[temp][i] && !visited_[i]) {
          s.push(i);
        }
      }
    }
    std::cout << '\n';
  }

  void BFS(int V) {
    ResetVisited();
    std::queue<int> q;
    q.push(V - 1);
    visited_[V - 1] = true;

    while (!q.empty()) {
      int temp = q.front();
      q.pop();
      for (int i = 0; i < n_; i++) {
        if (matrix_[temp][i] && !visited_[i]) {
          q.push(i);
          visited_[i] = true;
        }
      }
      std::cout << temp + 1 << " ";
    }
    std::cout << '\n';
  }

 private:
  int** matrix_ = nullptr;
  Vertex* vertices_ = nullptr;
  int n_ = 0;             // size
  int max_vertices_ = 0;  // capacity
  bool* visited_ = nullptr;
};

int main(void) {
  int N, M, V;
  std::cin >> N >> M >> V;

  AdjMatGraph<int> m(N + 1);
  for (int i = 1; i <= N; i++) m.InsertVertex(i);

  int u, v;
  for (int i = 0; i < M; i++) {
    std::cin >> u >> v;
    m.InsertEdge(u, v);
  }

  // m.PrintMatrix();
  m.DFS(V);
  m.BFS(V);

  return 0;
}