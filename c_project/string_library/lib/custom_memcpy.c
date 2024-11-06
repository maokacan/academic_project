#include "../custom_string.h"

void *custom_memcpy(void *dest, const void *src, size_t n) {
  char *dest_ptr = (char *)dest;
  const char *src_ptr = (char *)src;
  while (n != 0) {
    *dest_ptr = *src_ptr;
    dest_ptr++;
    src_ptr++;
    n--;
  }
  return dest;
}