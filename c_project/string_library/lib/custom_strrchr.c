#include "../custom_string.h"

char *custom_strrchr(const char *str, int c) {
  int ind;
  char tmp = (char)c;
  for (ind = 0; *str; ind++) {
    str++;
  }
  for (; ind > 0; ind--) {
    if (*str == tmp) {
      ind = 0;
    } else {
      str--;
    }
  }
  return (char *)(*str == tmp ? str : CUS_NULL);
}