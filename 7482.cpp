#include <cmath>
#include <iostream>

int main(void) {
  int n;
  std::cin >> n;

  double width = 0.0;
  double height = 0.0;
  double volume = 0.0;
  for (int i = 0; i < n; i++) {
    std::cin >> width;

    // volume = (width - (height*2))^2 * height
    // volume = 4*height^3 - 4*width*height^2 + width^2*height

    // volume' = 12height^2 - 8width*height + width^2
    // volume' = (2height - widtt)(6height - width);
    // height = 1/2 width or 1/6 width

    height = width / 6;
    std::cout << std::fixed;
    std::cout.precision(10);
    std::cout << height << '\n';
  }
}