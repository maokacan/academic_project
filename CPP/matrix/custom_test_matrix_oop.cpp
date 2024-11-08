#include <gtest/gtest.h>

#include "./custom_matrix_oop.h"
#define ACCURACY 1e-7

TEST(CustomMatrixTest, SetCols123) {
  CustomMatrix matrix(2, 2);
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(1, 0) = 3.0;
  matrix(1, 1) = 4.0;
  matrix.SetCols(3);
  EXPECT_DOUBLE_EQ(matrix(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(matrix(0, 1), 2.0);
  EXPECT_DOUBLE_EQ(matrix(0, 2), 0.0);
  EXPECT_DOUBLE_EQ(matrix(1, 0), 3.0);
  EXPECT_DOUBLE_EQ(matrix(1, 1), 4.0);
  EXPECT_DOUBLE_EQ(matrix(1, 2), 0.0);
}

TEST(CustomMatrixTest, SetRows842) {
  CustomMatrix matrix(2, 2);
  matrix(0, 0) = 1.0;
  matrix(0, 1) = 2.0;
  matrix(1, 0) = 3.0;
  matrix(1, 1) = 4.0;
  matrix.SetRows(3);
  EXPECT_DOUBLE_EQ(matrix(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(matrix(0, 1), 2.0);
  EXPECT_DOUBLE_EQ(matrix(1, 0), 3.0);
  EXPECT_DOUBLE_EQ(matrix(1, 1), 4.0);
  EXPECT_DOUBLE_EQ(matrix(2, 0), 0.0);
  EXPECT_DOUBLE_EQ(matrix(2, 1), 0.0);
}

TEST(CustomMatrixTest, AccessElementsWithinBounds) {
  CustomMatrix matrix(3, 3);
  matrix(0, 0) = 1.0;
  matrix(1, 1) = 2.0;
  matrix(2, 2) = 3.0;

  EXPECT_DOUBLE_EQ(matrix(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(matrix(1, 1), 2.0);
  EXPECT_DOUBLE_EQ(matrix(2, 2), 3.0);
}

TEST(CustomMatrixTest, AccessElementsOutOfBounds) {
  CustomMatrix matrix(3, 3);

  EXPECT_THROW(matrix(-1, 0), std::out_of_range);
  EXPECT_THROW(matrix(0, -1), std::out_of_range);
  EXPECT_THROW(matrix(3, 0), std::out_of_range);
  EXPECT_THROW(matrix(0, 3), std::out_of_range);
}

TEST(CustomMatrixTest, DefaultConstructor) {
  CustomMatrix m;
  EXPECT_EQ(m.GetRows(), 3);
  EXPECT_EQ(m.GetCols(), 3);
  for (int i = 0; i < m.GetRows(); ++i) {
    for (int j = 0; j < m.GetCols(); ++j) {
      EXPECT_DOUBLE_EQ(m(i, j), 0.0);
    }
  }
}

TEST(CustomMatrixTest, ParameterizedConstructor) {
  CustomMatrix m(2, 3);
  EXPECT_EQ(m.GetRows(), 2);
  EXPECT_EQ(m.GetCols(), 3);
  for (int i = 0; i < m.GetRows(); ++i) {
    for (int j = 0; j < m.GetCols(); ++j) {
      EXPECT_DOUBLE_EQ(m(i, j), 0.0);
    }
  }
}

TEST(CustomMatrixTest, CopyConstructor) {
  CustomMatrix m1(2, 3);
  m1(0, 0) = 1.0;
  m1(1, 2) = 2.0;
  CustomMatrix m2(m1);
  EXPECT_EQ(m2.GetRows(), 2);
  EXPECT_EQ(m2.GetCols(), 3);
  EXPECT_DOUBLE_EQ(m2(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(m2(1, 2), 2.0);
  EXPECT_DOUBLE_EQ(m2(0, 1), 0.0);
}

TEST(CustomMatrixTest, MoveConstructor) {
  CustomMatrix m1(2, 3);
  m1(0, 0) = 1.0;
  m1(1, 2) = 2.0;
  CustomMatrix m2(std::move(m1));
  EXPECT_EQ(m2.GetRows(), 2);
  EXPECT_EQ(m2.GetCols(), 3);
  EXPECT_DOUBLE_EQ(m2(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(m2(1, 2), 2.0);
  EXPECT_EQ(m1.GetRows(), 0);
  EXPECT_EQ(m1.GetCols(), 0);
}

TEST(CustomMatrixTest, CopyConstructor_2) {
  CustomMatrix m1(2, 2);
  m1(0, 0) = 1.0;
  m1(0, 1) = 2.0;
  m1(1, 0) = 3.0;
  m1(1, 1) = 4.0;

  CustomMatrix m2(m1);
  EXPECT_EQ(m2.GetRows(), 2);
  EXPECT_EQ(m2.GetCols(), 2);
  EXPECT_DOUBLE_EQ(m2(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(m2(0, 1), 2.0);
  EXPECT_DOUBLE_EQ(m2(1, 0), 3.0);
  EXPECT_DOUBLE_EQ(m2(1, 1), 4.0);
}

TEST(CustomMatrixTest, MoveConstructor_2) {
  CustomMatrix m1(2, 2);
  m1(0, 0) = 1.0;
  m1(0, 1) = 2.0;
  m1(1, 0) = 3.0;
  m1(1, 1) = 4.0;

  CustomMatrix m2(std::move(m1));
  EXPECT_EQ(m2.GetRows(), 2);
  EXPECT_EQ(m2.GetCols(), 2);
  EXPECT_DOUBLE_EQ(m2(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(m2(0, 1), 2.0);
  EXPECT_DOUBLE_EQ(m2(1, 0), 3.0);
  EXPECT_DOUBLE_EQ(m2(1, 1), 4.0);

  EXPECT_EQ(m1.GetRows(), 0);
  EXPECT_EQ(m1.GetCols(), 0);
  EXPECT_EQ(m1.GetMatrix(), nullptr);
}
TEST(CustomMatrixTest, AssignmentOperator) {
  CustomMatrix m1(2, 3);
  m1(0, 0) = 1.0;
  m1(1, 2) = 2.0;
  CustomMatrix m2 = m1;
  EXPECT_EQ(m2.GetRows(), 2);
  EXPECT_EQ(m2.GetCols(), 3);
  EXPECT_DOUBLE_EQ(m2(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(m2(1, 2), 2.0);
}

TEST(CustomMatrixTest, SetRows) {
  CustomMatrix m(2, 2);
  m.SetRows(3);
  EXPECT_EQ(m.GetRows(), 3);
  EXPECT_EQ(m.GetCols(), 2);
}

TEST(CustomMatrixTest, SetCols) {
  CustomMatrix m(2, 2);
  m.SetCols(3);
  EXPECT_EQ(m.GetRows(), 2);
  EXPECT_EQ(m.GetCols(), 3);
}

TEST(CustomMatrixTest, AdditionOperator) {
  CustomMatrix m1(2, 2);
  CustomMatrix m2(2, 2);
  m1(0, 0) = 1.0;
  m1(1, 1) = 2.0;
  m2(0, 1) = 3.0;
  m2(1, 0) = 4.0;
  CustomMatrix m3 = m1 + m2;
  EXPECT_DOUBLE_EQ(m3(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(m3(0, 1), 3.0);
  EXPECT_DOUBLE_EQ(m3(1, 0), 4.0);
  EXPECT_DOUBLE_EQ(m3(1, 1), 2.0);
}

TEST(CustomMatrixTest, SubtractionOperator) {
  CustomMatrix m1(2, 2);
  CustomMatrix m2(2, 2);
  m1(0, 0) = 1.0;
  m1(1, 1) = 2.0;
  m2(0, 1) = 3.0;
  m2(1, 0) = 4.0;
  CustomMatrix m3 = m1 - m2;
  EXPECT_DOUBLE_EQ(m3(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(m3(0, 1), -3.0);
  EXPECT_DOUBLE_EQ(m3(1, 0), -4.0);
  EXPECT_DOUBLE_EQ(m3(1, 1), 2.0);
}

TEST(CustomMatrixTest, SumMatrix) {
  CustomMatrix m1(2, 2);
  CustomMatrix m2(2, 2);
  m1(0, 0) = 1.0;
  m1(0, 1) = 2.0;
  m1(1, 0) = 3.0;
  m1(1, 1) = 4.0;

  m2(0, 0) = 1.0;
  m2(0, 1) = 1.0;
  m2(1, 0) = 1.0;
  m2(1, 1) = 1.0;

  m1.SumMatrix(m2);
  EXPECT_DOUBLE_EQ(m1(0, 0), 2.0);
  EXPECT_DOUBLE_EQ(m1(0, 1), 3.0);
  EXPECT_DOUBLE_EQ(m1(1, 0), 4.0);
  EXPECT_DOUBLE_EQ(m1(1, 1), 5.0);
}

TEST(CustomMatrixTest, SumMatrix_2) {
  CustomMatrix m1;
  CustomMatrix m2;
  m1(0, 0) = 1.0;
  m1(0, 1) = 2.0;
  m1(0, 2) = 3.0;
  m1(1, 0) = 4.0;
  m1(1, 1) = 5.0;
  m1(1, 2) = 6.0;
  m1(2, 0) = 7.0;
  m1(2, 1) = 8.0;
  m1(2, 2) = 9.0;

  m2(0, 0) = 9.0;
  m2(0, 1) = 8.0;
  m2(0, 2) = 7.0;
  m2(1, 0) = 6.0;
  m2(1, 1) = 5.0;
  m2(1, 2) = 4.0;
  m2(2, 0) = 3.0;
  m2(2, 1) = 2.0;
  m2(2, 2) = 1.0;

  m1.SumMatrix(m2);

  EXPECT_DOUBLE_EQ(m1(0, 0), 10.0);
  EXPECT_DOUBLE_EQ(m1(0, 1), 10.0);
  EXPECT_DOUBLE_EQ(m1(0, 2), 10.0);
  EXPECT_DOUBLE_EQ(m1(1, 0), 10.0);
  EXPECT_DOUBLE_EQ(m1(1, 1), 10.0);
  EXPECT_DOUBLE_EQ(m1(1, 2), 10.0);
  EXPECT_DOUBLE_EQ(m1(2, 0), 10.0);
  EXPECT_DOUBLE_EQ(m1(2, 1), 10.0);
  EXPECT_DOUBLE_EQ(m1(2, 2), 10.0);
}

TEST(CustomMatrixTest, SumMatrix_3) {
  CustomMatrix m1;
  CustomMatrix m2;
  m1(0, 0) = 1.9999999;
  m1(0, 1) = 2.8888888;
  m1(0, 2) = 3.7777777;
  m1(1, 0) = 4.6666666;
  m1(1, 1) = 5.5555555;
  m1(1, 2) = 6.4444444;
  m1(2, 0) = 7.3333333;
  m1(2, 1) = 8.2222222;
  m1(2, 2) = 9.1111111;

  m2(0, 0) = 9.11111111;
  m2(0, 1) = 8.1111111;
  m2(0, 2) = 7.1111111;
  m2(1, 0) = 6.11111110;
  m2(1, 1) = 5.1111111;
  m2(1, 2) = 4.1111111;
  m2(2, 0) = 3.11111110;
  m2(2, 1) = 2.1111111;
  m2(2, 2) = 1.0000001;

  m1.SumMatrix(m2);

  EXPECT_DOUBLE_EQ(m1(0, 0), 11.11111101);
  EXPECT_DOUBLE_EQ(m1(0, 1), 10.99999990);
  EXPECT_DOUBLE_EQ(m1(0, 2), 10.88888880);
  EXPECT_DOUBLE_EQ(m1(1, 0), 10.77777770);
  EXPECT_DOUBLE_EQ(m1(1, 1), 10.66666660);
  EXPECT_DOUBLE_EQ(m1(1, 2), 10.55555550);
  EXPECT_DOUBLE_EQ(m1(2, 0), 10.44444440);
  EXPECT_DOUBLE_EQ(m1(2, 1), 10.33333330);
  EXPECT_DOUBLE_EQ(m1(2, 2), 10.11111120);
}

TEST(CustomMatrixTest, SumMatrixCorrectAddition) {
  CustomMatrix m1(2, 2);
  CustomMatrix m2(2, 2);
  m1(0, 0) = 1.0;
  m1(0, 1) = 2.0;
  m1(1, 0) = 3.0;
  m1(1, 1) = 4.0;
  m2(0, 0) = 5.0;
  m2(0, 1) = 6.0;
  m2(1, 0) = 7.0;
  m2(1, 1) = 8.0;

  m1.SumMatrix(m2);

  EXPECT_DOUBLE_EQ(m1(0, 0), 6.0);
  EXPECT_DOUBLE_EQ(m1(0, 1), 8.0);
  EXPECT_DOUBLE_EQ(m1(1, 0), 10.0);
  EXPECT_DOUBLE_EQ(m1(1, 1), 12.0);
}

TEST(CustomMatrixTest, SumMatrixDifferentSizes) {
  CustomMatrix m1(2, 2);
  CustomMatrix m2(3, 3);
  EXPECT_THROW(m1.SumMatrix(m2), std::invalid_argument);
}

TEST(CustomMatrixTest, SubMatrix) {
  CustomMatrix m1(2, 2);
  CustomMatrix m2(2, 2);
  m1(0, 0) = 1.0;
  m1(0, 1) = 2.0;
  m1(1, 0) = 3.0;
  m1(1, 1) = 4.0;

  m2(0, 0) = 1.0;
  m2(0, 1) = 1.0;
  m2(1, 0) = 1.0;
  m2(1, 1) = 1.0;

  m1.SubMatrix(m2);
  EXPECT_DOUBLE_EQ(m1(0, 0), 0.0);
  EXPECT_DOUBLE_EQ(m1(0, 1), 1.0);
  EXPECT_DOUBLE_EQ(m1(1, 0), 2.0);
  EXPECT_DOUBLE_EQ(m1(1, 1), 3.0);
}

TEST(CustomMatrixTest, SubMatrix_2) {
  CustomMatrix m1;
  CustomMatrix m2;
  m1(0, 0) = 1.0;
  m1(0, 1) = 2.0;
  m1(0, 2) = 3.0;
  m1(1, 0) = 4.0;
  m1(1, 1) = 5.0;
  m1(1, 2) = 6.0;
  m1(2, 0) = 7.0;
  m1(2, 1) = 8.0;
  m1(2, 2) = 9.0;

  m2(0, 0) = 9.0;
  m2(0, 1) = 8.0;
  m2(0, 2) = 7.0;
  m2(1, 0) = 6.0;
  m2(1, 1) = 5.0;
  m2(1, 2) = 4.0;
  m2(2, 0) = 3.0;
  m2(2, 1) = 2.0;
  m2(2, 2) = 1.0;

  m1.SubMatrix(m2);

  EXPECT_LT(m1(0, 0) - -8.0, ACCURACY);
  EXPECT_LT(m1(0, 1) - -6.0, ACCURACY);
  EXPECT_LT(m1(0, 2) - -4.0, ACCURACY);
  EXPECT_LT(m1(1, 0) - -2.0, ACCURACY);
  EXPECT_LT(m1(1, 1) - 0.0, ACCURACY);
  EXPECT_LT(m1(1, 2) - 2.0, ACCURACY);
  EXPECT_LT(m1(2, 0) - 4.0, ACCURACY);
  EXPECT_LT(m1(2, 1) - 6.0, ACCURACY);
  EXPECT_LT(m1(2, 2) - 8.0, ACCURACY);
}

TEST(CustomMatrixTest, SubMatrix_3) {
  CustomMatrix m1;
  CustomMatrix m2;
  m1(0, 0) = 1.9999999;
  m1(0, 1) = 2.8888888;
  m1(0, 2) = 3.7777777;
  m1(1, 0) = 4.6666666;
  m1(1, 1) = 5.5555555;
  m1(1, 2) = 6.4444444;
  m1(2, 0) = 7.3333333;
  m1(2, 1) = 8.2222222;
  m1(2, 2) = 9.1111111;

  m2(0, 0) = 9.11111111;
  m2(0, 1) = 8.1111111;
  m2(0, 2) = 7.1111111;
  m2(1, 0) = 6.11111110;
  m2(1, 1) = 5.1111111;
  m2(1, 2) = 4.1111111;
  m2(2, 0) = 3.11111110;
  m2(2, 1) = 2.1111111;
  m2(2, 2) = 1.0000001;

  m1.SubMatrix(m2);
  EXPECT_LT(m1(0, 0) - -7.1111112, ACCURACY);
  EXPECT_LT(m1(0, 1) - -5.2222223, ACCURACY);
  EXPECT_LT(m1(0, 2) - -3.3333334, ACCURACY);
  EXPECT_LT(m1(1, 0) - -1.4444445, ACCURACY);
  EXPECT_LT(m1(1, 1) - 0.4444444, ACCURACY);
  EXPECT_LT(m1(1, 2) - 2.3333333, ACCURACY);
  EXPECT_LT(m1(2, 0) - 4.2222222, ACCURACY);
  EXPECT_LT(m1(2, 1) - 6.1111111, ACCURACY);
  EXPECT_LT(m1(2, 2) - 8.1111110, ACCURACY);
}

TEST(CustomMatrixTest, SubMatrixCorrectSubtraction) {
  CustomMatrix m1(2, 2);
  CustomMatrix m2(2, 2);
  m1(0, 0) = 5.0;
  m1(0, 1) = 6.0;
  m1(1, 0) = 7.0;
  m1(1, 1) = 8.0;
  m2(0, 0) = 1.0;
  m2(0, 1) = 2.0;
  m2(1, 0) = 3.0;
  m2(1, 1) = 4.0;

  m1.SubMatrix(m2);

  EXPECT_DOUBLE_EQ(m1(0, 0), 4.0);
  EXPECT_DOUBLE_EQ(m1(0, 1), 4.0);
  EXPECT_DOUBLE_EQ(m1(1, 0), 4.0);
  EXPECT_DOUBLE_EQ(m1(1, 1), 4.0);
}

TEST(CustomMatrixTest, SubMatrixDifferentSizes) {
  CustomMatrix m1(2, 2);
  CustomMatrix m2(3, 3);
  EXPECT_THROW(m1.SubMatrix(m2), std::invalid_argument);
}

TEST(CustomMatrixTest, MultiplicationByNumberOperator) {
  CustomMatrix m1(2, 2);
  m1(0, 0) = 1.0;
  m1(1, 1) = 2.0;
  CustomMatrix m2 = m1 * 2.0;
  EXPECT_DOUBLE_EQ(m2(0, 0), 2.0);
  EXPECT_DOUBLE_EQ(m2(1, 1), 4.0);
}

TEST(CustomMatrixTest, MultiplicationByMatrixOperator) {
  CustomMatrix m1(2, 2);
  CustomMatrix m2(2, 2);
  m1(0, 0) = 1.0;
  m1(0, 1) = 2.0;
  m1(1, 0) = 3.0;
  m1(1, 1) = 4.0;
  m2(0, 0) = 2.0;
  m2(0, 1) = 0.0;
  m2(1, 0) = 1.0;
  m2(1, 1) = 2.0;
  CustomMatrix m3 = m1 * m2;
  EXPECT_DOUBLE_EQ(m3(0, 0), 4.0);
  EXPECT_DOUBLE_EQ(m3(0, 1), 4.0);
  EXPECT_DOUBLE_EQ(m3(1, 0), 10.0);
  EXPECT_DOUBLE_EQ(m3(1, 1), 8.0);
}

TEST(CustomMatrixTest, MulNumber) {
  CustomMatrix m(2, 2);
  m(0, 0) = 1.0;
  m(0, 1) = 2.0;
  m(1, 0) = 3.0;
  m(1, 1) = 4.0;

  m.MulNumber(2.0);
  EXPECT_DOUBLE_EQ(m(0, 0), 2.0);
  EXPECT_DOUBLE_EQ(m(0, 1), 4.0);
  EXPECT_DOUBLE_EQ(m(1, 0), 6.0);
  EXPECT_DOUBLE_EQ(m(1, 1), 8.0);
}

TEST(CustomMatrixTest, MulMatrix) {
  CustomMatrix m1(2, 2);
  CustomMatrix m2(2, 2);
  m1(0, 0) = 1.0;
  m1(0, 1) = 2.0;
  m1(1, 0) = 3.0;
  m1(1, 1) = 4.0;

  m2(0, 0) = 1.0;
  m2(0, 1) = 0.0;
  m2(1, 0) = 0.0;
  m2(1, 1) = 1.0;

  m1.MulMatrix(m2);
  EXPECT_DOUBLE_EQ(m1(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(m1(0, 1), 2.0);
  EXPECT_DOUBLE_EQ(m1(1, 0), 3.0);
  EXPECT_DOUBLE_EQ(m1(1, 1), 4.0);
}

TEST(CustomMatrixTest, MulMatrixCorrectMultiplication) {
  CustomMatrix m1(2, 3);
  CustomMatrix m2(3, 2);
  m1(0, 0) = 1.0;
  m1(0, 1) = 2.0;
  m1(0, 2) = 3.0;
  m1(1, 0) = 4.0;
  m1(1, 1) = 5.0;
  m1(1, 2) = 6.0;
  m2(0, 0) = 7.0;
  m2(0, 1) = 8.0;
  m2(1, 0) = 9.0;
  m2(1, 1) = 10.0;
  m2(2, 0) = 11.0;
  m2(2, 1) = 12.0;

  m1.MulMatrix(m2);

  EXPECT_DOUBLE_EQ(m1(0, 0), 58.0);
  EXPECT_DOUBLE_EQ(m1(0, 1), 64.0);
  EXPECT_DOUBLE_EQ(m1(1, 0), 139.0);
  EXPECT_DOUBLE_EQ(m1(1, 1), 154.0);
}

TEST(CustomMatrixTest, MulMatrixIncompatibleSizes) {
  CustomMatrix m1(2, 2);
  CustomMatrix m2(3, 3);

  EXPECT_THROW(m1.MulMatrix(m2), std::invalid_argument);
}

TEST(CustomMatrixTest, Transpose) {
  CustomMatrix m(2, 2);
  m(0, 0) = 1.0;
  m(0, 1) = 2.0;
  m(1, 0) = 3.0;
  m(1, 1) = 4.0;

  CustomMatrix transposed = m.Transpose();
  EXPECT_DOUBLE_EQ(transposed(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(transposed(0, 1), 3.0);
  EXPECT_DOUBLE_EQ(transposed(1, 0), 2.0);
  EXPECT_DOUBLE_EQ(transposed(1, 1), 4.0);
}

TEST(CustomMatrixTest, Transpose_2) {
  CustomMatrix m(3, 2);
  m(0, 0) = 1.0;
  m(0, 1) = 4.0;
  m(1, 0) = 2.0;
  m(1, 1) = 5.0;
  m(2, 0) = 3.0;
  m(2, 1) = 6.0;

  CustomMatrix transposed = m.Transpose();
  EXPECT_DOUBLE_EQ(transposed(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(transposed(0, 1), 2.0);
  EXPECT_DOUBLE_EQ(transposed(0, 2), 3.0);
  EXPECT_DOUBLE_EQ(transposed(1, 0), 4.0);
  EXPECT_DOUBLE_EQ(transposed(1, 1), 5.0);
  EXPECT_DOUBLE_EQ(transposed(1, 2), 6.0);
}

TEST(CustomMatrixTest, Transpose_3) {
  CustomMatrix m(5, 5);
  m(0, 0) = 1.0;
  m(0, 1) = 2.0;
  m(0, 2) = 3.0;
  m(0, 3) = 4.0;
  m(0, 4) = 5.0;
  m(1, 0) = 6.0;
  m(1, 1) = 7.0;
  m(1, 2) = 8.0;
  m(1, 3) = 9.0;
  m(1, 4) = 10.0;
  m(2, 0) = 11.0;
  m(2, 1) = 12.0;
  m(2, 2) = 13.0;
  m(2, 3) = 14.0;
  m(2, 4) = 15.0;
  m(3, 0) = 16.0;
  m(3, 1) = 17.0;
  m(3, 2) = 18.0;
  m(3, 3) = 19.0;
  m(3, 4) = 20.0;
  m(4, 0) = 21.0;
  m(4, 1) = 22.0;
  m(4, 2) = 23.0;
  m(4, 3) = 24.0;
  m(4, 4) = 25.0;

  CustomMatrix transposed = m.Transpose();
  EXPECT_LT(transposed(0, 0) - 1.0, ACCURACY);
  EXPECT_LT(transposed(0, 1) - 6.0, ACCURACY);
  EXPECT_LT(transposed(0, 2) - 11.0, ACCURACY);
  EXPECT_LT(transposed(0, 3) - 16.0, ACCURACY);
  EXPECT_LT(transposed(0, 4) - 21.0, ACCURACY);
  EXPECT_LT(transposed(1, 0) - 2.0, ACCURACY);
  EXPECT_LT(transposed(1, 1) - 7.0, ACCURACY);
  EXPECT_LT(transposed(1, 2) - 12.0, ACCURACY);
  EXPECT_LT(transposed(1, 3) - 17.0, ACCURACY);
  EXPECT_LT(transposed(1, 4) - 22.0, ACCURACY);
  EXPECT_LT(transposed(2, 0) - 3.0, ACCURACY);
  EXPECT_LT(transposed(2, 1) - 8.0, ACCURACY);
  EXPECT_LT(transposed(2, 2) - 13.0, ACCURACY);
  EXPECT_LT(transposed(2, 3) - 18.0, ACCURACY);
  EXPECT_LT(transposed(2, 4) - 23.0, ACCURACY);
  EXPECT_LT(transposed(3, 0) - 4.0, ACCURACY);
  EXPECT_LT(transposed(3, 1) - 9.0, ACCURACY);
  EXPECT_LT(transposed(3, 2) - 14.0, ACCURACY);
  EXPECT_LT(transposed(3, 3) - 19.0, ACCURACY);
  EXPECT_LT(transposed(3, 4) - 24.0, ACCURACY);
  EXPECT_LT(transposed(4, 0) - 5.0, ACCURACY);
  EXPECT_LT(transposed(4, 1) - 10.0, ACCURACY);
  EXPECT_LT(transposed(4, 2) - 15.0, ACCURACY);
  EXPECT_LT(transposed(4, 3) - 20.0, ACCURACY);
  EXPECT_LT(transposed(4, 4) - 25.0, ACCURACY);
}

TEST(CustomMatrixTest, Determinant) {
  CustomMatrix m(2, 2);
  m(0, 0) = 1.0;
  m(0, 1) = 2.0;
  m(1, 0) = 3.0;
  m(1, 1) = 4.0;

  EXPECT_DOUBLE_EQ(m.Determinant(), -2.0);
}

TEST(CustomMatrixTest, Determinant_2) {
  CustomMatrix m(5, 5);
  m(0, 0) = 1.0;
  m(0, 1) = 3.0;
  m(0, 2) = 5.0;
  m(0, 3) = 8.0;
  m(0, 4) = 3.0;
  m(1, 0) = 9.0;
  m(1, 1) = 9.0;
  m(1, 2) = 1.0;
  m(1, 3) = 2.0;
  m(1, 4) = 5.0;
  m(2, 0) = 2.0;
  m(2, 1) = 2.0;
  m(2, 2) = 2.0;
  m(2, 3) = 2.0;
  m(2, 4) = 4.0;
  m(3, 0) = 3.0;
  m(3, 1) = 6.0;
  m(3, 2) = 7.0;
  m(3, 3) = 2.0;
  m(3, 4) = 1.0;
  m(4, 0) = 8.0;
  m(4, 1) = 9.0;
  m(4, 2) = 2.0;
  m(4, 3) = 7.0;
  m(4, 4) = 6.0;
  EXPECT_LT(m.Determinant() - 520.0, ACCURACY);
}

TEST(CustomMatrixTest, DeterminantCorrectCalculation) {
  CustomMatrix m1(2, 2);
  m1(0, 0) = 1.0;
  m1(0, 1) = 2.0;
  m1(1, 0) = 3.0;
  m1(1, 1) = 4.0;

  EXPECT_DOUBLE_EQ(m1.Determinant(), -2.0);
}

TEST(CustomMatrixTest, DeterminantNonSquareMatrix) {
  CustomMatrix m1(2, 3);

  EXPECT_THROW(m1.Determinant(), std::invalid_argument);
}

TEST(CustomMatrixTest, EqMatrixEqual) {
  CustomMatrix m1(2, 2);
  CustomMatrix m2(2, 2);
  m1(0, 0) = 1.0;
  m1(0, 1) = 2.0;
  m1(1, 0) = 3.0;
  m1(1, 1) = 4.0;
  m2(0, 0) = 1.0;
  m2(0, 1) = 2.0;
  m2(1, 0) = 3.0;
  m2(1, 1) = 4.0;

  EXPECT_TRUE(m1.EqMatrix(m2));
}

TEST(CustomMatrixTest, EqMatrixNotEqual) {
  CustomMatrix m1(2, 2);
  CustomMatrix m2(2, 2);
  m1(0, 0) = 1.0;
  m1(0, 1) = 2.0;
  m1(1, 0) = 3.0;
  m1(1, 1) = 4.0;
  m2(0, 0) = 5.0;
  m2(0, 1) = 6.0;
  m2(1, 0) = 7.0;
  m2(1, 1) = 8.0;

  EXPECT_FALSE(m1.EqMatrix(m2));
}

TEST(CustomMatrixTest, EqMatrixDifferentSizes) {
  CustomMatrix m1(2, 2);
  CustomMatrix m2(3, 3);

  EXPECT_FALSE(m1.EqMatrix(m2));
}
TEST(CustomMatrixTest, EqualityOperator) {
  CustomMatrix m1(2, 2);
  CustomMatrix m2(2, 2);
  m1(0, 0) = 1.0;
  m1(1, 1) = 2.0;
  m2(0, 0) = 1.0;
  m2(1, 1) = 2.0;
  EXPECT_TRUE(m1 == m2);
}

TEST(CustomMatrixTest, IndexOperator) {
  CustomMatrix m(2, 2);
  m(0, 0) = 1.0;
  m(1, 1) = 2.0;
  EXPECT_DOUBLE_EQ(m(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(m(1, 1), 2.0);
  EXPECT_THROW(m(2, 2), std::out_of_range);
}

TEST(CustomMatrixTest, CalcComplements) {
  CustomMatrix m(2, 2);
  m(0, 0) = 1.0;
  m(0, 1) = 2.0;
  m(1, 0) = 3.0;
  m(1, 1) = 4.0;

  CustomMatrix complements = m.CalcComplements();
  EXPECT_DOUBLE_EQ(complements(0, 0), 4.0);
  EXPECT_DOUBLE_EQ(complements(0, 1), -3.0);
  EXPECT_DOUBLE_EQ(complements(1, 0), -2.0);
  EXPECT_DOUBLE_EQ(complements(1, 1), 1.0);
}

TEST(CustomMatrixTest, CalcComplementsCorrectCalculation) {
  CustomMatrix m1(3, 3);
  m1(0, 0) = 1.0;
  m1(0, 1) = 2.0;
  m1(0, 2) = 3.0;
  m1(1, 0) = 0.0;
  m1(1, 1) = 1.0;
  m1(1, 2) = 4.0;
  m1(2, 0) = 5.0;
  m1(2, 1) = 6.0;
  m1(2, 2) = 0.0;

  CustomMatrix complements = m1.CalcComplements();

  EXPECT_DOUBLE_EQ(complements(0, 0), -24.0);
  EXPECT_DOUBLE_EQ(complements(0, 1), 20.0);
  EXPECT_DOUBLE_EQ(complements(0, 2), -5.0);
  EXPECT_DOUBLE_EQ(complements(1, 0), 18.0);
  EXPECT_DOUBLE_EQ(complements(1, 1), -15.0);
  EXPECT_DOUBLE_EQ(complements(1, 2), 4.0);
  EXPECT_DOUBLE_EQ(complements(2, 0), 5.0);
  EXPECT_DOUBLE_EQ(complements(2, 1), -4.0);
  EXPECT_DOUBLE_EQ(complements(2, 2), 1.0);
}

TEST(CustomMatrixTest, CalcComplementsCorrectCalculation_1x1) {
  CustomMatrix m1(1, 1);
  m1(0, 0) = 9.0;

  CustomMatrix complements = m1.CalcComplements();

  EXPECT_DOUBLE_EQ(complements(0, 0), 1);
}

TEST(CustomMatrixTest, CalcComplementsNonSquareMatrix) {
  CustomMatrix m1(2, 3);

  EXPECT_THROW(m1.CalcComplements(), std::invalid_argument);
}

TEST(CustomMatrixTest, InverseMatrix) {
  CustomMatrix m(2, 2);
  m(0, 0) = 1.0;
  m(0, 1) = 2.0;
  m(1, 0) = 3.0;
  m(1, 1) = 4.0;

  CustomMatrix inverse = m.InverseMatrix();
  EXPECT_DOUBLE_EQ(inverse(0, 0), -2.0);
  EXPECT_DOUBLE_EQ(inverse(0, 1), 1.0);
  EXPECT_DOUBLE_EQ(inverse(1, 0), 1.5);
  EXPECT_DOUBLE_EQ(inverse(1, 1), -0.5);
}

TEST(CustomMatrixTest, OperatorParentheses) {
  CustomMatrix m(2, 2);
  m(0, 0) = 1.0;
  m(0, 1) = 2.0;
  m(1, 0) = 3.0;
  m(1, 1) = 4.0;

  EXPECT_DOUBLE_EQ(m(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(m(0, 1), 2.0);
  EXPECT_DOUBLE_EQ(m(1, 0), 3.0);
  EXPECT_DOUBLE_EQ(m(1, 1), 4.0);
}

TEST(CustomMatrixTest, OperatorEquality) {
  CustomMatrix m1(2, 2);
  CustomMatrix m2(2, 2);
  m1(0, 0) = 1.0;
  m1(0, 1) = 2.0;
  m1(1, 0) = 3.0;
  m1(1, 1) = 4.0;

  m2(0, 0) = 1.0;
  m2(0, 1) = 2.0;
  m2(1, 0) = 3.0;
  m2(1, 1) = 4.0;

  EXPECT_TRUE(m1 == m2);
}

TEST(CustomMatrixTest, OperatorAddition) {
  CustomMatrix m1(2, 2);
  CustomMatrix m2(2, 2);
  m1(0, 0) = 1.0;
  m1(0, 1) = 2.0;
  m1(1, 0) = 3.0;
  m1(1, 1) = 4.0;

  m2(0, 0) = 1.0;
  m2(0, 1) = 1.0;
  m2(1, 0) = 1.0;
  m2(1, 1) = 1.0;

  CustomMatrix result = m1 + m2;
  EXPECT_DOUBLE_EQ(result(0, 0), 2.0);
  EXPECT_DOUBLE_EQ(result(0, 1), 3.0);
  EXPECT_DOUBLE_EQ(result(1, 0), 4.0);
  EXPECT_DOUBLE_EQ(result(1, 1), 5.0);
}

TEST(CustomMatrixTest, OperatorSubtraction) {
  CustomMatrix m1(2, 2);
  CustomMatrix m2(2, 2);
  m1(0, 0) = 1.0;
  m1(0, 1) = 2.0;
  m1(1, 0) = 3.0;
  m1(1, 1) = 4.0;

  m2(0, 0) = 1.0;
  m2(0, 1) = 1.0;
  m2(1, 0) = 1.0;
  m2(1, 1) = 1.0;

  CustomMatrix result = m1 - m2;
  EXPECT_DOUBLE_EQ(result(0, 0), 0.0);
  EXPECT_DOUBLE_EQ(result(0, 1), 1.0);
  EXPECT_DOUBLE_EQ(result(1, 0), 2.0);
  EXPECT_DOUBLE_EQ(result(1, 1), 3.0);
}

TEST(CustomMatrixTest, OperatorMultiplicationByNumber) {
  CustomMatrix m(2, 2);
  m(0, 0) = 1.0;
  m(0, 1) = 2.0;
  m(1, 0) = 3.0;
  m(1, 1) = 4.0;

  CustomMatrix result = m * 2.0;
  EXPECT_DOUBLE_EQ(result(0, 0), 2.0);
  EXPECT_DOUBLE_EQ(result(0, 1), 4.0);
  EXPECT_DOUBLE_EQ(result(1, 0), 6.0);
  EXPECT_DOUBLE_EQ(result(1, 1), 8.0);
}

TEST(CustomMatrixTest, InverseMatrixThrowsExceptionForZeroDeterminant) {
  CustomMatrix m(2, 2);
  m(0, 0) = 1.0;
  m(0, 1) = 2.0;
  m(1, 0) = 2.0;
  m(1, 1) = 4.0;

  EXPECT_THROW(m.InverseMatrix(), std::invalid_argument);
}

TEST(CustomMatrixTest, OperatorMultiplicationByMatrix) {
  CustomMatrix m1(2, 2);
  CustomMatrix m2(2, 2);
  m1(0, 0) = 1.0;
  m1(0, 1) = 2.0;
  m1(1, 0) = 3.0;
  m1(1, 1) = 4.0;

  m2(0, 0) = 1.0;
  m2(0, 1) = 0.0;
  m2(1, 0) = 0.0;
  m2(1, 1) = 1.0;

  CustomMatrix result = m1 * m2;
  EXPECT_DOUBLE_EQ(result(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(result(0, 1), 2.0);
  EXPECT_DOUBLE_EQ(result(1, 0), 3.0);
  EXPECT_DOUBLE_EQ(result(1, 1), 4.0);
}

TEST(CustomMatrixTest, AssignmentOperatorCorrectAssignment) {
  CustomMatrix m1(2, 2);
  m1(0, 0) = 1.0;
  m1(0, 1) = 2.0;
  m1(1, 0) = 3.0;
  m1(1, 1) = 4.0;

  CustomMatrix m2 = m1;

  EXPECT_DOUBLE_EQ(m2(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(m2(0, 1), 2.0);
  EXPECT_DOUBLE_EQ(m2(1, 0), 3.0);
  EXPECT_DOUBLE_EQ(m2(1, 1), 4.0);
}

TEST(CustomMatrixTest, AssignmentOperatorSelfAssignment) {
  CustomMatrix m1(2, 2);
  m1(0, 0) = 1.0;
  m1(0, 1) = 2.0;
  m1(1, 0) = 3.0;
  m1(1, 1) = 4.0;
  CustomMatrix* p = &m1;
  m1 = *p;

  EXPECT_DOUBLE_EQ(m1(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(m1(0, 1), 2.0);
  EXPECT_DOUBLE_EQ(m1(1, 0), 3.0);
  EXPECT_DOUBLE_EQ(m1(1, 1), 4.0);
}

TEST(CustomMatrixTest, OperatorAssignment) {
  CustomMatrix m1(2, 2);
  m1(0, 0) = 1.0;
  m1(0, 1) = 2.0;
  m1(1, 0) = 3.0;
  m1(1, 1) = 4.0;

  CustomMatrix m2 = m1;
  EXPECT_DOUBLE_EQ(m2(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(m2(0, 1), 2.0);
  EXPECT_DOUBLE_EQ(m2(1, 0), 3.0);
  EXPECT_DOUBLE_EQ(m2(1, 1), 4.0);
}

TEST(CustomMatrixTest, OperatorAddAssign) {
  CustomMatrix m1(2, 2);
  CustomMatrix m2(2, 2);
  m1(0, 0) = 1.0;
  m1(0, 1) = 2.0;
  m1(1, 0) = 3.0;
  m1(1, 1) = 4.0;

  m2(0, 0) = 1.0;
  m2(0, 1) = 1.0;
  m2(1, 0) = 1.0;
  m2(1, 1) = 1.0;

  m1 += m2;
  EXPECT_DOUBLE_EQ(m1(0, 0), 2.0);
  EXPECT_DOUBLE_EQ(m1(0, 1), 3.0);
  EXPECT_DOUBLE_EQ(m1(1, 0), 4.0);
  EXPECT_DOUBLE_EQ(m1(1, 1), 5.0);
}

TEST(CustomMatrixTest, OperatorSubAssign) {
  CustomMatrix m1(2, 2);
  CustomMatrix m2(2, 2);
  m1(0, 0) = 1.0;
  m1(0, 1) = 2.0;
  m1(1, 0) = 3.0;
  m1(1, 1) = 4.0;

  m2(0, 0) = 1.0;
  m2(0, 1) = 1.0;
  m2(1, 0) = 1.0;
  m2(1, 1) = 1.0;

  m1 -= m2;
  EXPECT_DOUBLE_EQ(m1(0, 0), 0.0);
  EXPECT_DOUBLE_EQ(m1(0, 1), 1.0);
  EXPECT_DOUBLE_EQ(m1(1, 0), 2.0);
  EXPECT_DOUBLE_EQ(m1(1, 1), 3.0);
}

TEST(CustomMatrixTest, OperatorMulAssignByNumber) {
  CustomMatrix m(2, 2);
  m(0, 0) = 1.0;
  m(0, 1) = 2.0;
  m(1, 0) = 3.0;
  m(1, 1) = 4.0;

  m *= 2.0;
  EXPECT_DOUBLE_EQ(m(0, 0), 2.0);
  EXPECT_DOUBLE_EQ(m(0, 1), 4.0);
  EXPECT_DOUBLE_EQ(m(1, 0), 6.0);
  EXPECT_DOUBLE_EQ(m(1, 1), 8.0);
}

TEST(CustomMatrixTest, OperatorMulAssignByMatrix) {
  CustomMatrix m1(2, 2);
  CustomMatrix m2(2, 2);
  m1(0, 0) = 1.0;
  m1(0, 1) = 2.0;
  m1(1, 0) = 3.0;
  m1(1, 1) = 4.0;

  m2(0, 0) = 1.0;
  m2(0, 1) = 0.0;
  m2(1, 0) = 0.0;
  m2(1, 1) = 1.0;

  m1 *= m2;
  EXPECT_DOUBLE_EQ(m1(0, 0), 1.0);
  EXPECT_DOUBLE_EQ(m1(0, 1), 2.0);
  EXPECT_DOUBLE_EQ(m1(1, 0), 3.0);
  EXPECT_DOUBLE_EQ(m1(1, 1), 4.0);
}

// delete
// delete
// delete

TEST(CustomMatrixTest, ConstructorDefault) {
  CustomMatrix mtx;

  EXPECT_EQ(mtx.GetRows(), 3);
  EXPECT_EQ(mtx.GetCols(), 3);

  for (int i = 0; i < mtx.GetRows(); i++) {
    for (int j = 0; j < mtx.GetCols(); j++) EXPECT_EQ(mtx(i, j), 0);
  }
}

TEST(CustomMatrixTest, EqMatrixTest) {
  CustomMatrix mtx1(3, 3);
  CustomMatrix mtx2(3, 3);
  CustomMatrix mtx3(3, 3);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      mtx1(i, j) = i + j;
      mtx2(i, j) = i + j;
      mtx3(i, j) = i + j + 1;
    }
  }

  EXPECT_TRUE(mtx1.EqMatrix(mtx2));
  EXPECT_FALSE(mtx1.EqMatrix(mtx3));
}

TEST(CustomMatrixTest_2, EqMatrixDifferentSizeTest) {
  CustomMatrix mtx1(3, 3);
  CustomMatrix mtx2(4, 4);
  EXPECT_FALSE(mtx1.EqMatrix(mtx2));
}

TEST(CustomMatrixTest_3, EqMatrixEmptyTest) {
  CustomMatrix mtx1(0, 0);
  CustomMatrix mtx2(0, 0);
  EXPECT_TRUE(mtx1.EqMatrix(mtx2));
}

TEST(CustomMatrixTest_4, EqMatrixFloatingPointTest) {
  CustomMatrix mtx1(3, 3);
  CustomMatrix mtx2(3, 3);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      mtx1(i, j) = 1.0 + 0.000001 * (i + j);
      mtx2(i, j) = 1.0 + 0.000002 * (i + j);
    }
  }

  EXPECT_FALSE(mtx1.EqMatrix(mtx2));
}

TEST(CustomMatrixTest_5, EqMatrixBoundaryTest) {
  CustomMatrix mtx1(3, 3);
  CustomMatrix mtx2(3, 3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      mtx1(i, j) = 1e-7;
      mtx2(i, j) = 1e-7;
    }
  }
  EXPECT_TRUE(mtx1.EqMatrix(mtx2));
}

TEST(CustomMatrixTest_6, EqMatrixLargeTest) {
  CustomMatrix mtx1(100, 100);
  CustomMatrix mtx2(100, 100);
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      mtx1(i, j) = i + j;
      mtx2(i, j) = i + j;
    }
  }
  EXPECT_TRUE(mtx1.EqMatrix(mtx2));
}

TEST(CustomMatrixTest_7, EqMatrixSameElementsTest) {
  CustomMatrix mtx1(3, 3);
  CustomMatrix mtx2(3, 3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      mtx1(i, j) = 2;
      mtx2(i, j) = 2;
    }
  }
  EXPECT_TRUE(mtx1.EqMatrix(mtx2));
}

TEST(CustomMatrixTest_8, EqMatrixZeroElementsTest) {
  CustomMatrix mtx1(3, 3);
  CustomMatrix mtx2(3, 3);
  mtx1(0, 0) = 0;
  mtx1(1, 1) = 0;
  mtx2(0, 0) = 0;
  mtx2(1, 1) = 0;
  EXPECT_TRUE(mtx1.EqMatrix(mtx2));
}

TEST(CustomMatrixTest_9, SumMatrix) {
  CustomMatrix mtx1(2, 2);
  CustomMatrix mtx2(2, 2);
  CustomMatrix mtx3(2, 2);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      mtx1(i, j) = 2;
      mtx2(i, j) = 2;
      mtx3(i, j) = 4;
    }
  }
  mtx1.SumMatrix(mtx2);
  EXPECT_TRUE(mtx1 == mtx3);
}

TEST(CustomMatrixTest_10, SumMatrixDifferentSize) {
  CustomMatrix mtx1(2, 2);
  CustomMatrix mtx2(3, 3);
  ASSERT_THROW(mtx1.SumMatrix(mtx2), std::invalid_argument);
}

TEST(CustomMatrixTest_11, SumMatrixZeroMatrix) {
  CustomMatrix mtx1(2, 2);
  CustomMatrix mtx2(2, 2);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) mtx1(i, j) = 0;
  }
  mtx1.SumMatrix(mtx2);
  EXPECT_TRUE(mtx1 == mtx2);
}

TEST(CustomMatrixTest_12, SumMatrixNegativeValues) {
  CustomMatrix mtx1(2, 2);
  CustomMatrix mtx2(2, 2);
  CustomMatrix mtx3(2, 2);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      mtx1(i, j) = -1;
      mtx2(i, j) = -5;
      mtx3(i, j) = -6;
    }
  }
  mtx1.SumMatrix(mtx2);
  EXPECT_TRUE(mtx1 == mtx3);
}

TEST(CustomMatrixTest_13, SumMatrixFloatingPoint) {
  CustomMatrix mtx1(2, 2);
  CustomMatrix mtx2(2, 2);
  CustomMatrix mtx3(2, 2);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      mtx1(i, j) = 1.1 + 1.1 * i + 1.1 * j;
      mtx2(i, j) = 5.5 + 1.1 * i + 1.1 * j;
      mtx3(i, j) = 6.6 + 2.2 * i + 2.2 * j;
    }
  }
  mtx1.SumMatrix(mtx2);
  EXPECT_TRUE(mtx1 == mtx3);
}

TEST(CustomMatrixTest_14, SumMatrixSameMatrix) {
  CustomMatrix mtx1(2, 2);
  CustomMatrix mtx2(2, 2);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      mtx1(i, j) = i + j + 1;
      mtx2(i, j) = 2 * (i + j + 1);
    }
  }
  mtx1.SumMatrix(mtx1);
  EXPECT_TRUE(mtx1 == mtx2);
}

TEST(CustomMatrixTest_15, SubMatrix) {
  CustomMatrix mtx1(2, 2);
  CustomMatrix mtx2(2, 2);
  CustomMatrix mtx3(2, 2);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      mtx1(i, j) = 2;
      mtx2(i, j) = 2;
      mtx3(i, j) = 0;
    }
  }
  mtx1.SubMatrix(mtx2);
  EXPECT_TRUE(mtx1 == mtx3);
}

TEST(CustomMatrixTest_16, SubMatrixDifferentSize) {
  CustomMatrix mtx1(2, 2);
  CustomMatrix mtx2(3, 3);
  ASSERT_THROW(mtx1.SubMatrix(mtx2), std::invalid_argument);
}

TEST(CustomMatrixTest_17, SubMatrixZeroMatrix) {
  CustomMatrix mtx1(2, 2);
  CustomMatrix mtx2(2, 2);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) mtx1(i, j) = 0;
  }
  mtx1.SubMatrix(mtx2);
  EXPECT_TRUE(mtx1 == mtx2);
}

TEST(CustomMatrixTest_18, SubMatrixNegativeValues) {
  CustomMatrix mtx1(2, 2);
  CustomMatrix mtx2(2, 2);
  CustomMatrix mtx3(2, 2);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      mtx1(i, j) = -1 - i - j;
      mtx2(i, j) = -5 - i - j;
      mtx3(i, j) = 4;
    }
  }
  mtx1.SubMatrix(mtx2);
  EXPECT_TRUE(mtx1 == mtx3);
}

TEST(CustomMatrixTest_19, SubMatrixFloatingPoint) {
  CustomMatrix mtx1(2, 2);
  CustomMatrix mtx2(2, 2);
  CustomMatrix mtx3(2, 2);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      mtx1(i, j) = 1.1 + 1.1 * i + 1.1 * j;
      mtx2(i, j) = 0.5 + 0.6 * i + 0.6 * j;
      mtx3(i, j) = 0.6 + 0.5 * i + 0.5 * j;
    }
  }
  mtx1.SubMatrix(mtx2);
  EXPECT_TRUE(mtx1 == mtx3);
}

TEST(CustomMatrixTest_20, SubMatrixSameMatrix) {
  CustomMatrix mtx1(2, 2);
  CustomMatrix mtx2(2, 2);
  int count = 0;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      mtx1(i, j) = count++;
      mtx2(i, j) = 0;
    }
  }
  mtx1.SubMatrix(mtx1);
  EXPECT_TRUE(mtx1 == mtx2);
}

TEST(CustomMatrixTest_21, mult_number) {
  CustomMatrix mtx1(2, 2);
  CustomMatrix mtx3(2, 2);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      mtx1(i, j) = 2;
      mtx3(i, j) = 4;
    }
  }
  mtx1.MulNumber(2);

  EXPECT_TRUE(mtx1 == mtx3);
}

TEST(CustomMatrixTest_22, MulNumberZero) {
  CustomMatrix mtx1(2, 2);
  CustomMatrix mtx2(2, 2);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      mtx1(i, j) = 2;
      mtx2(i, j) = 0;
    }
  }
  mtx1.MulNumber(0);

  EXPECT_TRUE(mtx1 == mtx2);
}

TEST(CustomMatrixTest_23, MulNumberNegative) {
  CustomMatrix mtx1(2, 2);
  CustomMatrix mtx2(2, 2);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      mtx1(i, j) = 2;
      mtx2(i, j) = -4;
    }
  }
  mtx1.MulNumber(-2);

  EXPECT_TRUE(mtx1 == mtx2);
}

TEST(CustomMatrixTest_24, MulNumberFloatingPoint) {
  CustomMatrix mtx1(2, 2);
  CustomMatrix mtx2(2, 2);
  float num_mtx1 = 1.5;
  float num_mtx2 = 3.0;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      mtx1(i, j) = num_mtx1 + 1;
      mtx2(i, j) = num_mtx2 + 2;
    }
  }
  mtx1.MulNumber(2.0);

  EXPECT_TRUE(mtx1 == mtx2);
}

TEST(CustomMatrixTest_25, MulNumberIdentity) {
  CustomMatrix mtx1(2, 2);
  CustomMatrix mtx2(2, 2);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      mtx1(i, j) = 2;
      mtx2(i, j) = 2;
    }
  }
  mtx1.MulNumber(1);

  EXPECT_TRUE(mtx1 == mtx2);
}

