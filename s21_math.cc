#include <cmath>
#include <iostream>

#include "s21_matrix_oop.h"

bool S21Matrix::EqMatrix(const S21Matrix& other) {
  bool reply = true;
  if (cols_ != other.cols_ || rows_ != other.rows_)
    reply = false;
  else {
    double limit = pow(10, -7);
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        double sub = fabs(matrix_[i][j] - other.matrix_[i][j]);
        if (limit < sub) reply = false;
      }
    }
  }
  return reply;
}

void S21Matrix::SumMatrix(const S21Matrix& other) { SumAndSub(other, 0); }

void S21Matrix::SubMatrix(const S21Matrix& other) { SumAndSub(other, 1); }

void S21Matrix::SumAndSub(const S21Matrix& other, int sign) {
  if (rows_ != other.rows_ || cols_ != other.cols_)
    throw std::invalid_argument("Matrixs has different size");
  else {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        matrix_[i][j] += other.matrix_[i][j] * (double)pow(-1, sign);
      }
    }
  }
}

void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (cols_ != other.rows_)
    throw std::invalid_argument(
        "Matrix's columns isn't equal other matrix's rows");
  else {
    S21Matrix temp(rows_, other.cols_);

    for (int i = 0; i < temp.rows_; i++) {
      for (int j = 0; j < temp.cols_; j++) {
        for (int k = 0; k < cols_; k++) {
          temp.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
        }
      }
    }
    RemoveMatrix();
    rows_ = temp.rows_;
    cols_ = temp.cols_;
    CreateMatrix();
    CopyMatrix(temp);
  }
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix result(cols_, rows_);
  for (int i = 0; i < result.rows_; i++) {
    for (int j = 0; j < result.cols_; j++) {
      result.matrix_[i][j] = matrix_[j][i];
    }
  }
  return result;
}

double S21Matrix::Determinant() {
  double result = 0;
  if (rows_ != cols_)
    throw std::invalid_argument("Matrix is not square");
  else if (rows_ == 1)
    result = matrix_[0][0];
  else if (rows_ == 2) {
    result = (matrix_[0][0] * matrix_[1][1]) - (matrix_[1][0] * matrix_[0][1]);
  } else {
    for (int i = 0; i < cols_; i++) {
      S21Matrix minor = MinorMatrix(0, i);

      double temp_det = minor.Determinant();
      result += pow(-1, i) * matrix_[0][i] * temp_det;
    }
  }
  return result;
}

S21Matrix S21Matrix::CalcComplements() {
  S21Matrix result(rows_, cols_);
  if (rows_ != cols_)
    throw std::invalid_argument("Matrix is not square");
  else if (rows_ == 1)
    result.matrix_[0][0] = matrix_[0][0];
  else {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        S21Matrix minor = MinorMatrix(i, j);
        result.matrix_[i][j] = minor.Determinant() * (double)pow(-1, i + j);
      }
    }
  }
  return result;
}

S21Matrix S21Matrix::MinorMatrix(int rows, int cols) {
  S21Matrix result(rows_ - 1, cols_ - 1);
  for (int i = 0, a = 0; i < rows_; i++) {
    if (i != rows) {
      for (int j = 0, b = 0; j < cols_; j++) {
        if (j != cols) {
          result.matrix_[a][b++] = matrix_[i][j];
        }
      }
      a++;
    }
  }
  return result;
}

S21Matrix S21Matrix::InverseMatrix() {
  if (rows_ != cols_)
    throw std::invalid_argument("Matrix is not square");
  else if (Determinant() == 0)
    throw std::invalid_argument("Determinant of matrix is 0");
  return CalcComplements().Transpose() * (1 / Determinant());
}