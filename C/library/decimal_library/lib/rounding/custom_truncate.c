#include "../../custom_decimal.h"

int custom_truncate(custom_decimal value, custom_decimal *result) {
  int exp = custom_get_exp(value);
  while (exp) {
    custom_div_ten(&value);
    exp--;
  }
  custom_set_scale(&value, exp);
  custom_copy_decimal(&value, result);
  return 0;
}