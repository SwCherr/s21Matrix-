#include "tests.h"

// +
TEST_F(S21MatrixTest, test_overload_func_1) {
  S21Matrix test_matrix_1(3, 3);
  S21Matrix test_matrix_2(3, 3);
  GenerateMatrix(test_matrix_1, 1);
  S21Matrix result_matrix = test_matrix_2 + test_matrix_1;
  bool result = result_matrix.EqMatrix(test_matrix_1);
  ASSERT_EQ(result, true);
}

// -
TEST_F(S21MatrixTest, test_overload_func_2) {
  S21Matrix test_matrix_1(3, 3);
  S21Matrix test_matrix_2(3, 3);
  GenerateMatrix(test_matrix_1, 2);
  GenerateMatrix(test_matrix_2, 1);
  S21Matrix result_matrix = test_matrix_1 - test_matrix_2;
  S21Matrix check_matrix(3, 3);
  check_matrix.SetValue(0, 0, 1);
  check_matrix.SetValue(0, 1, 2);
  check_matrix.SetValue(0, 2, 4);
  check_matrix.SetValue(1, 0, 8);
  check_matrix.SetValue(1, 1, 16);
  check_matrix.SetValue(1, 2, 32);
  check_matrix.SetValue(2, 0, 64);
  check_matrix.SetValue(2, 1, 128);
  check_matrix.SetValue(2, 2, 256);
  bool result = result_matrix.EqMatrix(check_matrix);
  ASSERT_EQ(result, true);
}

// *
TEST_F(S21MatrixTest, test_overload_func_3) {
  S21Matrix test_matrix_1(3, 3);
  S21Matrix test_matrix_2(3, 3);
  GenerateMatrix(test_matrix_1, 2);
  GenerateMatrix(test_matrix_2, 1);
  S21Matrix result_matrix = test_matrix_1 * test_matrix_2;
  S21Matrix check_matrix(3, 3);
  check_matrix.SetValue(0, 0, 546);
  check_matrix.SetValue(0, 1, 1092);
  check_matrix.SetValue(0, 2, 2184);
  check_matrix.SetValue(1, 0, 4368);
  check_matrix.SetValue(1, 1, 8736);
  check_matrix.SetValue(1, 2, 17472);
  check_matrix.SetValue(2, 0, 34944);
  check_matrix.SetValue(2, 1, 69888);
  check_matrix.SetValue(2, 2, 139776);
  bool result = result_matrix.EqMatrix(check_matrix);
  ASSERT_EQ(result, true);
}

// +=
TEST_F(S21MatrixTest, test_overload_func_4) {
  S21Matrix test_matrix_1(3, 3);
  S21Matrix test_matrix_2(3, 3);
  GenerateMatrix(test_matrix_1, 1);
  GenerateMatrix(test_matrix_2, 2);
  test_matrix_1 += test_matrix_2;
  S21Matrix check_matrix(3, 3);
  check_matrix.SetValue(0, 0, 3);
  check_matrix.SetValue(0, 1, 6);
  check_matrix.SetValue(0, 2, 12);
  check_matrix.SetValue(1, 0, 24);
  check_matrix.SetValue(1, 1, 48);
  check_matrix.SetValue(1, 2, 96);
  check_matrix.SetValue(2, 0, 192);
  check_matrix.SetValue(2, 1, 384);
  check_matrix.SetValue(2, 2, 768);
  bool result = test_matrix_1.EqMatrix(check_matrix);
  ASSERT_EQ(result, true);
}

// -=
TEST_F(S21MatrixTest, test_overload_func_5) {
  S21Matrix test_matrix_1(3, 3);
  S21Matrix test_matrix_2(3, 3);
  GenerateMatrix(test_matrix_1, 2);
  GenerateMatrix(test_matrix_2, 1);
  test_matrix_1 -= test_matrix_2;
  S21Matrix check_matrix(3, 3);
  check_matrix.SetValue(0, 0, 1);
  check_matrix.SetValue(0, 1, 2);
  check_matrix.SetValue(0, 2, 4);
  check_matrix.SetValue(1, 0, 8);
  check_matrix.SetValue(1, 1, 16);
  check_matrix.SetValue(1, 2, 32);
  check_matrix.SetValue(2, 0, 64);
  check_matrix.SetValue(2, 1, 128);
  check_matrix.SetValue(2, 2, 256);
  bool result = test_matrix_1.EqMatrix(check_matrix);
  ASSERT_EQ(result, true);
}

// *=
TEST_F(S21MatrixTest, test_overload_func_6) {
  S21Matrix test_matrix_1(3, 3);
  S21Matrix test_matrix_2(3, 3);
  GenerateMatrix(test_matrix_1, 2);
  GenerateMatrix(test_matrix_2, 1);
  test_matrix_1 *= test_matrix_2;
  S21Matrix check_matrix(3, 3);
  check_matrix.SetValue(0, 0, 546);
  check_matrix.SetValue(0, 1, 1092);
  check_matrix.SetValue(0, 2, 2184);
  check_matrix.SetValue(1, 0, 4368);
  check_matrix.SetValue(1, 1, 8736);
  check_matrix.SetValue(1, 2, 17472);
  check_matrix.SetValue(2, 0, 34944);
  check_matrix.SetValue(2, 1, 69888);
  check_matrix.SetValue(2, 2, 139776);
  bool result = test_matrix_1.EqMatrix(check_matrix);
  ASSERT_EQ(result, true);
}

