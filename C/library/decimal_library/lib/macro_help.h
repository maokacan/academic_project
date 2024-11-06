#ifndef MACRO_HELP_H
#define MACRO_HELP_H

#define VALUE_IS_ZERO                                                         \
  {                                                                           \
    {                                                                         \
      0b00000000000000000000000000000000, 0b00000000000000000000000000000000, \
          0b00000000000000000000000000000000,                                 \
          0b00000000000000000000000000000000                                  \
    }                                                                         \
  }

#define VALUE_IS_ONE                                                          \
  {                                                                           \
    {                                                                         \
      0b00000000000000000000000000000001, 0b00000000000000000000000000000000, \
          0b00000000000000000000000000000000,                                 \
          0b00000000000000000000000000000000                                  \
    }                                                                         \
  }

#define BIT 8
#define SIZE_BITS 4
#define SIZE_BITS_BIG 8
#define NUM_255 255

#define TRUE 1
#define FALSE 0

#define OK 0
#define BIG_NUMBER 1
#define SMALL_NUMBER 2
#define DIVISION_BY_0 3

#define CUS_MAX_UINT 4294967295
#define is_fin(x) __builtin_isfinite(x)
#define is_nan(x) __builtin_isnan(x)
#define is_inf(x) __builtin_isinf(x)

typedef struct {
  unsigned int bits[SIZE_BITS];
} custom_decimal;

typedef union {
  float flt;
  unsigned int bits;
} lens_t;

#endif  //  MACRO_HELP_H
