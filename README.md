# Matrix-Plus
## Реализация функции библиотеки s21_matrix_oop.h

* Программа разработана на языке C++ стандарта C++17 с использованием компилятора gcc;
* Код находится в папке src;
* Решение оформлено как статическая библиотека (с заголовочным файлом s21_matrix_oop.h);
* Присутствует полное покрытие unit-тестами функций библиотеки c помощью библиотеки GTest;
* Предусмотрен Makefile для сборки библиотеки и тестов.

## Описание целей в Makefile

1. all: 
   - Основная цель, которая вызывает сборку библиотеки s21_matrix_oop.a, тестов и отчет о покрытии кода.

2. s21_matrix_oop.a: 
   - Создает статическую библиотеку из объектного файла s21_matrix_oop.oa.

3. tests/test_constructors.o: 
   - Компилирует файл tests/test_constructors.cc в объектный файл, используя флаги для тестирования. Зависят от заголовка s21_matrix_oop.h.

4. tests/test_operations_with_matrices.o: 
   - Компилирует файл tests/test_operations_with_matrices.cc в объектный файл, используя аналогичные флаги.

5. tests/test_get_set.o: 
   - Компилирует файл tests/test_get_set.cc в объектный файл.

6. tests/test_overload_the_operators.o: 
   - Компилирует файл tests/test_overload_the_operators.cc в объектный файл.

7. test: 
   - Запускает исполняемый файл tests/tests_main.exe, который содержит все тесты.

8. gcov_report: 
   - Генерирует отчет о покрытии кода с помощью gcovr, создавая HTML-отчет в директории report. Открывает отчет с помощью команды, соответствующей операционной системе.

9. tests/tests_main.exe: 
   - Компилирует все объектные файлы тестов и связывает их с библиотеками Google Test и gcov, создавая исполняемый файл.

10. s21_matrix_oop.o: 
    - Компилирует файл s21_matrix_oop.cc в объектный файл с использованием строгих флагов компиляции и флагов для покрытия.

11. s21_matrix_oop.oa: 
    - Компилирует файл s21_matrix_oop.cc в объектный файл без флагов покрытия.

12. check_style: 
    - Копирует файл конфигурации линтера .clang-format и проверяет стиль кода в файлах .cc и .h, не изменяя их.

13. set_style_google: 
    - Копирует файл конфигурации линтера и применяет стиль Google к файлам .cc и .h, изменяя их.

14. clean: 
    - Удаляет все временные и сгенерированные файлы, включая объектные файлы, исполняемые файлы, отчеты о покрытии и директорию отчетов.