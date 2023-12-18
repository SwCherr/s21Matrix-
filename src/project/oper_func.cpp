#include "s21_matrix_oop.h"

bool S21Matrix::EqMatrix(const S21Matrix& o) {
  bool answer = true;
  if (rows_ == o.rows_ && cols_ == o.cols_) {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        if (abs(matrix_[i][j] - o.matrix_[i][j]) > 1e-6) answer = false;
      }
    }
  } else
    answer = false;
  return answer;
}

void S21Matrix::SumMatrix(const S21Matrix& o) {
  if (rows_ != o.rows_ || cols_ != o.cols_) {
    throw std::out_of_range(
        "Incorrect input, matrices should have the same size");
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = matrix_[i][j] + o.matrix_[i][j];
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix& o) {
  if (rows_ != o.rows_ || cols_ != o.cols_) {
    throw std::out_of_range(
        "Incorrect input, matrices should have the same size");
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = matrix_[i][j] - o.matrix_[i][j];
    }
  }
}

void S21Matrix::MulNumber(const double number) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = matrix_[i][j] * number;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix& o) {
  if (cols_ != o.rows_) {
    throw std::out_of_range(
        "Incorrect input, matrices should have the same size");
  }
  S21Matrix matrix_tmp(rows_, o.cols_);
  for (int i = 0; i < matrix_tmp.rows_; i++) {
    for (int j = 0; j < matrix_tmp.cols_; j++) {
      double sum_tmp = 0;
      for (int k = 0; k < cols_; k++) {
        sum_tmp += matrix_[i][k] * o.matrix_[k][j];
      }
      matrix_tmp.matrix_[i][j] = sum_tmp;
    }
  }
  this->SetCols(o.cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = matrix_tmp.matrix_[i][j];
    }
  }
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix res(cols_, rows_);
  for (int i = 0; i < res.rows_; i++) {
    for (int j = 0; j < res.cols_; j++) {
      res.matrix_[i][j] = matrix_[j][i];
    }
  }
  return res;
}

S21Matrix S21Matrix::GetMinor(int cur_row, int cur_col) {
  S21Matrix minor(rows_ - 1, cols_ - 1);
  int row_min = 0;
  int col_min = 0;
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      if (i != cur_row && j != cur_col) {
        minor.matrix_[row_min][col_min++] = matrix_[i][j];
        if (col_min == minor.rows_) {
          col_min = 0;
          row_min++;
        }
      }
    }
  }
  return minor;
}

S21Matrix S21Matrix::CalcComplements() {
  if (rows_ != cols_) {
    throw std::out_of_range(
        "Incorrect input, matrices should have the same size");
  }
  S21Matrix minor(rows_, cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      S21Matrix curr_minor = this->GetMinor(i, j);
      double determin = curr_minor.Determinant();
      minor.matrix_[i][j] = pow(-1, i + j) * determin;
    }
  }
  return minor;
}

double S21Matrix::Determinant() {
  double result = 0;
  if (rows_ != cols_) {
    throw std::out_of_range(
        "Incorrect input, matrices should have the same size");
  }
  if (rows_ == 1)
    result = matrix_[0][0];
  else {
    for (int i = 0; i < rows_; i++) {
      S21Matrix curr_minor = this->GetMinor(0, i);
      double determin = curr_minor.Determinant();
      result += pow(-1, i) * matrix_[0][i] * determin;
    }
  }
  return result;
}

S21Matrix S21Matrix::InverseMatrix() {
  double determin = this->Determinant();
  if (fabs(determin) < 1e-7) {
    throw std::out_of_range(
        "The inverse matrix cannot be found because the determinant of the "
        "matrix is zero");
  }
  S21Matrix inverse_m(rows_, cols_);
  S21Matrix compl_m = this->CalcComplements();
  S21Matrix trans_m = compl_m.Transpose();
  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < cols_; j++)
      inverse_m.matrix_[i][j] = trans_m.matrix_[i][j] / determin;
  return inverse_m;
}