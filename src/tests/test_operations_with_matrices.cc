#include <gtest/gtest.h>

#include <exception>

#include "../s21_matrix_oop.h"

TEST(test_operations_with_matrices, test_EqMatrix) {
  S21Matrix obj;
  S21Matrix obj1;
  EXPECT_EQ(obj.EqMatrix(obj1), true);

  S21Matrix obj2(2, 3);
  EXPECT_EQ(obj2.EqMatrix(obj), false);

  S21Matrix obj3(2, 3);
  obj3(0, 0) = 0.1;
  obj3(0, 1) = 0.2;
  obj3(0, 2) = 0.3;
  obj3(1, 0) = 0.4;
  obj3(1, 1) = 0.5;
  obj3(1, 2) = 0.6;
  S21Matrix obj4(obj3);
  EXPECT_EQ(obj3.EqMatrix(obj4), true);

  S21Matrix obj5(2, 3);
  obj5(0, 0) = 0.11;
  obj5(0, 1) = 0.2778;
  obj5(0, 2) = 0.38;
  obj5(1, 0) = 0.4;
  obj5(1, 1) = 0.5;
  obj5(1, 2) = 0.6;
  EXPECT_EQ(obj3.EqMatrix(obj5), false);

  S21Matrix obj6(2, 3);
  obj6(0, 0) = 0.1000001;
  obj6(0, 1) = 0.2;
  obj6(0, 2) = 0.3;
  obj6(1, 0) = 0.4;
  obj6(1, 1) = 0.5;
  obj6(1, 2) = 0.6;
  EXPECT_EQ(obj3.EqMatrix(obj6), true);

  obj6(0, 0) = 0.10000001;
  obj6(0, 1) = 0.2;
  obj6(0, 2) = 0.3;
  obj6(1, 0) = 0.4;
  obj6(1, 1) = 0.5;
  obj6(1, 2) = 0.6;
  EXPECT_EQ(obj3.EqMatrix(obj6), true);

  obj6(0, 0) = 0.10000011;
  obj6(0, 1) = 0.2;
  obj6(0, 2) = 0.3;
  obj6(1, 0) = 0.4;
  obj6(1, 1) = 0.5;
  obj6(1, 2) = 0.6;
  EXPECT_EQ(obj3.EqMatrix(obj6), false);
}

TEST(test_operations_with_matrices, test_SumMatrix) {
  S21Matrix obj;
  S21Matrix obj1;
  obj.SumMatrix(obj1);
  EXPECT_EQ(obj.GetRows(), 0);
  EXPECT_EQ(obj.GetCols(), 0);
  EXPECT_EQ(obj.GetMatrix(), nullptr);

  S21Matrix obj2(2, 3);
  obj2(0, 0) = 0.1;
  obj2(0, 1) = 0.2;
  obj2(0, 2) = 0.3;
  obj2(1, 0) = 0.4;
  obj2(1, 1) = 0.5;
  obj2(1, 2) = 0.6;
  EXPECT_THROW(obj.SumMatrix(obj2), out_of_range);

  S21Matrix obj3(2, 3);
  obj3(0, 0) = 0.01;
  obj3(0, 1) = 0.02;
  obj3(0, 2) = 0.03;
  obj3(1, 0) = 0.04;
  obj3(1, 1) = 0.05;
  obj3(1, 2) = 0.06;

  obj2.SumMatrix(obj3);

  EXPECT_DOUBLE_EQ(obj2(0, 0), 0.11);
  EXPECT_DOUBLE_EQ(obj2(0, 1), 0.22);
  EXPECT_DOUBLE_EQ(obj2(0, 2), 0.33);

  EXPECT_DOUBLE_EQ(obj2(1, 0), 0.44);
  EXPECT_DOUBLE_EQ(obj2(1, 1), 0.55);
  EXPECT_DOUBLE_EQ(obj2(1, 2), 0.66);

  EXPECT_DOUBLE_EQ(obj3(0, 0), 0.01);
  EXPECT_DOUBLE_EQ(obj3(0, 1), 0.02);
  EXPECT_DOUBLE_EQ(obj3(0, 2), 0.03);

  EXPECT_DOUBLE_EQ(obj3(1, 0), 0.04);
  EXPECT_DOUBLE_EQ(obj3(1, 1), 0.05);
  EXPECT_DOUBLE_EQ(obj3(1, 2), 0.06);
}

