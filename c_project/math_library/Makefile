FLAGS = -Wall -Werror -Wextra

all: custom_math.a test gcov_report

custom_math: custom_math.o

custom_math.o: custom_math.c
	gcc $(FLAGS) -c custom_math.c

custom_math.a:
	gcc $(FLAGS) -c custom_*.c
	ar r custom_math.a *.o 
	rm *.o

check:
	clang-format -style=Google -n *.c *.h

test: custom_math.a
	gcc $(FLAGS) test.c custom_math.c custom_math.a -lcheck -lm -lpthread --coverage -o test
	./test

gcov_report:
	gcov *.c
	lcov -t "test_info" -o test.info -c -d .
	lcov -r test.info "/usr/include/*" -o test.info
	genhtml -o report test.info
	open ./report/index.html

clean:
	rm -rf report *.o *.a *.gcno *.gcda *.gcov *.info test

rebuild: clean custom_math.a
