#include "../custom_string.h"

int custom_memcmp(const void *str1, const void *str2, custom_size_t n) {
  char *s1 = (char *)str1;
  char *s2 = (char *)str2;
  int result = 0;
  for (custom_size_t i = 0; i < n && result == 0; i++) {
    if (s1[i] != s2[i]) {
      result = s1[i] - s2[i];
    }
  }
  return result;
}