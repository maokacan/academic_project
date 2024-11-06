#include <check.h>
#include <math.h>

#include "custom_math.h"

// max and min
#define CUSTOM_DBL_MAX 1.7976931348623158e+308L
#define CUSTOM_DBL_MIN 2.2250738585072014e-308L
#define CUSTOM_INT_MAX 2147483647
#define CUSTOM_INT_MIN -2147483648

// zero
#define CUSTOM_ZERO_D 0.0000000000001
#define CUSTOM_ZERO_P 0.0 / 1.0
#define CUSTOM_ZERO_N -0.0 / 1.0

// special value
#define CUSTOM_NAN (0.0 / 0.0)
#define CUSTOM_INF_P (1.0 / 0.0)
#define CUSTOM_INF_N (-1.0 / 0.0)

// conditions for tests
#define CUSTOM_INF_CONDITION                                                 \
  (result == CUSTOM_INF_P || result == CUSTOM_INF_N || expected == CUSTOM_INF_P || \
   result == CUSTOM_INF_N)
#define CUSTOM_NAN_CONDITION (isnan(result) || isnan(expected))
#define CUSTOM_MAX_CONDITION (result < CUSTOM_MAX && expected < CUSTOM_MAX)
#define CUSTOM_ACCURACY 1e-06
#define CUSTOM_MAX 1e+16

// idk what to call it
#define CUSTOM_EPS_E 1E-16
#define CUSTOM_EPS 1E-9

// angles
#define CUSTOM_PI 3.14159265358979323846
#define CUSTOM_PI_BY_TWO (CUSTOM_PI / 2)
#define CUSTOM_PI_BY_THREE (CUSTOM_PI / 3)
#define CUSTOM_PI_BY_FOUR (CUSTOM_PI / 4)
#define CUSTOM_PI_BY_SIX (CUSTOM_PI / 6)

#define MASS_SIZE_O 20
#define MASS_SIZE_I 5

double initialize_mass_positive(int i) {
  double value[] = {0.1,     0.5,     1.0,      2.0,        3.1,
                    3.9,     0.0001,  9999.992, 5.8,        999.919,
                    0.12312, 3.232,   12.32332, 9.99,       0.0001,
                    12.0,    13.2323, 3.848,    11.1234567, 3.0};
  return value[i];
}
double initialize_mass_negative(int i) {
  double value[] = {-0.1,      -0.5,         -1.0,     -2.0,   -111.111,
                    -122.0,    -12.32332,    -0.12312, -2.12,  -123.321,
                    -99.99,    -123213.2323, -3.1,     -3.9,   -0.0001,
                    -9999.992, -3.232,       -0.9999,  -3.848, -3.0};
  return value[i];
}
double initialize_mass_int(int i) {
  double value[] = {3.0, 4.0, 5.0, 10.0, 15.0};
  return value[i];
}
double initialize_mass_from_minus_one_to_one(int i) {
  double value[] = {-1,  -0.9, -0.8, -0.7, -0.6, -0.5, -0.4, -0.3, -0.2, -0.1,
                    0.1, 0.2,  0.3,  0.4,  0.5,  0.6,  0.7,  0.8,  0.9,  1};
  return value[i];
}

START_TEST(test_abs_positive) {
  for (int i = 0; i < MASS_SIZE_O; i++) {
    int x = initialize_mass_positive(i);
    ck_assert_msg(custom_abs(x) == abs(x), "Expected: %d, Reality: %d", abs(x),
                  custom_abs(x));
  }
}
START_TEST(test_abs_negative) {
  for (int i = 0; i < MASS_SIZE_O; i++) {
    int x = initialize_mass_negative(i);
    ck_assert_msg(custom_abs(x) == abs(x), "Expected: %d, Reality: %d", abs(x),
                  custom_abs(x));
  }
}
START_TEST(test_abs_boundary_values) {
  int x = CUSTOM_INT_MAX;
  ck_assert_msg(custom_abs(x) == abs(x), "Expected: %d, Reality: %d", abs(x),
                custom_abs(x));
  x = CUSTOM_INT_MAX - 1;
  ck_assert_msg(custom_abs(x) == abs(x), "Expected: %d, Reality: %d", abs(x),
                custom_abs(x));
  x = CUSTOM_INT_MIN;
  ck_assert_msg(custom_abs(x) == abs(x), "Expected: %d, Reality: %d", abs(x),
                custom_abs(x));
  x = CUSTOM_INT_MIN + 1;
  ck_assert_msg(custom_abs(x) == abs(x), "Expected: %d, Reality: %d", abs(x),
                custom_abs(x));
}
START_TEST(test_abs_zero) {
  int x = 0;
  ck_assert_msg(custom_abs(x) == abs(x), "Expected: %d, Reality: %d", abs(x),
                custom_abs(x));
  x = CUSTOM_ZERO_P;
  ck_assert_msg(custom_abs(x) == abs(x), "Expected: %d, Reality: %d", abs(x),
                custom_abs(x));
  x = CUSTOM_ZERO_N;
  ck_assert_msg(custom_abs(x) == abs(x), "Expected: %d, Reality: %d", abs(x),
                custom_abs(x));
}
START_TEST(test_abs_special_value) {
  int x = CUSTOM_NAN;
  ck_assert_msg(custom_abs(x) == abs(x), "Expected: %d, Reality: %d", abs(x),
                custom_abs(x));
  x = CUSTOM_INF_P;
  ck_assert_msg(custom_abs(x) == abs(x), "Expected: %d, Reality: %d", abs(x),
                custom_abs(x));
  x = CUSTOM_INF_N;
  ck_assert_msg(custom_abs(x) == abs(x), "Expected: %d, Reality: %d", abs(x),
                custom_abs(x));
}

