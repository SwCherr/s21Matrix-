#include "tests.h"

// **************************************
// -------------- EqMatrix --------------
// **************************************

TEST_F(S21MatrixTest, test_oper_func_1) {
  S21Matrix test_matrix(4, 4);
  GenerateMatrix(test_matrix, 1);
  GenerateMatrix(*test_matrix_44, 1);
  bool result = test_matrix.EqMatrix(*test_matrix_44);
  ASSERT_EQ(result, true);
}

TEST_F(S21MatrixTest, test_oper_func_2) {
  S21Matrix test_matrix(4, 4);
  GenerateMatrix(*test_matrix_44, 1);
  bool result = test_matrix.EqMatrix(*test_matrix_44);
  ASSERT_EQ(result, false);
}

TEST_F(S21MatrixTest, test_oper_func_3) {
  S21Matrix test_matrix(3, 4);
  GenerateMatrix(test_matrix, 1);
  GenerateMatrix(test_matrix, 1);
  GenerateMatrix(*test_matrix_44, 1);
  bool result = test_matrix.EqMatrix(*test_matrix_44);
  ASSERT_EQ(result, false);
  ASSERT_EQ(test_matrix.GetRows(), 3);
  ASSERT_EQ(test_matrix.GetCols(), 4);
}

TEST_F(S21MatrixTest, test_oper_func_4) {
  S21Matrix test_matrix(4, 3);
  GenerateMatrix(test_matrix, 1);
  GenerateMatrix(test_matrix, 1);
  GenerateMatrix(*test_matrix_44, 1);
  bool result = test_matrix.EqMatrix(*test_matrix_44);
  ASSERT_EQ(result, false);
  ASSERT_EQ(test_matrix.GetRows(), 4);
  ASSERT_EQ(test_matrix.GetCols(), 3);
}

TEST_F(S21MatrixTest, test_oper_func_5) {
  S21Matrix test_matrix;
  bool result = test_matrix.EqMatrix(*test_matrix_44);
  ASSERT_EQ(result, false);
  ASSERT_EQ(test_matrix.GetRows(), 0);
  ASSERT_EQ(test_matrix.GetCols(), 0);
}

TEST_F(S21MatrixTest, test_oper_func_6) {
  S21Matrix test_matrix(-4, 4);
  GenerateMatrix(test_matrix, 1);
  GenerateMatrix(test_matrix, 1);
  GenerateMatrix(*test_matrix_44, 1);
  bool result = test_matrix.EqMatrix(*test_matrix_44);
  ASSERT_EQ(result, false);
  ASSERT_EQ(test_matrix.GetRows(), 0);
  ASSERT_EQ(test_matrix.GetCols(), 0);
}

TEST_F(S21MatrixTest, test_oper_func_7) {
  S21Matrix test_matrix(4, -4);
  GenerateMatrix(test_matrix, 1);
  GenerateMatrix(test_matrix, 1);
  GenerateMatrix(*test_matrix_44, 1);
  bool result = test_matrix.EqMatrix(*test_matrix_44);
  ASSERT_EQ(result, false);
  ASSERT_EQ(test_matrix.GetRows(), 0);
  ASSERT_EQ(test_matrix.GetCols(), 0);
}

// **************************************
// -------------- SumMatrix --------------
// **************************************

TEST_F(S21MatrixTest, test_oper_func_8) {
  double count_begin = 1.000001;
  S21Matrix test_matrix(4, 4);
  S21Matrix result_matrix(4, 4);
  GenerateMatrix(test_matrix, count_begin);
  GenerateMatrix(*test_matrix_44, count_begin);
  test_matrix.SumMatrix(*test_matrix_44);
  for (int i = 0; i < result_matrix.GetRows(); i++) {
    for (int j = 0; j < result_matrix.GetCols(); j++) {
      result_matrix.SetValue(i, j, count_begin + count_begin);
      count_begin += count_begin;
    }
  }
  bool result = test_matrix.EqMatrix(result_matrix);
  ASSERT_EQ(result, true);
}

TEST_F(S21MatrixTest, test_oper_func_9) {
  double count_begin = -1.000001;
  S21Matrix test_matrix(4, 4);
  S21Matrix result_matrix(4, 4);
  GenerateMatrix(test_matrix, count_begin);
  GenerateMatrix(*test_matrix_44, count_begin);
  test_matrix.SumMatrix(*test_matrix_44);
  for (int i = 0; i < result_matrix.GetRows(); i++) {
    for (int j = 0; j < result_matrix.GetCols(); j++) {
      result_matrix.SetValue(i, j, count_begin + count_begin);
      count_begin += count_begin;
    }
  }
  bool result = test_matrix.EqMatrix(result_matrix);
  ASSERT_EQ(result, true);
}

