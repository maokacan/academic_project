#include "bigdec_helpers.h"

void decimal_to_big_decimal(custom_decimal decimal, custom_big_decimal *result) {
  bd_reset(result);
  for (int i = 0; i < 3; i++) {
    result->bits[i] = decimal.bits[i];
  }
  result->bits[7] = decimal.bits[3];
}

int big_decimal_to_decimal(custom_big_decimal num, custom_decimal *result) {
  int err = 0;
  int scale = bd_get_scale(num);
  int sign = bd_get_sign(num);

  int overflow =
      (num.bits[6] || num.bits[5] || num.bits[4] || num.bits[3]) != 0;
  while (overflow && scale > 0) {
    bd_div_10(&num);
    scale--;
    overflow = (num.bits[6] | num.bits[5] | num.bits[4] | num.bits[3]) != 0;
  }

  if (overflow == 0 && !bd_is_empty(num)) {
    bd_set_scale(&num, scale);
    bd_set_sign(&num, sign);
    for (int i = 0; i < 3; i++) {
      result->bits[i] = num.bits[i];
    }
    result->bits[3] = num.bits[7];

  } else if (overflow && sign == 0) {
    err = BIG_NUMBER;

  } else if (overflow && sign == 1) {
    err = SMALL_NUMBER;
  }

  for (int i = 0; i < 3; i++) {
    result->bits[i] = num.bits[i];
  }
  result->bits[3] = num.bits[7];

  return err;
}
