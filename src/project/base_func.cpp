#include "s21_matrix_oop.h"

// *****************************
// --------- CONSTRUCT ---------
// *****************************

void S21Matrix::InitialMatrix() {
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] = 0;
    }
  }
}

S21Matrix::S21Matrix() : rows_(0), cols_(0), matrix_(nullptr) {}

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  if (rows_ >= 0 && cols_ >= 0) {
    matrix_ = new double*[rows_]();
    for (int i = 0; i < rows_; ++i) matrix_[i] = new double[cols_];
    this->InitialMatrix();
  } else {
    rows_ = 0;
    cols_ = 0;
    matrix_ = nullptr;
  }
}

S21Matrix::S21Matrix(const S21Matrix& o) : S21Matrix(o.rows_, o.cols_) {
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] = o.matrix_[i][j];
    }
  }
}

S21Matrix::S21Matrix(S21Matrix&& o)
    : rows_(o.rows_), cols_(o.cols_), matrix_(o.matrix_) {
  o.rows_ = 0;
  o.cols_ = 0;
  o.matrix_ = nullptr;
}

// *******************************
// --------- DECONSTRUCT ---------
// *******************************

S21Matrix::~S21Matrix() {
  if (matrix_) {
    for (int i = 0; i < rows_; ++i) {
      if (matrix_[i]) delete[] matrix_[i];
    }
    delete[] matrix_;
    matrix_ = nullptr;
    rows_ = 0;
    cols_ = 0;
  }
}

// *******************************
// ----- ACCESSROR & MUTATOR -----
// *******************************

int S21Matrix::GetRows() { return rows_; }
int S21Matrix::GetCols() { return cols_; }

void S21Matrix::SetRows(int newrows_) {
  if (newrows_ < 0) {
    throw std::length_error("matrix rows count must be non-negative");
  }

  if (newrows_ != rows_) {
    S21Matrix new_m(newrows_, cols_);
    int min = std::min(rows_, newrows_);
    for (int i = 0; i < min; ++i) {
      for (int j = 0; j < cols_; ++j) {
        new_m.matrix_[i][j] = (*this).matrix_[i][j];
      }
    }
    *this = new_m;
  }
}

void S21Matrix::SetCols(int newcols_) {
  if (newcols_ < 0) {
    throw std::length_error("matrix cols count must be non-negative");
  }

  if (newcols_ != cols_) {
    S21Matrix new_m(rows_, newcols_);
    int min = std::min(cols_, newcols_);
    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < min; ++j) {
        new_m.matrix_[i][j] = (*this).matrix_[i][j];
      }
    }
    *this = new_m;
  }
}

double S21Matrix::GetValue(int i, int j) {
  if ((i < 0) || (i >= rows_) || (j < 0) || (j >= cols_)) {
    throw std::out_of_range("Incorrect input, index is out of range");
  }
  return matrix_[i][j];
}

void S21Matrix::SetValue(int i, int j, double value) {
  if ((i < 0) || (i >= rows_) || (j < 0) || (j >= cols_)) {
    throw std::out_of_range("Incorrect input, index is out of range");
  }
  matrix_[i][j] = value;
}