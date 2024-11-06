#include "../custom_string.h"

char *custom_strstr(const char *haystack, const char *needle) {
  size_t srcptrLength = custom_strlen(needle);
  size_t srcptrLength_1 = custom_strlen(haystack);
  const char *result = CUS_NULL;
  int x = 0;

  if (srcptrLength != 0 && srcptrLength_1 >= srcptrLength) {
    for (; result == CUS_NULL && haystack[x] != '\0'; x += 1) {
      if (haystack[x] == needle[0]) {
        if (custom_strncmp(haystack + x, needle, srcptrLength) == 0)
          result = haystack + x;
      }
    }
  } else if (srcptrLength == 0 || srcptrLength_1 == 0) {
    result = haystack + x;
  }

  return srcptrLength_1 < srcptrLength ? CUS_NULL : (char *)result;
}