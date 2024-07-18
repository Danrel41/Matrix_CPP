#include "s21_test.h"

TEST(Constructors, Default) {
  S21Matrix A;

  EXPECT_EQ(A.GetRows(), 3);
  EXPECT_EQ(A.GetCols(), 3);

  for (int i = 0; i < A.GetRows(); i++) {
    for (int j = 0; j < A.GetCols(); j++) {
      EXPECT_EQ(A(i, j), 0);
    }
  }
}

TEST(Constructors, WithParameters) {
  bool error = false;
  S21Matrix A(4, 6);

  EXPECT_EQ(A.GetRows(), 4);
  EXPECT_EQ(A.GetCols(), 6);

  for (int i = 0; i < A.GetRows(); i++) {
    for (int j = 0; j < A.GetCols(); j++) {
      EXPECT_EQ(A(i, j), 0);
    }
  }

  try {
    S21Matrix B(-2, -5);

  } catch (const std::exception& e) {
    error = true;
  }

  EXPECT_TRUE(error);
}

TEST(Constructors, Copy) {
  S21Matrix A(3, 3);
  A.FillMatrix(1, 1);

  S21Matrix B(A);

  EXPECT_TRUE(A.EqMatrix(B));
}

TEST(Constructors, Move) {
  S21Matrix A(3, 3);
  A.FillMatrix(1, 1);

  S21Matrix copy_A(A);

  S21Matrix B(std::move(A));

  EXPECT_TRUE(B.EqMatrix(copy_A));
  EXPECT_EQ(A.GetRows(), 0);
  EXPECT_EQ(A.GetCols(), 0);
}

TEST(Constructors, CopyMatrix) {
  S21Matrix A(5, 3);
  A.FillMatrix(1, 1);

  S21Matrix B(5, 3);
  B.CopyMatrix(A);

  EXPECT_EQ(A(2, 2), B(2, 2));
  EXPECT_EQ(A(4, 1), B(4, 1));
}