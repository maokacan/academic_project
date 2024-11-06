#include "../custom_string.h"

void *custom_memchr(const void *str, int c, custom_size_t n) {
  const unsigned char *ptr = str;
  while (n-- > 0) {
    if (*ptr == (unsigned char)c) {
      return (void *)ptr;
    }
    ptr++;
  }
  return CUS_NULL;
}