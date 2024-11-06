#include "bitwise_operations.h"

void custom_div_ten(custom_decimal *src) {
  long long int buffer = (unsigned int)src->bits[2];
  long long int mod_res;
  for (int i = 2; i >= 0; i--) {
    mod_res = buffer % 10;
    src->bits[i] = (unsigned int)(buffer / 10);
    if (i) {
      buffer = mod_res << 32;
      buffer += (unsigned int)src->bits[i - 1];
    }
  }
}

void custom_copy_decimal(custom_decimal *src, custom_decimal *dst) {
  for (int i = 0; i < 4; i++) {
    dst->bits[i] = src->bits[i];
  }
}
void custom_set_bit(custom_decimal *num, int index, int bit) {
  if (bit == 1) {
    num->bits[index / 32] = num->bits[index / 32] | (1 << index % 32);
  } else {
    num->bits[index / 32] = num->bits[index / 32] & ~(1 << index % 32);
  }
}
int custom_dec_is_negative(custom_decimal src) {
  return (src.bits[3] &= 1 << 31) != 0;
}

int custom_get_exp(custom_decimal src) {
  src.bits[3] &= ~(1 << 31);
  return src.bits[3] >> 16;
}

void custom_set_sign1(custom_decimal *num, int sign) {
  return custom_set_bit(num, 127, sign);
}

void custom_set_scale(custom_decimal *num, int scale) {
  int sign = get_sign(num);
  num->bits[3] = (scale << 16);
  custom_set_sign1(num, sign);
}

int is_zero(custom_decimal number) {
  int result =
      number.bits[0] == 0 && number.bits[1] == 0 && number.bits[2] == 0;
  return result;
}
void delete_sign(custom_decimal *number) {
  int mask = ~(1U << 31);
  number->bits[3] &= mask;
}

void set_sign(custom_decimal *number) {
  int mask = 1U << 31;
  number->bits[3] |= mask;
}

int get_sign(custom_decimal *num) {
  int res = -1;
  if (test_bit(num->bits[3], 31) == 0) {
    res = 0;  // если num положительный
  } else {
    res = 1;  // если num отрицательный
  }
  return res;
}

int test_bit(unsigned int value, int BitNumber) {
  return value & (1 << BitNumber);
}

custom_decimal custom_superior_10(int power, custom_decimal *value) {
  int inferior = custom_10_conv(*value);

  custom_rev_10_conv(value, power);
  for (int i = 0; i < (power - inferior); i++) {
    mult_10(*value, value);
  }
  return (*value);
}

int custom_10_conv(custom_decimal value) {
  int result = 0;
  int power = 1;
  for (int i = 16; i < 21; i++, power = power * 2)
    if (test_bit(value.bits[3], i)) {
      result = result + power;
    }
  return result;
}

void custom_rev_10_conv(custom_decimal *value, int result) {
  int power = 16;
  for (int i = 20; i > 15; i--, power /= 2)
    if (result >= power) {
      result -= power;
      set_1_bit(&value->bits[3], i);
    } else {
      set_0_bit(&value->bits[3], i);
    }
}

void mult_10(custom_decimal value, custom_decimal *result) {
  custom_decimal ins_val = value;
  custom_shift(&ins_val);
  *result = ins_val;
  custom_shift(&ins_val);
  custom_shift(&ins_val);
  custom_addiction_logic(*result, ins_val, result);
}

void set_1_bit(unsigned int *value, int BitNumber) {
  *value |= (1 << BitNumber);
}

void set_0_bit(unsigned int *value, int BitNumber) {
  *value &= ~(1 << BitNumber);
}

int custom_shift(custom_decimal *number) {
  int vault_1 = 0;  // Хранит значение предыдущего бита
  int vault_2 = 0;  // Сохраняет нынешний бит
  int error = test_bit(number->bits[2], 31);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 32; j++) {
      vault_2 = test_bit((number->bits[i]), j);
      if (vault_1)
        set_1_bit(&number->bits[i], j);
      else
        set_0_bit(&number->bits[i], j);
      vault_1 = vault_2;
    }
  }
  return error;
}