TEST(test_operations_with_matrices, test_SubMatrix) {
  S21Matrix obj;
  S21Matrix obj1;
  obj.SubMatrix(obj1);
  EXPECT_EQ(obj.GetRows(), 0);
  EXPECT_EQ(obj.GetCols(), 0);
  EXPECT_EQ(obj.GetMatrix(), nullptr);

  S21Matrix obj2(2, 3);
  obj2(0, 0) = 0.1;
  obj2(0, 1) = 0.2;
  obj2(0, 2) = 0.3;
  obj2(1, 0) = 0.4;
  obj2(1, 1) = 0.5;
  obj2(1, 2) = 0.6;
  EXPECT_THROW(obj.SubMatrix(obj2), out_of_range);

  S21Matrix obj3(2, 3);
  obj3(0, 0) = 0.01;
  obj3(0, 1) = 0.02;
  obj3(0, 2) = 0.03;
  obj3(1, 0) = 0.04;
  obj3(1, 1) = 0.05;
  obj3(1, 2) = 0.06;

  obj2.SubMatrix(obj3);

  EXPECT_DOUBLE_EQ(obj2(0, 0), 0.09);
  EXPECT_DOUBLE_EQ(obj2(0, 1), 0.18);
  EXPECT_DOUBLE_EQ(obj2(0, 2), 0.27);

  EXPECT_DOUBLE_EQ(obj2(1, 0), 0.36);
  EXPECT_DOUBLE_EQ(obj2(1, 1), 0.45);
  EXPECT_DOUBLE_EQ(obj2(1, 2), 0.54);

  EXPECT_DOUBLE_EQ(obj3(0, 0), 0.01);
  EXPECT_DOUBLE_EQ(obj3(0, 1), 0.02);
  EXPECT_DOUBLE_EQ(obj3(0, 2), 0.03);

  EXPECT_DOUBLE_EQ(obj3(1, 0), 0.04);
  EXPECT_DOUBLE_EQ(obj3(1, 1), 0.05);
  EXPECT_DOUBLE_EQ(obj3(1, 2), 0.06);

  obj2(0, 0) = 0.1;
  obj2(0, 1) = 0.2;
  obj2(0, 2) = 0.3;
  obj2(1, 0) = 0.4;
  obj2(1, 1) = 0.5;
  obj2(1, 2) = 0.6;
  obj3.SubMatrix(obj2);

  EXPECT_DOUBLE_EQ(obj3(0, 0), -0.09);
  EXPECT_DOUBLE_EQ(obj3(0, 1), -0.18);
  EXPECT_DOUBLE_EQ(obj3(0, 2), -0.27);

  EXPECT_DOUBLE_EQ(obj3(1, 0), -0.36);
  EXPECT_DOUBLE_EQ(obj3(1, 1), -0.45);
  EXPECT_DOUBLE_EQ(obj3(1, 2), -0.54);

  EXPECT_DOUBLE_EQ(obj2(0, 0), 0.1);
  EXPECT_DOUBLE_EQ(obj2(0, 1), 0.2);
  EXPECT_DOUBLE_EQ(obj2(0, 2), 0.3);

  EXPECT_DOUBLE_EQ(obj2(1, 0), 0.4);
  EXPECT_DOUBLE_EQ(obj2(1, 1), 0.5);
  EXPECT_DOUBLE_EQ(obj2(1, 2), 0.6);
}

