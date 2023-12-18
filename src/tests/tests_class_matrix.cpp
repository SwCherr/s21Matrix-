#include "tests.h"

TEST_F(S21MatrixTest, test_class_matrix_1) {
  S21Matrix test_matrix;
  ASSERT_EQ(test_matrix.GetRows(), 0);
  ASSERT_EQ(test_matrix.GetCols(), 0);
}

TEST_F(S21MatrixTest, test_class_matrix_2) {
  S21Matrix test_matrix(3, 3);
  bool result_check = test_matrix.EqMatrix(*test_matrix_33);
  ASSERT_EQ(result_check, true);
  ASSERT_EQ(test_matrix.GetRows(), 3);
  ASSERT_EQ(test_matrix.GetCols(), 3);
}

TEST_F(S21MatrixTest, test_class_matrix_3) {
  S21Matrix test_matrix(2, 4);
  test_matrix_33->SetRows(2);
  test_matrix_33->SetCols(4);
  bool result_check = test_matrix.EqMatrix(*test_matrix_33);
  ASSERT_EQ(result_check, true);
  ASSERT_EQ(test_matrix.GetRows(), 2);
  ASSERT_EQ(test_matrix.GetCols(), 4);
}

TEST_F(S21MatrixTest, test_class_matrix_4) {
  S21Matrix test_matrix(2, 4);
  test_matrix_33->SetRows(2);
  test_matrix_33->SetCols(4);
  GenerateMatrix(test_matrix, 1);
  GenerateMatrix(*test_matrix_33, 1);
  bool result_check = test_matrix.EqMatrix(*test_matrix_33);
  ASSERT_EQ(result_check, true);
  ASSERT_EQ(test_matrix.GetRows(), 2);
  ASSERT_EQ(test_matrix.GetCols(), 4);
}

TEST_F(S21MatrixTest, test_class_matrix_5) {
  S21Matrix test_matrix(2, 4);
  test_matrix.SetRows(5);
  test_matrix.SetCols(6);
  ASSERT_EQ(test_matrix.GetRows(), 5);
  ASSERT_EQ(test_matrix.GetCols(), 6);
}

// zero size construct
TEST_F(S21MatrixTest, test_class_matrix_6) {
  S21Matrix test_matrix(0, 0);
  ASSERT_EQ(test_matrix.GetRows(), 0);
  ASSERT_EQ(test_matrix.GetCols(), 0);
}

// negative size construct
TEST_F(S21MatrixTest, test_class_matrix_7) {
  S21Matrix test_matrix(-1, -2);
  ASSERT_EQ(test_matrix.GetRows(), 0);
  ASSERT_EQ(test_matrix.GetCols(), 0);
}

// negative size construct
TEST_F(S21MatrixTest, test_class_matrix_8) {
  S21Matrix test_matrix(2, -2);
  ASSERT_EQ(test_matrix.GetRows(), 0);
  ASSERT_EQ(test_matrix.GetCols(), 0);
}

// negative size construct
TEST_F(S21MatrixTest, test_class_matrix_9) {
  S21Matrix test_matrix(-2, 2);
  ASSERT_EQ(test_matrix.GetRows(), 0);
  ASSERT_EQ(test_matrix.GetCols(), 0);
}

// copy construct
TEST_F(S21MatrixTest, test_class_matrix_10) {
  S21Matrix test_matrix(*test_matrix_33);
  bool result_check = test_matrix.EqMatrix(*test_matrix_33);
  ASSERT_EQ(result_check, true);
  ASSERT_EQ(test_matrix.GetRows(), 3);
  ASSERT_EQ(test_matrix.GetCols(), 3);
}

// copy construct
TEST_F(S21MatrixTest, test_class_matrix_11) {
  S21Matrix test_matrix(4, 5);
  S21Matrix test_matrix_2(test_matrix);
  bool result_check = test_matrix.EqMatrix(test_matrix_2);
  ASSERT_EQ(result_check, true);
  ASSERT_EQ(test_matrix.GetRows(), 4);
  ASSERT_EQ(test_matrix.GetCols(), 5);
}

// move construct
TEST_F(S21MatrixTest, test_class_matrix_12) {
  S21Matrix test_matrix_1(3, 4);
  GenerateMatrix(test_matrix_1, 1);
  S21Matrix test_matrix_2 = std::move(test_matrix_1);
  S21Matrix check_matrix_3(3, 4);
  GenerateMatrix(check_matrix_3, 1);
  bool result_check = test_matrix_2.EqMatrix(check_matrix_3);
  ASSERT_EQ(result_check, true);
  ASSERT_EQ(test_matrix_2.GetRows(), 3);
  ASSERT_EQ(test_matrix_2.GetCols(), 4);
  ASSERT_EQ(test_matrix_1.GetRows(), 0);  // ДОЛЖЕН БЫТЬ РАВЕН 0 !!!
  ASSERT_EQ(test_matrix_1.GetCols(), 0);  // ДОЛЖЕН БЫТЬ РАВЕН 0 !!!
  // ASSERT_EQ(test_matrix_1.GetMatrixPointer(), nullptr);
}

