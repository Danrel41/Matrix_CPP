#include "s21_test.h"

TEST(MathematicalFunc, EqMatrix) {
  S21Matrix A;
  A.FillMatrix(2, 1);
  S21Matrix B;
  B.FillMatrix(2, 1);
  S21Matrix C;
  C.FillMatrix(2, 2);

  EXPECT_TRUE(A.EqMatrix(B));
  EXPECT_FALSE(A.EqMatrix(C));

  A.SetRows(5);

  EXPECT_FALSE(A.EqMatrix(B));
}

TEST(MathematicalFunc, SumMatrix) {
  bool error = false;
  S21Matrix A;
  A.FillMatrix(1, 0);
  S21Matrix B;
  B.FillMatrix(2, 0);

  A.SumMatrix(B);

  for (int i = 0; i < A.GetRows(); i++) {
    for (int j = 0; j < A.GetCols(); j++) {
      EXPECT_EQ(A(i, j), 3);
    }
  }

  B.SetCols(4);

  try {
    A.SumMatrix(B);

  } catch (const std::exception& e) {
    error = true;
  }

  EXPECT_TRUE(error);
}

TEST(MathematicalFunc, SubMatrix) {
  bool error = false;
  S21Matrix A;
  A.FillMatrix(9, 0);
  S21Matrix B;
  B.FillMatrix(4, 0);

  A.SubMatrix(B);

  for (int i = 0; i < A.GetRows(); i++) {
    for (int j = 0; j < A.GetCols(); j++) {
      EXPECT_EQ(A(i, j), 5);
    }
  }

  B.SetRows(2);

  try {
    A.SubMatrix(B);

  } catch (const std::exception& e) {
    error = true;
  }

  EXPECT_TRUE(error);
}

TEST(MathematicalFunc, MulNumber) {
  S21Matrix A;
  A.FillMatrix(1, 1);

  A.MulNumber(4);

  int num = 4;
  for (int i = 0; i < A.GetRows(); i++) {
    for (int j = 0; j < A.GetCols(); j++) {
      EXPECT_EQ(A(i, j), num);
      num += 4;
    }
  }
}

TEST(MathematicalFunc, MulMatrix) {
  bool error = false;
  S21Matrix A(2, 3);
  A.FillMatrix(1, 1);
  S21Matrix B(3, 2);
  B.FillMatrix(1, 1);

  A.MulMatrix(B);

  EXPECT_EQ(A.GetRows(), 2);
  EXPECT_EQ(A.GetCols(), 2);
  EXPECT_EQ(A(0, 0), 22);
  EXPECT_EQ(A(0, 1), 28);
  EXPECT_EQ(A(1, 0), 49);
  EXPECT_EQ(A(1, 1), 64);

  A.SetCols(5);

  try {
    A.MulMatrix(B);
  } catch (const std::exception& e) {
    error = true;
  }
  EXPECT_TRUE(error);
}

TEST(MathematicalFunc, Transpose) {
  S21Matrix A;
  A.FillMatrix(2, 2);
  S21Matrix B = A.Transpose();

  for (int i = 0; i < A.GetRows(); i++) {
    for (int j = 0; j < A.GetCols(); j++) {
      EXPECT_EQ(A(i, j), B(j, i));
    }
  }
}

TEST(MathematicalFunc, Determinant) {
  bool error = false;
  S21Matrix A;
  A.FillMatrix(1, 1);

  double num = A.Determinant();
  EXPECT_EQ(num, 0.0);

  A.SetRows(1);
  A.SetCols(1);

  num = A.Determinant();
  EXPECT_EQ(num, 1);

  A.SetRows(3);

  try {
    A.Determinant();
  } catch (const std::exception& e) {
    error = true;
  }
  EXPECT_TRUE(error);
}

TEST(MathematicalFunc, CalcComplements) {
  bool error = false;
  S21Matrix A;
  A.FillMatrix(2, 2);
  S21Matrix B = A.CalcComplements();

  EXPECT_EQ(B(0, 0), -12);
  EXPECT_EQ(B(0, 1), 24);
  EXPECT_EQ(B(0, 2), -12);
  EXPECT_EQ(B(1, 0), 24);
  EXPECT_EQ(B(1, 1), -48);
  EXPECT_EQ(B(1, 2), 24);
  EXPECT_EQ(B(2, 0), -12);
  EXPECT_EQ(B(2, 1), 24);
  EXPECT_EQ(B(2, 2), -12);

  A.SetCols(1);
  A.SetRows(1);
  S21Matrix C = A.CalcComplements();

  EXPECT_EQ(C(0, 0), 2);

  B.SetCols(2);
  B.SetRows(3);
  B.FillMatrix(1, 1);

  try {
    B.CalcComplements();

  } catch (const std::exception& e) {
    error = true;
  }
  EXPECT_TRUE(error);
}

TEST(MathematicalFunc, InverseMatrix) {
  bool error = false;
  S21Matrix A;
  A(0, 0) = -0.25;
  A(0, 1) = -0.125;
  A(0, 2) = 0.75;
  A(1, 0) = -0.25;
  A(1, 1) = 0.375;
  A(1, 2) = -0.25;
  A(2, 0) = 0.75;
  A(2, 1) = -0.125;
  A(2, 2) = -0.25;

  S21Matrix B = A.InverseMatrix();

  EXPECT_EQ(B(0, 0), 1);
  EXPECT_EQ(B(0, 1), 1);
  EXPECT_EQ(B(0, 2), 2);
  EXPECT_EQ(B(1, 0), 2);
  EXPECT_EQ(B(1, 1), 4);
  EXPECT_EQ(B(1, 2), 2);
  EXPECT_EQ(B(2, 0), 2);
  EXPECT_EQ(B(2, 1), 1);
  EXPECT_EQ(B(2, 2), 1);

  A.FillMatrix(1, 1);

  try {
    A.InverseMatrix();
  } catch (const std::exception& e) {
    error = true;
  }
  EXPECT_TRUE(error);

  A.SetRows(5);

  try {
    A.InverseMatrix();
  } catch (const std::exception& e) {
    error = true;
  }
  EXPECT_TRUE(error);
}