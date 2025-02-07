#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

struct Node {
  int value, id;
};

class MinHeap {
 public:
  std::vector<Node> heap;

  void push(const Node& node) {
    heap.push_back(node);
    siftUp(heap.size() - 1);
  }

  Node top() { return heap.front(); }

  void pop() {
    std::swap(heap.front(), heap.back());
    heap.pop_back();
    siftDown(0);
  }

  bool empty() { return heap.empty(); }

 private:
  void siftUp(int idx) {
    while (idx > 0) {
      int parent = (idx - 1) / 2;
      if (heap[idx].value < heap[parent].value) {
        std::swap(heap[idx], heap[parent]);
        idx = parent;
      } else {
        break;
      }
    }
  }

  void siftDown(int idx) {
    int n = heap.size();
    while (idx < n) {
      int smallest = idx;
      int left = idx * 2 + 1;
      int right = idx * 2 + 2;
      if (left < n && heap[left].value < heap[smallest].value) {
        smallest = left;
      }

      if (right < n && heap[right].value < heap[smallest].value) {
        smallest = right;
      }

      if (smallest != idx) {
        std::swap(heap[idx], heap[smallest]);
        idx = smallest;
      } else {
        break;
      }
    }
  }
};

class MaxHeap {
 public:
  std::vector<Node> heap;

  void push(const Node& node) {
    heap.push_back(node);
    siftUp(heap.size() - 1);
  }

  Node top() { return heap.front(); }

  void pop() {
    std::swap(heap.front(), heap.back());
    heap.pop_back();
    siftDown(0);
  }

  bool empty() { return heap.empty(); }

 private:
  void siftUp(int idx) {
    while (idx > 0) {
      int parent = (idx - 1) / 2;
      if (heap[idx].value > heap[parent].value) {
        std::swap(heap[idx], heap[parent]);
        idx = parent;
      } else {
        break;
      }
    }
  }
  void siftDown(int idx) {
    int n = heap.size();
    while (idx < n) {
      int largest = idx;
      int left = idx * 2 + 1;
      int right = idx * 2 + 2;

      if (left < n && heap[left].value > heap[largest].value) {
        largest = left;
      }

      if (right < n && heap[right].value > heap[largest].value) {
        largest = right;
      }

      if (largest != idx) {
        std::swap(heap[idx], heap[largest]);
        idx = largest;
      } else {
        break;
      }
    }
  }
};

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int T;
  std::cin >> T;

  while (T--) {
    int k;
    std::cin >> k;

    MinHeap minHeap;
    MaxHeap maxHeap;

    std::vector<bool> valid(1000001, false);
    int currId = 0;

    for (int i = 0; i < k; i++) {
      char op;
      long long num;
      std::cin >> op >> num;

      if (op == 'I') {
        Node node;
        node.id = currId;
        node.value = num;

        minHeap.push(node);
        maxHeap.push(node);
        valid[currId] = true;
        currId++;
      } else if (op == 'D') {
        if (num == 1) {
          while (!maxHeap.empty() && !valid[maxHeap.top().id]) {
            maxHeap.pop();
          }
          if (!maxHeap.empty()) {
            valid[maxHeap.top().id] = false;
            maxHeap.pop();
          }
        } else if (num == -1) {
          while (!minHeap.empty() && !valid[minHeap.top().id]) {
            minHeap.pop();
          }
          if (!minHeap.empty()) {
            valid[minHeap.top().id] = false;
            minHeap.pop();
          }
        }
      }
    }

    while (!minHeap.empty() && !valid[minHeap.top().id]) {
      minHeap.pop();
    }
    while (!maxHeap.empty() && !valid[maxHeap.top().id]) {
      maxHeap.pop();
    }

    if (minHeap.empty() || maxHeap.empty()) {
      std::cout << "EMPTY" << '\n';
    } else {
      std::cout << maxHeap.top().value << " " << minHeap.top().value << '\n';
    }
  }

  return 0;
}
