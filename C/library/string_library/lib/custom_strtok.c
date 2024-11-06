#include "../custom_string.h"

char *custom_strtok(char *str, const char *delim) {
  static char *lastToken = CUS_NULL;
  char *token = CUS_NULL;

  if (str != CUS_NULL) lastToken = str;

  if (lastToken != CUS_NULL) {
    while (*lastToken && custom_strchr(delim, *lastToken)) ++lastToken;

    if (*lastToken == '\0') {
      lastToken = CUS_NULL;
    } else {
      token = lastToken;
      lastToken = custom_strpbrk(lastToken, delim);

      if (lastToken != CUS_NULL) {
        *lastToken = '\0';
        ++lastToken;
      }
    }
  }
  return token;
}