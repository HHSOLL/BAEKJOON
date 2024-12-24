#include <cmath>
#include <cstring>
#include <iostream>

template <typename T>
class absoluteHeap {
 public:
  absoluteHeap(int cap = 10) : size_(0), capacity_(cap) {
    heap_ = new T[capacity_ + 1];
  }

  ~absoluteHeap() { delete[] heap_; }

  void Resize(int new_capacity) {
    T* new_heap = new T[new_capacity + 1];
    std::memcpy(new_heap, heap_, sizeof(T) * (size_ + 1));
    delete[] heap_;
    heap_ = new_heap;
    capacity_ = new_capacity;
  }

  T Top() {
    if (isEmpty()) return 0;
    return heap_[1];
  }

  bool isEmpty() { return size_ == 0; }

  void push(const T& item) {
    if (size_ == capacity_) Resize(capacity_ * 2);

    size_++;
    int current = size_;

    while (current != 1 && Compare(item, heap_[current / 2])) {
      heap_[current] = heap_[current / 2];
      current /= 2;
    }
    heap_[current] = item;
  }

  void pop() {
    if (isEmpty()) {
      std::cout << "0\n";
      return;
    }

    std::cout << heap_[1] << "\n";
    T temp = heap_[size_];
    size_--;

    int curr_idx = 1;
    int child_idx;

    while (curr_idx * 2 <= size_) {
      int left = curr_idx * 2;
      int right = left + 1;

      if (right <= size_ && Compare(heap_[right], heap_[left])) {
        child_idx = right;
      } else {
        child_idx = left;
      }

      if (Compare(temp, heap_[child_idx])) break;

      heap_[curr_idx] = heap_[child_idx];
      curr_idx = child_idx;
    }
    heap_[curr_idx] = temp;
  }

 private:
  T* heap_ = nullptr;
  int size_ = 0;
  int capacity_ = 0;

  bool Compare(const T& a, const T& b) {
    if (std::abs(a) == std::abs(b)) return a < b;
    return std::abs(a) < std::abs(b);
  }
};

int main() {
  int rec;
  std::cin >> rec;

  absoluteHeap<int> absHeap;

  int num;
  for (int i = 0; i < rec; i++) {
    std::cin >> num;

    if (num == 0) {
      absHeap.pop();
    } else {
      absHeap.push(num);
    }
  }

  return 0;
}