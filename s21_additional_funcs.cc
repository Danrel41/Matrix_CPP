#include <iostream>

#include "s21_matrix_oop.h"

int S21Matrix::GetRows() { return rows_; }

int S21Matrix::GetCols() { return cols_; }

void S21Matrix::SetRows(int rows) {
  if (rows <= 0)
    throw std::invalid_argument("Incorrect rows");
  else if (rows_ != rows) {
    S21Matrix temp_matrix(*this);
    RemoveMatrix();
    rows_ = rows;
    CreateMatrix();
    CopyMatrix(temp_matrix);
  }
}

void S21Matrix::SetCols(int cols) {
  if (cols <= 0)
    throw std::invalid_argument("Incorrect cols");
  else if (cols_ != cols) {
    S21Matrix temp_matrix(*this);
    RemoveMatrix();
    cols_ = cols;
    CreateMatrix();
    CopyMatrix(temp_matrix);
  }
}