TEST(test_operations_with_matrices, test_MulNumber) {
  S21Matrix obj(3, 3);
  obj(0, 0) = 1.0;
  obj(0, 1) = 2.0;
  obj(0, 2) = 3.0;
  obj(1, 0) = 3.0;
  obj(1, 1) = 4.0;
  obj(1, 2) = 5.0;

  obj.MulNumber(2);

  EXPECT_DOUBLE_EQ(obj(0, 0), 2.0);
  EXPECT_DOUBLE_EQ(obj(0, 1), 4.0);
  EXPECT_DOUBLE_EQ(obj(0, 2), 6.0);
  EXPECT_DOUBLE_EQ(obj(1, 0), 6.0);
  EXPECT_DOUBLE_EQ(obj(1, 1), 8.0);
  EXPECT_DOUBLE_EQ(obj(1, 2), 10.0);
  //////////////////////////////////
  obj.MulNumber(0.2);

  EXPECT_DOUBLE_EQ(obj(0, 0), 0.4);
  EXPECT_DOUBLE_EQ(obj(0, 1), 0.8);
  EXPECT_DOUBLE_EQ(obj(0, 2), 1.2);
  EXPECT_DOUBLE_EQ(obj(1, 0), 1.2);
  EXPECT_DOUBLE_EQ(obj(1, 1), 1.6);
  EXPECT_DOUBLE_EQ(obj(1, 2), 2);
}

TEST(test_operations_with_matrices, test_MulMatrix) {
  S21Matrix obj(5, 2);
  obj(0, 0) = 1;
  obj(0, 1) = 2;
  obj(1, 0) = 3;
  obj(1, 1) = 4;

  S21Matrix matrix_2(2, 5);

  matrix_2(0, 0) = 5;
  matrix_2(0, 1) = 6;
  matrix_2(1, 0) = 7;
  matrix_2(1, 1) = 8;

  obj.MulMatrix(matrix_2);

  EXPECT_DOUBLE_EQ(obj(0, 0), 19);
  EXPECT_DOUBLE_EQ(obj(0, 1), 22);
  EXPECT_DOUBLE_EQ(obj(1, 0), 43);
  EXPECT_DOUBLE_EQ(obj(1, 1), 50);

  ///////////////////////////////////
  S21Matrix obj_1(2, 2);
  obj_1(0, 0) = 1;
  obj_1(0, 1) = 2;
  obj_1(1, 0) = 3;
  obj_1(1, 1) = 4;

  S21Matrix obj_2(2, 2);
  obj_2(0, 0) = 5;
  obj_2(0, 1) = 6;
  obj_2(1, 0) = 7;
  obj_2(1, 1) = 8;

  obj_1.MulMatrix(obj_2);

  EXPECT_DOUBLE_EQ(obj_1(0, 0), 19);
  EXPECT_DOUBLE_EQ(obj_1(0, 1), 22);
  EXPECT_DOUBLE_EQ(obj_1(1, 0), 43);
  EXPECT_DOUBLE_EQ(obj_1(1, 1), 50);

  ////////////////////////////////////////
  S21Matrix obj_3(2, 3);
  S21Matrix obj_4(2, 2);

  EXPECT_THROW(obj_3.MulMatrix(obj_4), out_of_range);
  //////////////////////////////////////////
  S21Matrix obj_5;
  S21Matrix obj_6;
  obj_5.MulMatrix(obj_6);
  EXPECT_EQ(obj_5.GetRows(), 0);
  EXPECT_EQ(obj_5.GetCols(), 0);
  EXPECT_EQ(obj_5.GetMatrix(), nullptr);
}

