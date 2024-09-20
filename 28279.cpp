#include <cstring>
#include <iostream>

template <typename T>
class Deque {
 public:
  Deque(int capacity = 2) : capacity_(capacity), front_(0), rear_(0), size_(0) {
    deque_ = new T[capacity_];
  }
  ~Deque() {
    if (deque_) delete[] deque_;
  }

  void Resize(int new_capacity) {
    T* new_deque = new T[new_capacity];

    if (front_ < rear_) {
      std::memcpy(new_deque, deque_ + front_, size_ * sizeof(T));
    } else {
      int front_size = capacity_ - front_;
      std::memcpy(new_deque, deque_ + front_, front_size * sizeof(T));
      std::memcpy(new_deque + front_size, deque_, rear_ * sizeof(T));
    }

    delete[] deque_;
    deque_ = new_deque;

    front_ = 0;
    rear_ = size_;
    capacity_ = new_capacity;
  }

  void push_front(const T& item) {
    if (size_ == capacity_ - 1) Resize(capacity_ * 2);

    front_ = (front_ - 1 + capacity_) % capacity_;
    deque_[front_] = item;
    size_++;
  }

  void push_back(const T& item) {
    if (size_ == capacity_ - 1) Resize(capacity_ * 2);

    deque_[rear_] = item;
    rear_ = (rear_ + 1) % capacity_;
    size_++;
  }

  T pop_front() {
    if (front_ == rear_) return -1;

    T temp = deque_[front_];
    front_ = (front_ + 1) % capacity_;

    size_--;

    return temp;
  }

  T pop_back() {
    if (front_ == rear_) return -1;

    rear_ = (rear_ - 1 + capacity_) % capacity_;

    T temp = deque_[rear_];

    size_--;

    return temp;
  }

  int size() { return size_; }

  int isEmpty() { return size_ == 0; }

  T front() {
    if (front_ == rear_) return -1;

    return deque_[front_];
  }

  T back() {
    if (front_ == rear_) return -1;

    return deque_[(rear_ - 1 + capacity_) % capacity_];
  }

  // bool isFull() { return size_ == capacity_; }

 private:
  T* deque_ = nullptr;
  int size_ = 0;
  int capacity_ = 0;
  int front_ = 0;
  int rear_ = 0;
};

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  Deque<int> d(2);
  int n;
  std::cin >> n;

  int order = 0;
  int num = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> order;

    switch (order) {
      case 1:
        std::cin >> num;
        d.push_front(num);
        break;
      case 2:
        std::cin >> num;
        d.push_back(num);
        break;
      case 3:
        std::cout << d.pop_front() << '\n';
        break;
      case 4:
        std::cout << d.pop_back() << '\n';
        break;
      case 5:
        std::cout << d.size() << '\n';
        break;
      case 6:
        std::cout << d.isEmpty() << '\n';
        break;
      case 7:
        std::cout << d.front() << '\n';
        break;
      case 8:
        std::cout << d.back() << '\n';
        break;
      default:
        std::cout << "wrong order" << '\n';
        break;
    }
  }
  return 0;
}