TEST_F(S21MatrixTest, test_oper_func_10) {
  double count_begin = -88888881.000001;
  S21Matrix test_matrix(4, 4);
  S21Matrix result_matrix(4, 4);
  GenerateMatrix(test_matrix, count_begin);
  GenerateMatrix(*test_matrix_44, count_begin);
  test_matrix.SumMatrix(*test_matrix_44);
  for (int i = 0; i < result_matrix.GetRows(); i++) {
    for (int j = 0; j < result_matrix.GetCols(); j++) {
      result_matrix.SetValue(i, j, count_begin + count_begin);
      count_begin += count_begin;
    }
  }
  bool result = test_matrix.EqMatrix(result_matrix);
  ASSERT_EQ(result, true);
}

// разные  размеры матриц
TEST_F(S21MatrixTest, test_oper_func_11) {
  bool result = false;
  double count_begin = 1;
  S21Matrix test_matrix(3, 3);
  GenerateMatrix(test_matrix, count_begin);
  GenerateMatrix(*test_matrix_44, count_begin);
  try {
    test_matrix.SumMatrix(*test_matrix_44);
  } catch (const std::exception& err) {
    result = true;
  }
  ASSERT_EQ(result, true);
  ASSERT_EQ(test_matrix.GetRows(), 3);
  ASSERT_EQ(test_matrix.GetCols(), 3);
}

// **************************************
// -------------- SubMatrix --------------
// **************************************

TEST_F(S21MatrixTest, test_oper_func_12) {
  double count_begin = 1.000001;
  S21Matrix test_matrix(4, 4);
  S21Matrix result_matrix(4, 4);
  GenerateMatrix(test_matrix, count_begin);
  GenerateMatrix(*test_matrix_44, count_begin);
  test_matrix.SubMatrix(*test_matrix_44);
  for (int i = 0; i < result_matrix.GetRows(); i++) {
    for (int j = 0; j < result_matrix.GetCols(); j++) {
      result_matrix.SetValue(i, j, count_begin - count_begin);
      count_begin += count_begin;
    }
  }
  bool result = test_matrix.EqMatrix(result_matrix);
  ASSERT_EQ(result, true);
}

TEST_F(S21MatrixTest, test_oper_func_13) {
  double count_begin = -1.000001;
  S21Matrix test_matrix(4, 4);
  S21Matrix result_matrix(4, 4);
  GenerateMatrix(test_matrix, count_begin);
  GenerateMatrix(*test_matrix_44, count_begin);
  test_matrix.SubMatrix(*test_matrix_44);
  for (int i = 0; i < result_matrix.GetRows(); i++) {
    for (int j = 0; j < result_matrix.GetCols(); j++) {
      result_matrix.SetValue(i, j, count_begin - count_begin);
      count_begin += count_begin;
    }
  }
  bool result = test_matrix.EqMatrix(result_matrix);
  ASSERT_EQ(result, true);
}

TEST_F(S21MatrixTest, test_oper_func_14) {
  double count_begin = -88888881.000001;
  S21Matrix test_matrix(4, 4);
  S21Matrix result_matrix(4, 4);
  GenerateMatrix(test_matrix, count_begin);
  GenerateMatrix(*test_matrix_44, count_begin);
  test_matrix.SubMatrix(*test_matrix_44);
  for (int i = 0; i < result_matrix.GetRows(); i++) {
    for (int j = 0; j < result_matrix.GetCols(); j++) {
      result_matrix.SetValue(i, j, count_begin - count_begin);
      count_begin += count_begin;
    }
  }
  bool result = test_matrix.EqMatrix(result_matrix);
  ASSERT_EQ(result, true);
}

// разные  размеры матриц
TEST_F(S21MatrixTest, test_oper_func_15) {
  double count_begin = 1;
  S21Matrix test_matrix(3, 3);
  GenerateMatrix(test_matrix, count_begin);
  GenerateMatrix(*test_matrix_44, count_begin);
  try {
    test_matrix.SubMatrix(*test_matrix_44);
  } catch (const std::exception& err) {
  }
  S21Matrix result_matrix(3, 3);
  GenerateMatrix(result_matrix, count_begin);
  bool result = test_matrix.EqMatrix(result_matrix);
  ASSERT_EQ(result, true);
  ASSERT_EQ(test_matrix.GetRows(), 3);
  ASSERT_EQ(test_matrix.GetCols(), 3);
}

