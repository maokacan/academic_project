#include "./custom_matrix_oop.h"

long double CustomMatrix::custom_fabs(double x) {
  if (x < 0) x *= -1.0;
  return x;
}

void CustomMatrix::CreateMatrix() {
  matrix_ = new double*[rows_];
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_];
  }
}

void CustomMatrix::RemoveMatrix() {
  for (int i = 0; i < rows_; i++) {
    delete[] matrix_[i];
  }
  delete[] matrix_;
  rows_ = 0;
  cols_ = 0;
  matrix_ = nullptr;
}

void CustomMatrix::CopyMatrix(const CustomMatrix& other) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

void CustomMatrix::InitMatrix() {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = 0.0;
    }
  }
}
CustomMatrix::CustomMatrix() : rows_(3), cols_(3) {
  CreateMatrix();
  InitMatrix();
}

CustomMatrix::CustomMatrix(int rows, int cols) : rows_(rows), cols_(cols) {
  CreateMatrix();
  InitMatrix();
}

CustomMatrix::CustomMatrix(const CustomMatrix& other)
    : rows_(other.rows_), cols_(other.cols_) {
  CreateMatrix();
  CopyMatrix(other);
}

CustomMatrix::CustomMatrix(CustomMatrix&& other)
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
}

CustomMatrix::~CustomMatrix() { RemoveMatrix(); }

void CustomMatrix::SetRows(int rows) {
  if (rows <= 0) {
    throw std::invalid_argument("пупупу");
  }
  if (rows != rows_) {
    int temp = rows_, temp2 = cols_;
    CustomMatrix tempMtrx(rows, cols_);
    for (int i = 0; i < temp; i++) {
      for (int j = 0; j < temp2; j++) {
        tempMtrx(i, j) = matrix_[i][j];
      }
    }
    RemoveMatrix();
    rows_ = rows;
    cols_ = temp2;
    CreateMatrix();
    for (int i = 0; i < temp; i++) {
      for (int j = 0; j < temp2; j++) {
        matrix_[i][j] = tempMtrx(i, j);
      }
    }
    tempMtrx.RemoveMatrix();
  }
}

void CustomMatrix::SetCols(int cols) {
  if (cols <= 0) {
    throw std::invalid_argument("пупупу");
  }
  if (cols != cols_) {
    int temp = rows_, temp2 = cols_;
    CustomMatrix tempMtrx(rows_, cols);
    for (int i = 0; i < temp; i++) {
      for (int j = 0; j < temp2; j++) {
        tempMtrx(i, j) = matrix_[i][j];
      }
    }
    RemoveMatrix();
    cols_ = cols;
    rows_ = temp;
    CreateMatrix();
    for (int i = 0; i < temp; i++) {
      for (int j = 0; j < temp2; j++) {
        matrix_[i][j] = tempMtrx(i, j);
      }
    }
    tempMtrx.RemoveMatrix();
  }
}

int CustomMatrix::GetRows() const { return rows_; };
int CustomMatrix::GetCols() const { return cols_; };

void CustomMatrix::SumMatrix(const CustomMatrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::invalid_argument("пупупу");
  }

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] += other.matrix_[i][j];
    }
  }
}

bool CustomMatrix::EqMatrix(const CustomMatrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    return false;
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      if (custom_fabs(matrix_[i][j] - other.matrix_[i][j]) > 1e-7) {
        return false;
      }
    }
  }

  return true;
}

void CustomMatrix::SubMatrix(const CustomMatrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::invalid_argument("пупупу");
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] -= other.matrix_[i][j];
    }
  }
}

void CustomMatrix::MulNumber(const double num) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] *= num;
    }
  }
}

void CustomMatrix::MulMatrix(const CustomMatrix& other) {
  if (cols_ != other.rows_) {
    throw std::invalid_argument("Вот тебе и пироги! Ошибочка!");
  }
  CustomMatrix result(rows_, other.cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < other.cols_; j++) {
      result.matrix_[i][j] = 0.0;
      for (int k = 0; k < cols_; k++) {
        result.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
      }
    }
  }
  *this = result;
}

CustomMatrix CustomMatrix::Transpose() const {
  CustomMatrix result(cols_, rows_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      result.matrix_[j][i] = matrix_[i][j];
    }
  }
  return result;
}

