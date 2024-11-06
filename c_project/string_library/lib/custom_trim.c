#include "../custom_string.h"

void *custom_trim(const char *src, const char *trim_chars) {
  char *result = CUS_NULL;
  if (src != CUS_NULL && trim_chars != CUS_NULL) {
    size_t src_len = custom_strlen(src);
    size_t start_index = 0;
    size_t end_index;

    if (src_len != 0)
      end_index = src_len - 1;
    else
      end_index = src_len;

    // Finding the start index to trim
    while (start_index < src_len &&
           custom_strchr(trim_chars, src[start_index]) != CUS_NULL) {
      start_index++;
    }

    // Finding the end index to trim
    while (end_index > start_index &&
           custom_strchr(trim_chars, src[end_index]) != CUS_NULL) {
      end_index--;
    }

    // Calculating the length of the trimmed string
    size_t trimmed_len =
        (end_index >= start_index) ? (end_index - start_index + 1) : 0;

    result = (char *)malloc((trimmed_len + 1) * sizeof(char));
    if (result != CUS_NULL) {
      // Copying the trimmed string
      custom_strncpy(result, src + start_index, trimmed_len);
      result[trimmed_len] = '\0';
    }
  }

  return result;
}