TEST(test_operations_with_matrices, test_Transpose) {
  S21Matrix obj_1(3, 2);
  obj_1(0, 0) = 1;
  obj_1(0, 1) = 2;
  obj_1(1, 0) = 3;
  obj_1(1, 1) = 4;
  obj_1(2, 0) = 5;
  obj_1(2, 1) = 6;

  S21Matrix obj_2 = obj_1.Transpose();

  EXPECT_DOUBLE_EQ(obj_2(0, 0), 1);
  EXPECT_DOUBLE_EQ(obj_2(0, 1), 3);
  EXPECT_DOUBLE_EQ(obj_2(0, 2), 5);
  EXPECT_DOUBLE_EQ(obj_2(1, 0), 2);
  EXPECT_DOUBLE_EQ(obj_2(1, 1), 4);
  EXPECT_DOUBLE_EQ(obj_2(1, 2), 6);
  ///////////////////////////////////////////////
  S21Matrix obj_3(3, 3);
  obj_3(0, 0) = 1;
  obj_3(0, 1) = 2;
  obj_3(0, 2) = 3;
  obj_3(1, 0) = 4;
  obj_3(1, 1) = 5;
  obj_3(1, 2) = 6;
  obj_3(2, 0) = 7;
  obj_3(2, 1) = 8;
  obj_3(2, 2) = 9;

  S21Matrix obj_4 = obj_3.Transpose();

  EXPECT_DOUBLE_EQ(obj_4(0, 0), 1);
  EXPECT_DOUBLE_EQ(obj_4(0, 1), 4);
  EXPECT_DOUBLE_EQ(obj_4(0, 2), 7);
  EXPECT_DOUBLE_EQ(obj_4(1, 0), 2);
  EXPECT_DOUBLE_EQ(obj_4(1, 1), 5);
  EXPECT_DOUBLE_EQ(obj_4(1, 2), 8);
  EXPECT_DOUBLE_EQ(obj_4(2, 0), 3);
  EXPECT_DOUBLE_EQ(obj_4(2, 1), 6);
  EXPECT_DOUBLE_EQ(obj_4(2, 2), 9);

  /////////////////////////////////////////
  S21Matrix obj_5(1, 1);
  obj_5(0, 0) = 8;
  S21Matrix obj_6 = obj_5.Transpose();
  EXPECT_DOUBLE_EQ(obj_6(0, 0), 8);
}

TEST(test_operations_with_matrices, test_CalcComplements) {
  S21Matrix obj_1(3, 3);
  obj_1(0, 0) = 1;
  obj_1(0, 1) = 0;
  obj_1(0, 2) = 5;
  obj_1(1, 0) = 2;
  obj_1(1, 1) = 4;
  obj_1(1, 2) = 2;
  obj_1(2, 0) = 3;
  obj_1(2, 1) = 2;
  obj_1(2, 2) = 1;

  S21Matrix obj_2 = obj_1.CalcComplements();

  EXPECT_DOUBLE_EQ(obj_2(0, 0), 0);
  EXPECT_DOUBLE_EQ(obj_2(0, 1), 4);
  EXPECT_DOUBLE_EQ(obj_2(0, 2), -8);
  EXPECT_DOUBLE_EQ(obj_2(1, 0), 10);
  EXPECT_DOUBLE_EQ(obj_2(1, 1), -14);
  EXPECT_DOUBLE_EQ(obj_2(1, 2), -2);
  EXPECT_DOUBLE_EQ(obj_2(2, 0), -20);
  EXPECT_DOUBLE_EQ(obj_2(2, 1), 8);
  EXPECT_DOUBLE_EQ(obj_2(2, 2), 4);
  ////////////////////////////////////
  S21Matrix obj_3(1, 3);
  EXPECT_THROW(obj_3.CalcComplements(), logic_error);
  ////////////////////////////////////
  S21Matrix obj_4(1, 1);
  obj_4(0, 0) = 8;
  S21Matrix obj_5 = obj_4.CalcComplements();
  EXPECT_DOUBLE_EQ(obj_5(0, 0), 1);
}