TEST(CustomMatrixTest_26, mult_matrix) {
  CustomMatrix mtx1(2, 2);
  CustomMatrix mtx2(2, 2);
  CustomMatrix mtx3(2, 2);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      mtx1(i, j) = 2;
      mtx2(i, j) = 2;
      mtx3(i, j) = 8;
    }
  }
  mtx1.MulMatrix(mtx2);

  EXPECT_TRUE(mtx1 == mtx3);
}

TEST(CustomMatrixTest_27, MulMatrixDifferentSize) {
  CustomMatrix mtx1(2, 3);
  CustomMatrix mtx2(2, 3);
  ASSERT_THROW(mtx1.MulMatrix(mtx2), std::invalid_argument);
}

TEST(CustomMatrixTest_28, MulMatrixZeroMatrix) {
  CustomMatrix mtx1(2, 2);
  CustomMatrix mtx2(2, 2);
  CustomMatrix mtx3(2, 2);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      mtx1(i, j) = 0;
      mtx2(i, j) = 2;
      mtx3(i, j) = 0;
    }
  }
  mtx1.MulMatrix(mtx2);

  EXPECT_TRUE(mtx1 == mtx3);
}

TEST(CustomMatrixTest_29, MulMatrixNegativeValues) {
  CustomMatrix mtx1(2, 2);
  CustomMatrix mtx2(2, 2);
  CustomMatrix mtx3(2, 2);
  int num_mtx1 = 0, num_mtx2 = -4;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      mtx1(i, j) = --num_mtx1;
      mtx2(i, j) = --num_mtx2;
    }
  }
  mtx1.MulMatrix(mtx2);
  mtx3(0, 0) = 19;
  mtx3(0, 1) = 22;
  mtx3(1, 0) = 43;
  mtx3(1, 1) = 50;
  EXPECT_TRUE(mtx1 == mtx3);
}

