#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::vector<int> minCount(4, 0);
std::vector<int> count(4, 0);

bool check() {
  for (int i = 0; i < 4; i++) {
    if (count[i] < minCount[i]) return false;
  }
  return true;
}

void add(std::string& str, int eidx) {
  switch (str[eidx]) {
    case 'A':
      count[0]++;
      break;
    case 'C':
      count[1]++;
      break;
    case 'G':
      count[2]++;
      break;
    case 'T':
      count[3]++;
      break;
    default:
      break;
  }
}

void remove(std::string& str, int sidx) {
  switch (str[sidx]) {
    case 'A':
      count[0]--;
      break;
    case 'C':
      count[1]--;
      break;
    case 'G':
      count[2]--;
      break;
    case 'T':
      count[3]--;
      break;
    default:
      break;
  }
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int S, P;
  std::cin >> S >> P;

  std::string str;
  std::cin >> str;

  for (int i = 0; i < 4; i++) {
    std::cin >> minCount[i];
  }

  int start_idx = 0;
  int end_idx = start_idx + P - 1;
  int countPW = 0;

  for (int i = 0; i < P; i++) {
    add(str, i);
  }
  if (check()) countPW++;

  for (int i = P; i < S; i++) {
    add(str, i);
    remove(str, i - P);
    if (check()) countPW++;
  }

  std::cout << countPW << '\n';

  return 0;
}