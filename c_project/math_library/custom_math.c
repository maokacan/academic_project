#include "custom_math.h"

int custom_abs(int x) {
  if (x < 0) x *= -1;
  return x;
}

long double custom_fabs(double x) {
  if (x < 0) x *= -1.0;
  return x;
}

long double custom_log(double x) {
  int ex_pow = 0;
  long double result = 0;
  long double compare = 0;
  if (CUSTOM_IS_NAN(x) || x < 0) {
    result = CUSTOM_NAN;
  } else if (x == CUSTOM_INF_P || x == CUSTOM_INF_N) {
    result = x;
  } else if (x == 0) {
    result = CUSTOM_INF_N;
  } else if (x == 1) {
    result = 0;
  } else {
    for (; x >= CUSTOM_E; ex_pow++) x /= CUSTOM_E;
    for (int i = 0; i < 100; i++) {
      compare = result;
      result = compare + 2 * (x - custom_exp(compare)) / (x + custom_exp(compare));
    }
    result += ex_pow;
  }
  return result;
}

long double custom_exp(double x) {
  long double add_value = 1;
  long double i = 1;
  long double result = 1;
  int sign_x = 0;
  if (x == CUSTOM_INF_P) {
    result = CUSTOM_INF_P;
  } else if (x == CUSTOM_INF_N) {
    result = CUSTOM_INF_N;
  } else if (x == CUSTOM_NAN) {
    result = CUSTOM_NAN;
  } else if (x == 0) {
    result = 1;
  } else {
    if (x < 0) {
      x = custom_fabs(x);
      sign_x = 1;
    }
    while (custom_fabs(add_value) > CUSTOM_EPS && result < CUSTOM_DBL_MAX) {
      add_value *= x / i;
      i += 1;
      result += add_value;
    }
    if (sign_x) result = 1 / result;
  }
  if (result > CUSTOM_DBL_MAX) {
    result = CUSTOM_INF_P;
  } else if (result < CUSTOM_EPS_E) {
    result = 0;
  }
  return result;
}

long double custom_ceil(double x) {
  long double tmp;
  if (x == CUSTOM_NAN) {
    tmp = x;
  } else if (x == CUSTOM_INF_P) {
    tmp = CUSTOM_INF_P;
  } else if (x == CUSTOM_INF_N) {
    tmp = CUSTOM_INF_N;
  } else if (x == CUSTOM_ZERO_P) {
    tmp = x;
  } else {
    if (x >= 0) {
      tmp = (long)x;
      if (x != (double)tmp) tmp++;
    } else {
      tmp = (long)x;
    }
  }
  return tmp;
}

long double custom_floor(double x) {
  double part = (long)x;
  if (x == CUSTOM_NAN) {
    part = x;
  } else if (x == CUSTOM_INF_P) {
    part = CUSTOM_INF_P;
  } else if (x == CUSTOM_INF_N) {
    part = CUSTOM_INF_N;
  } else if (x == CUSTOM_ZERO_P) {
    part = x;
  } else if (x <= 0 && part != x) {
    part--;
  }
  return part;
}
long double custom_fmod(double x, double y) {
  long double res = 0;
  if (CUSTOM_IS_NAN(x) || CUSTOM_IS_NAN(y) || y == 0) {
    res = CUSTOM_NAN;
  } else if (CUSTOM_IS_INF(x)) {
    res = CUSTOM_INF_P;
  } else if (CUSTOM_IS_INF(y)) {
    res = x;
  } else if (x == 0.0 && y != 0.0) {
    res = 0.0;
  } else {
    long long int nep_chastnoe = x / y;
    res = (long double)x - (long double)(nep_chastnoe * (long double)y);
  }
  return res;
}

long double custom_pow(double base, double exp) {
  long double result = 0;
  if (!exp) {
    result = 1;
  } else if (base == CUSTOM_INF_N && exp == CUSTOM_INF_N) {
    result = 0;
  } else if (base == CUSTOM_INF_N && exp == CUSTOM_INF_P) {
    result = CUSTOM_INF_P;
  } else if (base < 0 && exp != (long long int)exp) {
    result = CUSTOM_INF_N;
  } else if (base == CUSTOM_NAN || exp == CUSTOM_NAN) {
    return CUSTOM_NAN;
  } else {
    if (base > 0) {
      result = custom_exp(exp * custom_log(base));
    } else if (base < 0) {
      base = custom_fabs(base);
      result = custom_exp(exp * custom_log(base));
      if (((int)exp % 2) != 0) result = -result;
    }
  }
  return result;
}