// **************************************
// -------------- MulNumber --------------
// **************************************

TEST_F(S21MatrixTest, test_oper_func_16) {
  double count_begin = 1.000001;
  double number = 2.3;
  S21Matrix test_matrix(4, 4);
  S21Matrix result_matrix(4, 4);
  GenerateMatrix(test_matrix, count_begin);
  test_matrix.MulNumber(number);
  for (int i = 0; i < result_matrix.GetRows(); i++) {
    for (int j = 0; j < result_matrix.GetCols(); j++) {
      result_matrix.SetValue(i, j, count_begin * number);
      count_begin += count_begin;
    }
  }
  bool result = test_matrix.EqMatrix(result_matrix);
  ASSERT_EQ(result, true);
}

TEST_F(S21MatrixTest, test_oper_func_17) {
  double count_begin = 1.000001;
  double number = -2.3;
  S21Matrix test_matrix(4, 4);
  S21Matrix result_matrix(4, 4);
  GenerateMatrix(test_matrix, count_begin);
  test_matrix.MulNumber(number);
  for (int i = 0; i < result_matrix.GetRows(); i++) {
    for (int j = 0; j < result_matrix.GetCols(); j++) {
      result_matrix.SetValue(i, j, count_begin * number);
      count_begin += count_begin;
    }
  }
  bool result = test_matrix.EqMatrix(result_matrix);
  ASSERT_EQ(result, true);
}

TEST_F(S21MatrixTest, test_oper_func_18) {
  double count_begin = 1.000001;
  double number = 0;
  S21Matrix test_matrix(4, 4);
  S21Matrix result_matrix(4, 4);
  GenerateMatrix(test_matrix, count_begin);
  test_matrix.MulNumber(number);
  for (int i = 0; i < result_matrix.GetRows(); i++) {
    for (int j = 0; j < result_matrix.GetCols(); j++) {
      result_matrix.SetValue(i, j, count_begin * number);
      count_begin += count_begin;
    }
  }
  bool result = test_matrix.EqMatrix(result_matrix);
  ASSERT_EQ(result, true);
}

// **************************************
// -------------- MulMatrix --------------
// **************************************

TEST_F(S21MatrixTest, test_oper_func_19) {
  double count_begin = 1;
  S21Matrix test_matrix(3, 3);
  S21Matrix result_matrix(3, 3);
  GenerateMatrix(test_matrix, count_begin);
  GenerateMatrix(*test_matrix_33, count_begin);
  test_matrix.MulMatrix(*test_matrix_33);
  result_matrix.SetValue(0, 0, 273);
  result_matrix.SetValue(0, 1, 546);
  result_matrix.SetValue(0, 2, 1092);
  result_matrix.SetValue(1, 0, 2184);
  result_matrix.SetValue(1, 1, 4368);
  result_matrix.SetValue(1, 2, 8736);
  result_matrix.SetValue(2, 0, 17472);
  result_matrix.SetValue(2, 1, 34944);
  result_matrix.SetValue(2, 2, 69888);
  bool result = test_matrix.EqMatrix(result_matrix);
  ASSERT_EQ(result, true);
}

TEST_F(S21MatrixTest, test_oper_func_20) {
  double count_begin = 1;
  S21Matrix test_matrix(1, 3);
  S21Matrix result_matrix(1, 3);
  GenerateMatrix(test_matrix, count_begin);
  GenerateMatrix(*test_matrix_33, count_begin);
  test_matrix.MulMatrix(*test_matrix_33);
  result_matrix.SetValue(0, 0, 273);
  result_matrix.SetValue(0, 1, 546);
  result_matrix.SetValue(0, 2, 1092);
  bool result = test_matrix.EqMatrix(result_matrix);
  ASSERT_EQ(result, true);
}

