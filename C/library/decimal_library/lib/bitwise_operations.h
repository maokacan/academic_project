#ifndef BITWISE_OPERATIONS_H
#define BITWISE_OPERATIONS_H
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "macro_help.h"

int test_bit(unsigned int value, int BitNumber);
void set_1_bit(unsigned int *value, int BitNumber);
void set_0_bit(unsigned int *value, int BitNumber);
int custom_is_less_num(custom_decimal num1, custom_decimal num2, int result);
int custom_is_greater_num(custom_decimal num1, custom_decimal num2, int result);
int custom_shift(custom_decimal *number);
int custom_addiction_logic(custom_decimal value_1, custom_decimal value_2,
                        custom_decimal *result);
int get_sign(custom_decimal *num);
void mult_10(custom_decimal value, custom_decimal *result);
custom_decimal custom_superior_10(int power, custom_decimal *value);
int custom_10_conv(custom_decimal value);
void custom_rev_10_conv(custom_decimal *value, int result);

void custom_copy_decimal(custom_decimal *src, custom_decimal *dst);
int custom_get_exp(custom_decimal src);
void custom_div_ten(custom_decimal *src);

int custom_set_sign(custom_decimal *value);
void custom_zero_decimal(custom_decimal *dst);
int custom_from_float_to_decimal(float src, custom_decimal *dst);
int custom_from_int_to_decimal(int src, custom_decimal *dst);
void delete_sign(custom_decimal *number);
void set_sign(custom_decimal *number);
int is_zero(custom_decimal number);

void custom_set_bit(custom_decimal *num, int index, int bit);
void custom_set_scale(custom_decimal *num, int scale);
int custom_dec_is_negative(custom_decimal src);

int custom_get_bit(custom_decimal number, int index);
void left_shift(custom_decimal *value);
void right_shift(custom_decimal *value);
int search_unit_bit(custom_decimal src);

#endif  // BITWISE_OPERATIONS_H
