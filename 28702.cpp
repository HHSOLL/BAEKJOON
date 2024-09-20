#include <iostream>
#include <string>

int main(void) {
  std::string s1;
  std::string s2;
  std::string s3;

  std::cin >> s1;
  std::cin >> s2;
  std::cin >> s3;

  // s s n
  if (48 <= s3[0] && s3[0] <= 57) {
    switch (stoll(s3) % 15) {
      case 2:
      case 5:
      case 8:
      case 11:
        std::cout << "Fizz" << '\n';
        break;

      case 4:
      case 9:
        std::cout << "Buzz" << '\n';
        break;

      case 14:
        std::cout << "FizzBuzz" << '\n';
        break;

      default:
        std::cout << stoll(s3) + 1 << '\n';
        break;
    }
    // ? n s
  } else if (48 <= s2[0] && s2[0] <= 57) {
    switch (stoi(s2) % 15) {
      case 1:
      case 4:
      case 7:
      case 10:
        std::cout << "Fizz" << '\n';
        break;

      case 3:
      case 8:
        std::cout << "Buzz" << '\n';
        break;

      default:
        std::cout << stoll(s2) + 2 << '\n';
        break;
    }
    // ? s s
  } else {
    switch (stoll(s1) % 15) {
      case 4:
        std::cout << stoll(s1) + 3;
        break;
      case 8:
        std::cout << stoll(s1) + 3;
        break;
    }
  }

  return 0;
}