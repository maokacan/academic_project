#include "../../custom_decimal.h"

int custom_from_decimal_to_int(custom_decimal src, int *dst) {
  int error_code = 0;
  custom_truncate(src, &src);
  *dst = src.bits[0];
  if (custom_dec_is_negative(src)) {
    *dst *= -1;
  }
  return error_code;
}