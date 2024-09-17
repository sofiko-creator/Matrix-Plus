#include "s21_matrix_oop.h"

// Constructors
S21Matrix::S21Matrix() noexcept {
  rows_ = 0;
  cols_ = 0;
  matrix_ = nullptr;
}

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  if ((rows_ <= 0) || (cols_ <= 0))
    throw range_error("Incorrect input rows or columns");  // exception
  // Выделение памяти для массива указателей
  matrix_ = new double*[rows_];
  // Выделение памяти для каждого ряда
  for (int i = 0; i < rows_; ++i) {
    matrix_[i] = new double[cols_];
  }
  // Заполнение нулями
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = 0;
    }
  }
}

S21Matrix::S21Matrix(const S21Matrix& other)
    : rows_(other.rows_), cols_(other.cols_) {
  if ((rows_ == 0) && (cols_ == 0)) {
    matrix_ = nullptr;
  }
  if ((rows_ > 0) && (cols_ > 0)) {
    // Выделение памяти для массива указателей
    matrix_ = new double*[rows_];
    // Выделение памяти для каждого ряда
    for (int i = 0; i < rows_; ++i) {
      matrix_[i] = new double[cols_];
    }
    // Копирование значений из другой матрицы
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        matrix_[i][j] = other.matrix_[i][j];
      }
    }
  }
}

S21Matrix::S21Matrix(S21Matrix&& other) noexcept
    : rows_{other.rows_}, cols_{other.cols_}, matrix_(other.matrix_) {
  other.matrix_ = nullptr;
  other.rows_ = 0;
  other.cols_ = 0;
}

S21Matrix::~S21Matrix() noexcept {
  if (matrix_) {
    for (int i = 0; i < rows_; ++i) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
  }
}

// Methods

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if ((rows_ != other.rows_) || (cols_ != other.cols_)) {
    throw out_of_range(
        "Incorrect input, matrices should have the same size");  // exception
  }
  if (matrix_ && other.matrix_) {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        matrix_[i][j] = matrix_[i][j] + other.matrix_[i][j];
      }
    }
  }
}

bool S21Matrix::EqMatrix(const S21Matrix& other) const {
  bool result = true;
  if ((rows_ != other.rows_) || (cols_ != other.cols_)) {
    result = false;
  } else {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        if (abs(matrix_[i][j] - other.matrix_[i][j]) > precision_value) {
          result = false;
        }
      }
    }
  }
  return result;
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if ((rows_ != other.rows_) || (cols_ != other.cols_)) {
    throw out_of_range(
        "Incorrect input, matrices should have the same size");  // exception
  }
  if (matrix_ && other.matrix_) {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        matrix_[i][j] = matrix_[i][j] - other.matrix_[i][j];
      }
    }
  }
}

void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = matrix_[i][j] * num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (cols_ != other.rows_) {
    throw out_of_range(
        "Incorrect input, matrices should have the same size");  // exception
  }
  if (matrix_ && other.matrix_) {
    int k = cols_;
    cols_ = other.cols_;
    double** result_matrix = nullptr;

    result_matrix = new double*[rows_];
    for (int i = 0; i < rows_; i++) {
      result_matrix[i] = new double[cols_];
    }

    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        result_matrix[i][j] = 0;
        for (int p = 0; p < k; p++) {
          result_matrix[i][j] += matrix_[i][p] * other.matrix_[p][j];
        }
      }
    }

    for (int i = 0; i < rows_; i++) {
      delete[] matrix_[i];
    }
    delete[] matrix_;

    matrix_ = result_matrix;
  }
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix ret_obj(cols_, rows_);
  for (int i = 0; i < cols_; i++) {
    for (int j = 0; j < rows_; j++) {
      ret_obj.matrix_[i][j] = matrix_[j][i];
    }
  }
  return ret_obj;
}

void S21Matrix::s21_fill_matrix_without_i_j(S21Matrix* A, S21Matrix* res,
                                            int i_ind, int j_ind) {
  int a = 0, b = 0;
  for (int i = 0; i < A->rows_; i++) {
    for (int j = 0; j < A->cols_; j++) {
      if (i != i_ind && j != j_ind) {
        res->matrix_[a][b] = A->matrix_[i][j];
        b++;
      }
    }
    if (i != i_ind) {
      a++;
      b = 0;
    }
  }
}

