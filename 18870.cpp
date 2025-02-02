#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <vector>

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int n;
  std::cin >> n;

  std::vector<int> coords(n);
  for (int i = 0; i < n; i++) {
    std::cin >> coords[i];
  }

  std::vector<int> uniqueCoords = coords;
  std::sort(uniqueCoords.begin(), uniqueCoords.end());
  uniqueCoords.erase(unique(uniqueCoords.begin(), uniqueCoords.end()),
                     uniqueCoords.end());

  std::map<int, int> compress;
  for (int i = 0; i < uniqueCoords.size(); i++) {
    compress[uniqueCoords[i]] = i;
  }

  std::vector<int> compressed;
  for (int x : coords) {
    compressed.push_back(compress[x]);
  }

  for (int x : compressed) {
    std::cout << x << " ";
  }
  std::cout << '\n';

  return 0;
}
