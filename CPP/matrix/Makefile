CC = g++
CFLAGS = -Werror -Wall -Wextra -std=c++17
GTEST_FLAGS = -lgtest -lgtest_main -pthread
GCOV_FLAGS = -fprofile-arcs -ftest-coverage
VALGRIND_FLAGS = --log-file="valgrind.txt" --track-origins=yes --trace-children=yes --leak-check=full --leak-resolution=med --show-leak-kinds=all

FILES = custom_matrix_oop.cpp
TEST_FILES = custom_test_matrix_oop.cpp
OUT_FILE = custom_matrix_oop
LIBRARY = custom_matrix_oop.a
TEST_EXECUTABLE = test_executable

ifeq ($(shell uname -s), Linux)
    GTEST_FLAGS += -lm -lsubunit
    OPEN = xdg-open
else
    OPEN = open
endif

all: clang $(LIBRARY)

$(LIBRARY):
	$(CC) -c $(CFLAGS) $(FILES)
	ar rcs $(LIBRARY) ./*.o 
	ranlib $(LIBRARY)
	rm ./*.o

test: $(LIBRARY)
	$(CC) -g $(CFLAGS) $(TEST_FILES) $(LIBRARY) -o $(OUT_FILE) $(GTEST_FLAGS)
	./$(OUT_FILE)
	
gcov_report: clean_gcov $(LIBRARY)
	$(CC) -g $(CFLAGS) $(GCOV_FLAGS) $(FILES) $(TEST_FILES) -o $(TEST_EXECUTABLE) $(GTEST_FLAGS)
	-./$(TEST_EXECUTABLE)  # Игнорировать ошибку выполнения тестов
	lcov -t "gcov_report" -o report.info --no-external -c -d . --ignore-errors inconsistent
	genhtml -o report report.info --ignore-errors inconsistent
	$(OPEN) ./report/index.html

test_leaks: gcov_report
	leaks -atExit -- ./test_executable
	
clean:
	-rm -f *.o *.a $(OUT_FILE) $(LIBRARY) $(TEST_EXECUTABLE)
	-rm -rf report
	-rm -f report.info
	-rm .clang-format
	-make clean_gcov
	#-rm -f valgrind.txt

clean_gcov:
	-rm -f *.gcno *.gcda

rebuild:
	make clean
	make all

clang:
	# cp ../materials/linters/.clang-format ./
	# clang-format -i *.cpp *.h

format_check:
	cp ../materials/linters/.clang-format ./
	clang-format -n $(TEST_FILES) $(FILES) *.h

valgrind: $(LIBRARY)
	$(CC) $(CFLAGS) $(TEST_FILES) $(LIBRARY) -o $(OUT_FILE) $(GTEST_FLAGS)
	valgrind $(VALGRIND_FLAGS) ./$(OUT_FILE)