START_TEST(test_fabs_positive) {
  for (int i = 0; i < MASS_SIZE_O; i++) {
    double x = initialize_mass_positive(i);
    ck_assert_msg(custom_fabs(x) == fabs(x), "Expected: %f, Reality: %Lf", fabs(x),
                  custom_fabs(x));
  }
}
START_TEST(test_fabs_negative) {
  for (int i = 0; i < MASS_SIZE_O; i++) {
    double x = initialize_mass_negative(i);
    ck_assert_msg(custom_fabs(x) == fabs(x), "Expected: %f, Reality: %Lf", fabs(x),
                  custom_fabs(x));
  }
}
START_TEST(test_fabs_boundary_values) {
  double x = DBL_MAX;
  ck_assert_msg(custom_fabs(x) == fabs(x), "Expected: %f, Reality: %Lf", fabs(x),
                custom_fabs(x));
  x = DBL_MAX + 1;
  ck_assert_msg(custom_fabs(x) == fabs(x), "Expected: %f, Reality: %Lf", fabs(x),
                custom_fabs(x));
  x = DBL_MIN;
  ck_assert_msg(custom_fabs(x) == fabs(x), "Expected: %f, Reality: %Lf", fabs(x),
                custom_fabs(x));
  x = DBL_MIN - 1;
  ck_assert_msg(custom_fabs(x) == fabs(x), "Expected: %f, Reality: %Lf", fabs(x),
                custom_fabs(x));
}
START_TEST(test_fabs_zero) {
  double x = CUSTOM_ZERO_D;
  ck_assert_msg(custom_fabs(x) == fabs(x), "Expected: %f, Reality: %Lf", fabs(x),
                custom_fabs(x));
  x = CUSTOM_ZERO_P;
  ck_assert_msg(custom_fabs(x) == fabs(x), "Expected: %f, Reality: %Lf", fabs(x),
                custom_fabs(x));
  x = CUSTOM_ZERO_N;
  ck_assert_msg(custom_fabs(x) == fabs(x), "Expected: %f, Reality: %Lf", fabs(x),
                custom_fabs(x));
}
START_TEST(test_fabs_special_value) {
  double x = CUSTOM_NAN;
  ck_assert_ldouble_nan(custom_fabs(x));
  x = CUSTOM_INF_P;
  ck_assert_msg(custom_fabs(x) == fabs(x), "Expected: %f, Reality: %Lf", fabs(x),
                custom_fabs(x));
  x = CUSTOM_INF_N;
  ck_assert_msg(custom_fabs(x) == fabs(x), "Expected: %f, Reality: %Lf", fabs(x),
                custom_fabs(x));
}

START_TEST(test_floor_positive) {
  for (int i = 0; i < MASS_SIZE_O; i++) {
    double x = initialize_mass_positive(i);
    long double expected = floor(x);
    long double result = custom_floor(x);
    ck_assert_ldouble_eq_tol(expected, result, CUSTOM_ACCURACY);
  }
}
START_TEST(test_floor_negative) {
  for (int i = 0; i < MASS_SIZE_O; i++) {
    double x = initialize_mass_negative(i);
    long double expected = floor(x);
    long double result = custom_floor(x);
    ck_assert_ldouble_eq_tol(expected, result, CUSTOM_ACCURACY);
  }
}
START_TEST(test_floor_int) {
  for (int i = 0; i < MASS_SIZE_I; i++) {
    double x = initialize_mass_int(i);
    long double expected = floor(x);
    long double result = custom_floor(x);
    ck_assert_ldouble_eq_tol(expected, result, CUSTOM_ACCURACY);
  }
}
START_TEST(test_floor_special_value) {
  double x = CUSTOM_INF_P;
  ck_assert_msg(custom_floor(x) == floor(x), "Expected: %f, Reality: %Lf",
                floor(x), custom_floor(x));
  x = CUSTOM_INF_N;
  ck_assert_msg(custom_floor(x) == floor(x), "Expected: %f, Reality: %Lf",
                floor(x), custom_floor(x));
}