TEST(CustomMatrixTest_30, MulMatrixFloatingPoint) {
  CustomMatrix mtx1(2, 2);
  CustomMatrix mtx2(2, 2);
  CustomMatrix mtx3(2, 2);
  float num_mtx1 = 0.0, num_mtx2 = 4.4;
  float epsilon = 0.01;

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      num_mtx1 += 1.1;
      num_mtx2 += 1.1;
      mtx1(i, j) = num_mtx1;
      mtx2(i, j) = num_mtx2;
    }
  }

  mtx1.MulMatrix(mtx2);

  mtx3(0, 0) = 22.99;
  mtx3(0, 1) = 26.62;
  mtx3(1, 0) = 52.03;
  mtx3(1, 1) = 60.5;

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      EXPECT_NEAR(mtx1(i, j), mtx3(i, j), epsilon);
    }
  }
}

TEST(CustomMatrixTest_31, transpose) {
  CustomMatrix mtx1(2, 2);
  mtx1(0, 0) = 2;
  mtx1(0, 1) = 1;
  mtx1(1, 0) = 2;
  mtx1(1, 1) = 1;
  CustomMatrix mtx2 = mtx1.Transpose();
  CustomMatrix mtx3(2, 2);
  mtx3(0, 0) = 2;
  mtx3(0, 1) = 2;
  mtx3(1, 0) = 1;
  mtx3(1, 1) = 1;
  EXPECT_TRUE(mtx2 == mtx3);
}

