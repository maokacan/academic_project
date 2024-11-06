#include "../../custom_decimal.h"

int custom_from_int_to_decimal(int src, custom_decimal *dst) {
  custom_zero_decimal(dst);
  int error = 0;
  if (src < 0) {
    custom_set_sign(dst);
    src = (-1) * src;
  }
  if (src > INT_MAX)
    error = 1;
  else
    dst->bits[0] = src;
  return error;
}