START_TEST(test_fmod_positive) {
  for (int i = 0; i < MASS_SIZE_O; i++) {
    double x = initialize_mass_positive(i);
    double y = initialize_mass_positive(i);
    long double result = custom_fmod(x, y);
    long double expected = fmodl(x, y);
    ck_assert_msg(custom_fabs(result - expected) < CUSTOM_ACCURACY,
                  "Expected: %Lf, Result: %Lf", expected, result);
  }
}
START_TEST(test_fmod_negative) {
  for (int i = 0; i < MASS_SIZE_O; i++) {
    double x = initialize_mass_negative(i);
    double y = initialize_mass_negative(i);
    long double result = custom_fmod(x, y);
    long double expected = fmodl(x, y);
    ck_assert_msg(custom_fabs(result - expected) < CUSTOM_ACCURACY,
                  "Expected: %Lf, Result: %Lf", expected, result);
  }
}
START_TEST(test_fmod_combinations) {
  for (int i = 0; i < MASS_SIZE_O; i++) {
    double x = initialize_mass_positive(i);
    double y = initialize_mass_negative(i);
    long double result = custom_fmod(x, y);
    long double expected = fmodl(x, y);
    ck_assert_msg(custom_fabs(result - expected) < CUSTOM_ACCURACY,
                  "Expected: %Lf, Result: %Lf", expected, result);
  }
}
START_TEST(test_fmod_zero) {
  double x[5] = {CUSTOM_ZERO_D, 10.22, CUSTOM_ZERO_D, CUSTOM_ZERO_P, CUSTOM_ZERO_N};
  double y[5] = {10.22, CUSTOM_ZERO_D, CUSTOM_ZERO_D, CUSTOM_ZERO_N, CUSTOM_ZERO_N};
  for (int i = 0; i < 4; i++) {
    long double result = custom_fmod(x[i], y[i]);
    long double expected = fmodl(x[i], y[i]);
    if (CUSTOM_NAN_CONDITION) {
      ck_assert_ldouble_nan(result);
    } else {
      ck_assert_msg(custom_fabs(result - expected) < CUSTOM_ACCURACY,
                    "Expected: %Lf, Result: %Lf", fmodl(x[i], y[i]),
                    custom_fmod(x[i], y[i]));
    }
  }
}

START_TEST(test_log_positive) {
  for (int i = 0; i < MASS_SIZE_O; i++) {
    double x = initialize_mass_positive(i);
    long double expected = logl(x);
    long double result = custom_log(x);
    ck_assert_ldouble_eq_tol(expected, result, CUSTOM_ACCURACY);
  }
}
START_TEST(test_log_negative) {
  for (int i = 0; i < MASS_SIZE_O; i++) {
    double x = initialize_mass_negative(i);
    ck_assert_ldouble_nan(custom_log(x));
  }
}
START_TEST(test_log_zero) {
  double x = CUSTOM_ZERO_D;
  ck_assert_ldouble_eq_tol(logl(x), custom_log(x), CUSTOM_ACCURACY);
}
START_TEST(test_log_special_value) {
  double x = CUSTOM_NAN;
  ck_assert_ldouble_nan(custom_log(x));
  x = CUSTOM_INF_P;
  ck_assert_msg(custom_log(x) == logl(x), "Expected: %Lf, Reality: %Lf", logl(x),
                custom_log(x));
  x = CUSTOM_INF_N;
  ck_assert_ldouble_nan(custom_log(x));
}

START_TEST(test_pow_positive) {
  for (int i = 0; i < MASS_SIZE_O; i++) {
    double x = initialize_mass_positive(i);
    double y = initialize_mass_positive(MASS_SIZE_O - i - 1);
    long double result = custom_pow(x, y);
    long double expected = powl(x, y);
    if (CUSTOM_INF_CONDITION) {
      ck_assert_msg(result == expected, "Expected: %Lf, Result: %Lf", expected,
                    result);
    }
  }
}
START_TEST(test_pow_combinations) {
  for (int i = 0; i < MASS_SIZE_O; i++) {
    double x = initialize_mass_positive(i);
    double y = initialize_mass_negative(i);
    long double result = custom_pow(x, y);
    long double expected = powl(x, y);
    if (CUSTOM_MAX_CONDITION) {
      ck_assert_msg(custom_fabs(result - expected) < CUSTOM_ACCURACY,
                    "Expected: %Lf, Result: %Lf", expected, result);
    }
  }
}
START_TEST(test_pow_zero) {
  double x[5] = {CUSTOM_ZERO_D, 10.22, CUSTOM_ZERO_D, CUSTOM_ZERO_P, CUSTOM_ZERO_N};
  double y[5] = {10.22, CUSTOM_ZERO_D, CUSTOM_ZERO_D, CUSTOM_ZERO_N, CUSTOM_ZERO_N};
  for (int i = 0; i < 4; i++) {
    long double result = custom_pow(x[i], y[i]);
    long double expected = powl(x[i], y[i]);
    ck_assert_msg(custom_fabs(result - expected) < CUSTOM_ACCURACY,
                  "Expected: %Lf, Result: %Lf", powl(x[i], y[i]),
                  custom_pow(x[i], y[i]));
  }
}
START_TEST(test_pow_special_value) {
  double x = CUSTOM_INF_P;
  double y = CUSTOM_INF_P;
  ck_assert_msg(custom_pow(x, y) == powl(x, y), "Expected: %Lf, Reality: %Lf",
                powl(x, y), custom_pow(x, y));
  x = CUSTOM_INF_N;
  y = CUSTOM_INF_P;
  ck_assert_msg(custom_pow(x, y) == powl(x, y), "Expected: %Lf, Reality: %Lf",
                powl(x, y), custom_pow(x, y));
}