TEST(test_operations_with_matrices, test_Determinant) {
  S21Matrix obj_1(3, 3);
  obj_1(0, 0) = 1;
  obj_1(0, 1) = 2;
  obj_1(0, 2) = 3;
  obj_1(1, 0) = 4;
  obj_1(1, 1) = 5;
  obj_1(1, 2) = 6;
  obj_1(2, 0) = 7;
  obj_1(2, 1) = 8;
  obj_1(2, 2) = 9;

  EXPECT_DOUBLE_EQ(obj_1.Determinant(), 0);
  //////////////////////////////////////////
  S21Matrix obj_2(2, 3);
  EXPECT_THROW(obj_2.Determinant(), logic_error);
  //////////////////////////////////////////
  S21Matrix obj_3(1, 1);
  obj_3(0, 0) = 5;
  EXPECT_DOUBLE_EQ(obj_3.Determinant(), 5);
  ////////////////////////////////////////
  S21Matrix obj_4(2, 2);
  obj_4(0, 0) = 6;
  obj_4(0, 1) = 2;
  obj_4(1, 0) = 3;
  obj_4(1, 1) = 4;
  EXPECT_DOUBLE_EQ(obj_4.Determinant(), 18);
  ////////////////////////////////////////
  S21Matrix obj_5;
  EXPECT_DOUBLE_EQ(obj_5.Determinant(), 0);
}

TEST(test_operations_with_matrices, test_InverseMatrix) {
  S21Matrix A(5, 5);
  A(0, 0) = 1;
  A(0, 1) = 0;
  A(0, 2) = 5;
  A(0, 3) = 5;
  A(0, 4) = 5;

  A(1, 0) = 2;
  A(1, 1) = 4;
  A(1, 2) = 2;
  A(1, 3) = 4;
  A(1, 4) = 2;

  A(2, 0) = 3;
  A(2, 1) = 2;
  A(2, 2) = 1;
  A(2, 3) = 2;
  A(2, 4) = 1;

  A(3, 1) = 4;

  A(4, 2) = 5;
  A(4, 3) = 4;

  S21Matrix result = A.InverseMatrix();
  EXPECT_DOUBLE_EQ(result(0, 0), 0);
  EXPECT_DOUBLE_EQ(result(0, 1), -0.25);
  EXPECT_DOUBLE_EQ(result(0, 2), 0.5);
  EXPECT_DOUBLE_EQ(result(0, 3), 0);
  EXPECT_DOUBLE_EQ(result(0, 4), 0);

  EXPECT_DOUBLE_EQ(result(1, 0), 0);
  EXPECT_DOUBLE_EQ(result(1, 1), 0);
  EXPECT_DOUBLE_EQ(result(1, 2), 0);
  EXPECT_DOUBLE_EQ(result(1, 3), 0.25);
  EXPECT_DOUBLE_EQ(result(1, 4), 0);

  EXPECT_DOUBLE_EQ(result(2, 0), 0.16);
  EXPECT_DOUBLE_EQ(result(2, 1), -0.56);
  EXPECT_DOUBLE_EQ(result(2, 2), 0.32);
  EXPECT_DOUBLE_EQ(result(2, 3), 0.4);
  EXPECT_DOUBLE_EQ(result(2, 4), 0.2);

  EXPECT_DOUBLE_EQ(result(3, 0), -0.2);
  EXPECT_DOUBLE_EQ(result(3, 1), 0.70000000000000007);
  EXPECT_DOUBLE_EQ(result(3, 2), -0.4);
  EXPECT_DOUBLE_EQ(result(3, 3), -0.5);
  EXPECT_DOUBLE_EQ(result(3, 4), 0);

  EXPECT_DOUBLE_EQ(result(4, 0), 0.24);
  EXPECT_DOUBLE_EQ(result(4, 1), -0.09);
  EXPECT_DOUBLE_EQ(result(4, 2), -0.02);
  EXPECT_DOUBLE_EQ(result(4, 3), 0.1);
  EXPECT_DOUBLE_EQ(result(4, 4), -0.2);

  //////////////////////////////////////
  S21Matrix obj(2, 3);
  EXPECT_THROW(obj.InverseMatrix(), logic_error);
  ///////////////////////////////////////
  S21Matrix obj_1;
  EXPECT_THROW(obj_1.InverseMatrix(), invalid_argument);
  ///////////////////////////////////////
  S21Matrix obj_2(1, 1);
  obj_2(0, 0) = 4;
  S21Matrix result_1 = obj_2.InverseMatrix();
  EXPECT_DOUBLE_EQ(result_1(0, 0), 0.25);
}