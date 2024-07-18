#include <iostream>

#include "s21_matrix_oop.h"

void S21Matrix::CreateMatrix() {
  if (rows_ <= 0 || cols_ <= 0)
    throw std::out_of_range{"S21Matrix::CreateMatrix()"};
  else {
    matrix_ = new double* [rows_] {};
    for (int i = 0; i < rows_; i++) {
      matrix_[i] = new double[cols_]{};
    }
  }
}

void S21Matrix::RemoveMatrix() {
  if (matrix_ != nullptr) {
    for (int i{}; i < rows_; i++) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
  }
}

S21Matrix::S21Matrix() {
  rows_ = 3;
  cols_ = 3;
  CreateMatrix();
}

S21Matrix::S21Matrix(int rows, int cols) {
  rows_ = rows;
  cols_ = cols;
  CreateMatrix();
}

S21Matrix::S21Matrix(const S21Matrix& other) {
  rows_ = other.rows_;
  cols_ = other.cols_;
  CreateMatrix();
  for (int i = 0; i < other.rows_; i++) {
    for (int j = 0; j < other.cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

S21Matrix::S21Matrix(S21Matrix&& other) {
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = other.matrix_;
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
}

S21Matrix::~S21Matrix() { RemoveMatrix(); }

void S21Matrix::FillMatrix(int a, int b) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = a;
      a += b;
    }
  }
}

void S21Matrix::CopyMatrix(const S21Matrix& temp_matrix) {
  for (int i = 0; i < temp_matrix.rows_; i++) {
    for (int j = 0; j < temp_matrix.cols_; j++) {
      if (i < rows_ && j < cols_) matrix_[i][j] = temp_matrix.matrix_[i][j];
    }
  }
}