// = оператор копирования
TEST_F(S21MatrixTest, test_overload_func_7_1) {
  S21Matrix test_matrix_1(2, 2);
  S21Matrix test_matrix_2(3, 3);
  GenerateMatrix(test_matrix_1, 8);
  GenerateMatrix(test_matrix_2, 1);
  test_matrix_1 = test_matrix_2;
  S21Matrix check_matrix(3, 3);
  check_matrix.SetValue(0, 0, 1);
  check_matrix.SetValue(0, 1, 2);
  check_matrix.SetValue(0, 2, 4);
  check_matrix.SetValue(1, 0, 8);
  check_matrix.SetValue(1, 1, 16);
  check_matrix.SetValue(1, 2, 32);
  check_matrix.SetValue(2, 0, 64);
  check_matrix.SetValue(2, 1, 128);
  check_matrix.SetValue(2, 2, 256);
  bool result = test_matrix_1.EqMatrix(check_matrix);
  ASSERT_EQ(result, true);
  ASSERT_EQ(test_matrix_1.GetRows(), 3);
  ASSERT_EQ(test_matrix_1.GetCols(), 3);
}

// = оператор перемещения
TEST_F(S21MatrixTest, test_overload_func_7_2) {
  S21Matrix test_matrix_1(3, 3);
  S21Matrix test_matrix_2(3, 3);
  GenerateMatrix(test_matrix_1, 8);
  GenerateMatrix(test_matrix_2, 1);
  test_matrix_1 = std::move(test_matrix_2);
  S21Matrix check_matrix(3, 3);
  check_matrix.SetValue(0, 0, 1);
  check_matrix.SetValue(0, 1, 2);
  check_matrix.SetValue(0, 2, 4);
  check_matrix.SetValue(1, 0, 8);
  check_matrix.SetValue(1, 1, 16);
  check_matrix.SetValue(1, 2, 32);
  check_matrix.SetValue(2, 0, 64);
  check_matrix.SetValue(2, 1, 128);
  check_matrix.SetValue(2, 2, 256);
  bool result = test_matrix_1.EqMatrix(check_matrix);
  ASSERT_EQ(test_matrix_2.GetRows(), 0);
  ASSERT_EQ(test_matrix_2.GetCols(), 0);
  ASSERT_EQ(result, true);
}

// == TRUE
TEST_F(S21MatrixTest, test_overload_func_8) {
  S21Matrix test_matrix_1(3, 3);
  S21Matrix test_matrix_2(3, 3);
  GenerateMatrix(test_matrix_1, 1);
  GenerateMatrix(test_matrix_2, 1);
  bool result = (test_matrix_1 == test_matrix_2);
  ASSERT_EQ(result, true);
}

// == FALSE
TEST_F(S21MatrixTest, test_overload_func_9) {
  S21Matrix test_matrix_1(3, 3);
  S21Matrix test_matrix_2(3, 3);
  GenerateMatrix(test_matrix_1, 2);
  GenerateMatrix(test_matrix_2, 1);
  bool result = (test_matrix_1 == test_matrix_2);
  ASSERT_EQ(result, false);
}

// () CORRECT SIZE
TEST_F(S21MatrixTest, test_overload_func_10) {
  S21Matrix test_matrix(3, 3);
  GenerateMatrix(test_matrix, 1);
  double count = 1;
  for (int i = 0; i < test_matrix.GetRows(); i++) {
    for (int j = 0; j < test_matrix.GetCols(); j++) {
      ASSERT_EQ(test_matrix(i, j), count);
      count += count;
    }
  }
}

// () INCORRECT SIZE ROWS
TEST_F(S21MatrixTest, test_overload_func_11) {
  bool result = false;
  S21Matrix test_matrix(3, 3);
  GenerateMatrix(test_matrix, 1);
  try {
    double count = 1;
    for (int i = 0; i < test_matrix.GetRows() + 1; i++) {
      for (int j = 0; j < test_matrix.GetCols(); j++) {
        ASSERT_EQ(test_matrix(i, j), count);
        count += count;
      }
    }
  } catch (const std::exception& err) {
    result = true;
  }
  ASSERT_EQ(result, true);
}

// () INCORRECT SIZE COLS
TEST_F(S21MatrixTest, test_overload_func_12) {
  bool result = false;
  S21Matrix test_matrix(3, 3);
  GenerateMatrix(test_matrix, 1);
  try {
    double count = 1;
    for (int i = 0; i < test_matrix.GetRows(); i++) {
      for (int j = 0; j < test_matrix.GetCols() + 1; j++) {
        ASSERT_EQ(test_matrix(i, j), count);
        count += count;
      }
    }
  } catch (const std::exception& err) {
    result = true;
  }
  ASSERT_EQ(result, true);
}