#include <gtest/gtest.h>

#include <exception>

#include "../s21_matrix_oop.h"

TEST(test_overload, test_operator1) {
  S21Matrix A(2, 3);
  A(0, 0) = 1;
  A(0, 1) = 13;
  A(0, 2) = 15;

  A(1, 0) = 10;
  A(1, 1) = 12;
  A(1, 2) = 11;

  EXPECT_DOUBLE_EQ(A(0, 0), 1);
  EXPECT_DOUBLE_EQ(A(0, 1), 13);
  EXPECT_DOUBLE_EQ(A(0, 2), 15);

  EXPECT_DOUBLE_EQ(A(1, 0), 10);
  EXPECT_DOUBLE_EQ(A(1, 1), 12);
  EXPECT_DOUBLE_EQ(A(1, 2), 11);

  EXPECT_THROW(A(-1, 0), range_error);
  EXPECT_THROW(A(1, -9), range_error);
  EXPECT_THROW(A(5, 0), range_error);
  EXPECT_THROW(A(0, 5), range_error);
}

TEST(test_overload, test_operator_value_assignment) {
  S21Matrix A(2, 3);
  A(0, 0) = 1;
  A(0, 1) = 13;
  A(0, 2) = 15;

  A(1, 0) = 10;
  A(1, 1) = 12;
  A(1, 2) = 11;

  S21Matrix B(2, 3);
  B(0, 0) = -1;
  B(0, 1) = -13;
  B(0, 2) = -15;

  B(1, 0) = -10;
  B(1, 1) = -11;
  B(1, 2) = 110;

  A = B;
  EXPECT_DOUBLE_EQ(A(0, 0), -1);
  EXPECT_DOUBLE_EQ(A(0, 1), -13);
  EXPECT_DOUBLE_EQ(A(0, 2), -15);

  EXPECT_DOUBLE_EQ(A(1, 0), -10);
  EXPECT_DOUBLE_EQ(A(1, 1), -11);
  EXPECT_DOUBLE_EQ(A(1, 2), 110);

  A = A;
  EXPECT_DOUBLE_EQ(A(0, 0), -1);
  EXPECT_DOUBLE_EQ(A(0, 1), -13);
  EXPECT_DOUBLE_EQ(A(0, 2), -15);

  EXPECT_DOUBLE_EQ(A(1, 0), -10);
  EXPECT_DOUBLE_EQ(A(1, 1), -11);
  EXPECT_DOUBLE_EQ(A(1, 2), 110);

  S21Matrix C(3, 2);

  C(0, 0) = 1.234;
  C(0, 1) = -6;

  C(1, 0) = 11;
  C(1, 1) = 15.6;

  C(2, 0) = 111;
  C(2, 1) = 175;

  A = C;

  EXPECT_DOUBLE_EQ(A(0, 0), 1.234);
  EXPECT_DOUBLE_EQ(A(0, 1), -6);

  EXPECT_DOUBLE_EQ(A(1, 0), 11);
  EXPECT_DOUBLE_EQ(A(1, 1), 15.6);

  EXPECT_DOUBLE_EQ(A(2, 0), 111);
  EXPECT_DOUBLE_EQ(A(2, 1), 175);

  S21Matrix D;
  A = D;
  EXPECT_DOUBLE_EQ(A.GetCols(), 0);
  EXPECT_DOUBLE_EQ(A.GetRows(), 0);
  EXPECT_EQ(A.GetMatrix(), nullptr);
}

TEST(test_overload, test_operator_equal) {
  S21Matrix A(2, 3);
  A(0, 0) = 1;
  A(0, 1) = 13;
  A(0, 2) = 15;

  A(1, 0) = 10;
  A(1, 1) = 12;
  A(1, 2) = 11;

  S21Matrix B(2, 3);
  B(0, 0) = -1;
  B(0, 1) = -13;
  B(0, 2) = -15;

  B(1, 0) = -10;
  B(1, 1) = -11;
  B(1, 2) = 110;

  S21Matrix C;
  C = A;
  EXPECT_EQ(A == C, true);
  EXPECT_EQ(A == B, false);

  S21Matrix D(9, 8);

  EXPECT_EQ(A == D, false);

  S21Matrix E, E1;
  EXPECT_EQ(E == E1, true);
  EXPECT_EQ(E == A, false);
}

