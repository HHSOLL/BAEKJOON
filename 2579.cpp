#include <iostream>

int RecurStair(int arr[], int num_stair, int count, int score, int curr) {
  if (curr == num_stair - 1) {
    score = score + arr[curr];
  }

  if (curr == num_stair - 2 && count == 0)
    return RecurStair(arr, num_stair, count, score, curr + 1);
}

int main(void) {
  int num_stair = 0;
  std::cin >> num_stair;

  int arr[num_stair];
  for (int i = 0; i < num_stair; i++) std::cin >> arr[i];

  int size = sizeof(arr) / sizeof(int);

  int count = 0;
  int score = 0;
  int max_score = RecurStair(arr, num_stair, count, score, 0);

  return 0;
}