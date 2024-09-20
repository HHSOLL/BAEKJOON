#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

struct Num {
  int freq;
  int value;
};

int main(void) {
  int n;
  std::cin >> n;

  std::vector<int> v;
  std::vector<Num> v2;
  double sum = 0.0;

  for (int i = 0; i < n; i++) {  // 입력받기
    int value;
    std::cin >> value;
    v.push_back(value);
    sum += value;
  }

  std::stable_sort(v.begin(), v.end());  // 입력받은 벡터 정렬

  v2.push_back({1, v[0]});  // v2 벡터에 입력받은 값과 그 빈도 저장
  int max_freq = 1;
  for (int i = 1; i < v.size(); i++) {
    if (v2.back().value == v[i]) {
      v2.back().freq++;
    } else {
      v2.push_back({1, v[i]});
    }
    if (v2.back().freq > max_freq) max_freq = v2.back().freq;
  }

  // std::cout << "vector : ";
  // for (int i = 0; i < v.size(); i++) {
  //   std::cout << v[i] << " ";
  // }
  // std::cout << '\n';

  int sansul = 0;
  int jungang = 0;
  int choi = 0;
  int range = 0;

  // 산술평균
  sansul = round(sum / n);
  std::cout << sansul << '\n';

  // 중앙값
  jungang = v[n / 2];
  std::cout << jungang << '\n';

  // 최빈값
  int freq_count = 0;
  for (int i = 0; i < v2.size(); i++) {  // 최빈값의 개수 찾기
    if (v2[i].freq == max_freq) freq_count++;
  }
  if (freq_count == 1) {  // 최빈값이 하나라면 출력하기
    for (int i = 0; i < v2.size(); i++) {
      if (v2[i].freq == max_freq) std::cout << v2[i].value << '\n';
    }
  } else {
    int count = 0;  // 최빈값이 여러개라면, 두번째로 작은 값 출력
    for (int i = 0; i < v2.size(); i++) {
      if (v2[i].freq == max_freq) {
        count++;
        if (count == 2) {
          std::cout << v2[i].value << '\n';
        }
      }
    }
  }

  // 범위
  range = v.back() - v.front();
  std::cout << range << '\n';

  return 0;
}