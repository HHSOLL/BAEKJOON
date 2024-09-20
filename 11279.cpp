#include <cstring>
#include <iostream>

template <typename T>
class MaxHeap {
 public:
  MaxHeap(int cap = 10) : size_(0), capacity_(cap) { heap_ = new T[cap + 1]; }

  void Resize(int new_cap) {
    T* new_heap = new T[new_cap + 1];
    std::memcpy(new_heap, heap_, sizeof(T) * (size_ + 1));

    if (heap_) delete[] heap_;

    heap_ = new_heap;
    capacity_ = new_cap;
  }

  bool IsEmpty() { return size_ == 0; }

  void Push(const T& item) {
    if (size_ == capacity_) Resize(capacity_ * 2);

    size_++;
    int curr = size_;

    while (curr != 1 && item > heap_[curr / 2]) {
      heap_[curr] = heap_[curr / 2];
      curr /= 2;
    }
    heap_[curr] = item;
  }

  T Pop() {
    if (size_ == 0) return 0;

    T max = heap_[1];
    T temp = heap_[size_];
    size_--;

    int curr = 1;
    int cld = 1;

    while (cld <= size_) {
      if (size_ > curr * 2) {
        cld = heap_[curr * 2] >= heap_[curr * 2 + 1] ? curr * 2 : curr * 2 + 1;
      } else if (size_ == curr * 2) {
        cld = curr * 2;
      } else {
        heap_[curr] = temp;
        break;
      }

      if (temp >= heap_[cld]) {
        heap_[curr] = temp;
        break;
      } else {
        heap_[curr] = heap_[cld];
        curr = cld;
      }
    }

    return max;
  }

 private:
  T* heap_ = nullptr;
  int size_ = 0;
  int capacity_ = 0;
};

int main(void) {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

  MaxHeap<int> h;

  int n;
  std::cin >> n;

  int num;
  for (int i = 0; i < n; i++) {
    std::cin >> num;
    if (num == 0) {
      std::cout << h.Pop() << '\n';
    } else {
      h.Push(num);
    }
  }

  return 0;
}