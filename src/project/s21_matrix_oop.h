#ifndef __CPP1_S21_MATRIXPLUS_SRC_PROJECT_S21MATRIX_H__
#define __CPP1_S21_MATRIXPLUS_SRC_PROJECT_S21MATRIX_H__

#include <math.h>
#include <iostream>

class S21Matrix {
 public:
  S21Matrix();                    // default constructor
  S21Matrix(int rows, int cols);  // parameterized constructor
  S21Matrix(const S21Matrix& o);  // copy cnstructor
  S21Matrix(S21Matrix&& o);       // move cnstructor
  ~S21Matrix();                   // destructor

  int GetRows();
  int GetCols();
  void SetRows(int new_rows);
  void SetCols(int new_cols);
  void SetValue(int i, int j, double value);
  double GetValue(int i, int j);

  bool EqMatrix(const S21Matrix& o);
  void SumMatrix(const S21Matrix& o);
  void SubMatrix(const S21Matrix& o);
  void MulNumber(const double number);
  void MulMatrix(const S21Matrix& o);

  double Determinant();
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  S21Matrix InverseMatrix();

  S21Matrix operator+(const S21Matrix& o);
  S21Matrix operator-(const S21Matrix& o);
  S21Matrix operator*(const S21Matrix& o);
  S21Matrix& operator+=(const S21Matrix& o);
  S21Matrix& operator-=(const S21Matrix& o);
  S21Matrix& operator*=(const S21Matrix& o);
  S21Matrix& operator=(S21Matrix& o);
  S21Matrix& operator=(S21Matrix&& o);
  bool operator==(const S21Matrix& o);
  const double& operator()(int row, int col);

 private:
  int rows_, cols_;
  double** matrix_;
  void InitialMatrix();
  S21Matrix GetMinor(int cur_row, int cur_col);
};

#endif // __CPP1_S21_MATRIXPLUS_SRC_PROJECT_S21MATRIX_H__
