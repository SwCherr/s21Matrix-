#include "tests.h"

void S21MatrixTest::SetUp() {
  test_matrix_00 = new S21Matrix();
  test_matrix_33 = new S21Matrix(3, 3);
  test_matrix_44 = new S21Matrix(4, 4);
}

void S21MatrixTest::TearDown() {
  delete test_matrix_00;
  delete test_matrix_33;
  delete test_matrix_44;
}

void S21MatrixTest::GenerateMatrix(S21Matrix& m, double count) {
  for (int i = 0; i < m.GetRows(); i++) {
    for (int j = 0; j < m.GetCols(); j++) {
      m.SetValue(i, j, count);
      count += count;
    }
  }
}

// void S21MatrixTest::PrintMatrix(S21Matrix& m) {
//   printf("\n");
//   for (int i = 0; i < m.GetRows(); i++) {
//     for (int j = 0; j < m.GetCols(); j++) {
//       printf("%f ", m(i, j));
//     }
//     printf("\n");
//   }
// }
