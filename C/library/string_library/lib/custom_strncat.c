#include "../custom_string.h"

char *custom_strncat(char *dest, const char *src, size_t n) {
  size_t dest_len = custom_strlen(dest);
  size_t i;
  for (i = 0; i < n && src[i] != '\0'; ++i) {
    dest[dest_len + i] = src[i];
  }
  dest[dest_len + i] = '\0';
  return dest;
}
