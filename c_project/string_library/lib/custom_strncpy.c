#include "../custom_string.h"

char *custom_strncpy(char *dest, const char *src, size_t n) {
  custom_size_t index = 0;
  while (n > index && src[index] != '\0') {
    dest[index] = src[index];
    index++;
  }
  while (index < n) {
    dest[index] = '\0';
    index++;
  }
  return dest;
}