START_TEST(test_sqrt_positive) {
  for (int i = 0; i < MASS_SIZE_O; i++) {
    double x = initialize_mass_positive(i);
    long double expected = sqrtl(x);
    long double result = custom_sqrt(x);
    ck_assert_ldouble_eq_tol(expected, result, CUSTOM_ACCURACY);
  }
}
START_TEST(test_sqrt_negative) {
  for (int i = 0; i < MASS_SIZE_O; i++) {
    double x = initialize_mass_negative(i);
    ck_assert_ldouble_nan(custom_sqrt(x));
  }
}
START_TEST(test_sqrt_zero) {
  double x = CUSTOM_ZERO_D;
  ck_assert_msg(custom_fabs(custom_sqrt(x) - sqrtl(x)) < CUSTOM_EPS,
                "Expected: %Lf, Result: %Lf", sqrtl(x), custom_sqrt(x));
  x = CUSTOM_ZERO_P;
  ck_assert_msg(custom_sqrt(x) == sqrtl(x), "Expected: %Lf, Reality: %Lf",
                sqrtl(x), custom_sqrt(x));
  x = CUSTOM_ZERO_N;
  ck_assert_msg(custom_sqrt(x) == sqrtl(x), "Expected: %Lf, Reality: %Lf",
                sqrtl(x), custom_sqrt(x));
}
START_TEST(test_sqrt_special_value) {
  double x = CUSTOM_NAN;
  ck_assert_ldouble_nan(custom_sqrt(x));
  x = CUSTOM_INF_P;
  ck_assert_msg(custom_sqrt(x) == sqrtl(x), "Expected: %Lf, Reality: %Lf",
                sqrtl(x), custom_sqrt(x));
  x = CUSTOM_INF_N;
  ck_assert_ldouble_nan(custom_sqrt(x));
}

START_TEST(test_sin_angles) {
  double x = CUSTOM_PI;
  ck_assert_msg(custom_fabs(custom_sin(x) - sinl(x)) < CUSTOM_ACCURACY,
                "Expected: %Lf, Result: %Lf", sinl(x), custom_sin(x));
  x = CUSTOM_PI_BY_TWO;
  ck_assert_msg(custom_fabs(custom_sin(x) - sinl(x)) < CUSTOM_ACCURACY,
                "Expected: %Lf, Result: %Lf", sinl(x), custom_sin(x));
  x = CUSTOM_PI_BY_THREE;
  ck_assert_msg(custom_fabs(custom_sin(x) - sinl(x)) < CUSTOM_ACCURACY,
                "Expected: %Lf, Result: %Lf", sinl(x), custom_sin(x));
  x = CUSTOM_PI_BY_FOUR;
  ck_assert_msg(custom_fabs(custom_sin(x) - sinl(x)) < CUSTOM_ACCURACY,
                "Expected: %Lf, Result: %Lf", sinl(x), custom_sin(x));
  x = CUSTOM_PI_BY_SIX;
  ck_assert_msg(custom_fabs(custom_sin(x) - sinl(x)) < CUSTOM_ACCURACY,
                "Expected: %Lf, Result: %Lf", sinl(x), custom_sin(x));
}
START_TEST(test_sin_zero) {
  double x = CUSTOM_ZERO_D;
  ck_assert_msg(custom_fabs(custom_sin(x) - sinl(x)) < CUSTOM_ACCURACY,
                "Expected: %Lf, Result: %Lf", sinl(x), custom_sin(x));
  x = CUSTOM_ZERO_P;
  ck_assert_msg(custom_fabs(custom_sin(x) - sinl(x)) < CUSTOM_ACCURACY,
                "Expected: %Lf, Result: %Lf", sinl(x), custom_sin(x));
  x = CUSTOM_ZERO_N;
  ck_assert_msg(custom_fabs(custom_sin(x) - sinl(x)) < CUSTOM_ACCURACY,
                "Expected: %Lf, Result: %Lf", sinl(x), custom_sin(x));
}
START_TEST(test_sin_angles_non_standart) {
  double x = -(CUSTOM_PI);
  ck_assert_msg(custom_fabs(custom_sin(x) - sinl(x)) < CUSTOM_ACCURACY,
                "Expected: %Lf, Result: %Lf", sinl(x), custom_sin(x));
  x = 3 * (CUSTOM_PI_BY_TWO);
  ck_assert_msg(custom_fabs(custom_sin(x) - sinl(x)) < CUSTOM_ACCURACY,
                "Expected: %Lf, Result: %Lf", sinl(x), custom_sin(x));
  x = 2 * (CUSTOM_PI);
  ck_assert_msg(custom_fabs(custom_sin(x) - sinl(x)) < CUSTOM_ACCURACY,
                "Expected: %Lf, Result: %Lf", sinl(x), custom_sin(x));
  x = 5 * (CUSTOM_PI_BY_FOUR);
  ck_assert_msg(custom_fabs(custom_sin(x) - sinl(x)) < CUSTOM_ACCURACY,
                "Expected: %Lf, Result: %Lf", sinl(x), custom_sin(x));
}
START_TEST(test_sin_one_to_one) {
  for (int i = 0; i < MASS_SIZE_O; i++) {
    double x = initialize_mass_from_minus_one_to_one(i);
    ck_assert_msg(custom_fabs(custom_sin(x) - sinl(x)) < CUSTOM_ACCURACY,
                  "Expected: %Lf, Result: %Lf", sinl(x), custom_sin(x));
  }
}

