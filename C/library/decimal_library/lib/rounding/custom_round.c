#include "../decimal_helpers.h"

int custom_round(custom_decimal value, custom_decimal *result) {
  if (result == NULL) {
    return 1;
  }
  int sign = get_sign(&value);
  custom_zero_decimal(result);
  custom_decimal remainder;
  custom_zero_decimal(&remainder);
  custom_decimal five = {{5}};
  custom_decimal one = VALUE_IS_ONE;
  delete_sign(&value);
  custom_set_scale(&five, 1);
  custom_truncate(value, result);
  custom_remainder(value, one, &remainder);
  if (!custom_is_less(remainder, five)) {
    custom_add(*result, one, result);
  }
  if (sign) {
    set_sign(result);
  }
  return 0;
}
