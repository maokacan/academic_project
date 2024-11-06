FLAGS = -Wall -Werror -Wextra
LIB = ./lib/*.c
TEST = ./tests/*.c

all: custom_string.a test gcov_report

custom_string: custom_string.o

custom_string.o: custom_string.c
	gcc $(FLAGS) -c $(LIB)

custom_string.a:
	gcc $(FLAGS) -c $(LIB)
	ar r custom_string.a *.o
	rm *.o

check:
	clang-format -style=Google -n *.c *.h

test: custom_string.a
	gcc $(FLAGS) $(TEST) $(LIB) custom_string.a -lcheck -lm -lpthread --coverage -o test
	./test

gcov_report:
	lcov -t "test_info" -o test.info -c -d .
	genhtml -o report test.info
	open ./report/index.html

clean:
	rm -rf report *.o *.a *.gcno *.gcda  *.info test

rebuild: clean custom_string.a