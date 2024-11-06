#ifndef SRC_TEST_H_
#define SRC_TEST_H_

#define RESET "\033[0m"
#define RED "\e[0;91m"
#define GREEN "\033[32m"
#define BLUE "\e[0;94m"

#define CUS_TRUE 1
#define CUS_FALSE 0
#define CONVERTERS_CUS_TRUE 0
#define CONVERTERS_CUS_FALSE 1
#define U_MAX_INT 4294967295          // 0b11111111111111111111111111111111
#define MAX_INT 2147483647            // 0b01111111111111111111111111111111
#define EXPONENT_MINUS_1 2147549184   // 0b10000000000000010000000000000000
#define EXPONENT_PLUS_1 65536         // 0b00000000000000010000000000000000
#define EXPONENT_PLUS_2 196608        // 0b00000000000000110000000000000000
#define EXPONENT_MINUS_28 2149318656  // 0b10000000000111000000000000000000
#define EXPONENT_PLUS_28 1835008      // 0b00000000000111000000000000000000
#define MINUS 2147483648              // 0b10000000000000000000000000000000
#define MAX_DECIMAL 79228162514264337593543950335.0F
#define MIN_DECIMAL -79228162514264337593543950335.0F

#include <check.h>

#include "../custom_decimal.h"

Suite *suite_from_float_to_decimal(void);
Suite *suite_from_int_to_decimal(void);
Suite *suite_is_equal(void);
Suite *suite_is_not_equal(void);
Suite *suite_is_greater(void);
Suite *suite_is_greater_or_equal(void);
Suite *suite_is_less(void);
Suite *suite_is_less_or_equal(void);
void run_tests(void);
void run_testcase(Suite *testcase);

Suite *test_add(void);
Suite *test_sub(void);
Suite *test_mul(void);
Suite *test_dec_to_int(void);
Suite *test_dec_to_float(void);
Suite *test_negate(void);
Suite *test_truncate(void);
Suite *test_div(void);

Suite *test_round(void);
Suite *test_floor(void);

void run_tests2();

#endif  // SRC_TESTS_TESTS_SUITCASES_H_