START_TEST(test_cos_angles) {
  double x = CUSTOM_PI;
  ck_assert_msg(custom_fabs(custom_cos(x) - cosl(x)) < CUSTOM_ACCURACY,
                "Expected: %Lf, Result: %Lf", cosl(x), custom_cos(x));
  x = CUSTOM_PI_BY_TWO;
  ck_assert_msg(custom_fabs(custom_cos(x) - cosl(x)) < CUSTOM_ACCURACY,
                "Expected: %Lf, Result: %Lf", cosl(x), custom_cos(x));
  x = CUSTOM_PI_BY_THREE;
  ck_assert_msg(custom_fabs(custom_cos(x) - cosl(x)) < CUSTOM_ACCURACY,
                "Expected: %Lf, Result: %Lf", cosl(x), custom_cos(x));
  x = CUSTOM_PI_BY_FOUR;
  ck_assert_msg(custom_fabs(custom_cos(x) - cosl(x)) < CUSTOM_ACCURACY,
                "Expected: %Lf, Result: %Lf", cosl(x), custom_cos(x));
  x = CUSTOM_PI_BY_SIX;
  ck_assert_msg(custom_fabs(custom_cos(x) - cosl(x)) < CUSTOM_ACCURACY,
                "Expected: %Lf, Result: %Lf", cosl(x), custom_cos(x));
}
START_TEST(test_cos_zero) {
  double x = CUSTOM_ZERO_D;
  ck_assert_msg(custom_fabs(custom_cos(x) - cosl(x)) < CUSTOM_ACCURACY,
                "Expected: %Lf, Result: %Lf", cosl(x), custom_cos(x));
  x = CUSTOM_ZERO_P;
  ck_assert_msg(custom_fabs(custom_cos(x) - cosl(x)) < CUSTOM_ACCURACY,
                "Expected: %Lf, Result: %Lf", cosl(x), custom_cos(x));
  x = CUSTOM_ZERO_N;
  ck_assert_msg(custom_fabs(custom_cos(x) - cosl(x)) < CUSTOM_ACCURACY,
                "Expected: %Lf, Result: %Lf", cosl(x), custom_cos(x));
}
START_TEST(test_cos_angles_non_standart) {
  double x = -(CUSTOM_PI);
  ck_assert_msg(custom_fabs(custom_cos(x) - cosl(x)) < CUSTOM_ACCURACY,
                "Expected: %Lf, Result: %Lf", cosl(x), custom_cos(x));
  x = 3 * (CUSTOM_PI_BY_TWO);
  ck_assert_msg(custom_fabs(custom_cos(x) - cosl(x)) < CUSTOM_ACCURACY,
                "Expected: %Lf, Result: %Lf", cosl(x), custom_cos(x));
  x = 2 * (CUSTOM_PI);
  ck_assert_msg(custom_fabs(custom_cos(x) - cosl(x)) < CUSTOM_ACCURACY,
                "Expected: %Lf, Result: %Lf", cosl(x), custom_cos(x));
  x = 5 * (CUSTOM_PI_BY_FOUR);
  ck_assert_msg(custom_fabs(custom_cos(x) - cosl(x)) < CUSTOM_ACCURACY,
                "Expected: %Lf, Result: %Lf", cosl(x), custom_cos(x));
}
START_TEST(test_cos_one_to_one) {
  for (int i = 0; i < MASS_SIZE_O; i++) {
    double x = initialize_mass_from_minus_one_to_one(i);
    ck_assert_msg(custom_fabs(custom_cos(x) - cosl(x)) < CUSTOM_ACCURACY,
                  "Expected: %Lf, Result: %Lf", cosl(x), custom_cos(x));
  }
}

