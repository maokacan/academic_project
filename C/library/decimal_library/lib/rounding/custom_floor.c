#include "../decimal_helpers.h"

int custom_floor(custom_decimal value, custom_decimal *result) {
  if (result != NULL) {
    custom_zero_decimal(result);
    custom_decimal one = VALUE_IS_ONE;
    custom_decimal remainder;
    custom_zero_decimal(&remainder);
    int sign = get_sign(&value);
    delete_sign(&value);
    custom_remainder(value, one, &remainder);
    custom_truncate(value, &value);
    if (sign && !is_zero(remainder) && !is_zero(value)) {
      custom_add(value, one, result);
      set_sign(result);
    } else {
      *result = value;
      if (sign) {
        set_sign(result);
      }
    }
  } else {
    return 1;
  }
  return 0;
}
