#include "../../custom_decimal.h"

int custom_is_greater(custom_decimal num1, custom_decimal num2) {
  int result = -1;
  int sign_num1 = get_sign(&num1);
  int sign_num2 = get_sign(&num2);
  if (sign_num1 == sign_num2 && sign_num1 == 0) {  // оба положительные
    result = custom_is_greater_num(num1, num2, result);
  } else if (sign_num1 == 1 &&
             sign_num2 == 0) {  // num1 - отрицательный, num2 - положительный
    result = 0;
  } else if (sign_num1 == 0 &&
             sign_num2 == 1) {  // num1 - положительный, num2 - отрицательный
    result = 1;
  } else if (sign_num1 == sign_num2 && sign_num1 == 1) {  // оба отрицательный
    // result = !custom_is_greater_num(num1, num2, result);
    if (num1.bits[3] == num2.bits[3] && num1.bits[2] == num2.bits[2] &&
        num1.bits[1] == num2.bits[1] && num1.bits[0] == num2.bits[0]) {
      result = 0;
    } else {
      result = !custom_is_greater_num(num1, num2, result);
    }
    //     if (num1.bits[2] == num2.bits[2]) {
    //         if (num1.bits[1] == num2.bits[1]) {
    //             if (num1.bits[0] == num2.bits[0]) {
    //                 result = 0;
    //             } else {
    //                 result = !custom_is_greater_num(num1, num2, result);  // не
    //                 зашло
    //             }
    //         } else {
    //                 result = !custom_is_greater_num(num1, num2, result);  // не
    //                 зашло
    //         }
    //     } else {
    //         result = !custom_is_greater_num(num1, num2, result);
    //     }
    // } else {
    //     result = !custom_is_greater_num(num1, num2, result);
    // }
  }
  return result;
}