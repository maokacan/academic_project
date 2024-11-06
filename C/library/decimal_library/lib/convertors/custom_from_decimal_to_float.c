#include "../../custom_decimal.h"

int custom_from_decimal_to_float(custom_decimal src, float *dst) {
  int error_code = 0;
  double result = 0;
  for (int i = 2; i >= 0; i--) {
    result *= pow(2, 32);
    result += (unsigned int)src.bits[i];
  }
  int exp = custom_get_exp(src);
  result /= pow(10, exp);
  *dst = (float)result;
  if (custom_dec_is_negative(src)) {
    *dst *= -1;
  }
  return error_code;
}