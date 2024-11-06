#include "../../custom_decimal.h"

int custom_negate(custom_decimal value, custom_decimal *result) {
  value.bits[3] ^= (1 << 31);
  custom_copy_decimal(&value, result);
  return 0;
}