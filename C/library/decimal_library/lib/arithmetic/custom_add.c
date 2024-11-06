#include "../../custom_decimal.h"

int custom_add(custom_decimal value_1, custom_decimal value_2, custom_decimal *result) {
  int err = 0;

  custom_big_decimal num_1;
  custom_big_decimal num_2;
  custom_big_decimal big_res;

  decimal_to_big_decimal(value_1, &num_1);
  decimal_to_big_decimal(value_2, &num_2);
  int sign1 = bd_get_sign(num_1);
  int sign2 = bd_get_sign(num_2);

  if (sign1 == sign2) {
    bd_normalization(&num_1, &num_2);
    bd_sum_mantise(num_1, num_2, &big_res);

    bd_set_scale(&big_res, bd_get_scale(num_1));
    bd_set_sign(&big_res, sign1);

    err = big_decimal_to_decimal(big_res, result);

  } else if (sign1 == 1) {
    value_1.bits[3] &= ~(1 << 31);
    err = custom_sub(value_2, value_1, result);

  } else {
    value_2.bits[3] &= ~(1 << 31);
    err = custom_sub(value_1, value_2, result);
  }

  return err;
}