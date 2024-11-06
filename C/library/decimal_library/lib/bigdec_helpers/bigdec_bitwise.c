#include "bigdec_helpers.h"

int bd_get_bit(custom_big_decimal num, int bit) {
  unsigned int mask = 1 << (bit % 32);
  return (num.bits[bit / 32] & mask) >> (bit % 32);
}

void bd_set_bit(custom_big_decimal *num, int bit) {
  unsigned int mask = 1 << (bit % 32);
  num->bits[bit / 32] |= mask;
}

void bd_unset_bit(custom_big_decimal *num, int bit) {
  unsigned int mask = ~(1 << (bit % 32));
  num->bits[bit / 32] &= mask;
}

int bd_get_sign(custom_big_decimal num) { return num.bits[7] >> 31; }

void bd_set_sign(custom_big_decimal *num, int sign) {
  if (sign) {
    num->bits[7] |= 1 << 31;
  } else {
    num->bits[7] &= ~(1 << 31);
  }
}

void bd_set_scale(custom_big_decimal *num, int scale) {
  int sign = bd_get_sign(*num);
  num->bits[7] = 0;
  num->bits[7] |= (scale << 16);
  bd_set_sign(num, sign);
}

int bd_get_scale(custom_big_decimal num) { return num.bits[7] << 1 >> 17; }

void bd_reset(custom_big_decimal *num) {
  for (int i = 0; i < 8; i++) {
    num->bits[i] = 0;
  }
}

int bd_is_empty(custom_big_decimal num) {
  int res = 0;
  for (int i = 0; i < 7; i++) {
    res += num.bits[i];
  }
  return res == 0;
}
