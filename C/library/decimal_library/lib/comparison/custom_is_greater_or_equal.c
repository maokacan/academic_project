#include "../../custom_decimal.h"

int custom_is_greater_or_equal(custom_decimal num1, custom_decimal num2) {
  return (custom_is_greater(num1, num2) || custom_is_equal(num1, num2));
}