long double custom_sqrt(double x) {
  long double result = 0;
  if (CUSTOM_IS_NAN(x) || x == CUSTOM_INF_N || x < 0) {
    return CUSTOM_NAN;
  } else if (x == CUSTOM_INF_P || x == 0) {
    return (long double)x;
  } else {
    result = custom_pow(x, 0.5);
  }
  return result;
}

long double custom_sin(double x) { return custom_cos(CUSTOM_PI_BY_TWO - x); }

long double custom_asin(double x) {
  long double result = 0.0;
  if (x == 1.0) {
    result = CUSTOM_PI_BY_TWO;
  } else if (x == -1) {
    result = -CUSTOM_PI_BY_TWO;
  } else if (x > -1.0 && x < 1.0) {
    long double x_si = custom_sqrt(1.0 - custom_pow(x, 2));
    result = custom_atan(x / x_si);
  } else {
    result = CUSTOM_NAN;
  }

  return result;
}

long double custom_acos(double x) {
  long double result = 0.0;
  if (x == 1.0) {
    result = 0.0;
  } else if (x == -1.0) {
    result = CUSTOM_PI;
  } else if (x == 0.0) {
    result = CUSTOM_PI_BY_TWO;
  } else {
    long double x_si = custom_sqrt(1.0 - x * x);
    if (x > 0 && x < 1) {
      result = custom_atan(x_si / x);
    } else if (x > -1 && x < 0) {
      result = custom_atan(x_si / x) + CUSTOM_PI;
    } else {
      result = CUSTOM_NAN;
    }
  }

  return result;
}

long double custom_cos(double x) {
  long double sum = 1;
  if (CUSTOM_IS_NAN(x) || CUSTOM_IS_INF(x)) {
    sum = CUSTOM_NAN;
  } else {
    x = custom_fabs(custom_fmod(x, CUSTOM_PI * 2));
    long double num_sign = 1;
    long double prev_sum = 2;
    long double numerator = 1;
    long double denominator = 1;
    long double i = 2;
    if (x > CUSTOM_PI) {
      x = x - CUSTOM_PI;
      num_sign = -1;
      sum = -1;
    }
    while (sum != prev_sum) {
      prev_sum = sum;
      numerator *= x * x;
      denominator = denominator * i * (i - 1);
      i += 2;
      num_sign = num_sign * -1;
      sum += num_sign * numerator / denominator;
    }
  }
  return sum;
}

long double custom_tan(double x) { return (custom_sin(x) / custom_cos(x)); }

long double custom_atan(double x) {
  long double val = 0.0;
  double result = 0.0;
  double result_dif = 1.0;
  double xplus_exp = 1.0;
  int factorial = 1;
  int count = 1;
  if (x == 1) {
    result = CUSTOM_PI_BY_FOUR;
  } else if (x == -1) {
    result = -CUSTOM_PI_BY_FOUR;
  } else if (x == CUSTOM_INF_P) {
    result = CUSTOM_PI_BY_TWO;
  } else if (x == CUSTOM_INF_N) {
    result = -CUSTOM_PI_BY_TWO;
  } else if (x == CUSTOM_NAN) {
    result = CUSTOM_NAN;
  } else {
    val = custom_fabs(x) > 1.0 ? (1.0 / x) : x;
    while (custom_fabs(result - result_dif) > CUSTOM_EPS) {
      result_dif = result;
      if (count % 2) {
        result += (custom_pow(val, xplus_exp) / factorial);
      } else {
        result -= (custom_pow(val, xplus_exp) / factorial);
      }
      xplus_exp += 2;
      factorial += 2;
      count++;
    }
    if (x > 1.0) {
      result = CUSTOM_PI_BY_TWO - result;
    } else if (x < -1.0) {
      result = -1.0 * (CUSTOM_PI_BY_TWO + result);
    }
  }
  return result;
}
