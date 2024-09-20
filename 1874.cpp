// #include <cassert>
#include <cstring>
#include <iostream>
#include <vector>

template <typename T>
class Stack {
 public:
  Stack(int capacity = 2) {
    // assert(capacity > 0);
    Resize(capacity);
  }
  ~Stack() {
    if (stack_) delete[] stack_;
  }

  void Resize(int new_capacity) {
    T* new_stack = new T[new_capacity];

    if (stack_) {
      std::memcpy(new_stack, stack_, sizeof(T) * Size());
      delete[] stack_;
    }
    capacity_ = new_capacity;
    stack_ = new_stack;
  }

  int Size() { return top_ + 1; }

  void Push(T& item) {
    if (IsFull()) Resize(capacity_ * 2);
    stack_[++top_] = item;
  }

  T& Pop() { return stack_[top_--]; }

  T& Top() {
    if (IsEmpty()) throw std::out_of_range("Stack is empty");
    return stack_[top_];
  }

  bool IsEmpty() { return top_ + 1 == 0; }

  bool IsFull() { return capacity_ - 1 == top_; }

  void PrintStack() const {
    std::cout << "STACK" << '\n';
    for (int i = top_; i >= 0; i--) {
      std::cout << stack_[i] << '\n';
    }
  }

 private:
  T* stack_ = nullptr;
  int top_ = -1;
  int size_ = 0;
  int capacity_ = 0;
};

int main(void) {
  Stack<int> s;

  int n;
  std::cin >> n;

  std::vector<int> v;
  std::vector<char> pm;
  std::vector<int> cmp;

  for (int i = 0; i < n; i++) {
    int k;
    std::cin >> k;
    v.push_back(k);
  }

  int index = 0;
  int i = 1;
  while (i <= v.size() + 1) {
    if (index >= v.size()) break;

    if (s.IsEmpty()) {  // stack 비엇을 때 Top() 방지용
      s.Push(i);
      pm.push_back('+');
      i++;
    }

    if (s.Top() == v.at(index)) {
      cmp.push_back(s.Pop());
      index++;
      pm.push_back('-');
      continue;
    }
    s.Push(i);
    pm.push_back('+');
    i++;
  }

  if (v == cmp) {
    for (int i = 0; i < pm.size(); i++) {
      std::cout << pm[i] << '\n';
    }
  } else
    std::cout << "NO" << '\n';
  return 0;
}