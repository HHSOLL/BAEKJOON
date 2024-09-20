#include <algorithm>
#include <iostream>
#include <string>

struct member {
  int age;
  std::string name;
};

// void InsertionSort(member* m, int size);

bool compareMembers(const member& a, const member& b);

int main(void) {
  int n;
  std::cin >> n;

  member* m = new member[n];
  for (int i = 0; i < n; i++) {
    std::cin >> m[i].age >> m[i].name;
  }

  //   InsertionSort(m, n);

  std::stable_sort(m, m + n, compareMembers);

  for (int i = 0; i < n; i++) {
    std::cout << m[i].age << " " << m[i].name << '\n';
  }
  delete[] m;
  return 0;
}

// void InsertionSort(member* m, int size) {
//   for (int i = 1; i < size; i++) {
//     int j = i - 1;
//     member key = m[i];

//     while (j >= 0 && m[j].age > key.age) {
//       m[j + 1] = m[j];
//       j--;
//     }
//     m[j + 1] = key;
//   }
// }

bool compareMembers(const member& a, const member& b) { return a.age < b.age; }