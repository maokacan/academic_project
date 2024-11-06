#include "bigdec_helpers.h"

void bd_shift_left(custom_big_decimal *num, int shift) {
  unsigned int tmp1 = 0;
  unsigned int tmp2 = 0;
  for (int i = 0; i < 7; i++) {
    tmp1 = num->bits[i] >> (32 - shift);
    num->bits[i] = num->bits[i] << shift;
    num->bits[i] |= tmp2;
    tmp2 = tmp1;
  }
}

void bd_sum_mantise(custom_big_decimal num_1, custom_big_decimal num_2,
                    custom_big_decimal *result) {
  int scale = bd_get_scale(num_1);
  bd_reset(result);
  int carry = 0;
  for (int i = 0; i < 7 * 32; i++) {
    int sum = bd_get_bit(num_1, i) + bd_get_bit(num_2, i) + carry;
    if ((sum % 2) == 1) {
      bd_set_bit(result, i);
    }
    carry = sum / 2;
  }
  bd_set_scale(result, scale);
}

void bd_mult_10(custom_big_decimal *num) {
  custom_big_decimal tmp1 = *num;
  custom_big_decimal tmp2 = *num;

  bd_shift_left(&tmp1, 3);
  bd_shift_left(&tmp2, 1);
  bd_sum_mantise(tmp1, tmp2, num);
}

int bd_div_10(custom_big_decimal *num) {
  int scale = (num->bits[7] << 1) >> 17;
  int sign = num->bits[7] >> 31;

  unsigned int current_div_part = 0;
  unsigned int result = 0;
  unsigned int remainder = 0;

  custom_big_decimal res_num = {{0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
                              0xffffffff, 0xffffffff, 0xffffffff, 0}};

  bd_set_scale(&res_num, scale);
  bd_set_sign(&res_num, sign);

  for (int i = 6; i >= 0; i--) {
    for (int j = 0; j < 2; j++) {
      if (j == 0) {
        for (int k = 31; k >= 16; k--) {
          if (bd_get_bit(*num, i * 32 + k)) {
            current_div_part = current_div_part | (1 << (k - 16));
          }
        }

        current_div_part += (remainder << 16);

        result = current_div_part / 10;
        remainder = current_div_part % 10;

        res_num.bits[i] &= (result << 16) | 0x0000ffff;

      } else {
        for (int k = 15; k >= 0; k--) {
          if (bd_get_bit(*num, i * 32 + k)) {
            current_div_part = current_div_part | (1 << k);
          }
        }

        current_div_part += (remainder << 16);

        remainder = current_div_part % 10;
        result = current_div_part / 10;

        res_num.bits[i] &= ((result) | 0xffff0000);
      }
      current_div_part = 0;
    }
  }

  custom_big_decimal tmp = res_num;
  custom_big_decimal one = {{1, 0, 0, 0, 0, 0, 0, 0}};
  // округление
  if (remainder > 5) {
    bd_sum_mantise(tmp, one, &res_num);
  } else if (remainder == 5) {
    if (bd_get_bit(res_num, 0)) {
      bd_sum_mantise(tmp, one, &res_num);
    }
  }
  *num = res_num;
  return remainder;
}

void bd_inversion(custom_big_decimal *num) {
  for (int i = 0; i < 7; i++) {
    num->bits[i] = ~(num->bits[i]);
  }

  int carry = 1;
  for (int i = 0; i < 7 * 32; i++) {
    int sum = bd_get_bit(*num, i) + carry;
    if ((sum % 2) == 1) {
      bd_set_bit(num, i);
    } else {
      bd_unset_bit(num, i);
    }
    carry = sum / 2;
  }
}

int bd_mantise_is_bigger(custom_big_decimal num_1, custom_big_decimal num_2) {
  int res = 0;
  for (int i = 6; (i >= 0) && res != 1 && res != -1; i--) {
    if (num_1.bits[i] > num_2.bits[i]) {
      res = 1;
    } else if (num_1.bits[i] < num_2.bits[i]) {
      res = -1;
    }
  }
  return res;
}

void bd_normalization(custom_big_decimal *num_1, custom_big_decimal *num_2) {
  int max_scale = bd_get_scale(*num_1);
  int min_scale = bd_get_scale(*num_2);

  custom_big_decimal *max_scale_big_decimal = num_1;
  custom_big_decimal *min_scale_big_decimal = num_2;

  if (max_scale < min_scale) {
    max_scale_big_decimal = num_2;
    min_scale_big_decimal = num_1;
    max_scale = bd_get_scale(*num_2);
    min_scale = bd_get_scale(*num_1);
  }

  int sign_min_scale_decimal = bd_get_sign(*min_scale_big_decimal);
  int sign_max_scale_decimal = bd_get_sign(*max_scale_big_decimal);

  int difference = max_scale - min_scale;

  while (difference != 0) {
    bd_mult_10(min_scale_big_decimal);
    min_scale++;
    bd_set_scale(min_scale_big_decimal, min_scale);
    difference = max_scale - min_scale;
  }

  bd_set_sign(min_scale_big_decimal, sign_min_scale_decimal);
  bd_set_sign(max_scale_big_decimal, sign_max_scale_decimal);
}

void custom_mul_big_dec(custom_big_decimal value_1, custom_big_decimal value_2,
                     custom_big_decimal *result) {
  int first_val_scale = bd_get_scale(value_1);
  int second_val_scale = bd_get_scale(value_2);
  int first_val_sign = bd_get_sign(value_1);
  int second_val_sign = bd_get_sign(value_2);
  custom_big_decimal var;
  bd_reset(&var);
  for (int i = 0; i < 192; i++) {
    if (bd_get_bit(value_2, i)) {
      var = value_1;
      bd_shift_left(&var, i);
      custom_add_big_dec(var, *result, result);
    }
    bd_reset(&var);
  }
  bd_set_scale(result, first_val_scale + second_val_scale);
  bd_set_sign(result, first_val_sign ^ second_val_sign);
}

void custom_add_big_dec(custom_big_decimal value_1, custom_big_decimal value_2,
                     custom_big_decimal *result) {
  int remainder = 0, first_val_bit = 0, second_val_bit = 0, bit_sum = 0;
  for (int i = 0; i < 192; i++) {
    first_val_bit = bd_get_bit(value_1, i);
    second_val_bit = bd_get_bit(value_2, i);
    bit_sum = first_val_bit ^ second_val_bit ^ remainder;
    custom_set_big_bit(result, i, bit_sum);
    remainder = (first_val_bit && second_val_bit) ||
                (first_val_bit && remainder) || (second_val_bit && remainder);
  }
}

// возможно есть такая же
void custom_set_big_bit(custom_big_decimal *num, int index, int bit) {
  if (bit == 1) {
    num->bits[index / 32] = num->bits[index / 32] | (1 << index % 32);
  } else {
    num->bits[index / 32] = num->bits[index / 32] & ~(1 << index % 32);
  }
}