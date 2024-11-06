#include "../custom_string.h"

char *custom_strcpy(char *restrict str_1, const char *restrict str_2) {
  int i = 0;
  while (str_2[i] != '\0') {
    str_1[i] = str_2[i];
    i++;
  }
  str_1[i] = '\0';

  return str_1;
}
