CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
GCOV_FLAGS = -fprofile-arcs -ftest-coverage
UBUNTU_FLAGS = -lsubunit -lrt -lpthread -lm
LIBS = -lcheck
LDFLAGS = -L/usr/local/lib -I/usr/local/include

OS = $(shell uname -s)

HDR = ./lib/*.h ./lib/comparison/*.h ./lib/convertors/*.h ./lib/arithmetic/*.h ./lib/rounding/*.h ./lib/bigdec_helpers/*.h
SRC_FUNCTIONS = ./lib/*.c ./lib/comparison/*.c ./lib/convertors/*.c ./lib/arithmetic/*.c ./lib/rounding/*.c ./lib/bigdec_helpers/*.c
OBJ_FUNCTION = *.o
TEST_FUNCTIONS = ./tests/*.c

all: custom_decimal.a gcov_report
	
custom_decimal.a: ${SRC_FUNCTIONS}
	${CC} $(CFLAGS) -c $(SRC_FUNCTIONS)
	ar rc custom_decimal.a $(OBJ_FUNCTION)

check:
	clang-format -style=Google -n ${SRC_FUNCTIONS} ${HDR}

test: custom_decimal.a
ifeq ($(OS), Darwin)
	$(CC) $(CFLAGS) $(LDFLAGS) $(TEST_FUNCTIONS) -o test custom_decimal.a $(LIBS)
 else # Флаги для GNU 
	$(CC) $(CFLAGS) $(LDFLAGS) $(TEST_FUNCTIONS) -o test custom_decimal.a $(LIBS) $(UBUNTU_FLAGS)
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

rebuild: clean custom_decimal.a
