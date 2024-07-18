#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#define EPS 1e-7

class S21Matrix {
 private:
  int rows_, cols_;
  double** matrix_;

  void CreateMatrix();
  void RemoveMatrix();

 public:
  S21Matrix();
  S21Matrix(int r, int c);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);
  ~S21Matrix();

  int GetRows();
  int GetCols();
  void SetRows(int rows);
  void SetCols(int cols);

  bool EqMatrix(const S21Matrix& other);
  void SumAndSub(const S21Matrix& other, int sign);
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose();
  double Determinant();
  S21Matrix CalcComplements();
  S21Matrix InverseMatrix();

  S21Matrix operator+(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other);
  S21Matrix operator*(const S21Matrix& other);
  S21Matrix operator*(const double num);
  bool operator==(const S21Matrix& other);
  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix& operator*=(const S21Matrix& other);
  S21Matrix& operator*=(const double num);
  double& operator()(int i, int j);

  void CopyMatrix(const S21Matrix& temp_matrix);
  S21Matrix MinorMatrix(int rows, int cols);
  void FillMatrix(int a, int b);
};
#endif  // S21_MATRIX_H