// delete object
TEST_F(S21MatrixTest, test_class_matrix_13) {
  S21Matrix test_matrix(4, 5);
  test_matrix.~S21Matrix();
  ASSERT_EQ(test_matrix.GetRows(), 0);
  ASSERT_EQ(test_matrix.GetCols(), 0);
}

// delete object
TEST_F(S21MatrixTest, test_class_matrix_14) {
  S21Matrix test_matrix(3, 3);
  test_matrix.SetCols(6);
  test_matrix.~S21Matrix();
  ASSERT_EQ(test_matrix.GetRows(), 0);
  ASSERT_EQ(test_matrix.GetCols(), 0);
}

// get rows & cols
TEST_F(S21MatrixTest, test_class_matrix_15) {
  S21Matrix test_matrix(3, 3);
  ASSERT_EQ(test_matrix.GetRows(), 3);
  ASSERT_EQ(test_matrix.GetCols(), 3);
}

// set rows & col
TEST_F(S21MatrixTest, test_class_matrix_16) {
  S21Matrix test_matrix(3, 3);
  test_matrix.SetRows(6);
  test_matrix.SetCols(8);
  ASSERT_EQ(test_matrix.GetRows(), 6);
  ASSERT_EQ(test_matrix.GetCols(), 8);
}

// set negative rows
TEST_F(S21MatrixTest, test_class_matrix_17_1) {
  bool result = false;
  S21Matrix test_matrix(3, 3);
  try {
    test_matrix.SetRows(-6);
  } catch (const std::exception& err) {
    result = true;
  }
  ASSERT_EQ(result, true);
  ASSERT_EQ(test_matrix.GetRows(), 3);
  ASSERT_EQ(test_matrix.GetCols(), 3);
}

// set negative col
TEST_F(S21MatrixTest, test_class_matrix_17_2) {
  bool result = false;
  S21Matrix test_matrix(3, 3);
  try {
    test_matrix.SetRows(6);
    test_matrix.SetCols(-8);
  } catch (const std::exception& err) {
    result = true;
  }
  ASSERT_EQ(result, true);
  ASSERT_EQ(test_matrix.GetRows(), 6);
  ASSERT_EQ(test_matrix.GetCols(), 3);
}

// set zero rows & col
TEST_F(S21MatrixTest, test_class_matrix_18) {
  S21Matrix test_matrix(3, 3);
  test_matrix.SetRows(0);
  test_matrix.SetCols(0);
  ASSERT_EQ(test_matrix.GetRows(), 0);
  ASSERT_EQ(test_matrix.GetCols(), 0);
}

// set zero rows & col
TEST_F(S21MatrixTest, test_class_matrix_19) {
  S21Matrix test_matrix;
  ASSERT_EQ(test_matrix.GetRows(), 0);
  ASSERT_EQ(test_matrix.GetCols(), 0);
}

// GetValue TRUE
TEST_F(S21MatrixTest, test_class_matrix_20) {
  S21Matrix test_matrix(3, 3);
  GenerateMatrix(test_matrix, 1);
  double result = test_matrix.GetValue(0, 2);
  double check = 4;
  ASSERT_EQ(result, check);
}

// GetValue FALSE
TEST_F(S21MatrixTest, test_class_matrix_21) {
  bool result = false;
  S21Matrix test_matrix(3, 3);
  GenerateMatrix(test_matrix, 1);
  try {
    test_matrix.GetValue(0, 4);
  } catch (const std::exception& err) {
    result = true;
  }
  ASSERT_EQ(result, true);
}

// SetValue TRUE
TEST_F(S21MatrixTest, test_class_matrix_22) {
  S21Matrix test_matrix(3, 3);
  GenerateMatrix(test_matrix, 1);
  test_matrix.SetValue(0, 2, 66);
  double check = 66;
  ASSERT_EQ(check, test_matrix(0, 2));
}

// SetValue FALSE
TEST_F(S21MatrixTest, test_class_matrix_23) {
  bool result = false;
  S21Matrix test_matrix(3, 3);
  GenerateMatrix(test_matrix, 1);
  try {
    test_matrix.SetValue(0, 4, 66);
  } catch (const std::exception& err) {
    result = true;
  }
  ASSERT_EQ(result, true);
}
