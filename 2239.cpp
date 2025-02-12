#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

int board[9][9];
bool rowUsed[9][10] = {false};
bool colUsed[9][10] = {false};
bool boxUsed[9][10] = {false};

bool solved = false;

int getBoxIdx(int r, int c) { return (r / 3) * 3 + (c / 3); }

void sudoku(int idx) {
  if (idx == 81) {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        std::cout << board[i][j];
      }
      std::cout << '\n';
    }
    solved = true;
    return;
  }

  int r = idx / 9;
  int c = idx % 9;

  if (board[r][c] != 0) {
    sudoku(idx + 1);
    return;
  }

  for (int num = 1; num <= 9; num++) {
    int boxIdx = getBoxIdx(r, c);

    if (!rowUsed[r][num] && !colUsed[c][num] && !boxUsed[boxIdx][num]) {
      board[r][c] = num;
      rowUsed[r][num] = true;
      colUsed[c][num] = true;
      boxUsed[boxIdx][num] = true;

      sudoku(idx + 1);
      if (solved) return;

      board[r][c] = 0;
      rowUsed[r][num] = false;
      colUsed[c][num] = false;
      boxUsed[boxIdx][num] = false;
    }
  }
}

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  for (int i = 0; i < 9; i++) {
    std::string str;
    std::cin >> str;

    for (int j = 0; j < 9; j++) {
      board[i][j] = str[j] - '0';
    }
  }

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      int num = board[i][j];
      if (num != 0) {
        rowUsed[i][num] = true;
        colUsed[j][num] = true;
        boxUsed[getBoxIdx(i, j)][num] = true;
      }
    }
  }

  sudoku(0);

  return 0;
}
