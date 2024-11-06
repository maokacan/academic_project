#include "../custom_string.h"

char *custom_strpbrk(const char *str1, const char *str2) {
  char *result = CUS_NULL;
  for (custom_size_t i = 0; (str1[i] != 0) && (result == CUS_NULL); i++) {
    for (custom_size_t j = 0; (str2[j] != 0) && (result == CUS_NULL); j++) {
      if (str1[i] == str2[j]) {
        result = (char *)(str1 + i);
      }
    }
  }
  return result;
}