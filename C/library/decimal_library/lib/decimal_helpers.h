#ifndef DECIMAL_HELPERS_H
#define DECIMAL_HELPERS_H

#include "../custom_decimal.h"
custom_decimal whole_part(custom_decimal first_value, custom_decimal second_value,
                       custom_decimal* result);
custom_decimal bin_remainder(custom_decimal first_value, custom_decimal second_value);
custom_decimal div_normal(custom_decimal result_dif, int first_value_scale,
                       int second_value_scale);
custom_decimal custom_binary_div(custom_decimal first_value, custom_decimal second_value,
                           custom_decimal* result);
custom_decimal bank_round(custom_decimal value);
custom_decimal bin_bank_round(custom_decimal last_decimal, custom_decimal pre_digit,
                           custom_decimal result);
custom_decimal get_pre_digit(custom_decimal value);
int check_over(custom_decimal first_value, custom_decimal second_value);
int custom_remainder(custom_decimal first_value, custom_decimal second_value,
                  custom_decimal* result);
int custom_normalization(custom_decimal* first_value, custom_decimal* second_value);

#endif  //  DECIMAL_HELPERS_H
