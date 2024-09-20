#include <iostream>

template <typename T>
class LinkedList {
 public:
  struct Node {
    T item;
    Node* next;
  };

  LinkedList() {}
  ~LinkedList() { Clear(); }
  void Clear() {
    while (!(first_ == last_)) {
      Node* temp = first_;
      first_ = first_->next;
      delete temp;
    }
    last_ = nullptr;
    size_ = 0;
  }

  bool IsEmpty() { return first_ == nullptr; }

  void PushBack(T item) {
    Node* new_node = new Node;
    new_node->item = item;
    new_node->next = nullptr;

    if (first_ == nullptr) {
      first_ = new_node;
      last_ = new_node;
      new_node->next = first_;
    } else {
      last_->next = new_node;
      last_ = new_node;
      new_node->next = first_;
    }
    size_++;
  }

  T PopFront() {
    if (first_ == nullptr) return 0;

    Node* temp = first_;
    T value = temp->item;
    first_ = first_->next;
    last_->next = first_;
    delete temp;
    size_--;
    return value;
  }

  void MoveFront() {
    if (first_ != nullptr) {
      last_ = first_;
      first_ = first_->next;
    }
  }

 private:
  Node* first_ = nullptr;
  Node* last_ = nullptr;
  int size_ = 0;
};
int main(void) {
  int n, k;
  std::cin >> n >> k;

  LinkedList<int> list;
  for (int i = 1; i <= n; i++) {
    list.PushBack(i);
  }

  int count = 0;
  std::cout << "<";
  while (!list.IsEmpty()) {
    for (int i = 1; i < k; i++) {
      list.MoveFront();
    }
    std::cout << list.PopFront();
    count++;
    if (count < n) {
      std::cout << ", ";
    } else {
      std::cout << ">" << '\n';
      return 0;
    }
  }
  return 0;
}