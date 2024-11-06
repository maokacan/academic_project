//
// Created by maokacan on 05.11.2024.
// tg: @chrstfr
//

#ifndef MACRO_HELP_H
#define MACRO_HELP_H

#include <stdio.h>
#include <stdlib.h>

#define OK 0
#define INVALID_MATRIX 1
#define CALCULATION_ERROR 2

#define SUCCESS 1
#define FAILURE 0

#define INIT_MTRX \
  { NULL, 0, 0 }
#define INIT_ZERO 0.0

typedef struct matrix_struct {
  double** matrix;
  int rows;
  int columns;
} matrix_t;

#endif  // MACRO_HELP_H
