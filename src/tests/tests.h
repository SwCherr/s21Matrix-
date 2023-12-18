#ifndef __CPP1_S21_MATRIXPLUS_SRC_TESTS_TESTS_H__
#define __CPP1_S21_MATRIXPLUS_SRC_TESTS_TESTS_H__

#include <gtest/gtest.h>

#include "../project/s21_matrix_oop.h"

class S21MatrixTest : public testing::Test {
 protected:
  void SetUp();
  void TearDown();
  void GenerateMatrix(S21Matrix &m, double count);
  // void PrintMatrix(S21Matrix& m);
  S21Matrix *test_matrix_00;
  S21Matrix *test_matrix_33;
  S21Matrix *test_matrix_44;
};

#endif // __CPP1_S21_MATRIXPLUS_SRC_TESTS_TESTS_H__