START_TEST(test_tan_angles) {
  double x = CUSTOM_PI;
  ck_assert_msg(custom_fabs(custom_tan(x) - tanl(x)) < CUSTOM_ACCURACY,
                "Expected: %Lf, Result: %Lf", tanl(x), custom_tan(x));
  x = CUSTOM_PI_BY_THREE;
  ck_assert_msg(custom_fabs(custom_tan(x) - tanl(x)) < CUSTOM_ACCURACY,
                "Expected: %Lf, Result: %Lf", tanl(x), custom_tan(x));
  x = CUSTOM_PI_BY_FOUR;
  ck_assert_msg(custom_fabs(custom_tan(x) - tanl(x)) < CUSTOM_ACCURACY,
                "Expected: %Lf, Result: %Lf", tanl(x), custom_tan(x));
  x = CUSTOM_PI_BY_SIX;
  ck_assert_msg(custom_fabs(custom_tan(x) - tanl(x)) < CUSTOM_ACCURACY,
                "Expected: %Lf, Result: %Lf", tanl(x), custom_tan(x));
}
START_TEST(test_tan_zero) {
  double x = CUSTOM_ZERO_D;
  ck_assert_msg(custom_fabs(custom_tan(x) - tanl(x)) < CUSTOM_ACCURACY,
                "Expected: %Lf, Result: %Lf", tanl(x), custom_tan(x));
  x = CUSTOM_ZERO_P;
  ck_assert_msg(custom_fabs(custom_tan(x) - tanl(x)) < CUSTOM_ACCURACY,
                "Expected: %Lf, Result: %Lf", tanl(x), custom_tan(x));
  x = CUSTOM_ZERO_N;
  ck_assert_msg(custom_fabs(custom_tan(x) - tanl(x)) < CUSTOM_ACCURACY,
                "Expected: %Lf, Result: %Lf", tanl(x), custom_tan(x));
}
START_TEST(test_tan_angles_non_standart) {
  double x = -(CUSTOM_PI);
  ck_assert_msg(custom_fabs(custom_tan(x) - tanl(x)) < CUSTOM_ACCURACY,
                "Expected: %Lf, Result: %Lf", tanl(x), custom_tan(x));
  x = 2 * (CUSTOM_PI);
  ck_assert_msg(custom_fabs(custom_tan(x) - tanl(x)) < CUSTOM_ACCURACY,
                "Expected: %Lf, Result: %Lf", tanl(x), custom_tan(x));
  x = 5 * (CUSTOM_PI_BY_FOUR);
  ck_assert_msg(custom_fabs(custom_tan(x) - tanl(x)) < CUSTOM_ACCURACY,
                "Expected: %Lf, Result: %Lf", tanl(x), custom_tan(x));
}
START_TEST(test_tan_one_to_one) {
  for (int i = 0; i < MASS_SIZE_O; i++) {
    double x = initialize_mass_from_minus_one_to_one(i);
    ck_assert_msg(custom_fabs(custom_tan(x) - tanl(x)) < CUSTOM_ACCURACY,
                  "Expected: %Lf, Result: %Lf", tanl(x), custom_tan(x));
  }
}

START_TEST(test_asin_one_to_one) {
  for (int i = 0; i < MASS_SIZE_O; i++) {
    double x = initialize_mass_from_minus_one_to_one(i);
    ck_assert_msg(custom_fabs(custom_asin(x) - asinl(x)) < CUSTOM_ACCURACY,
                  "Expected: %Lf, Result: %Lf", asinl(x), custom_asin(x));
  }
}
START_TEST(test_asin_special_value) {
  double x = CUSTOM_NAN;
  ck_assert_ldouble_nan(custom_asin(x));
  x = CUSTOM_INF_P;
  ck_assert_ldouble_nan(custom_asin(x));
  x = CUSTOM_INF_N;
  ck_assert_ldouble_nan(custom_asin(x));
}
START_TEST(test_asin_angles_non_standart) {
  double x = -(CUSTOM_PI);
  ck_assert_ldouble_nan(custom_asin(x));
  x = 3 * (CUSTOM_PI_BY_TWO);
  ck_assert_ldouble_nan(custom_asin(x));
  x = 2 * (CUSTOM_PI);
  ck_assert_ldouble_nan(custom_asin(x));
  x = 5 * (CUSTOM_PI_BY_FOUR);
  ck_assert_ldouble_nan(custom_asin(x));
}
START_TEST(test_asin_zero) {
  double x = CUSTOM_ZERO_D;
  ck_assert_msg(custom_fabs(custom_asin(x) - asinl(x)) < CUSTOM_ACCURACY,
                "Expected: %Lf, Result: %Lf", asinl(x), custom_asin(x));
  x = CUSTOM_ZERO_P;
  ck_assert_msg(custom_fabs(custom_asin(x) - asinl(x)) < CUSTOM_ACCURACY,
                "Expected: %Lf, Result: %Lf", asinl(x), custom_asin(x));
  x = CUSTOM_ZERO_N;
  ck_assert_msg(custom_fabs(custom_asin(x) - asinl(x)) < CUSTOM_ACCURACY,
                "Expected: %Lf, Result: %Lf", asinl(x), custom_asin(x));
}

START_TEST(test_acos_one_to_one) {
  for (int i = 0; i < MASS_SIZE_O; i++) {
    double x = initialize_mass_from_minus_one_to_one(i);
    ck_assert_msg(custom_fabs(custom_acos(x) - acosl(x)) < CUSTOM_ACCURACY,
                  "Expected: %Lf, Result: %Lf", acosl(x), custom_acos(x));
  }
}
START_TEST(test_acos_special_value) {
  double x = CUSTOM_NAN;
  ck_assert_ldouble_nan(custom_acos(x));
  x = CUSTOM_INF_P;
  ck_assert_ldouble_nan(custom_acos(x));
  x = CUSTOM_INF_N;
  ck_assert_ldouble_nan(custom_acos(x));
}
START_TEST(test_acos_angles_non_standart) {
  double x = -(CUSTOM_PI);
  ck_assert_ldouble_nan(custom_acos(x));
  x = 3 * (CUSTOM_PI_BY_TWO);
  ck_assert_ldouble_nan(custom_acos(x));
  x = 2 * (CUSTOM_PI);
  ck_assert_ldouble_nan(custom_acos(x));
  x = 5 * (CUSTOM_PI_BY_FOUR);
  ck_assert_ldouble_nan(custom_acos(x));
}
START_TEST(test_acos_zero) {
  double x = CUSTOM_ZERO_D;
  ck_assert_msg(custom_fabs(custom_acos(x) - acosl(x)) < CUSTOM_ACCURACY,
                "Expected: %Lf, Result: %Lf", acosl(x), custom_acos(x));
  x = CUSTOM_ZERO_P;
  ck_assert_msg(custom_fabs(custom_acos(x) - acosl(x)) < CUSTOM_ACCURACY,
                "Expected: %Lf, Result: %Lf", acosl(x), custom_acos(x));
  x = CUSTOM_ZERO_N;
  ck_assert_msg(custom_fabs(custom_acos(x) - acosl(x)) < CUSTOM_ACCURACY,
                "Expected: %Lf, Result: %Lf", acosl(x), custom_acos(x));
}

