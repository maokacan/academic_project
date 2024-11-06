#ifndef CUS_DECIMAL_H
#define CUS_DECIMAL_H

#include "./lib/bigdec_helpers/bigdec_helpers.h"
#include "./lib/bitwise_operations.h"

int custom_add(custom_decimal value_1, custom_decimal value_2, custom_decimal *result);
int custom_sub(custom_decimal value_1, custom_decimal value_2, custom_decimal *result);
int custom_mul(custom_decimal value_1, custom_decimal value_2, custom_decimal *result);
int custom_div(custom_decimal value_1, custom_decimal value_2, custom_decimal *result);

int custom_is_less(custom_decimal num1, custom_decimal num2);
int custom_is_less_or_equal(custom_decimal num1, custom_decimal num2);
int custom_is_greater(custom_decimal num1, custom_decimal num2);
int custom_is_greater_or_equal(custom_decimal num1, custom_decimal num2);
int custom_is_equal(custom_decimal num1, custom_decimal num2);
int custom_is_not_equal(custom_decimal num1, custom_decimal num2);

int custom_from_float_to_decimal(float src, custom_decimal *dst);
int custom_from_int_to_decimal(int src, custom_decimal *dst);
int custom_from_decimal_to_float(custom_decimal src, float *dst);
int custom_from_decimal_to_int(custom_decimal src, int *dst);

int custom_negate(custom_decimal value, custom_decimal *result);
int custom_truncate(custom_decimal value, custom_decimal *result);
int custom_floor(custom_decimal value, custom_decimal *result);
int custom_round(custom_decimal value, custom_decimal *result);

#endif  // CUS_DECIMAL_H
