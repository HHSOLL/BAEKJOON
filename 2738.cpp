#include <iostream>
#include <vector>

class Matrix {
 public:
  Matrix(int num_row, int num_col)
      : num_rows_(num_row),
        num_cols_(num_col),
        v_(num_row, std::vector<int>(num_col, 0)) {}

  Matrix Add(const Matrix& m) {
    Matrix result(num_rows_, num_cols_);

    for (int i = 0; i < num_rows_; i++) {
      for (int j = 0; j < num_cols_; j++) {
        result.v_[i][j] = v_[i][j] + m.v_[i][j];
      }
    }
    return result;
  }

  void SetValue(int num_row, int num_col) {
    for (int i = 0; i < num_row; i++) {
      for (int j = 0; j < num_col; j++) {
        std::cin >> v_[i][j];
      }
    }
  }

  void Print() {
    for (int i = 0; i < num_rows_; i++) {
      for (int j = 0; j < num_cols_; j++) {
        std::cout << v_[i][j] << " ";
      }
      std::cout << '\n';
    }
  }

 private:
  std::vector<std::vector<int>> v_;
  int num_rows_ = 0;
  int num_cols_ = 0;
};

int main(void) {
  int m, n;
  std::cin >> m >> n;

  Matrix m1(m, n);
  Matrix m2(m, n);

  m1.SetValue(m, n);
  m2.SetValue(m, n);

  Matrix add = m1.Add(m2);
  add.Print();

  return 0;
}