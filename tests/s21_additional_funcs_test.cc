#include "s21_test.h"

TEST(AccessorMutator, SetGetRows) {
  bool error = false;
  S21Matrix A;
  A.FillMatrix(1, 1);
  A.SetRows(7);

  EXPECT_EQ(A.GetRows(), 7);
  EXPECT_EQ(A.GetCols(), 3);

  int num = 1;

  for (int i = 0; i < A.GetRows(); i++) {
    for (int j = 0; j < A.GetCols(); j++) {
      if (i < 3 && j < 3) {
        EXPECT_EQ(A(i, j), num++);

      } else {
        EXPECT_EQ(A(i, j), 0);
      }
    }
  }

  try {
    A.SetRows(-3);
  } catch (const std::exception& e) {
    error = true;
  }

  EXPECT_TRUE(error);
}

TEST(AccessorMutator, SetGetCols) {
  bool error = false;
  S21Matrix A;
  A.FillMatrix(1, 1);
  A.SetCols(4);

  EXPECT_EQ(A.GetRows(), 3);
  EXPECT_EQ(A.GetCols(), 4);

  int num = 1;

  for (int i = 0; i < A.GetRows(); i++) {
    for (int j = 0; j < A.GetCols(); j++) {
      if (i < 3 && j < 3) {
        EXPECT_EQ(A(i, j), num++);

      } else {
        EXPECT_EQ(A(i, j), 0);
      }
    }
  }

  try {
    A.SetCols(0);
  } catch (const std::exception& e) {
    error = true;
  }

  EXPECT_TRUE(error);
}