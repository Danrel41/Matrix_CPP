#include <iostream>

#include "s21_matrix_oop.h"

S21Matrix S21Matrix::operator+(const S21Matrix& other) {
  S21Matrix reply(*this);
  S21Matrix answer(std::move(reply));
  answer.SumMatrix(other);
  return answer;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) {
  S21Matrix reply(*this);
  S21Matrix answer(std::move(reply));
  answer.SubMatrix(other);
  return answer;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) {
  S21Matrix reply(*this);
  S21Matrix answer(std::move(reply));
  answer.MulMatrix(other);
  return answer;
  // S21Matrix reply(std::move(*this));
  // reply.MulMatrix(other);
  // return reply;
}

S21Matrix S21Matrix::operator*(const double num) {
  S21Matrix reply(*this);
  S21Matrix answer(std::move(reply));
  answer.MulNumber(num);
  return answer;
  // S21Matrix reply(*this);
  // reply.MulNumber(num);
  // return reply;
}

bool S21Matrix::operator==(const S21Matrix& other) { return EqMatrix(other); }

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  if (!(*this == other)) {
    RemoveMatrix();
    rows_ = other.rows_;
    cols_ = other.cols_;
    CreateMatrix();
    CopyMatrix(other);
  }
  return *this;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  SumMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  SubMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  MulMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const double num) {
  MulNumber(num);
  return *this;
}

double& S21Matrix::operator()(int i, int j) {
  if (i < 0 || j < 0 || i >= rows_ || j >= cols_)
    throw std::out_of_range{"S21Matrix::operator()"};
  return matrix_[i][j];
}