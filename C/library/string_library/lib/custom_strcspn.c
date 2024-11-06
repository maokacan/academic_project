#include "../custom_string.h"

size_t custom_strcspn(const char *str1, const char *str2) {
  custom_size_t strLength = custom_strlen(str1);
  custom_size_t res = 0;

  for (custom_size_t x = 0; x < strLength && custom_strchr(str2, str1[x]) == CUS_NULL;
       x += 1) {
    res += 1;
  }
  return res;
}
