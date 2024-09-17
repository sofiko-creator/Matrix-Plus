#include <gtest/gtest.h>

#include <exception>

#include "../s21_matrix_oop.h"

TEST(test_get_set, test_GetRowsCols_accessor) {
  S21Matrix obj(22, 11);
  EXPECT_DOUBLE_EQ(obj.GetRows(), 22);
  EXPECT_DOUBLE_EQ(obj.GetCols(), 11);

  S21Matrix obj1;
  EXPECT_DOUBLE_EQ(obj1.GetRows(), 0);
  EXPECT_DOUBLE_EQ(obj1.GetCols(), 0);
}

TEST(test_get_set, test_SetCols_mutator) {
  S21Matrix obj(2, 3);
  obj(0, 0) = 0.1;
  obj(0, 1) = 0.2;
  obj(0, 2) = 0.3;
  obj(1, 0) = 0.4;
  obj(1, 1) = 0.5;
  obj(1, 2) = 0.6;

  obj.SetCols(5);
  S21Matrix obj1(2, 5);
  obj1(0, 0) = 0.1;
  obj1(0, 1) = 0.2;
  obj1(0, 2) = 0.3;
  obj1(0, 3) = 0.0;
  obj1(0, 4) = 0.0;

  obj1(1, 0) = 0.4;
  obj1(1, 1) = 0.5;
  obj1(1, 2) = 0.6;
  obj1(1, 3) = 0.0;
  obj1(1, 4) = 0.0;
  EXPECT_EQ(obj1.EqMatrix(obj), true);

  obj.SetCols(1);

  S21Matrix obj2(2, 1);
  obj2(0, 0) = 0.1;
  obj2(1, 0) = 0.4;
  EXPECT_EQ(obj2.EqMatrix(obj), true);

  obj.SetCols(4);
  S21Matrix obj3(2, 4);
  obj3(0, 0) = 0.1;
  obj3(0, 1) = 0.0;
  obj3(0, 2) = 0.0;
  obj3(0, 3) = 0.0;

  obj3(1, 0) = 0.4;
  obj3(1, 1) = 0.0;
  obj3(1, 2) = 0.0;
  obj3(1, 3) = 0.0;

  EXPECT_EQ(obj3.EqMatrix(obj), true);

  EXPECT_THROW(obj.SetCols(0), range_error);
  EXPECT_THROW(obj.SetCols(-1), range_error);
  EXPECT_THROW(obj.SetCols(-999), range_error);
  obj.SetCols(4);
  EXPECT_EQ(obj3.EqMatrix(obj), true);
}

TEST(test_get_set, test_SetRows_mutator) {
  S21Matrix obj(2, 3);
  obj(0, 0) = 0.1;
  obj(0, 1) = 0.2;
  obj(0, 2) = 0.3;

  obj(1, 0) = 0.4;
  obj(1, 1) = 0.5;
  obj(1, 2) = 0.6;

  obj.SetRows(5);
  S21Matrix obj1(5, 3);
  obj1(0, 0) = 0.1;
  obj1(0, 1) = 0.2;
  obj1(0, 2) = 0.3;

  obj1(1, 0) = 0.4;
  obj1(1, 1) = 0.5;
  obj1(1, 2) = 0.6;

  obj1(2, 0) = 0.0;
  obj1(2, 1) = 0.0;
  obj1(2, 2) = 0.0;

  obj1(3, 0) = 0.0;
  obj1(3, 1) = 0.0;
  obj1(3, 2) = 0.0;

  obj1(4, 0) = 0.0;
  obj1(4, 1) = 0.0;
  obj1(4, 2) = 0.0;

  EXPECT_EQ(obj1.EqMatrix(obj), true);

  obj.SetRows(1);

  S21Matrix obj2(1, 3);
  obj2(0, 0) = 0.1;
  obj2(0, 1) = 0.2;
  obj2(0, 2) = 0.3;
  EXPECT_EQ(obj2.EqMatrix(obj), true);

  EXPECT_THROW(obj.SetRows(0), range_error);
  EXPECT_THROW(obj.SetRows(-1), range_error);
  EXPECT_THROW(obj.SetRows(-999), range_error);
  obj.SetRows(1);
  EXPECT_EQ(obj2.EqMatrix(obj), true);

  obj.SetRows(5);

  S21Matrix obj3(5, 3);
  obj3(0, 0) = 0.1;
  obj3(0, 1) = 0.2;
  obj3(0, 2) = 0.3;

  obj3(1, 0) = 0.0;
  obj3(1, 1) = 0.0;
  obj3(1, 2) = 0.0;

  obj3(2, 0) = 0.0;
  obj3(2, 1) = 0.0;
  obj3(2, 2) = 0.0;

  obj3(3, 0) = 0.0;
  obj3(3, 1) = 0.0;
  obj3(3, 2) = 0.0;

  obj3(4, 0) = 0.0;
  obj3(4, 1) = 0.0;
  obj3(4, 2) = 0.0;
  EXPECT_EQ(obj3.EqMatrix(obj), true);
}