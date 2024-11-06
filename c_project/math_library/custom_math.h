#ifndef CUSTOM_MATH_H
#define CUSTOM_MATH_H

#define CUSTOM_NAN (0.0 / 0.0)
#define CUSTOM_INF_P (1.0 / 0.0)
#define CUSTOM_INF_N (-1.0 / 0.0)
#define CUSTOM_IS_INF(x) (x == CUSTOM_INF_N || x == CUSTOM_INF_P)
#define CUSTOM_IS_NAN(x) (x != x)
#define CUSTOM_EPS_E 1E-16
#define CUSTOM_EPS 1E-9
#define CUSTOM_DBL_MAX 1.7976931348623158e+308L
#define CUSTOM_E 2.71828182845904523536
#define CUSTOM_ZERO_D 0.0000000000001
#define CUSTOM_ZERO_P 0.0 / 1.0
#define CUSTOM_ZERO_N -0.0 / 1.0
// angles
#define CUSTOM_PI 3.14159265358979323846
#define CUSTOM_PI_BY_TWO (CUSTOM_PI / 2)
#define CUSTOM_PI_BY_THREE (CUSTOM_PI / 3)
#define CUSTOM_PI_BY_FOUR (CUSTOM_PI / 4)
#define CUSTOM_PI_BY_SIX (CUSTOM_PI / 6)

#include <stdio.h>
#include <stdlib.h>

int custom_abs(int x);
long double custom_fabs(double x);
long double custom_ceil(double x);
long double custom_floor(double x);
long double custom_exp(double x);
long double custom_log(double x);
long double custom_pow(double base, double power);
long double custom_sqrt(double num);
long double custom_sin(double x);
long double custom_cos(double x);
long double custom_tan(double x);
long double custom_atan(double x);
long double custom_asin(double x);
long double custom_acos(double x);
long double custom_fmod(double x, double y);

#endif