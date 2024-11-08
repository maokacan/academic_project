#ifndef CUS_MATRIX_OOP_H_
#define CUS_MATRIX_OOP_H_

#include <iostream>

class CustomMatrix {
 private:
  int rows_, cols_;
  double** matrix_;

  void CreateMatrix();
  void RemoveMatrix();
  void CopyMatrix(const CustomMatrix& other);
  long double custom_fabs(double x);
  void InitMatrix();

 public:
  void GetMinorMatrix(int row, int column, CustomMatrix& other) const;
  double GetMinorSign(int i, int j) const;

  CustomMatrix();
  CustomMatrix(int rows, int cols);
  CustomMatrix(const CustomMatrix& other);
  CustomMatrix(CustomMatrix&& other);
  ~CustomMatrix();

  // getter's
  int GetRows() const;
  int GetCols() const;
  double** GetMatrix() const { return matrix_; };

  // setter's
  void SetRows(int rows);
  void SetCols(int cols);

  void SumMatrix(const CustomMatrix& other);
  bool EqMatrix(const CustomMatrix& other);
  void SubMatrix(const CustomMatrix& other);
  void MulNumber(const double num);
  void MulMatrix(const CustomMatrix& other);
  CustomMatrix Transpose() const;
  CustomMatrix CalcComplements() const;
  CustomMatrix InverseMatrix() const;
  double Determinant() const;

  double& operator()(int row, int col);
  double operator()(int row, int col) const;
  bool operator==(CustomMatrix& other);

  CustomMatrix operator+(const CustomMatrix& other) const;
  CustomMatrix operator-(const CustomMatrix& other) const;
  CustomMatrix operator*(const CustomMatrix& other) const;
  CustomMatrix operator*(double num) const;
  CustomMatrix& operator+=(const CustomMatrix& other);
  CustomMatrix& operator-=(const CustomMatrix& other);
  CustomMatrix& operator*=(const CustomMatrix& other);
  CustomMatrix& operator*=(double num);
  CustomMatrix& operator=(const CustomMatrix& other);
};

#endif  // CUS_MATRIX_OOP_H_