TEST(test_overload, test_operator_plus) {
  S21Matrix obj;
  S21Matrix obj1;
  S21Matrix obj_sum1 = obj + obj1;

  EXPECT_EQ(obj_sum1.GetRows(), 0);
  EXPECT_EQ(obj_sum1.GetCols(), 0);
  EXPECT_EQ(obj_sum1.GetMatrix(), nullptr);

  S21Matrix obj2(2, 3);
  obj2(0, 0) = 0.1;
  obj2(0, 1) = 0.2;
  obj2(0, 2) = 0.3;
  obj2(1, 0) = 0.4;
  obj2(1, 1) = 0.5;
  obj2(1, 2) = 0.6;
  EXPECT_THROW(obj + obj2, out_of_range);

  S21Matrix obj3(2, 3);
  obj3(0, 0) = 0.01;
  obj3(0, 1) = 0.02;
  obj3(0, 2) = 0.03;
  obj3(1, 0) = 0.04;
  obj3(1, 1) = 0.05;
  obj3(1, 2) = 0.06;

  S21Matrix obj_sum3 = obj2 + obj3;
  EXPECT_DOUBLE_EQ(obj_sum3(0, 0), 0.11);
  EXPECT_DOUBLE_EQ(obj_sum3(0, 1), 0.22);
  EXPECT_DOUBLE_EQ(obj_sum3(0, 2), 0.33);

  EXPECT_DOUBLE_EQ(obj_sum3(1, 0), 0.44);
  EXPECT_DOUBLE_EQ(obj_sum3(1, 1), 0.55);
  EXPECT_DOUBLE_EQ(obj_sum3(1, 2), 0.66);
}

TEST(test_overload, test_operator_minus) {
  S21Matrix obj;
  S21Matrix obj1;
  S21Matrix obj_sub1 = obj - obj1;
  EXPECT_EQ(obj_sub1.GetRows(), 0);
  EXPECT_EQ(obj_sub1.GetCols(), 0);
  EXPECT_EQ(obj_sub1.GetMatrix(), nullptr);

  S21Matrix obj2(2, 3);
  obj2(0, 0) = 0.1;
  obj2(0, 1) = 0.2;
  obj2(0, 2) = 0.3;
  obj2(1, 0) = 0.4;
  obj2(1, 1) = 0.5;
  obj2(1, 2) = 0.6;
  EXPECT_THROW(obj - obj2, out_of_range);

  S21Matrix obj3(2, 3);
  obj3(0, 0) = 0.01;
  obj3(0, 1) = 0.02;
  obj3(0, 2) = 0.03;
  obj3(1, 0) = 0.04;
  obj3(1, 1) = 0.05;
  obj3(1, 2) = 0.06;
  S21Matrix obj_sub3 = obj2 - obj3;

  EXPECT_DOUBLE_EQ(obj_sub3(0, 0), 0.09);
  EXPECT_DOUBLE_EQ(obj_sub3(0, 1), 0.18);
  EXPECT_DOUBLE_EQ(obj_sub3(0, 2), 0.27);

  EXPECT_DOUBLE_EQ(obj_sub3(1, 0), 0.36);
  EXPECT_DOUBLE_EQ(obj_sub3(1, 1), 0.45);
  EXPECT_DOUBLE_EQ(obj_sub3(1, 2), 0.54);

  obj2(0, 0) = 0.1;
  obj2(0, 1) = 0.2;
  obj2(0, 2) = 0.3;
  obj2(1, 0) = 0.4;
  obj2(1, 1) = 0.5;
  obj2(1, 2) = 0.6;
  obj3 = obj3 - obj2;

  EXPECT_DOUBLE_EQ(obj3(0, 0), -0.09);
  EXPECT_DOUBLE_EQ(obj3(0, 1), -0.18);
  EXPECT_DOUBLE_EQ(obj3(0, 2), -0.27);

  EXPECT_DOUBLE_EQ(obj3(1, 0), -0.36);
  EXPECT_DOUBLE_EQ(obj3(1, 1), -0.45);
  EXPECT_DOUBLE_EQ(obj3(1, 2), -0.54);
}

