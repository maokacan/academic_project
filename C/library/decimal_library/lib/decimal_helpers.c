#include "decimal_helpers.h"

custom_decimal whole_part(custom_decimal first_value, custom_decimal second_value,
                       custom_decimal* result) {
  custom_decimal result_sub;
  custom_zero_decimal(&result_sub);
  custom_decimal one_res = VALUE_IS_ONE;
  custom_decimal replace_val = second_value;
  if (custom_is_less(first_value, second_value)) {
    *result = result_sub;
    return result_sub;
  } else if (custom_is_equal(first_value, second_value)) {
    return one_res;
  }
  while (search_unit_bit(first_value) > search_unit_bit(replace_val)) {
    left_shift(&replace_val);
    left_shift(result);
  }
  if (custom_is_less(first_value, replace_val)) {
    right_shift(&replace_val);
    right_shift(result);
  }
  custom_sub(first_value, replace_val, &result_sub);
  one_res = whole_part(result_sub, second_value, &one_res);
  custom_add(*result, one_res, result);
  return *result;
}

custom_decimal bin_remainder(custom_decimal first_value, custom_decimal second_value) {
  custom_decimal result_sub, result;
  custom_zero_decimal(&result_sub);
  custom_zero_decimal(&result);
  custom_decimal replace_val = second_value;
  if (custom_is_less(first_value, second_value)) {
    return first_value;
  } else if (custom_is_equal(first_value, second_value)) {
    return result_sub;
  }
  while (search_unit_bit(first_value) > search_unit_bit(replace_val)) {
    left_shift(&replace_val);
  }
  if (custom_is_less(first_value, replace_val)) {
    right_shift(&replace_val);
  }
  custom_sub(first_value, replace_val, &result_sub);
  result = bin_remainder(result_sub, second_value);
  return result;
}

custom_decimal div_normal(custom_decimal result_dif, int first_value_scale,
                       int second_value_scale) {
  int difference;
  custom_decimal ten = {{10}};
  if (first_value_scale > second_value_scale) {
    difference = first_value_scale - second_value_scale;
    int result_power = custom_get_exp(result_dif) + difference;
    if (result_power > 28) {
      result_power = 28;
    }
    custom_set_scale(&result_dif, result_power);
  } else if (first_value_scale < second_value_scale) {
    difference = second_value_scale - first_value_scale;
    int result_power = custom_get_exp(result_dif) - difference;
    result_power = result_power < 0 ? 0 : result_power;
    custom_set_scale(&result_dif, 0);
    while (difference) {
      custom_mul(result_dif, ten, &result_dif);
      difference--;
    }
    custom_set_scale(&result_dif, result_power);
  }
  return result_dif;
}

custom_decimal bin_bank_round(custom_decimal last_decimal, custom_decimal pre_digit,
                           custom_decimal result) {
  custom_decimal two = {{2}};
  custom_decimal five = {{5}};
  custom_decimal is_even;
  custom_zero_decimal(&is_even);
  custom_decimal one = VALUE_IS_ONE;
  if (custom_is_equal(last_decimal, five)) {
    custom_remainder(pre_digit, two, &is_even);
    if (!is_zero(is_even)) {
      custom_add(result, one, &result);
    }
  } else if (custom_is_less(five, last_decimal)) {
    custom_add(result, one, &result);
  }
  return result;
}
custom_decimal bank_round(custom_decimal value) {
  custom_decimal ten = {{10}};
  custom_decimal last_decimal = VALUE_IS_ZERO;
  custom_zero_decimal(&last_decimal);
  custom_decimal result = VALUE_IS_ONE;

  custom_remainder(value, ten, &last_decimal);
  custom_decimal pre_digit = get_pre_digit(value);
  whole_part(value, ten, &result);

  return bin_bank_round(last_decimal, pre_digit, result);
}

custom_decimal get_pre_digit(custom_decimal value) {
  custom_decimal ten = {{10}};
  custom_decimal div_result = VALUE_IS_ONE;
  custom_decimal pre_digit = VALUE_IS_ZERO;
  custom_zero_decimal(&pre_digit);
  whole_part(value, ten, &div_result);
  custom_remainder(div_result, ten, &pre_digit);
  return pre_digit;
}

