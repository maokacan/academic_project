#include "../../custom_decimal.h"

int custom_is_equal(custom_decimal num1, custom_decimal num2) {
  int sign_num1 = get_sign(&num1);
  int sign_num2 = get_sign(&num2);
  int result = -1;
  if (sign_num1 == sign_num2) {
    if (num1.bits[3] == num2.bits[3]) {
      if (num1.bits[2] == num2.bits[2]) {
        if (num1.bits[1] == num2.bits[1]) {
          if (num1.bits[0] == num2.bits[0]) {
            result = 1;
          } else {
            result = 0;
          }
        } else {
          result = 0;
        }
      } else {
        result = 0;
      }
    } else {
      int exp1;
      int exp2;
      exp1 = custom_10_conv(num1);
      exp2 = custom_10_conv(num2);
      if (exp1 > exp2) {
        num2 = custom_superior_10(exp1, &num2);
      } else if (exp2 > exp1) {
        num1 = custom_superior_10(exp2, &num1);
      }
      if (num1.bits[3] == num2.bits[3]) {
        if (num1.bits[2] == num2.bits[2]) {
          if (num1.bits[1] == num2.bits[1]) {
            if (num1.bits[0] == num2.bits[0]) {
              result = 1;
            } else {
              result = 0;
            }
          } else {
            result = 0;
          }
        } else {
          result = 0;
        }
      } else {
        result = 0;
      }
    }
  } else {
    result = 0;
  }
  return result;
}
