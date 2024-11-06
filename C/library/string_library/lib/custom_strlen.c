#include "../custom_string.h"

custom_size_t custom_strlen(const char *string) {
  custom_size_t count = 0;
  for (int i = 0; string[i] != '\0'; i++) {
    count++;
  }
  return count;
}