TEST_F(S21MatrixTest, test_oper_func_21) {
  double count_begin = 1;
  S21Matrix test_matrix_1(3, 1);
  S21Matrix test_matrix_2(1, 3);
  S21Matrix result_matrix(3, 3);
  GenerateMatrix(test_matrix_1, count_begin);
  GenerateMatrix(test_matrix_2, count_begin);
  test_matrix_1.MulMatrix(test_matrix_2);
  result_matrix.SetValue(0, 0, 1);
  result_matrix.SetValue(0, 1, 2);
  result_matrix.SetValue(0, 2, 4);
  result_matrix.SetValue(1, 0, 2);
  result_matrix.SetValue(1, 1, 4);
  result_matrix.SetValue(1, 2, 8);
  result_matrix.SetValue(2, 0, 4);
  result_matrix.SetValue(2, 1, 8);
  result_matrix.SetValue(2, 2, 16);
  bool result = test_matrix_1.EqMatrix(result_matrix);
  ASSERT_EQ(result, true);
}

// число столбцов первой матрицы не равно числу строк второй матрицы
TEST_F(S21MatrixTest, test_oper_func_22) {
  bool result = false;
  double count_begin = 1;
  S21Matrix test_matrix(3, 1);
  GenerateMatrix(test_matrix, count_begin);
  try {
    test_matrix.MulMatrix(test_matrix);
  } catch (const std::exception& err) {
    result = true;
  }
  ASSERT_EQ(result, true);
}

// **************************************
// ------------ Determinant -------------
// **************************************
// double Determinant();

// матрица не является квадратной
TEST_F(S21MatrixTest, test_oper_func_23) {
  bool result = false;
  double count_begin = 1;
  S21Matrix test_matrix(3, 1);
  GenerateMatrix(test_matrix, count_begin);
  try {
    test_matrix.Determinant();
  } catch (const std::exception& err) {
    result = true;
  }
  ASSERT_EQ(result, true);
}

TEST_F(S21MatrixTest, test_oper_func_24) {
  S21Matrix test_matrix(3, 3);
  test_matrix.SetValue(0, 0, 5);
  test_matrix.SetValue(0, 1, 4);
  test_matrix.SetValue(0, 2, 3);
  test_matrix.SetValue(1, 0, 6);
  test_matrix.SetValue(1, 1, 66);
  test_matrix.SetValue(1, 2, 6);
  test_matrix.SetValue(2, 0, 88);
  test_matrix.SetValue(2, 1, 88);
  test_matrix.SetValue(2, 2, 88);
  double result = test_matrix.Determinant();
  ASSERT_EQ(result, 10560);
}

TEST_F(S21MatrixTest, test_oper_func_25) {
  S21Matrix test_matrix(3, 3);
  test_matrix.SetValue(0, 0, 5.5);
  test_matrix.SetValue(0, 1, 4.4);
  test_matrix.SetValue(0, 2, 3.3);
  test_matrix.SetValue(1, 0, 6);
  test_matrix.SetValue(1, 1, 66);
  test_matrix.SetValue(1, 2, 6);
  test_matrix.SetValue(2, 0, 88);
  test_matrix.SetValue(2, 1, 88);
  test_matrix.SetValue(2, 2, 88);
  double result = test_matrix.Determinant();
  ASSERT_EQ(result, 11616);
}

TEST_F(S21MatrixTest, test_oper_func_26) {
  S21Matrix test_matrix(3, 3);
  test_matrix.SetValue(0, 0, -5.5);
  test_matrix.SetValue(0, 1, 4.4);
  test_matrix.SetValue(0, 2, -3.3);
  test_matrix.SetValue(1, 0, 6);
  test_matrix.SetValue(1, 1, -66);
  test_matrix.SetValue(1, 2, 6);
  test_matrix.SetValue(2, 0, -88);
  test_matrix.SetValue(2, 1, 88);
  test_matrix.SetValue(2, 2, -88);
  double result = test_matrix.Determinant();
  ASSERT_EQ(result, -11616);
}

// **************************************
// ------------- Transpose --------------
// **************************************

TEST_F(S21MatrixTest, test_oper_func_27) {
  double count_begin = 1;
  S21Matrix test_matrix(3, 3);
  S21Matrix check_matrix(3, 3);
  GenerateMatrix(test_matrix, count_begin);
  S21Matrix result_matrix = test_matrix.Transpose();
  check_matrix.SetValue(0, 0, 1);
  check_matrix.SetValue(0, 1, 8);
  check_matrix.SetValue(0, 2, 64);
  check_matrix.SetValue(1, 0, 2);
  check_matrix.SetValue(1, 1, 16);
  check_matrix.SetValue(1, 2, 128);
  check_matrix.SetValue(2, 0, 4);
  check_matrix.SetValue(2, 1, 32);
  check_matrix.SetValue(2, 2, 256);
  bool result = result_matrix.EqMatrix(check_matrix);
  ASSERT_EQ(result, true);
}