TEST(test_overload, test_operator_plus_assignment) {
  S21Matrix obj;
  S21Matrix obj1;
  obj += obj1;
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
  EXPECT_THROW(obj += obj2, out_of_range);

  S21Matrix obj3(2, 3);
  obj3(0, 0) = 0.01;
  obj3(0, 1) = 0.02;
  obj3(0, 2) = 0.03;
  obj3(1, 0) = 0.04;
  obj3(1, 1) = 0.05;
  obj3(1, 2) = 0.06;
  obj2 += obj3;

  EXPECT_DOUBLE_EQ(obj2(0, 0), 0.11);
  EXPECT_DOUBLE_EQ(obj2(0, 1), 0.22);
  EXPECT_DOUBLE_EQ(obj2(0, 2), 0.33);

  EXPECT_DOUBLE_EQ(obj2(1, 0), 0.44);
  EXPECT_DOUBLE_EQ(obj2(1, 1), 0.55);
  EXPECT_DOUBLE_EQ(obj2(1, 2), 0.66);
}

TEST(test_overload, test_operator_minus_assignment) {
  S21Matrix obj;
  S21Matrix obj1;
  obj -= obj1;
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
  EXPECT_THROW(obj -= obj2, out_of_range);

  S21Matrix obj3(2, 3);
  obj3(0, 0) = 0.01;
  obj3(0, 1) = 0.02;
  obj3(0, 2) = 0.03;
  obj3(1, 0) = 0.04;
  obj3(1, 1) = 0.05;
  obj3(1, 2) = 0.06;
  obj2 -= obj3;
  EXPECT_DOUBLE_EQ(obj2(0, 0), 0.09);
  EXPECT_DOUBLE_EQ(obj2(0, 1), 0.18);
  EXPECT_DOUBLE_EQ(obj2(0, 2), 0.27);

  EXPECT_DOUBLE_EQ(obj2(1, 0), 0.36);
  EXPECT_DOUBLE_EQ(obj2(1, 1), 0.45);
  EXPECT_DOUBLE_EQ(obj2(1, 2), 0.54);

  obj2(0, 0) = 0.1;
  obj2(0, 1) = 0.2;
  obj2(0, 2) = 0.3;
  obj2(1, 0) = 0.4;
  obj2(1, 1) = 0.5;
  obj2(1, 2) = 0.6;
  obj3 -= obj2;
  EXPECT_DOUBLE_EQ(obj3(0, 0), -0.09);
  EXPECT_DOUBLE_EQ(obj3(0, 1), -0.18);
  EXPECT_DOUBLE_EQ(obj3(0, 2), -0.27);

  EXPECT_DOUBLE_EQ(obj3(1, 0), -0.36);
  EXPECT_DOUBLE_EQ(obj3(1, 1), -0.45);
  EXPECT_DOUBLE_EQ(obj3(1, 2), -0.54);
}

TEST(test_overload, test_operator_mult_number_assignment) {
  S21Matrix obj(3, 3);
  obj(0, 0) = 1.0;
  obj(0, 1) = 2.0;
  obj(0, 2) = 3.0;
  obj(1, 0) = 3.0;
  obj(1, 1) = 4.0;
  obj(1, 2) = 5.0;

  obj *= 2;

  EXPECT_DOUBLE_EQ(obj(0, 0), 2.0);
  EXPECT_DOUBLE_EQ(obj(0, 1), 4.0);
  EXPECT_DOUBLE_EQ(obj(0, 2), 6.0);
  EXPECT_DOUBLE_EQ(obj(1, 0), 6.0);
  EXPECT_DOUBLE_EQ(obj(1, 1), 8.0);
  EXPECT_DOUBLE_EQ(obj(1, 2), 10.0);
  //////////////////////////////////
  obj *= 0.2;

  EXPECT_DOUBLE_EQ(obj(0, 0), 0.4);
  EXPECT_DOUBLE_EQ(obj(0, 1), 0.8);
  EXPECT_DOUBLE_EQ(obj(0, 2), 1.2);
  EXPECT_DOUBLE_EQ(obj(1, 0), 1.2);
  EXPECT_DOUBLE_EQ(obj(1, 1), 1.6);
  EXPECT_DOUBLE_EQ(obj(1, 2), 2);
}

