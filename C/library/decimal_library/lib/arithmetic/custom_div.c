#include "../decimal_helpers.h"

int custom_div(custom_decimal first_value, custom_decimal second_value,
            custom_decimal *result) {
  int result_value = 0;
  custom_zero_decimal(result);

  int first_val_sign = get_sign(&first_value);
  int second_val_sign = get_sign(&second_value);
  int result_sign = 0;
  custom_decimal one = VALUE_IS_ONE;

  delete_sign(&first_value);
  delete_sign(&second_value);
  int pow1 = custom_get_exp(first_value);
  int pow2 = custom_get_exp(second_value);

  if ((!first_val_sign && second_val_sign) ||
      (first_val_sign && !second_val_sign)) {
    result_sign = 1;
  }

  if (is_zero(second_value)) {
    return 3;
  } else if (custom_is_equal(second_value, one)) {
    *result = first_value;
    result_sign ? set_sign(result) : 0;
    return result_value;
  }
  int is_over = check_over(first_value, second_value);
  if (is_over) {
    if ((!first_val_sign && !second_val_sign) ||
        (first_val_sign && second_val_sign)) {
      return 1;
    } else if ((!first_val_sign && second_val_sign) ||
               (first_val_sign && !second_val_sign)) {
      return 2;
    }
  }
  custom_set_scale(&first_value, 0);
  custom_set_scale(&second_value, 0);
  pow1 > pow2 ? custom_set_scale(result, pow1) : 0;
  custom_binary_div(first_value, second_value, result);
  *result = div_normal(*result, pow1, pow2);

  if (result_sign) {
    set_sign(result);
  }
  return result_value;
}