int custom_addiction_logic(custom_decimal value_1, custom_decimal value_2,
                        custom_decimal *result) {
  int a = 0;     // бит первого числа
  int b = 0;     // бит второго числа
  int prev = 0;  // была ли единица в уме
  int next = 0;  // будем ли мы передавать единицу в след разряд
  int res;  // бит который мы запишем в результат

  int error = 0;
  a = test_bit(value_1.bits[2], 31);
  b = test_bit(value_2.bits[2], 31);

  for (int j = 0; j < 3; j++) {
    for (int i = 0; i < 32; i++) {
      /*  int test_bit(int value, int BitNumber) { return value & (1 <<
       * BitNumber); }  */
      // проверка бита
      a = test_bit(value_1.bits[j], i);
      b = test_bit(value_2.bits[j], i);
      if (a == 0) {
        if (b == 0 && prev == 0) {
          res = 0;
          next = 0;
        } else if (b == 0 || prev == 0) {
          res = 1;
          next = 0;
        } else {
          res = 0;
          next = 1;
        }
      } else {
        if (b == 0 && prev == 0) {
          res = 1;
          next = 0;
        } else if (b == 0 || prev == 0) {
          res = 0;
          next = 1;
        } else {
          res = 1;
          next = 1;
        }
      }
      prev = next;
      /*  посе того как получили res - выставляем в num3 */
      if (res) {
        /*  set_1_bit(int *value, int BitNumber) { *value = *value | (1 <<
         * BitNumber); } */
        set_1_bit(&(result->bits[j]), i);
      } else {
        /*  set_0_bit(int *value, int BitNumber) { *value = *value & ~(1 <<
         * BitNumber); } */ // ЧТО ТАКОЕ "~" И КАК ОНА РАБОТАЕТ
        set_0_bit(&(result->bits[j]), i);
      }
    }
  }
  return error;
}

// далее функция для больше или равно

int custom_is_less_num(custom_decimal num1, custom_decimal num2, int result) {
  if (num1.bits[3] == num2.bits[3]) {
    if (num1.bits[2] == num2.bits[2]) {
      if (num1.bits[1] == num2.bits[1]) {
        if (num1.bits[0] == num2.bits[0]) {
          result = 0;
        } else if (num1.bits[0] < num2.bits[0]) {
          result = 1;
        } else {
          result = 0;
        }
      } else if (num1.bits[1] < num2.bits[1]) {
        result = 1;
      } else {
        result = 0;
      }
    } else if (num1.bits[2] < num2.bits[2]) {
      result = 1;
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
    if (num1.bits[2] == num2.bits[2]) {
      if (num1.bits[1] == num2.bits[1]) {
        if (num1.bits[0] == num2.bits[0]) {
          result = 0;
        } else if (num1.bits[0] < num2.bits[0]) {
          result = 1;
        } else {
          result = 0;
        }
      } else if (num1.bits[1] < num2.bits[1]) {
        result = 1;
      } else {
        result = 0;
      }
    } else if (num1.bits[2] < num2.bits[2]) {
      result = 1;
    } else {
      result = 0;
    }
  }
  return result;
}

int custom_is_greater_num(custom_decimal num1, custom_decimal num2, int result) {
  if (num1.bits[3] == num2.bits[3]) {
    if (num1.bits[2] == num2.bits[2]) {
      if (num1.bits[1] == num2.bits[1]) {
        if (num1.bits[0] == num2.bits[0]) {
          result = 0;
        } else if (num1.bits[0] > num2.bits[0]) {
          result = 1;
        } else {
          result = 0;
        }
      } else if (num1.bits[1] > num2.bits[1]) {
        result = 1;
      } else {
        result = 0;
      }
    } else if (num1.bits[2] > num2.bits[2]) {
      result = 1;
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
    if (num1.bits[2] == num2.bits[2]) {
      if (num1.bits[1] == num2.bits[1]) {
        if (num1.bits[0] == num2.bits[0]) {
          result = 0;
        } else if (num1.bits[0] > num2.bits[0]) {
          result = 1;
        } else {
          result = 0;
        }
      } else if (num1.bits[1] > num2.bits[1]) {
        result = 1;
      } else {
        result = 0;
      }
    } else if (num1.bits[2] > num2.bits[2]) {
      result = 1;
    } else {
      result = 0;
    }
  }
  return result;
}

// для тестов
int custom_set_sign(custom_decimal *value) {
  value->bits[3] = value->bits[3] | ((unsigned long)1 << (31));
  return 0;
}

/// Обнуление decimal
void custom_zero_decimal(custom_decimal *dst) {
  for (int i = 0; i < 4; i++) {
    dst->bits[i] = 0;
  }
  //  dst->bits[0] = dst->bits[1] = dst->bits[2] = dst->bits[3] = 0;
}

void left_shift(custom_decimal *value) {
  value->bits[2] <<= 1U;
  if (custom_get_bit(*value, 63)) {
    custom_set_bit(value, 64, 1);
  }
  value->bits[1] <<= 1U;
  if (custom_get_bit(*value, 31)) {
    custom_set_bit(value, 32, 1);
  }
  value->bits[0] <<= 1U;
}
void right_shift(custom_decimal *value) {
  value->bits[0] >>= 1U;
  if (custom_get_bit(*value, 32)) {
    custom_set_bit(value, 31, 1);
  }
  value->bits[1] >>= 1U;
  if (custom_get_bit(*value, 64)) {
    custom_set_bit(value, 63, 1);
  }
  value->bits[2] >>= 1U;
}

int custom_get_bit(custom_decimal number, int index) {
  return (number.bits[index / 32] >> (index % 32)) & 1U;
}

int search_unit_bit(custom_decimal src) {
  int index = -1;
  for (int i = 95; i >= 0; i--) {
    if (custom_get_bit(src, i)) {
      index = i;
      break;
    }
  }
  return index;
}