TEST(CustomMatrixTest_32, transposeSquareMatrix) {
  CustomMatrix mtx1(3, 3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) mtx1(i, j) = i * 3 + j + 1;
  }
  CustomMatrix mtx2 = mtx1.Transpose();
  CustomMatrix mtx3(3, 3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) mtx3(i, j) = j * 3 + i + 1;
  }
  EXPECT_TRUE(mtx2 == mtx3);
}

TEST(CustomMatrixTest_33, transposeRectangularMatrix) {
  CustomMatrix mtx1(2, 3);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) mtx1(i, j) = i * 3 + j + 1;
  }
  CustomMatrix mtx2 = mtx1.Transpose();
  CustomMatrix mtx3(3, 2);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) mtx3(j, i) = i * 3 + j + 1;
  }

  EXPECT_TRUE(mtx2 == mtx3);
}

TEST(CustomMatrixTest_34, transposeEmptyMatrix) {
  CustomMatrix mtx1(0, 0);
  CustomMatrix mtx2 = mtx1.Transpose();
  EXPECT_EQ(mtx2.GetRows(), 0);
  EXPECT_EQ(mtx2.GetCols(), 0);
}

TEST(CustomMatrixTest_35, transposeSingleElementMatrix) {
  CustomMatrix mtx1(1, 1);
  mtx1(0, 0) = 5;
  CustomMatrix mtx2 = mtx1.Transpose();
  CustomMatrix mtx3(1, 1);
  mtx3(0, 0) = 5;
  EXPECT_TRUE(mtx2 == mtx3);
}

