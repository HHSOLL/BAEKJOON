#include <algorithm>
#include <iostream>
#include <vector>

int find(int t, std::vector<int>& people) {
  if (t == people[t])
    return t;
  else
    return people[t] = find(people[t], people);
}

void makeUnion(int a, int b, std::vector<int>& people) {
  int x = find(a, people);
  int y = find(b, people);

  if (x != y) {
    people[y] = x;
  }
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  // 사람수, 파티수
  int N, M;
  std::cin >> N >> M;

  // 사람 수만큼 배열 초기화
  std::vector<int> people(N + 1, 0);
  for (int i = 1; i <= N; i++) people[i] = i;

  // 진실을 아는 사람의 수를 입력받아 저장
  int p;
  std::cin >> p;
  std::vector<int> truth(p);
  for (int i = 0; i < p; i++) std::cin >> truth[i];

  // 파티의 수만큼 입력받기.
  std::vector<std::vector<int>> party_people(M, std::vector<int>());
  for (int i = 0; i < M; i++) {
    int number_of_people;
    std::cin >> number_of_people;
    for (int j = 0; j < number_of_people; j++) {
      int tmp;
      std::cin >> tmp;
      party_people[i].push_back(tmp);
    }
  }

  for (int i = 0; i < M; i++) {
    int first = party_people[i][0];
    for (int j = 1; j < party_people[i].size(); j++) {
      makeUnion(first, party_people[i][j], people);
    }
  }

  int available_party_count = 0;

  for (int i = 0; i < M; i++) {
    bool isPossible = true;
    int curr = party_people[i][0];

    for (int j = 0; j < truth.size(); j++) {
      if (find(curr, people) == find(truth[j], people)) {
        isPossible = false;
        break;
      }
    }
    if (isPossible) available_party_count++;
  }
  std::cout << available_party_count << '\n';

  return 0;
}