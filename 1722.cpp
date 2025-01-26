#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  int N, K;
  std::cin >> N >> K;

  std::vector<long long> factorial(N + 1, 1);
  for (int i = 1; i <= N; i++) factorial[i] = factorial[i - 1] * i;

  if (K == 1) {
    long long order;
    std::cin >> order;

    std::vector<int> num;
    for (int i = 1; i <= N; i++) num.push_back(i);

    order--;
    std::vector<int> result;

    for (int i = 0; i < N; i++) {
      int idx = order / factorial[N - 1 - i];
      result.push_back(num[idx]);
      num.erase(num.begin() + idx);
      order %= factorial[N - 1 - i];
    }

    for (int num : result) std::cout << num << " ";

    std::cout << '\n';

  } else if (K == 2) {
    std::vector<int> perm(N);
    for (int i = 0; i < N; i++) {
      std::cin >> perm[i];
    }

    std::vector<int> numbers;
    for (int i = 1; i <= N; i++) {
      numbers.push_back(i);
    }

    long long order = 0;

    for (int i = 0; i < N; i++) {
      int idx = find(numbers.begin(), numbers.end(), perm[i]) - numbers.begin();
      order += idx * factorial[N - 1 - i];
      numbers.erase(numbers.begin() + idx);
    }

    std::cout << order + 1 << '\n';
  }

  return 0;
}