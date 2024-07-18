#include "s21_test.h"

TEST(Operator, Plus) {
  S21Matrix A;
  A.FillMatrix(4, 0);
  S21Matrix B;
  B.FillMatrix(9, 0);

  S21Matrix answer = A + B;

  for (int i = 0; i < A.GetRows(); i++) {
    for (int j = 0; j < A.GetCols(); j++) {
      EXPECT_EQ(answer(i, j), 13);
    }
  }
}

TEST(Operator, Minus) {
  S21Matrix A;
  A.FillMatrix(23, 0);
  S21Matrix B;
  B.FillMatrix(11, 0);

  S21Matrix answer = A - B;

  for (int i = 0; i < A.GetRows(); i++) {
    for (int j = 0; j < A.GetCols(); j++) {
      EXPECT_EQ(answer(i, j), 12);
    }
  }
}

TEST(Operator, OperatorMulNumber) {
  S21Matrix A;
  A.FillMatrix(3, 1);

  S21Matrix answer = A * 3;

  int num = 9;
  for (int i = 0; i < A.GetRows(); i++) {
    for (int j = 0; j < A.GetCols(); j++) {
      EXPECT_EQ(answer(i, j), num);
      num += 3;
    }
  }
}

TEST(Operator, OperatorMulMatrix) {
  S21Matrix A(2, 3);
  A.FillMatrix(1, 1);
  S21Matrix B(3, 2);
  B.FillMatrix(1, 1);

  S21Matrix answer = A * B;

  EXPECT_EQ(answer.GetRows(), 2);
  EXPECT_EQ(answer.GetCols(), 2);
  EXPECT_EQ(answer(0, 0), 22);
  EXPECT_EQ(answer(0, 1), 28);
  EXPECT_EQ(answer(1, 0), 49);
  EXPECT_EQ(answer(1, 1), 64);
}

TEST(Operator, Eq) {
  S21Matrix A;
  A.FillMatrix(1, 2);
  S21Matrix B(1, 1);

  B = A;

  EXPECT_TRUE(A == B);
}

TEST(Operator, EqEq) {
  S21Matrix A;
  A.FillMatrix(5, 3);
  S21Matrix B;
  B.FillMatrix(5, 3);

  bool error = false;

  if (!(A == B)) {
    error = true;
  }

  EXPECT_FALSE(error);
}

TEST(Operator, PlusEq) {
  S21Matrix A;
  A.FillMatrix(-6, 0);
  S21Matrix B;
  B.FillMatrix(2, 0);

  A += B;

  for (int i = 0; i < A.GetRows(); i++) {
    for (int j = 0; j < A.GetCols(); j++) {
      EXPECT_EQ(A(i, j), -4);
    }
  }
}

TEST(Operator, MinusEq) {
  S21Matrix A;
  A.FillMatrix(21, 0);
  S21Matrix B;
  B.FillMatrix(7, 0);

  A -= B;

  for (int i = 0; i < A.GetRows(); i++) {
    for (int j = 0; j < A.GetCols(); j++) {
      EXPECT_EQ(A(i, j), 14);
    }
  }
}

TEST(Operator, MulNumberEq) {
  S21Matrix A;
  A.FillMatrix(1, 1);

  A *= 2;

  int num = 2;
  for (int i = 0; i < A.GetRows(); i++) {
    for (int j = 0; j < A.GetCols(); j++) {
      EXPECT_EQ(A(i, j), num);
      num += 2;
    }
  }
}

TEST(Operator, MulMatrixEq) {
  S21Matrix A(2, 3);
  A.FillMatrix(1, 1);
  S21Matrix B(3, 2);
  B.FillMatrix(1, 1);

  A *= B;

  EXPECT_EQ(A.GetRows(), 2);
  EXPECT_EQ(A.GetCols(), 2);
  EXPECT_EQ(A(0, 0), 22);
  EXPECT_EQ(A(0, 1), 28);
  EXPECT_EQ(A(1, 0), 49);
  EXPECT_EQ(A(1, 1), 64);
}

TEST(Operator, Parentheses) {
  bool error = false;
  S21Matrix A;
  A.FillMatrix(1, 1);

  for (int i = 0, num = 1; i < A.GetRows(); i++) {
    for (int j = 0; j < A.GetCols(); j++) {
      EXPECT_EQ(A(i, j), num++);
    }
  }

  try {
    A(0, 1502);
  } catch (const std::exception& e) {
    error = true;
  }
  EXPECT_TRUE(error);

  try {
    A(236, 0);
  } catch (const std::exception& e) {
    error = true;
  }
  EXPECT_TRUE(error);

  try {
    A(583, 666);
  } catch (const std::exception& e) {
    error = true;
  }
  EXPECT_TRUE(error);
}