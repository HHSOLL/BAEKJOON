#include <iostream>
#include <vector>

template <typename T>
class set {
 public:
  set() : size_(0) {}
  // ~set() {}

  void add(T item) {
    if (!(find(item) < 0)) return;

    v_.push_back(item);
    size_++;
  }

  void remove(T item) {
    int check = find(item);
    if (!(check < 0)) {
      size_--;
      v_.erase(v_.begin() + check);
    }
  }

  int check(T item) {
    if (!(find(item) < 0)) return 1;
    return 0;
  }

  void toggle(T item) {
    if (!(find(item) < 0))
      remove(item);
    else
      add(item);
  }

  void all() {
    v_.clear();
    size_ = 0;
    for (int i = 1; i <= 20; i++) {
      v_.push_back(i);
      size_++;
    }
  }

  void empty() {
    v_.clear();
    size_ = 0;
  }

  int find(T value) {
    for (int i = 0; i < size_; i++) {
      if (v_[i] == value) {
        return i;
      }
    }
    return -1;
  }

 private:
  std::vector<int> v_;
  int size_;
};

constexpr unsigned int HashCode(const char* str) {
  return str[0] ? static_cast<unsigned int>(str[0]) +
                      0xEDB8832Full * HashCode(str + 1)
                : 8603;
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  int n;
  std::cin >> n;

  set<int> s;

  char str[9];
  for (int i = 0; i < n; i++) {
    std::cin >> str;

    switch (HashCode(str)) {
      case HashCode("add"):
        int num;
        std::cin >> num;
        s.add(num);
        break;
      case HashCode("remove"):
        std::cin >> num;
        s.remove(num);
        break;
      case HashCode("check"):
        std::cin >> num;
        std::cout << s.check(num) << '\n';
        break;
      case HashCode("toggle"):
        std::cin >> num;
        s.toggle(num);
        break;
      case HashCode("all"):
        s.all();
        break;
      case HashCode("empty"):
        s.empty();
        break;
      default:
        std::cout << "wrong order" << '\n';
        break;
    }
  }
  return 0;
}