#include "../custom_string.h"

void *custom_insert(const char *src, const char *str, size_t start_index) {
  char *result = CUS_NULL;
  if (src != CUS_NULL && str != CUS_NULL) {
    size_t src_len = custom_strlen(src);
    size_t str_len = custom_strlen(str);
    if (start_index <= src_len) {
      result = (char *)malloc((src_len + str_len + 1) * sizeof(char));
      if (result != CUS_NULL) {
        // Copying the src string until the start_index
        custom_strncpy(result, src, start_index);
        result[start_index] = '\0';

        // Concatenating the str string
        custom_strncat(result, str, str_len);

        // Concatenating the remaining part of src string
        custom_strncat(result, src + start_index, src_len - start_index);
      }
    }
  }

  return result;
}