TEST_F(S21MatrixTest, test_oper_func_28) {
  double count_begin = 1;
  S21Matrix test_matrix(3, 2);
  S21Matrix check_matrix(2, 3);
  GenerateMatrix(test_matrix, count_begin);
  test_matrix.Transpose();
  S21Matrix result_matrix = test_matrix.Transpose();
  check_matrix.SetValue(0, 0, 1);
  check_matrix.SetValue(0, 1, 4);
  check_matrix.SetValue(0, 2, 16);
  check_matrix.SetValue(1, 0, 2);
  check_matrix.SetValue(1, 1, 8);
  check_matrix.SetValue(1, 2, 32);
  bool result = result_matrix.EqMatrix(check_matrix);
  ASSERT_EQ(result, true);
}

// **************************************
// ----------- CalcComplements ----------
// **************************************
// S21Matrix CalcComplements();

// матрица не является квадратной
TEST_F(S21MatrixTest, test_oper_func_29) {
  bool result = false;
  double count_begin = 1;
  S21Matrix test_matrix(3, 1);
  GenerateMatrix(test_matrix, count_begin);
  try {
    test_matrix.CalcComplements();
  } catch (const std::exception& err) {
    result = true;
  }
  ASSERT_EQ(result, true);
}

TEST_F(S21MatrixTest, test_oper_func_30) {
  S21Matrix test_matrix(3, 3);
  test_matrix.SetValue(0, 0, 5);
  test_matrix.SetValue(0, 1, 4);
  test_matrix.SetValue(0, 2, 3);
  test_matrix.SetValue(1, 0, 6);
  test_matrix.SetValue(1, 1, 66);
  test_matrix.SetValue(1, 2, 6);
  test_matrix.SetValue(2, 0, 88);
  test_matrix.SetValue(2, 1, 88);
  test_matrix.SetValue(2, 2, 88);
  S21Matrix check_matrix(3, 3);
  check_matrix.SetValue(0, 0, 5280);
  check_matrix.SetValue(0, 1, 0);
  check_matrix.SetValue(0, 2, -5280);
  check_matrix.SetValue(1, 0, -88);
  check_matrix.SetValue(1, 1, 176);
  check_matrix.SetValue(1, 2, -88);
  check_matrix.SetValue(2, 0, -174);
  check_matrix.SetValue(2, 1, -12);
  check_matrix.SetValue(2, 2, 306);
  S21Matrix result_matrix = test_matrix.CalcComplements();
  bool result = result_matrix.EqMatrix(check_matrix);
  ASSERT_EQ(result, true);
}

// **************************************
// ----------- InverseMatrix ------------
// **************************************

// определитель матрицы равен 0
TEST_F(S21MatrixTest, test_oper_func_31) {
  bool result = false;
  double count_begin = 1;
  S21Matrix test_matrix_1(3, 3);
  GenerateMatrix(test_matrix_1, count_begin);
  try {
    test_matrix_1.InverseMatrix();
  } catch (const std::exception& err) {
    result = true;
  }
  ASSERT_EQ(result, true);
}

TEST_F(S21MatrixTest, test_oper_func_32) {
  S21Matrix test_matrix(3, 3);
  test_matrix.SetValue(0, 0, 5);
  test_matrix.SetValue(0, 1, 4);
  test_matrix.SetValue(0, 2, 3);
  test_matrix.SetValue(1, 0, 6);
  test_matrix.SetValue(1, 1, 66);
  test_matrix.SetValue(1, 2, 6);
  test_matrix.SetValue(2, 0, 88);
  test_matrix.SetValue(2, 1, 88);
  test_matrix.SetValue(2, 2, 88);
  S21Matrix check_matrix(3, 3);
  check_matrix.SetValue(0, 0, 0.500000);
  check_matrix.SetValue(0, 1, -0.008333);
  check_matrix.SetValue(0, 2, -0.016477);
  check_matrix.SetValue(1, 0, 0);
  check_matrix.SetValue(1, 1, 0.016667);
  check_matrix.SetValue(1, 2, -0.001136);
  check_matrix.SetValue(2, 0, -0.500000);
  check_matrix.SetValue(2, 1, -0.008333);
  check_matrix.SetValue(2, 2, 0.028977);
  S21Matrix result_matrix = test_matrix.InverseMatrix();
  bool result = result_matrix.EqMatrix(check_matrix);
  ASSERT_EQ(result, true);
}