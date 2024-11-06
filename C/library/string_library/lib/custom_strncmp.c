#include "../custom_string.h"

int custom_strncmp(const char *str1, const char *str2, custom_size_t n) {
  int result = 0;

  if (str1[0] == 0 && str2[0] != 0) {
    result = -str2[0];
  } else if (str2[0] == 0 && str1[0] != 0) {
    result = str1[0];
  }

  for (custom_size_t i = 0; (i < n) && (str1[i] != 0) && (str2[i] != 0); i++) {
    if (str1[i] != str2[i]) {
      result = str1[i] - str2[i];
    }
  }
  return result;
}