double CustomMatrix::Determinant() const {
  if (rows_ != cols_) {
    throw std::invalid_argument(
        "Matrix must be square to compute determinant.");
  }

  double determinant = 0.0;
  if (rows_ == 1) {
    return matrix_[0][0];
  } else if (rows_ == 2) {
    return matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
  } else {
    for (int i = 0; i < rows_; i++) {
      CustomMatrix minor_matrix(rows_ - 1, cols_ - 1);
      GetMinorMatrix(0, i, minor_matrix);
      double minor = minor_matrix.Determinant();
      double minor_sign = GetMinorSign(0, i);
      determinant += matrix_[0][i] * minor * minor_sign;
    }
  }

  return determinant;
}
void CustomMatrix::GetMinorMatrix(int row, int column, CustomMatrix& other) const {
  int m_i = 0, m_j = 0;
  for (int i = 0; i < rows_; i++) {
    if (i != row) {
      m_j = 0;
      for (int j = 0; j < cols_; j++) {
        if (j != column) {
          other.matrix_[m_i][m_j++] = matrix_[i][j];
        }
      }
      m_i++;
    }
  }
}

double CustomMatrix::GetMinorSign(int i, int j) const {
  return (i + j) % 2 == 0 ? 1.0 : -1.0;
}

CustomMatrix CustomMatrix::CalcComplements() const {
  if (rows_ != cols_) {
    throw std::invalid_argument(
        "Matrix must be square to calculate complements.");
  }

  CustomMatrix result(rows_, cols_);
  if (rows_ == 1) {
    result.matrix_[0][0] = 1;
    return result;
  }

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      CustomMatrix minor(rows_ - 1, cols_ - 1);
      GetMinorMatrix(i, j, minor);
      result.matrix_[i][j] = minor.Determinant() * GetMinorSign(i, j);
    }
  }

  return result;
}

CustomMatrix CustomMatrix::InverseMatrix() const {
  double det = Determinant();
  if (det == 0) {
    throw std::invalid_argument(
        "Matrix determinant is zero, inverse does not exist.");
  }

  CustomMatrix complements = CalcComplements();
  CustomMatrix adjugate = complements.Transpose();
  CustomMatrix inverse(rows_, cols_);

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      inverse.matrix_[i][j] = adjugate.matrix_[i][j] / det;
    }
  }

  return inverse;
}

double& CustomMatrix::operator()(int row, int col) {
  if (row < 0 || row >= rows_ || col < 0 || col >= cols_) {
    throw std::out_of_range("Index out of range");
  }

  return matrix_[row][col];
}

double CustomMatrix::operator()(int row, int col) const {
  if (row < 0 || col < 0 || row >= rows_ || col >= cols_) {
    throw std::out_of_range("Index is out of range");
  }
  return matrix_[row][col];
}

bool CustomMatrix::operator==(CustomMatrix& other) { return EqMatrix(other); }

CustomMatrix CustomMatrix::operator+(const CustomMatrix& other) const {
  CustomMatrix result(*this);
  result.SumMatrix(other);
  return result;
}

CustomMatrix CustomMatrix::operator-(const CustomMatrix& other) const {
  CustomMatrix result(*this);
  result.SubMatrix(other);
  return result;
}

CustomMatrix CustomMatrix::operator*(double num) const {
  CustomMatrix result(*this);
  result.MulNumber(num);
  return result;
}

CustomMatrix CustomMatrix::operator*(const CustomMatrix& other) const {
  CustomMatrix result(*this);
  result.MulMatrix(other);
  return result;
}

CustomMatrix& CustomMatrix::operator+=(const CustomMatrix& other) {
  SumMatrix(other);
  return *this;
}

CustomMatrix& CustomMatrix::operator-=(const CustomMatrix& other) {
  SubMatrix(other);
  return *this;
}

CustomMatrix& CustomMatrix::operator*=(double num) {
  MulNumber(num);
  return *this;
}

CustomMatrix& CustomMatrix::operator*=(const CustomMatrix& other) {
  MulMatrix(other);
  return *this;
}

CustomMatrix& CustomMatrix::operator=(const CustomMatrix& other) {
  if (this == &other) {
    return *this;
  }

  RemoveMatrix();
  rows_ = other.rows_;
  cols_ = other.cols_;
  CreateMatrix();
  CopyMatrix(other);

  return *this;
}