TEST(CustomMatrixTest_36, determinat) {
  CustomMatrix mtx1(3, 3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) mtx1(i, j) = 3;
  }
  double tmp = mtx1.Determinant();
  EXPECT_DOUBLE_EQ(tmp, 0);
}

TEST(CustomMatrixTest_37, determinantNegative) {
  CustomMatrix mtx1(3, 3);
  int num = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      num++;
      if (j == 2 && i == 2)
        mtx1(i, j) = 10;
      else
        mtx1(i, j) = num;
    }
  }
  double determinant = mtx1.Determinant();
  EXPECT_LT(determinant, 0);
}

TEST(CustomMatrixTest_38, determinantRectangularMatrix) {
  CustomMatrix mtx1(3, 4);
  int num = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      num++;
      mtx1(i, j) = num;
    }
  }
  ASSERT_THROW(mtx1.Determinant(), std::invalid_argument);
}

TEST(CustomMatrixTest_39, determinantZeroMatrix) {
  CustomMatrix mtx1(3, 3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) mtx1(i, j) = 0;
  }
  double determinant = mtx1.Determinant();

  EXPECT_DOUBLE_EQ(determinant, 0);
}

TEST(CustomMatrixTest_40, determinantSingleElementMatrix) {
  CustomMatrix mtx1(1, 1);
  mtx1(0, 0) = 5;
  double determinant = mtx1.Determinant();
  EXPECT_DOUBLE_EQ(determinant, 5);
}

