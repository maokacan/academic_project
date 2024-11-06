#ifndef HELPERS_H
#define HELPERS_H

#include "../../custom_decimal.h"
#include "../macro_help.h"

typedef struct {
  unsigned int bits[8];
} custom_big_decimal;

// bigdec_bitwise.c
int bd_get_bit(custom_big_decimal num, int bit);
void bd_set_bit(custom_big_decimal *num, int bit);
void bd_unset_bit(custom_big_decimal *num, int bit);
int bd_get_sign(custom_big_decimal num);
void bd_set_sign(custom_big_decimal *num, int sign);
int bd_get_scale(custom_big_decimal num);
void bd_set_scale(custom_big_decimal *num, int scale);
int bd_is_empty(custom_big_decimal num);
void bd_reset(custom_big_decimal *num);

// bigdec_operations.c
void bd_shift_left(custom_big_decimal *num, int shift);
void bd_sum_mantise(custom_big_decimal num_1, custom_big_decimal num_2,
                    custom_big_decimal *result);
void bd_inversion(custom_big_decimal *num);
int bd_mantise_is_bigger(custom_big_decimal num_1, custom_big_decimal num_2);
void bd_mult_10(custom_big_decimal *num);
int bd_div_10(custom_big_decimal *num);
void bd_normalization(custom_big_decimal *num_1, custom_big_decimal *num_2);

void custom_mul_big_dec(custom_big_decimal value_1, custom_big_decimal value_2,
                     custom_big_decimal *result);
void custom_add_big_dec(custom_big_decimal value_1, custom_big_decimal value_2,
                     custom_big_decimal *result);
void custom_set_big_bit(custom_big_decimal *num, int index, int bit);

// bigdec_converters.c
void decimal_to_big_decimal(custom_decimal decimal, custom_big_decimal *result);
int big_decimal_to_decimal(custom_big_decimal num, custom_decimal *result);

#endif