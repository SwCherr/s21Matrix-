#include "s21_matrix_oop.h"

S21Matrix S21Matrix::operator+(const S21Matrix& o) {
  S21Matrix res(rows_, cols_);
  res.SumMatrix(*this);
  res.SumMatrix(o);
  return res;
}

S21Matrix S21Matrix::operator-(const S21Matrix& o) {
  S21Matrix res(rows_, cols_);
  res.SumMatrix(*this);
  res.SubMatrix(o);
  return res;
}

S21Matrix S21Matrix::operator*(const S21Matrix& o) {
  S21Matrix res(rows_, cols_);
  res.SumMatrix(*this);
  res.MulMatrix(o);
  return res;
}

bool S21Matrix::operator==(const S21Matrix& o) { return this->EqMatrix(o); }

// ----- оператор копирования -----
S21Matrix& S21Matrix::operator=(S21Matrix& o) {
  if (this != &o) {
    std::swap(rows_, o.rows_);
    std::swap(cols_, o.cols_);
    std::swap(matrix_, o.matrix_);
  }
  return *this;
}

// ----- оператор перемещения -----
S21Matrix& S21Matrix::operator=(S21Matrix&& o) {
  if (this != &o) {
    if (this->matrix_)
      this->~S21Matrix();
    std::swap(rows_, o.rows_);
    std::swap(cols_, o.cols_);
    std::swap(matrix_, o.matrix_);
  }
  o.rows_ = 0;
  o.cols_ = 0;
  o.matrix_ = nullptr;
  return *this;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& o) {
  this->SumMatrix(o);
  return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& o) {
  this->SubMatrix(o);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& o) {
  this->MulMatrix(o);
  return *this;
}

const double& S21Matrix::operator()(int row, int col) {
  if (row >= rows_ || col >= cols_) {
    throw std::out_of_range("Incorrect input, index is out of range");
  }
  return matrix_[row][col];
}
