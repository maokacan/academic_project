#include "../custom_string.h"

char lowchar(int q) { return (char)(q + 32); }

void *custom_to_lower(const char *str) {
  char *result = CUS_NULL;
  if (str != CUS_NULL) {
    size_t len = custom_strlen(str);
    result = (char *)malloc((len + 1) * sizeof(char));
    if (result != CUS_NULL) {
      for (size_t i = 0; i < len; ++i) {
        (str[i] > 64 && str[i] < 91) ? result[i] = lowchar(str[i])
                                     : (result[i] = str[i]);
      }
      result[len] = '\0';
    }
  }

  return result;
}