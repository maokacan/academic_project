#include "../../custom_decimal.h"

int custom_mul(custom_decimal value_1, custom_decimal value_2, custom_decimal *result) {
  int error = 0;
  custom_big_decimal num_1, num_2, big_res;
  bd_reset(&num_1);
  bd_reset(&num_2);
  bd_reset(&big_res);
  decimal_to_big_decimal(value_1, &num_1);
  decimal_to_big_decimal(value_2, &num_2);
  custom_mul_big_dec(num_1, num_2, &big_res);

  error = big_decimal_to_decimal(big_res, result);

  return error;
}