TEST(CustomMatrixTest_41, calc_complements) {
  CustomMatrix mtx1(2, 2);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) mtx1(i, j) = 3;
  }
  CustomMatrix mtx2 = mtx1.CalcComplements();

  CustomMatrix mtx3(2, 2);

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) mtx3(i, j) = 3;
  }

  EXPECT_FALSE(mtx2 == mtx3);
}

TEST(CustomMatrixTest_42, calcComplementsSquareMatrix) {
  CustomMatrix mtx1(3, 3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) mtx1(i, j) = i * 3 + j + 1;
  }
  CustomMatrix mtx2 = mtx1.CalcComplements();

  CustomMatrix mtx3(3, 3);
  mtx3(0, 0) = -3;
  mtx3(0, 1) = 6;
  mtx3(0, 2) = -3;
  mtx3(1, 0) = 6;
  mtx3(1, 1) = -12;
  mtx3(1, 2) = 6;
  mtx3(2, 0) = -3;
  mtx3(2, 1) = 6;
  mtx3(2, 2) = -3;

  EXPECT_TRUE(mtx2 == mtx3);
}

TEST(CustomMatrixTest_43, calcComplementsNonSquareMatrix) {
  CustomMatrix mtx1(2, 3);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) mtx1(i, j) = i * 3 + j + 1;
  }
  ASSERT_THROW(mtx1.CalcComplements(), std::invalid_argument);
}

TEST(CustomMatrixTest_44, calcComplementsEmptyMatrix) {
  CustomMatrix mtx1(0, 0);
  CustomMatrix mtx2 = mtx1.CalcComplements();
  EXPECT_EQ(mtx2.GetRows(), 0);
  EXPECT_EQ(mtx2.GetCols(), 0);
}

TEST(CustomMatrixTest_45, calcComplementsSingleElementMatrix) {
  CustomMatrix mtx1(1, 1);
  mtx1(0, 0) = 5;
  CustomMatrix mtx2 = mtx1.CalcComplements();
  CustomMatrix mtx3(1, 1);
  mtx3(0, 0) = 1;
  EXPECT_TRUE(mtx2 == mtx3);
}

TEST(CustomMatrixTest_46, inverseMatrixSquare) {
  CustomMatrix mtx1(3, 3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) mtx1(i, j) = i * 3 + j + 1;
  }

  EXPECT_THROW(mtx1.InverseMatrix(), std::invalid_argument);
}

TEST(CustomMatrixTest_47, inverseMatrixSingle) {
  CustomMatrix mtx1(1, 1);
  mtx1(0, 0) = 5;
  CustomMatrix mtx2 = mtx1.InverseMatrix();
  CustomMatrix mtx3(1, 1);
  mtx3(0, 0) = 0.2;
  EXPECT_TRUE(mtx2 == mtx3);
}

TEST(CustomMatrixTest_48, inverseMatrixIdentityMatrix) {
  CustomMatrix mtx1(3, 3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (j == i) mtx1(i, j) = 1;
    }
  }
  CustomMatrix mtx2 = mtx1.InverseMatrix();

  CustomMatrix mtx3(3, 3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++)
      if (j == i) mtx3(i, j) = 1;
  }

  EXPECT_TRUE(mtx2 == mtx3);
}

TEST(CustomMatrixTest_49, inverseMatrixDiagonalMatrix) {
  CustomMatrix mtx1(3, 3);
  mtx1(0, 0) = 2;
  mtx1(1, 1) = 3;
  mtx1(2, 2) = 4;
  CustomMatrix mtx2 = mtx1.InverseMatrix();

  CustomMatrix mtx3(3, 3);
  mtx3(0, 0) = 0.5;
  mtx3(1, 1) = 1.0 / 3;
  mtx3(2, 2) = 0.25;

  EXPECT_TRUE(mtx2 == mtx3);
}

TEST(CustomMatrixTest_50, InverseMatrixTest) {
  CustomMatrix mtx1(3, 3);
  mtx1(0, 0) = 1;
  mtx1(0, 1) = 2;
  mtx1(0, 2) = 3;
  mtx1(1, 0) = 0;
  mtx1(1, 1) = 1;
  mtx1(1, 2) = 4;
  mtx1(2, 0) = 5;
  mtx1(2, 1) = 6;
  mtx1(2, 2) = 0;

  CustomMatrix mtx2 = mtx1.InverseMatrix();

  ASSERT_EQ(mtx1.GetRows(), mtx1.GetCols());

  double det = mtx1.Determinant();
  ASSERT_NE(det, 0);

  CustomMatrix identity = mtx1 * mtx2;
  CustomMatrix expected(3, 3);
  for (int i = 0; i < 3; i++) {
    expected(i, i) = 1.0;
  }
  EXPECT_TRUE(identity == expected);
}

TEST(CustomMatrixTest_51, operator_sum) {
  CustomMatrix mtx1(2, 2);
  CustomMatrix mtx2(2, 2);
  CustomMatrix mtx3(2, 2);
  CustomMatrix mtx4(2, 2);

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      mtx1(i, j) = i + j;
      mtx2(i, j) = i == j ? 0 : 1;
    }
  }

  mtx4 = mtx1 + mtx2;

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) mtx3(i, j) = i + j + (i == j ? 0 : 1);
  }

  EXPECT_TRUE(mtx4 == mtx3);
}

TEST(CustomMatrixTest_52, operatorSumDifferentSize) {
  CustomMatrix mtx1(2, 2);
  CustomMatrix mtx2(3, 3);
  ASSERT_THROW(mtx1 + mtx2, std::invalid_argument);
}

TEST(CustomMatrixTest_53, operatorSumEmptyMatrix) {
  CustomMatrix mtx1(0, 0);
  CustomMatrix mtx2(0, 0);
  CustomMatrix mtx3 = mtx1 + mtx2;
  EXPECT_EQ(mtx3.GetRows(), 0);
  EXPECT_EQ(mtx3.GetCols(), 0);
}

TEST(CustomMatrixTest_54, operatorSumSingleElementMatrix) {
  CustomMatrix mtx1(1, 1);
  mtx1(0, 0) = 5;
  CustomMatrix mtx2(1, 1);
  mtx2(0, 0) = 10;
  CustomMatrix mtx3 = mtx1 + mtx2;
  CustomMatrix mtx4(1, 1);
  mtx4(0, 0) = 15;
  EXPECT_TRUE(mtx3 == mtx4);
}

TEST(CustomMatrixTest_55, operatorSumNegativeElements) {
  CustomMatrix mtx1(2, 2);
  CustomMatrix mtx2(2, 2);
  CustomMatrix mtx3(2, 2);
  CustomMatrix mtx4(2, 2);

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      mtx1(i, j) = i == 0 ? (j == 0 ? -1 : 2) : (j == 0 ? 3 : -4);
      mtx2(i, j) = i == 0 ? (j == 0 ? 5 : -6) : (j == 0 ? 7 : 8);
    }
  }

  mtx3 = mtx1 + mtx2;

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++)
      mtx4(i, j) = i == 0 ? (j == 0 ? 4 : -4) : (j == 0 ? 10 : 4);
  }
  EXPECT_TRUE(mtx3 == mtx4);
}

