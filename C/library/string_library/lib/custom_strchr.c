#include "../custom_string.h"

char *custom_strchr(const char *str, int c) {
  char *res = CUS_NULL;
  while ((*str != '\0') && (*str != c)) {
    str++;
  }
  if (*str == c) {
    res = (char *)str;
  }
  return res;
}