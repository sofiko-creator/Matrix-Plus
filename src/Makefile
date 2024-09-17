CC=g++ 
STRICT_CFLAGS= -Wall -std=c++17 -Wextra -pedantic -Werror 


GCOVR_CFLAGS=-fprofile-arcs -ftest-coverage -fPIC
GCOVR_LFLAGS=-lgcov


GTEST_LFLAGS=-lgtest -lgtest_main

REPORT_DIRECTORY=report

all: s21_matrix_oop.a test gcov_report

s21_matrix_oop.a: s21_matrix_oop.oa 
		ar rcs $@ $^

tests/test_constructors.o: tests/test_constructors.cc s21_matrix_oop.h
		$(CC) -c -o $@ $< $(GTEST_CFLAGS)
tests/test_operations_with_matrices.o: tests/test_operations_with_matrices.cc s21_matrix_oop.h
		$(CC) -c -o $@ $< $(GTEST_CFLAGS)
tests/test_get_set.o: tests/test_get_set.cc s21_matrix_oop.h
		$(CC) -c -o $@ $< $(GTEST_CFLAGS)
tests/test_overload_the_operators.o: tests/test_overload_the_operators.cc s21_matrix_oop.h
		$(CC) -c -o $@ $< $(GTEST_CFLAGS)
test: tests/tests_main.exe
		./tests/tests_main.exe

gcov_report: test
		mkdir -p $(REPORT_DIRECTORY)
		gcovr . --html --html-details --exclude-lines-by-pattern '.*assert.*' -o $(REPORT_DIRECTORY)/coverage_report.html
		xdg-open $(REPORT_DIRECTORY)/coverage_report.html || open $(REPORT_DIRECTORY)/coverage_report.html  

tests/tests_main.exe: s21_matrix_oop.o tests/test_constructors.o tests/test_operations_with_matrices.o tests/test_get_set.o tests/test_overload_the_operators.o
		$(CC) -o $@ $^ $(GTEST_LFLAGS) $(GCOVR_LFLAGS)

s21_matrix_oop.o: s21_matrix_oop.cc s21_matrix_oop.h
		$(CC) -c $(STRICT_CFLAGS) $< -o $@ $(GCOVR_CFLAGS)

s21_matrix_oop.oa: s21_matrix_oop.cc s21_matrix_oop.h
		$(CC) -c $(STRICT_CFLAGS) $< -o $@

check_style:
		cp ../materials/linters/.clang-format .
		clang-format --style=Google -n *.cc
		clang-format --style=Google -n *.h
		clang-format --style=Google -n tests/*.cc
		rm .clang-format
		
set_style_google:
		cp ../materials/linters/.clang-format .
		clang-format --style=Google -i *.cc
		clang-format --style=Google -i *.h
		clang-format --style=Google -i tests/*.cc
		rm .clang-format

clean:
		rm -rf *.o *.exe *.out *.oa *.a
		rm -rf tests/*.o tests/*.exe tests/*.out
		rm -rf *.gcno *.gcda
		rm -rf $(REPORT_DIRECTORY)/*.css $(REPORT_DIRECTORY)/*.html $(REPORT_DIRECTORY)