double S21Matrix::Determinant() {
  if (cols_ != rows_)
    throw logic_error("Matrix must be square to compute the determinant");
  if (cols_ == 0) {
    return 0.0;
  }
  if (cols_ == 1) {
    return matrix_[0][0];
  } else if (cols_ == 2) {
    return matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
  } else {
    double ret_value = 0;
    S21Matrix temp_matrix(cols_ - 1, rows_ - 1);
    int sign = 1;

    for (int j = 0; j < cols_; ++j) {
      s21_fill_matrix_without_i_j(this, &temp_matrix, 0, j);
      ret_value += sign * matrix_[0][j] * temp_matrix.Determinant();
      sign = -sign;
    }

    return ret_value;
  }
}

S21Matrix S21Matrix::CalcComplements() {
  if (cols_ != rows_)
    throw logic_error("Matrix must be square to calculate complements");

  S21Matrix ret_obj(rows_, cols_);
  if (rows_ == 1) {
    ret_obj.matrix_[0][0] = 1;
  } else {
    S21Matrix temp_matrix(rows_ - 1, cols_ - 1);
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        s21_fill_matrix_without_i_j(this, &temp_matrix, i, j);
        ret_obj.matrix_[i][j] = pow(-1, i + j) * temp_matrix.Determinant();
      }
    }
  }

  return ret_obj;
}

S21Matrix S21Matrix::InverseMatrix() {
  if (cols_ != rows_)
    throw logic_error("Matrix must be square to calculate inverse matrix");
  double det = Determinant();
  if (fabs(det) < precision_value) {
    throw invalid_argument("The determinant is zero!");
  }
  S21Matrix calc_complements_matrix = CalcComplements();
  S21Matrix transpose_matrix = calc_complements_matrix.Transpose();
  S21Matrix ret_obj(rows_, cols_);
  if (rows_ > 1) {
    transpose_matrix.MulNumber(1. / Determinant());
    ret_obj = transpose_matrix;
  } else {
    ret_obj.matrix_[0][0] = 1. / det;
  }
  return ret_obj;
}

// Help Methods
int S21Matrix::GetRows() const noexcept {
  int rows_copy = rows_;
  return rows_copy;
}

int S21Matrix::GetCols() const noexcept {
  int cols_copy = cols_;
  return cols_copy;
}

const double* const* S21Matrix::GetMatrix() const { return matrix_; }

void S21Matrix::SetRows(int new_rows) {
  if (new_rows != rows_) {
    if (new_rows <= 0) throw range_error("Value is not positive!");
    S21Matrix obj(new_rows, cols_);
    int min = 0;
    if (rows_ < new_rows) {
      min = rows_;
    } else {
      min = new_rows;
    }
    for (int i = 0; i < min; i++) {
      for (int j = 0; j < cols_; j++) {
        obj(i, j) = (*this)(i, j);
      }
    }
    *this = move(obj);  // Перемещаем временную матрицу в текущую
  }
}

void S21Matrix::SetCols(int new_cols) {
  if (new_cols != cols_) {
    if (new_cols <= 0) throw range_error("Value is not positive!");
    S21Matrix obj(rows_, new_cols);
    int min = 0;
    if (cols_ < new_cols) {
      min = cols_;
    } else {
      min = new_cols;
    }
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < min; j++) {
        obj(i, j) = (*this)(i, j);
      }
    }
    *this = move(obj);  // Перемещаем временную матрицу в текущую
  }
}

// Operators
double& S21Matrix::operator()(int i, int j) {
  if (i < 0 || j < 0 || i >= rows_ || j >= cols_) {
    throw range_error("Incorrect input index");
  }
  return matrix_[i][j];
}

bool S21Matrix::operator==(const S21Matrix& other) const {
  return EqMatrix(other);
}

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  if (this == (&other)) return (*this);
  if (matrix_) {
    for (int i = 0; i < rows_; i++) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
  }
  rows_ = other.rows_;
  cols_ = other.cols_;
  if (other.matrix_ == nullptr) {
    this->matrix_ = nullptr;
  } else {
    // Выделение памяти для массива указателей
    matrix_ = new double*[rows_];
    // Выделение памяти для каждого ряда
    for (int i = 0; i < rows_; i++) {
      matrix_[i] = new double[cols_];
    }
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        matrix_[i][j] = other.matrix_[i][j];
      }
    }
  }
  return (*this);
}

S21Matrix S21Matrix::operator+(const S21Matrix& other) {
  S21Matrix result(*this);
  result.SumMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) {
  S21Matrix result(*this);
  result.SubMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) {
  S21Matrix result(*this);
  result.MulMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(const double number) {
  S21Matrix result(*this);
  result.MulNumber(number);
  return result;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  SumMatrix(other);
  return (*this);
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  SubMatrix(other);
  return (*this);
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  MulMatrix(other);
  return (*this);
}

S21Matrix& S21Matrix::operator*=(const double number) {
  MulNumber(number);
  return (*this);
}