START_TEST(test_atan_one_to_one) {
  for (int i = 0; i < MASS_SIZE_O; i++) {
    double x = initialize_mass_from_minus_one_to_one(i);
    ck_assert_msg(custom_fabs(custom_atan(x) - atanl(x)) < CUSTOM_ACCURACY,
                  "Expected: %Lf, Result: %Lf", atanl(x), custom_atan(x));
  }
}
START_TEST(test_atan_special_value) {
  double x = CUSTOM_INF_P;
  ck_assert_msg(custom_fabs(custom_atan(x) - atanl(x)) < CUSTOM_ACCURACY,
                "Expected: %Lf, Result: %Lf", atanl(x), custom_atan(x));
  x = CUSTOM_INF_N;
  ck_assert_msg(custom_fabs(custom_atan(x) - atanl(x)) < CUSTOM_ACCURACY,
                "Expected: %Lf, Result: %Lf", atanl(x), custom_atan(x));
}
START_TEST(test_atan_angles_non_standart) {
  double x = -(CUSTOM_PI);
  ck_assert_msg(custom_fabs(custom_atan(x) - atanl(x)) < CUSTOM_ACCURACY,
                "Expected: %Lf, Result: %Lf", atanl(x), custom_atan(x));
  x = 3 * (CUSTOM_PI_BY_TWO);
  ck_assert_msg(custom_fabs(custom_atan(x) - atanl(x)) < CUSTOM_ACCURACY,
                "Expected: %Lf, Result: %Lf", atanl(x), custom_atan(x));
  x = 2 * (CUSTOM_PI);
  ck_assert_msg(custom_fabs(custom_atan(x) - atanl(x)) < CUSTOM_ACCURACY,
                "Expected: %Lf, Result: %Lf", atanl(x), custom_atan(x));
  x = 5 * (CUSTOM_PI_BY_FOUR);
  ck_assert_msg(custom_fabs(custom_atan(x) - atanl(x)) < CUSTOM_ACCURACY,
                "Expected: %Lf, Result: %Lf", atanl(x), custom_atan(x));
}
START_TEST(test_atan_zero) {
  double x = CUSTOM_ZERO_D;
  ck_assert_msg(custom_fabs(custom_atan(x) - atanl(x)) < CUSTOM_ACCURACY,
                "Expected: %Lf, Result: %Lf", atanl(x), custom_atan(x));
  x = CUSTOM_ZERO_P;
  ck_assert_msg(custom_fabs(custom_atan(x) - atanl(x)) < CUSTOM_ACCURACY,
                "Expected: %Lf, Result: %Lf", atanl(x), custom_atan(x));
  x = CUSTOM_ZERO_N;
  ck_assert_msg(custom_fabs(custom_atan(x) - atanl(x)) < CUSTOM_ACCURACY,
                "Expected: %Lf, Result: %Lf", atanl(x), custom_atan(x));
}

START_TEST(test_ceil_positive) {
  for (int i = 0; i < MASS_SIZE_O; i++) {
    double x = initialize_mass_positive(i);
    long double expected = ceill(x);
    long double result = custom_ceil(x);
    ck_assert_ldouble_eq_tol(expected, result, CUSTOM_ACCURACY);
  }
}
START_TEST(test_ceil_negative) {
  for (int i = 0; i < MASS_SIZE_O; i++) {
    double x = initialize_mass_negative(i);
    long double expected = ceill(x);
    long double result = custom_ceil(x);
    ck_assert_ldouble_eq_tol(expected, result, CUSTOM_ACCURACY);
  }
}
START_TEST(test_ceil_int) {
  for (int i = 0; i < MASS_SIZE_I; i++) {
    double x = initialize_mass_int(i);
    long double expected = ceill(x);
    long double result = custom_ceil(x);
    ck_assert_ldouble_eq_tol(expected, result, CUSTOM_ACCURACY);
  }
}
START_TEST(test_ceil_special_value) {
  double x = CUSTOM_INF_P;
  ck_assert_msg(custom_ceil(x) == ceill(x), "Expected: %Lf, Reality: %Lf",
                ceill(x), custom_ceil(x));
  x = CUSTOM_INF_N;
  ck_assert_msg(custom_ceil(x) == ceill(x), "Expected: %Lf, Reality: %Lf",
                ceill(x), custom_ceil(x));
}

