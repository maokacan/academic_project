#include "../custom_string.h"

void *custom_memset(void *str, int c, size_t n) {
  if (str != CUS_NULL && n > 0) {
    size_t i = 0;
    char *s = str;
    while (n != i) {
      *(s + i) = c;
      i++;
    }
  }
  return str;
}