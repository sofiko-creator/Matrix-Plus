#include <gtest/gtest.h>

#include <exception>

#include "../s21_matrix_oop.h"

TEST(test_constructors, test_constructor_default) {
  S21Matrix obj;

  EXPECT_EQ(obj.GetRows(), 0);
  EXPECT_EQ(obj.GetCols(), 0);
  EXPECT_EQ(obj.GetMatrix(), nullptr);
}

TEST(test_constructors, test_constructor_parametrs_error) {
  EXPECT_THROW(S21Matrix obj(0, 0), range_error);
  EXPECT_THROW(S21Matrix obj(0, 1), range_error);
  EXPECT_THROW(S21Matrix obj(1, 0), range_error);
  EXPECT_THROW(S21Matrix obj(-1, -1), range_error);
  EXPECT_THROW(S21Matrix obj(-9, -9), range_error);
  EXPECT_THROW(S21Matrix obj(-1, 1), range_error);
  EXPECT_THROW(S21Matrix obj(1, -1), range_error);
}

TEST(test_constructors, test_constructor_parametrs_success) {
  S21Matrix obj(4, 3);

  EXPECT_EQ(obj.GetRows(), 4);
  EXPECT_EQ(obj.GetCols(), 3);

  for (int i = 0; i < obj.GetRows(); i++) {
    for (int j = 0; j < obj.GetCols(); j++) {
      EXPECT_DOUBLE_EQ(obj(i, j), 0.0);
    }
  }
}

TEST(test_constructors, test_constructor_parametrs_success_square) {
  S21Matrix obj(3, 3);

  EXPECT_EQ(obj.GetRows(), 3);
  EXPECT_EQ(obj.GetCols(), 3);

  for (int i = 0; i < obj.GetRows(); i++) {
    for (int j = 0; j < obj.GetCols(); j++) {
      EXPECT_DOUBLE_EQ(obj(i, j), 0.0);
    }
  }
}

TEST(test_constructors, test_constructor_copy) {
  S21Matrix obj(2, 3);
  obj(0, 0) = 0.1;
  obj(0, 1) = 0.2;
  obj(0, 2) = 0.3;
  obj(1, 0) = 0.4;
  obj(1, 1) = 0.5;
  obj(1, 2) = 0.6;
  S21Matrix obj2(obj);

  EXPECT_EQ(obj2.GetRows(), 2);
  EXPECT_EQ(obj2.GetCols(), 3);

  EXPECT_DOUBLE_EQ(obj(0, 0), 0.1);
  EXPECT_DOUBLE_EQ(obj(0, 1), 0.2);
  EXPECT_DOUBLE_EQ(obj(0, 2), 0.3);

  EXPECT_DOUBLE_EQ(obj(1, 0), 0.4);
  EXPECT_DOUBLE_EQ(obj(1, 1), 0.5);
  EXPECT_DOUBLE_EQ(obj(1, 2), 0.6);

  S21Matrix obj_1;
  S21Matrix obj_2(obj_1);
  EXPECT_EQ(obj_2.GetRows(), 0);
  EXPECT_EQ(obj_2.GetCols(), 0);
  EXPECT_EQ(obj_2.GetMatrix(), nullptr);
}

TEST(test_constructors, test_constructor_move) {
  S21Matrix obj_1(11, 12);
  for (int i = 0; i < obj_1.GetRows(); i++) {
    for (int j = 0; j < obj_1.GetCols(); j++) {
      obj_1(i, j) = 1.0;
    }
  }

  S21Matrix obj_2(move(obj_1));

  EXPECT_EQ(obj_1.GetCols(), 0);
  EXPECT_EQ(obj_1.GetRows(), 0);
  EXPECT_EQ(obj_1.GetMatrix(), nullptr);

  EXPECT_EQ(obj_2.GetRows(), 11);
  EXPECT_EQ(obj_2.GetCols(), 12);
  for (int i = 0; i < obj_2.GetRows(); i++) {
    for (int j = 0; j < obj_2.GetCols(); j++) {
      EXPECT_DOUBLE_EQ(obj_2(i, j), 1.0);
    }
  }

  S21Matrix obj_3;
  S21Matrix obj_4(move(obj_3));

  EXPECT_EQ(obj_3.GetRows(), 0);
  EXPECT_EQ(obj_3.GetCols(), 0);
  EXPECT_EQ(obj_3.GetMatrix(), nullptr);

  EXPECT_EQ(obj_4.GetRows(), 0);
  EXPECT_EQ(obj_4.GetCols(), 0);
  EXPECT_EQ(obj_4.GetMatrix(), nullptr);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}