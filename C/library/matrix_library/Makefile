CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
GCOV_FLAGS = -fprofile-arcs -ftest-coverage
LIBS = -lcheck
LDFLAGS = -L/usr/local/lib -I/usr/local/include

OS = $(shell uname -s)
HDR = ./lib/*.h ./*.h
TEST_HDR = ./tests/*.h
SRC_FUNCTIONS = ./lib/*.c ./lib/matrix_operations/*.c
OBJ_FUNCTION = *.o
TEST_FUNCTIONS = ./tests/*.c ./tests/tests_operations/*.c

custom_matrix.a: ${SRC_FUNCTIONS}
	${CC} $(CFLAGS) -c $(SRC_FUNCTIONS)
	ar rc custom_matrix.a $(OBJ_FUNCTION)

check:
	clang-format -style=Google -n ${SRC_FUNCTIONS} ${HDR} ${TEST_FUNCTIONS} ${TEST_HDR}
	cppcheck --enable=all --suppress=missingIncludeSystem ${SRC_FUNCTIONS} ${HDR} ${TEST_FUNCTIONS} ${TEST_HDR}

check_i:
	clang-format -style=Google -i ${SRC_FUNCTIONS} ${HDR} ${TEST_FUNCTIONS} ${TEST_HDR}

test: custom_matrix.a
ifeq ($(OS), Darwin)
	$(CC) $(CFLAGS) $(LDFLAGS) $(TEST_FUNCTIONS) -o test custom_matrix.a $(LIBS)
 else # Флаги для GNU
	$(CC) $(CFLAGS) $(LDFLAGS) $(TEST_FUNCTIONS) -o test custom_matrix.a $(LIBS) $(UBUNTU_FLAGS)
endif
	./test

gcov_report:
ifeq ($(OS), Darwin)
	$(CC) $(CFLAGS) $(LDFLAGS) $(GCOV_FLAGS) $(SRC_FUNCTIONS) $(TEST_FUNCTIONS) -o test $(LIBS)
 else # Флаги для GNU
	$(CC) $(CFLAGS) $(LDFLAGS) $(GCOV_FLAGS) $(SRC_FUNCTIONS) $(TEST_FUNCTIONS) -o test $(LIBS) $(UBUNTU_FLAGS)
endif
	./test
	mv *.gc* tests
	lcov -o ./tests/tests.info -c -d tests
	genhtml -o report ./tests/tests.info
	open ./report/index.html

clean:
	rm -rf report *.o *.a tests/*.gcno tests/*.gcda tests/*.gcov tests/*.info test

rebuild: clean custom_matrix.a