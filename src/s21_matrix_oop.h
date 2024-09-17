#ifndef __S21MATRIX_H__
#define __S21MATRIX_H__

#include <cmath>
#include <cstring>
#include <iostream>
#include <utility>  // std::move
using namespace std;

class S21Matrix {
 private:
  // Attributes
  int rows_, cols_;  // Rows and columns
  double** matrix_;  // Pointer to the memory where the matrix is allocated
  void s21_fill_matrix_without_i_j(S21Matrix* A, S21Matrix* res, int i_ind,
                                   int j_ind);
  double precision_value = 1e-7;

 public:
  S21Matrix() noexcept;  // Default constructor
  ~S21Matrix();          // Destructor
  S21Matrix(int rows, int cols);  // Параметризированный конструктор с
                                  // количеством строк и столбцов.
  S21Matrix(const S21Matrix& other);  // Конструктор копирования.
  S21Matrix(S21Matrix&& other) noexcept;  // Конструктор переноса.

  // Other methods..
  bool EqMatrix(const S21Matrix& other)
      const;  // Проверяет матрицы на равенство между собой.
  void SumMatrix(
      const S21Matrix& other);  // Прибавляет вторую матрицы к текущей
  void SubMatrix(const S21Matrix& other);  // Вычитает из текущей матрицы другую
  void MulNumber(const double num);  // Умножает текущую матрицу на число.
  void MulMatrix(
      const S21Matrix& other);  // Умножает текущую матрицу на вторую.
  S21Matrix Transpose();  // Создает новую транспонированную матрицу из текущей
                          // и возвращает ее.
  S21Matrix CalcComplements();  // Вычисляет матрицу алгебраических дополнений
                                // текущей матрицы и возвращает ее.
  double Determinant();  // Вычисляет и возвращает определитель текущей матрицы.
  S21Matrix InverseMatrix();

  // help_methods
  const double* const* GetMatrix() const;
  // Метод(accessor), который используется для получения значения
  // приватного поля this->rows_.
  int GetRows() const noexcept;
  // Метод(accessor), который используется для получения значения
  // приватного поля this->сols_.
  int GetCols() const noexcept;

  /// @brief Метод(mutator), который используется для изменения значения
  /// приватной переменной this->rows_. При увеличении размера матрица
  /// дополняется нулевыми элементами, при уменьшении - лишнее просто
  /// отбрасывается;
  /// @param new_rows новое количество строк
  void SetRows(int new_rows);

  /// @brief Метод(mutator), который используется для изменения значения
  /// приватной переменной this->cols_. При увеличении размера матрица
  /// дополняется нулевыми элементами, при уменьшении - лишнее просто
  /// отбрасывается;
  /// @param new_cols новое количество колонок
  void SetCols(int new_cols);

  // operators
  double& operator()(int i, int j);
  S21Matrix& operator=(const S21Matrix& other);
  bool operator==(const S21Matrix& other) const;
  S21Matrix operator+(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other);
  S21Matrix operator*(const S21Matrix& other);
  S21Matrix operator*(const double number);
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix& operator*=(const S21Matrix& other);
  S21Matrix& operator*=(const double number);
};

#endif