TEST(test_overload, test_operator_mult_number) {
  S21Matrix obj(3, 3);
  obj(0, 0) = 1.0;
  obj(0, 1) = 2.0;
  obj(0, 2) = 3.0;
  obj(1, 0) = 3.0;
  obj(1, 1) = 4.0;
  obj(1, 2) = 5.0;

  S21Matrix obj_res = obj * 2;

  EXPECT_DOUBLE_EQ(obj_res(0, 0), 2.0);
  EXPECT_DOUBLE_EQ(obj_res(0, 1), 4.0);
  EXPECT_DOUBLE_EQ(obj_res(0, 2), 6.0);
  EXPECT_DOUBLE_EQ(obj_res(1, 0), 6.0);
  EXPECT_DOUBLE_EQ(obj_res(1, 1), 8.0);
  EXPECT_DOUBLE_EQ(obj_res(1, 2), 10.0);
  //////////////////////////////////
  S21Matrix obj_res1 = obj_res * 0.2;

  EXPECT_DOUBLE_EQ(obj_res1(0, 0), 0.4);
  EXPECT_DOUBLE_EQ(obj_res1(0, 1), 0.8);
  EXPECT_DOUBLE_EQ(obj_res1(0, 2), 1.2);
  EXPECT_DOUBLE_EQ(obj_res1(1, 0), 1.2);
  EXPECT_DOUBLE_EQ(obj_res1(1, 1), 1.6);
  EXPECT_DOUBLE_EQ(obj_res1(1, 2), 2);
}

TEST(test_overload, test_operator_mult_matrix_assignment) {
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

  obj *= matrix_2;

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

  obj_1 *= obj_2;

  EXPECT_DOUBLE_EQ(obj_1(0, 0), 19);
  EXPECT_DOUBLE_EQ(obj_1(0, 1), 22);
  EXPECT_DOUBLE_EQ(obj_1(1, 0), 43);
  EXPECT_DOUBLE_EQ(obj_1(1, 1), 50);

  ////////////////////////////////////////
  S21Matrix obj_3(2, 3);
  S21Matrix obj_4(2, 2);

  EXPECT_THROW(obj_3 *= obj_4, out_of_range);
  //////////////////////////////////////////
  S21Matrix obj_5;
  S21Matrix obj_6;
  obj_5 *= obj_6;
  EXPECT_EQ(obj_5.GetRows(), 0);
  EXPECT_EQ(obj_5.GetCols(), 0);
  EXPECT_EQ(obj_5.GetMatrix(), nullptr);
}

TEST(test_overload, test_operator_mult_matrix) {
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

  S21Matrix res = obj * matrix_2;

  EXPECT_DOUBLE_EQ(res(0, 0), 19);
  EXPECT_DOUBLE_EQ(res(0, 1), 22);
  EXPECT_DOUBLE_EQ(res(1, 0), 43);
  EXPECT_DOUBLE_EQ(res(1, 1), 50);

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

  S21Matrix res1 = obj_1 * obj_2;

  EXPECT_DOUBLE_EQ(res1(0, 0), 19);
  EXPECT_DOUBLE_EQ(res1(0, 1), 22);
  EXPECT_DOUBLE_EQ(res1(1, 0), 43);
  EXPECT_DOUBLE_EQ(res1(1, 1), 50);

  ////////////////////////////////////////
  S21Matrix obj_3(2, 3);
  S21Matrix obj_4(2, 2);

  EXPECT_THROW(obj_3 * obj_4, out_of_range);
  //////////////////////////////////////////
  S21Matrix obj_5;
  S21Matrix obj_6;
  S21Matrix res3 = obj_5 * obj_6;
  EXPECT_EQ(obj_5.GetRows(), 0);
  EXPECT_EQ(obj_5.GetCols(), 0);
  EXPECT_EQ(obj_5.GetMatrix(), nullptr);
}