CC = g++
TEST_LIBS = -lgtest -lgtest_main
ifeq ($(shell uname -s), Linux)
	TEST_LIBS += -lsubunit -lm -pthread
endif
CFLAGS = -std=c++17 -Wall -Werror -Wextra -Wno-sign-compare
SRC_TEST_DIR = ./tests/
SRC_TEST	= $(wildcard $(SRC_TEST_DIR)*.cc)

ifeq ($(shell uname -s), Linux)
    GTEST_FLAGS += -lm -lsubunit
    OPEN = xdg-open
else
    OPEN = open
endif

GCOV_FLAGS = -fprofile-arcs -ftest-coverage
TEST_EXECUTABLE = test_executable

all: style test gcov_report

test:
	$(CC) $(CFLAGS) $(SRC_TEST) -o test $(TEST_LIBS)
	./test
	rm -rf tests/*.o

style:
	# cp ../materials/linters/.clang-format ./
	# clang-format --style=google -n *.h ./lib/*.h
	# clang-format --style=google -n tests/*.cc

gcov_report:
	$(CC) -g $(CFLAGS) $(GCOV_FLAGS) $(SRC_TEST) -o $(TEST_EXECUTABLE) $(TEST_LIBS)
	-./$(TEST_EXECUTABLE)
	lcov -t "gcov_report" -o report.info --no-external -c -d . --ignore-errors inconsistent
	genhtml -o report report.info --ignore-errors inconsistent
	$(OPEN) ./report/index.html

test_leaks:
	$(CC) $(CFLAGS) $(SRC_TEST) -o test $(TEST_LIBS)
	rm -rf tests/*.o
ifeq ($(shell uname -s), Linux)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./test
else
	leaks --atExit -- ./test
endif

clean_gcov:
	-rm -f *.gcno *.gcda
	rm -rf report test_executable.dSYM
	rm test_executable report.info

clean: clean_gcov
	rm -rf *.o tests/*.o test

.PHONY: all clean test style