START_TEST(test_exp_positive) {
  for (int i = 0; i < MASS_SIZE_O; i++) {
    double x = initialize_mass_positive(i);
    long double expected = exp(x);
    long double result = custom_exp(x);
    if (CUSTOM_INF_CONDITION) {
      ck_assert_msg(result == expected, "Expected: %Lf, Result: %Lf", expected,
                    result);
    } else {
      ck_assert_ldouble_eq_tol(expected, result, CUSTOM_ACCURACY);
    }
  }
}
START_TEST(test_exp_negative) {
  for (int i = 0; i < MASS_SIZE_O; i++) {
    double x = initialize_mass_negative(i);
    long double expected = exp(x);
    long double result = custom_exp(x);
    ck_assert_ldouble_eq_tol(expected, result, CUSTOM_ACCURACY);
  }
}
START_TEST(test_exp_int) {
  for (int i = 0; i < MASS_SIZE_I; i++) {
    double x = initialize_mass_int(i);
    long double expected = exp(x);
    long double result = custom_exp(x);
    ck_assert_ldouble_eq_tol(expected, result, CUSTOM_ACCURACY);
  }
}
START_TEST(test_exp_special_value) {
  double x = CUSTOM_NAN;
  ck_assert_ldouble_nan(custom_exp(x));
  x = CUSTOM_INF_P;
  ck_assert_msg(custom_exp(x) == expl(x), "Expected: %Lf, Reality: %Lf", expl(x),
                custom_exp(x));
  x = CUSTOM_INF_N;
  ck_assert_msg(custom_exp(x) == expl(x), "Expected: %Lf, Reality: %Lf", expl(x),
                custom_exp(x));
}

Suite *math_functions_suite() {
  Suite *s;
  TCase *tc_core;

  s = suite_create("Math Functions");

  /* Core test case */
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_abs_positive);
  tcase_add_test(tc_core, test_abs_negative);
  tcase_add_test(tc_core, test_abs_boundary_values);
  tcase_add_test(tc_core, test_abs_zero);
  tcase_add_test(tc_core, test_abs_special_value);

  tcase_add_test(tc_core, test_fabs_positive);
  tcase_add_test(tc_core, test_fabs_negative);
  tcase_add_test(tc_core, test_fabs_boundary_values);
  tcase_add_test(tc_core, test_fabs_zero);
  tcase_add_test(tc_core, test_fabs_special_value);

  tcase_add_test(tc_core, test_floor_positive);
  tcase_add_test(tc_core, test_floor_negative);
  tcase_add_test(tc_core, test_floor_int);
  tcase_add_test(tc_core, test_floor_special_value);

  tcase_add_test(tc_core, test_fmod_positive);
  tcase_add_test(tc_core, test_fmod_negative);
  tcase_add_test(tc_core, test_fmod_combinations);
  tcase_add_test(tc_core, test_fmod_zero);

  tcase_add_test(tc_core, test_log_positive);
  tcase_add_test(tc_core, test_log_negative);
  tcase_add_test(tc_core, test_log_special_value);
  tcase_add_test(tc_core, test_log_zero);

  tcase_add_test(tc_core, test_pow_positive);
  tcase_add_test(tc_core, test_pow_combinations);
  tcase_add_test(tc_core, test_pow_zero);
  tcase_add_test(tc_core, test_pow_special_value);

  tcase_add_test(tc_core, test_sqrt_positive);
  tcase_add_test(tc_core, test_sqrt_negative);
  tcase_add_test(tc_core, test_sqrt_zero);
  tcase_add_test(tc_core, test_sqrt_special_value);

  tcase_add_test(tc_core, test_sin_angles);
  tcase_add_test(tc_core, test_sin_zero);
  tcase_add_test(tc_core, test_sin_angles_non_standart);
  tcase_add_test(tc_core, test_sin_one_to_one);

  tcase_add_test(tc_core, test_cos_angles);
  tcase_add_test(tc_core, test_cos_zero);
  tcase_add_test(tc_core, test_cos_angles_non_standart);
  tcase_add_test(tc_core, test_cos_one_to_one);

  tcase_add_test(tc_core, test_tan_angles);
  tcase_add_test(tc_core, test_tan_zero);
  tcase_add_test(tc_core, test_tan_angles_non_standart);
  tcase_add_test(tc_core, test_tan_one_to_one);

  tcase_add_test(tc_core, test_asin_one_to_one);
  tcase_add_test(tc_core, test_asin_special_value);
  tcase_add_test(tc_core, test_asin_angles_non_standart);
  tcase_add_test(tc_core, test_asin_zero);

  tcase_add_test(tc_core, test_acos_one_to_one);
  tcase_add_test(tc_core, test_acos_special_value);
  tcase_add_test(tc_core, test_acos_angles_non_standart);
  tcase_add_test(tc_core, test_acos_zero);

  tcase_add_test(tc_core, test_atan_one_to_one);
  tcase_add_test(tc_core, test_atan_special_value);
  tcase_add_test(tc_core, test_atan_angles_non_standart);
  tcase_add_test(tc_core, test_atan_zero);

  tcase_add_test(tc_core, test_ceil_positive);
  tcase_add_test(tc_core, test_ceil_negative);
  tcase_add_test(tc_core, test_ceil_int);
  tcase_add_test(tc_core, test_ceil_special_value);

  tcase_add_test(tc_core, test_exp_positive);
  tcase_add_test(tc_core, test_exp_negative);
  tcase_add_test(tc_core, test_exp_int);
  tcase_add_test(tc_core, test_exp_special_value);

  suite_add_tcase(s, tc_core);

  return s;
}

int main() {
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = math_functions_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_ENV);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}