custom_decimal custom_binary_div(custom_decimal first_value, custom_decimal second_value,
                           custom_decimal* result) {
  unsigned int pre_digit = 0;
  custom_decimal inter_result = VALUE_IS_ONE;
  custom_decimal result_sub;
  custom_zero_decimal(&result_sub);
  custom_decimal one = VALUE_IS_ONE;
  custom_decimal replace_val = second_value;
  if (custom_is_less(first_value, second_value)) {
    custom_decimal ten = {{10}};
    if (!is_zero(first_value)) {
      int is_over = 0;
      int power = custom_get_exp(*result);
      if (power == 28) {
        is_over = 1;
      } else {
        is_over = custom_mul(*result, ten, result);
      }
      power += 1;
      custom_mul(first_value, ten, &first_value);
      if (is_over) {
        whole_part(first_value, second_value, &inter_result);
        custom_decimal pre_digit_dec = {{pre_digit}};
        *result = bin_bank_round(inter_result, pre_digit_dec, *result);
        return result_sub;
      }
      custom_set_scale(result, power);
      pre_digit = 0;
      custom_binary_div(first_value, second_value, result);
    }
    return result_sub;
  } else if (custom_is_equal(first_value, second_value)) {
    custom_add(*result, one, result);
    return one;
  }
  while (search_unit_bit(first_value) > search_unit_bit(replace_val)) {
    left_shift(&replace_val);
    left_shift(&inter_result);
  }
  if (custom_is_less(first_value, replace_val)) {
    right_shift(&replace_val);
    right_shift(&inter_result);
  }
  custom_add(*result, inter_result, result);
  custom_sub(first_value, replace_val, &result_sub);
  pre_digit += inter_result.bits[0];
  custom_binary_div(result_sub, second_value, result);
  return *result;
}

int check_over(custom_decimal first_value, custom_decimal second_value) {
  int check_over = 0;
  int first_value_scale = custom_get_exp(first_value);
  int second_value_scale = custom_get_exp(second_value);
  custom_set_scale(&first_value, 0);
  custom_set_scale(&second_value, 0);

  int max_scale = first_value_scale > second_value_scale ? first_value_scale
                                                         : second_value_scale;
  int min_scale = first_value_scale < second_value_scale ? first_value_scale
                                                         : second_value_scale;
  custom_decimal num_normalize =
      first_value_scale < second_value_scale ? first_value : second_value;
  custom_decimal small =
      first_value_scale < second_value_scale ? second_value : first_value;
  custom_decimal result;
  custom_zero_decimal(&result);
  custom_decimal ten = {{10}};

  while (min_scale != max_scale) {
    check_over = custom_mul(num_normalize, ten, &result);
    if (check_over) {
      break;
    }
    min_scale++;
    num_normalize = result;
    custom_zero_decimal(&result);
  }

  if (check_over) {
    while (min_scale < max_scale) {
      small = bank_round(small);
      min_scale++;
    }
    if (is_zero(small)) {
      return check_over;
    }
  }
  return 0;
}

int custom_remainder(custom_decimal first_value, custom_decimal second_value,
                  custom_decimal* result) {
  custom_zero_decimal(result);
  if (is_zero(second_value)) {
    return 3;
  }
  int sign = get_sign(&first_value);
  delete_sign(&first_value);
  delete_sign(&second_value);
  int pow_1 = custom_get_exp(first_value);
  int pow_2 = custom_get_exp(second_value);
  int is_over = custom_normalization(&first_value, &second_value);
  if (is_over && is_zero(second_value)) {
    return 0;
  }
  custom_set_scale(&first_value, 0);
  custom_set_scale(&second_value, 0);
  *result = bin_remainder(first_value, second_value);
  if (sign) {
    set_sign(result);
  }
  int max = pow_1 > pow_2 ? pow_1 : pow_2;
  custom_set_scale(result, max);
  if (is_over) {
    custom_truncate(*result, result);
  }
  return 0;
}

int custom_normalization(custom_decimal* first_value, custom_decimal* second_value) {
  int check_over = 0;
  int first_value_scale = custom_get_exp(*first_value);
  int second_value_scale = custom_get_exp(*second_value);
  custom_set_scale(first_value, 0);
  custom_set_scale(second_value, 0);

  int max_scale = first_value_scale > second_value_scale ? first_value_scale
                                                         : second_value_scale;
  int min_scale = first_value_scale < second_value_scale ? first_value_scale
                                                         : second_value_scale;
  custom_decimal num_normalize =
      first_value_scale < second_value_scale ? *first_value : *second_value;
  custom_decimal small =
      first_value_scale < second_value_scale ? *second_value : *first_value;
  custom_decimal result = VALUE_IS_ZERO;
  custom_decimal ten = {{10}};

  while (min_scale != max_scale) {
    check_over = custom_mul(num_normalize, ten, &result);
    if (check_over) {
      break;
    }
    min_scale++;
    num_normalize = result;
    custom_zero_decimal(&result);
  }
  if (check_over) {
    while (min_scale < max_scale) {
      small = bank_round(small);
      min_scale++;
    }
  }
  if (first_value_scale < second_value_scale) {
    *first_value = num_normalize;
    *second_value = small;
  } else {
    *second_value = num_normalize;
    *first_value = small;
  }
  custom_set_scale(first_value, max_scale);
  custom_set_scale(second_value, max_scale);
  return check_over;
}
