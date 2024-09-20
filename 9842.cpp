#include <cmath>
#include <iostream>

int main(void) {
  int n;
  std::cin >> n;

  int count = 1;
  int num = 2;
  while (!(count == n)) {
    num++;
    int check = 0;

    if (num > 10) {
      for (int i = 1; i <= sqrt(num); i++) {
        if (num % i == 0) check++;
      }
    } else {
      for (int i = 1; i < num; i++) {
        if (num % i == 0) check++;
      }
    }
    if (check == 1) {
      count++;
    }
  }
  std::cout << num << '\n';

  return 0;
}