TEST(CustomMatrixTest_56, operator_sub) {
  CustomMatrix mtx1(2, 2);
  CustomMatrix mtx2(2, 2);
  CustomMatrix mtx3(2, 2);
  CustomMatrix mtx4(2, 2);

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      mtx1(i, j) = i == 1 && j == 0 ? 1 : 0;
      mtx2(i, j) = i == 1 && j == 0 ? 1 : 0;
    }
  }

  mtx4 = mtx1 - mtx2;

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) mtx2(i, j) = 0;
  }

  EXPECT_TRUE(mtx4 == mtx2);
}

TEST(CustomMatrixTest_57, operatorSubDifferentSize) {
  CustomMatrix mtx1(2, 2);
  CustomMatrix mtx2(3, 3);
  ASSERT_THROW(mtx1 - mtx2, std::invalid_argument);
}

TEST(CustomMatrixTest_58, operatorSubEmptyMatrix) {
  CustomMatrix mtx1(0, 0);
  CustomMatrix mtx2(0, 0);
  CustomMatrix mtx3 = mtx1 - mtx2;
  EXPECT_EQ(mtx3.GetRows(), 0);
  EXPECT_EQ(mtx3.GetCols(), 0);
}

TEST(CustomMatrixTest_59, operatorSubSingleElementMatrix) {
  CustomMatrix mtx1(1, 1);
  mtx1(0, 0) = 5;
  CustomMatrix mtx2(1, 1);
  mtx2(0, 0) = 2;
  CustomMatrix mtx3 = mtx1 - mtx2;
  CustomMatrix mtx4(1, 1);
  mtx4(0, 0) = 3;
  EXPECT_TRUE(mtx3 == mtx4);
}

TEST(CustomMatrixTest_60, operatorSubNegativeElements) {
  CustomMatrix mtx1(2, 2);
  CustomMatrix mtx2(2, 2);
  CustomMatrix mtx3(2, 2);
  CustomMatrix mtx4(2, 2);

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      mtx1(i, j) = i == 0 ? (j == 0 ? -1 : 2) : (j == 0 ? 3 : -4);
      mtx2(i, j) = i == 0 ? (j == 0 ? 5 : -6) : (j == 0 ? 7 : 8);
    }
  }

  mtx3 = mtx1 - mtx2;

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++)
      mtx4(i, j) = i == 0 ? (j == 0 ? -6 : 8) : (j == 0 ? -4 : -12);
  }

  EXPECT_TRUE(mtx3 == mtx4);
}

TEST(CustomMatrixTest_61, oper_sum_eq) {
  CustomMatrix mtx1(2, 2);
  CustomMatrix mtx2(2, 2);
  CustomMatrix mtx3(2, 2);
  mtx1(0, 0) = 0;
  mtx1(0, 1) = 1;
  mtx1(1, 0) = 1;
  mtx1(1, 1) = 2;

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) mtx2(i, j) = i == 0 ? 0 : 1;
  }

  mtx1 += mtx2;

  mtx3(0, 0) = 0;
  mtx3(0, 1) = 1;
  mtx3(1, 0) = 2;
  mtx3(1, 1) = 3;
  EXPECT_TRUE(mtx1 == mtx3);
}

TEST(CustomMatrixTest_62, operatorSumEqDifferentSize) {
  CustomMatrix mtx1(2, 2);
  CustomMatrix mtx2(3, 3);
  ASSERT_THROW(mtx1 += mtx2, std::invalid_argument);
}

TEST(CustomMatrixTest_63, operatorSumEqEmptyMatrix) {
  CustomMatrix mtx1(0, 0);
  CustomMatrix mtx2(0, 0);
  mtx1 += mtx2;
  EXPECT_EQ(mtx1.GetRows(), 0);
  EXPECT_EQ(mtx1.GetCols(), 0);
}

TEST(CustomMatrixTest_64, operatorSumEqSingleElementMatrix) {
  CustomMatrix mtx1(1, 1);
  mtx1(0, 0) = 5;
  CustomMatrix mtx2(1, 1);
  mtx2(0, 0) = 10;
  mtx1 += mtx2;
  CustomMatrix mtx3(1, 1);
  mtx3(0, 0) = 15;
  EXPECT_TRUE(mtx1 == mtx3);
}

TEST(CustomMatrixTest_65, operatorSumEqMatrix3x3) {
  CustomMatrix mtx1(3, 3);
  CustomMatrix mtx2(3, 3);
  CustomMatrix mtx3(3, 3);

  int value = 9;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      mtx1(i, j) = i * 3 + j + 1;
      mtx2(i, j) = ++value;
    }
  }

  mtx1 += mtx2;

  int num = 9;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      num += 2;
      mtx3(i, j) = num;
    }
  }

  EXPECT_TRUE(mtx1 == mtx3);
}

TEST(CustomMatrixTest_66, operator_sub_eq) {
  CustomMatrix mtx1(2, 2);
  CustomMatrix mtx2(2, 2);
  CustomMatrix mtx3(2, 2);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      mtx1(i, j) = i == 0 ? 0 : 1;
      mtx2(i, j) = i == 0 ? 0 : 1;
    }
  }

  mtx1 -= mtx2;

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) mtx3(i, j) = 0;
  }
  EXPECT_TRUE(mtx1 == mtx3);
}

TEST(CustomMatrixTest_67, operatorSubEqDifferentSize) {
  CustomMatrix mtx1(2, 2);
  CustomMatrix mtx2(3, 3);
  ASSERT_THROW(mtx1 -= mtx2, std::invalid_argument);
}

TEST(CustomMatrixTest_68, operatorSubEqEmptyMatrix) {
  CustomMatrix mtx1(0, 0);
  CustomMatrix mtx2(0, 0);
  mtx1 -= mtx2;
  EXPECT_EQ(mtx1.GetRows(), 0);
  EXPECT_EQ(mtx1.GetCols(), 0);
}

TEST(CustomMatrixTest_69, operatorSubEqSingleElementMatrix) {
  CustomMatrix mtx1(1, 1);
  mtx1(0, 0) = 5;
  CustomMatrix mtx2(1, 1);
  mtx2(0, 0) = 2;
  mtx1 -= mtx2;
  CustomMatrix mtx3(1, 1);
  mtx3(0, 0) = 3;
  EXPECT_TRUE(mtx1 == mtx3);
}

TEST(CustomMatrixTest_70, operatorSubEqNegativeElements) {
  CustomMatrix mtx1(2, 2);
  mtx1(0, 0) = -1;
  mtx1(0, 1) = 2;
  mtx1(1, 0) = 3;
  mtx1(1, 1) = -4;
  CustomMatrix mtx2(2, 2);
  mtx2(0, 0) = 5;
  mtx2(0, 1) = -6;
  mtx2(1, 0) = 7;
  mtx2(1, 1) = 8;
  mtx1 -= mtx2;
  CustomMatrix mtx3(2, 2);
  mtx3(0, 0) = -6;
  mtx3(0, 1) = 8;
  mtx3(1, 0) = -4;
  mtx3(1, 1) = -12;
  EXPECT_TRUE(mtx1 == mtx3);
}

TEST(CustomMatrixTest_71, operatorSubEqMatrix3x3) {
  CustomMatrix mtx1(3, 3);
  CustomMatrix mtx2(3, 3);
  CustomMatrix mtx3(3, 3);

  int value_mtx1 = 9, value_mtx2 = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      mtx1(i, j) = ++value_mtx1;
      mtx2(i, j) = ++value_mtx2;
    }
  }

  mtx1 -= mtx2;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      mtx3(i, j) = 9;
    }
  }

  EXPECT_TRUE(mtx1 == mtx3);
}

TEST(CustomMatrixTest_72, operator_mul) {
  CustomMatrix mtx1(2, 2);
  CustomMatrix mtx2(2, 2);
  CustomMatrix mtx3(2, 2);
  CustomMatrix mtx4(2, 2);

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      mtx1(i, j) = i == 0 ? 0 : 1;
      mtx2(i, j) = 0;
    }
  }

  mtx4 = mtx1 * mtx2;

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) mtx3(i, j) = 0;
  }

  EXPECT_TRUE(mtx4 == mtx3);
}

TEST(CustomMatrixTest_73, operatorMulMatrixDifferentSize) {
  CustomMatrix mtx1(2, 2);
  CustomMatrix mtx2(3, 3);
  ASSERT_THROW(mtx1 * mtx2, std::invalid_argument);
}

TEST(CustomMatrixTest_74, operatorMulMatrixEmptyMatrix) {
  CustomMatrix mtx1(2, 2);
  CustomMatrix mtx2(2, 2);
  CustomMatrix mtx3 = mtx1 * mtx2;
  EXPECT_EQ(mtx3.GetRows(), 2);
  EXPECT_EQ(mtx3.GetCols(), 2);
}

TEST(CustomMatrixTest_75, operatorMulMatrixSingleElementMatrix) {
  CustomMatrix mtx1(1, 1);
  mtx1(0, 0) = 5;
  CustomMatrix mtx2(1, 1);
  mtx2(0, 0) = 2;
  CustomMatrix mtx3 = mtx1 * mtx2;
  CustomMatrix mtx4(1, 1);
  mtx4(0, 0) = 10;
  EXPECT_TRUE(mtx3 == mtx4);
}

TEST(CustomMatrixTest_76, operatorMulMatrixNegativeElements) {
  CustomMatrix mtx1(2, 2);
  mtx1(0, 0) = -1;
  mtx1(0, 1) = 2;
  mtx1(1, 0) = 3;
  mtx1(1, 1) = -4;

  CustomMatrix mtx2(2, 2);
  mtx2(0, 0) = 5;
  mtx2(0, 1) = -6;
  mtx2(1, 0) = 7;
  mtx2(1, 1) = 8;

  CustomMatrix mtx3 = mtx1 * mtx2;

  CustomMatrix mtx4(2, 2);
  mtx4(0, 0) = 9;
  mtx4(0, 1) = 22;
  mtx4(1, 0) = -13;
  mtx4(1, 1) = -50;

  EXPECT_TRUE(mtx3 == mtx4);
}

TEST(CustomMatrixTest_77, operatorMulMatrix3x3) {
  CustomMatrix mtx1(3, 3);
  CustomMatrix mtx2(3, 3);
  CustomMatrix mtx3(3, 3);
  CustomMatrix mtx4(3, 3);

  int num_mtx1 = 0, num_mtx2 = 9;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      mtx1(i, j) = ++num_mtx1;
      mtx2(i, j) = ++num_mtx2;
    }
  }

  mtx3 = mtx1 * mtx2;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      int sum = 0;
      for (int k = 0; k < 3; k++) {
        sum += mtx1(i, k) * mtx2(k, j);
      }
      mtx4(i, j) = sum;
    }
  }

  EXPECT_TRUE(mtx3 == mtx4);
}

TEST(CustomMatrixTest_78, operator_mul_eq) {
  CustomMatrix mtx1(2, 2);
  CustomMatrix mtx2(2, 2);
  CustomMatrix mtx3(2, 2);

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      mtx1(i, j) = i == 0 ? 0 : 1;
      mtx2(i, j) = 0;
    }
  }

  mtx1 *= mtx2;

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) mtx3(i, j) = 0;
  }

  EXPECT_TRUE(mtx1 == mtx3);
}

TEST(CustomMatrixTest_79, operatorMulEqDifferentSize) {
  CustomMatrix mtx1(2, 2);
  CustomMatrix mtx2(3, 3);
  ASSERT_THROW(mtx1 *= mtx2, std::invalid_argument);
}

TEST(CustomMatrixTest_80, operatorMulEqEmptyMatrix) {
  CustomMatrix mtx1(0, 0);
  CustomMatrix mtx2(0, 0);
  mtx1 *= mtx2;
  EXPECT_EQ(mtx1.GetRows(), 0);
  EXPECT_EQ(mtx1.GetCols(), 0);
}

TEST(CustomMatrixTest_81, operatorMulEqSingleElementMatrix) {
  CustomMatrix mtx1(1, 1);
  mtx1(0, 0) = 5;
  CustomMatrix mtx2(1, 1);
  mtx2(0, 0) = 2;
  mtx1 *= mtx2;
  CustomMatrix mtx3(1, 1);
  mtx3(0, 0) = 10;
  EXPECT_TRUE(mtx1 == mtx3);
}

TEST(CustomMatrixTest_82, operatorMulEqNegativeElements) {
  CustomMatrix mtx1(2, 2);
  mtx1(0, 0) = -1;
  mtx1(0, 1) = 2;
  mtx1(1, 0) = 3;
  mtx1(1, 1) = -4;
  CustomMatrix mtx2(2, 2);
  mtx2(0, 0) = 5;
  mtx2(0, 1) = -6;
  mtx2(1, 0) = 7;
  mtx2(1, 1) = 8;
  mtx1 *= mtx2;
  CustomMatrix mtx3(2, 2);
  mtx3(0, 0) = 9;
  mtx3(0, 1) = 22;
  mtx3(1, 0) = -13;
  mtx3(1, 1) = -50;
  EXPECT_TRUE(mtx1 == mtx3);
}

TEST(CustomMatrixTest_83, operatorMulEqMatrix3x3) {
  CustomMatrix mtx1(3, 3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      mtx1(i, j) = i * 3 + j + 1;
    }
  }

  CustomMatrix mtx2(3, 3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) mtx2(i, j) = (i + 1) * 3 + j + 1;
  }

  CustomMatrix mtx1_copy = mtx1;
  mtx1_copy *= mtx2;

  CustomMatrix mtx3(3, 3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      int sum = 0;
      for (int k = 0; k < 3; k++) {
        sum += mtx1(i, k) * mtx2(k, j);
      }
      mtx3(i, j) = sum;
    }
  }

  EXPECT_TRUE(mtx1_copy == mtx3);
}

TEST(CustomMatrixTest_84, operatorMulNumber) {
  CustomMatrix mtx1(2, 2);

  int num = 0;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) mtx1(i, j) = ++num;
  }

  CustomMatrix mtx2 = mtx1 * 2.0;

  CustomMatrix mtx3(2, 2);

  int num_res = 0;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      num_res += 2;
      mtx3(i, j) = num_res;
    }
  }

  EXPECT_TRUE(mtx2 == mtx3);
}

TEST(CustomMatrixTest_85, operatorMulNumberNegative) {
  CustomMatrix mtx1(2, 2);
  mtx1(0, 0) = -1;
  mtx1(0, 1) = 2;
  mtx1(1, 0) = 3;
  mtx1(1, 1) = -4;

  CustomMatrix mtx2 = mtx1 * -2.0;

  CustomMatrix mtx3(2, 2);
  mtx3(0, 0) = 2;
  mtx3(0, 1) = -4;
  mtx3(1, 0) = -6;
  mtx3(1, 1) = 8;

  EXPECT_TRUE(mtx2 == mtx3);
}

TEST(CustomMatrixTest_86, operatorMulNumberZero) {
  CustomMatrix mtx1(2, 2);
  int num = 0;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) mtx1(i, j) = ++num;
  }

  CustomMatrix mtx2 = mtx1 * 0.0;

  CustomMatrix mtx3(2, 2);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) mtx3(i, j) = 0;
  };

  EXPECT_TRUE(mtx2 == mtx3);
}

TEST(CustomMatrixTest_87, operatorMulNumberEmpty) {
  CustomMatrix mtx1(0, 0);
  CustomMatrix mtx2 = mtx1 * 2.0;
  EXPECT_EQ(mtx2.GetRows(), 0);
  EXPECT_EQ(mtx2.GetCols(), 0);
}

TEST(CustomMatrixTest_88, operator_mul_eq) {
  CustomMatrix mtx1(2, 2);
  CustomMatrix mtx2(2, 2);

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) mtx1(i, j) = i == 0 ? 0 : 1;
  }

  mtx1 *= 2;

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) mtx2(i, j) = i == 0 ? 0 : 2;
  }

  EXPECT_TRUE(mtx1 == mtx2);
}

TEST(CustomMatrixTest_89, operatorMulEqFractionalNumber) {
  CustomMatrix mtx1(2, 2);
  mtx1(0, 0) = 1.5;
  mtx1(0, 1) = 2.5;
  mtx1(1, 0) = 3.5;
  mtx1(1, 1) = 4.5;

  mtx1 *= 1.5;

  CustomMatrix mtx2(2, 2);
  mtx2(0, 0) = 2.25;
  mtx2(0, 1) = 3.75;
  mtx2(1, 0) = 5.25;
  mtx2(1, 1) = 6.75;

  EXPECT_TRUE(mtx1 == mtx2);
}

TEST(CustomMatrixTest_90, operatorMulEqZero) {
  CustomMatrix mtx1(2, 2);
  int num = 0;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) mtx1(i, j) = ++num;
  }

  mtx1 *= 0;

  CustomMatrix mtx2(2, 2);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) mtx2(i, j) = 0;
  }

  EXPECT_TRUE(mtx1 == mtx2);
}

TEST(CustomMatrixTest_91, oper_eq_bool) {
  CustomMatrix mtx1(2, 2);
  CustomMatrix mtx2(2, 2);
  CustomMatrix mtx3(2, 2);

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      mtx1(i, j) = i == 0 ? 0 : 1;
      mtx2(i, j) = i == 0 ? 0 : 1;
    }
  }

  mtx3(0, 0) = 0.5;
  mtx3(0, 1) = 0.75;
  mtx3(1, 0) = 1.5;
  mtx3(1, 1) = 2.75;
  EXPECT_TRUE(mtx1 == mtx2);
  EXPECT_FALSE(mtx1 == mtx3);
}

TEST(CustomMatrixTest_92, NegativeRows) {
  CustomMatrix mtx(2, 2);
  EXPECT_THROW(mtx.SetRows(-1), std::invalid_argument);
}

TEST(CustomMatrixTest_93, SameRows) {
  CustomMatrix mtx(2, 2);
  mtx.SetRows(2);
  EXPECT_EQ(mtx.GetRows(), 2);
}

TEST(CustomMatrixTest_94, NegativeColumns) {
  CustomMatrix mtx(2, 2);
  EXPECT_THROW(mtx.SetCols(-1), std::invalid_argument);
}

TEST(CustomMatrixTest_95, SameColumns) {
  CustomMatrix mtx(2, 2);
  mtx.SetCols(2);
  EXPECT_EQ(mtx.GetCols(), 2);
}

TEST(CustomMatrixTest_96, OperatorParenthesesValidIndex) {
  CustomMatrix mtx(2, 2);

  int num = 0;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) mtx(i, j) = ++num;
  }

  EXPECT_EQ(mtx(0, 0), 1);
  EXPECT_EQ(mtx(0, 1), 2);
  EXPECT_EQ(mtx(1, 0), 3);
  EXPECT_EQ(mtx(1, 1), 4);
}

TEST(CustomMatrixTest_97, OperatorParenthesesInvalidIndex) {
  CustomMatrix mtx(2, 2);

  EXPECT_THROW(mtx(-1, 0), std::out_of_range);
  EXPECT_THROW(mtx(0, -1), std::out_of_range);
  EXPECT_THROW(mtx(2, 0), std::out_of_range);
  EXPECT_THROW(mtx(0, 2), std::out_of_range);
}

TEST(CustomMatrixTest_97_2, OperatorParenthesesConstValidIndex) {
  CustomMatrix mtx(2, 2);
  int num = 0;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) mtx(i, j) = ++num;
  }

  const CustomMatrix& const_mtx = mtx;

  EXPECT_EQ(const_mtx(0, 0), 1);
  EXPECT_EQ(const_mtx(0, 1), 2);
  EXPECT_EQ(const_mtx(1, 0), 3);
  EXPECT_EQ(const_mtx(1, 1), 4);
}

TEST(CustomMatrixTest_97_3, OperatorParenthesesConstInvalidIndex) {
  CustomMatrix mtx(2, 2);
  const CustomMatrix& const_mtx = mtx;

  EXPECT_THROW(const_mtx(-1, 0), std::out_of_range);
  EXPECT_THROW(const_mtx(0, -1), std::out_of_range);
  EXPECT_THROW(const_mtx(2, 0), std::out_of_range);
  EXPECT_THROW(const_mtx(0, 2), std::out_of_range);
}

TEST(CustomMatrixTest_98, OperatorAssignmentSameSize) {
  CustomMatrix mtx1(2, 2);
  int num = 0;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) mtx1(i, j) = ++num;
  }

  CustomMatrix mtx2(2, 2);
  mtx2 = mtx1;

  EXPECT_TRUE(mtx1 == mtx2);
}

TEST(CustomMatrixTest_99, SetRowsIncreasesRowCount) {
  CustomMatrix matrix(2, 3);
  matrix.SetRows(4);
  EXPECT_EQ(matrix.GetRows(), 4);
}

TEST(CustomMatrixTest_100, SetColssIncreasesRowCount) {
  CustomMatrix matrix(2, 3);
  matrix.SetCols(4);
  EXPECT_EQ(matrix.GetCols(), 4);
}

TEST(CustomMatrixTest_101, OperatorAssignmentDifferentSize) {
  CustomMatrix mtx1(2, 2);
  int num = 0;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) mtx1(i, j) = ++num;
  }

  CustomMatrix mtx2(3, 3);
  mtx2 = mtx1;

  EXPECT_EQ(mtx2.GetRows(), 2);
  EXPECT_EQ(mtx2.GetCols(), 2);
  EXPECT_EQ(mtx2(0, 0), 1);
  EXPECT_EQ(mtx2(0, 1), 2);
  EXPECT_EQ(mtx2(1, 0), 3);
  EXPECT_EQ(mtx2(1, 1), 4);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}