#ifndef CUSTOM_STRING_H
#define CUSTOM_STRING_H

#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#define CUS_NULL ((void *)0)

typedef long unsigned custom_size_t;

void *custom_memchr(const void *str, int c, size_t n);
int custom_memcmp(const void *str1, const void *str2, size_t n);
void *custom_memcpy(void *dest, const void *src, size_t n);
void *custom_memset(void *str, int c, size_t n);
char *custom_strncat(char *dest, const char *src, size_t n);
char *custom_strchr(const char *str, int c);
int custom_strncmp(const char *str1, const char *str2, size_t n);
char *custom_strncpy(char *dest, const char *src, size_t n);
char *custom_strcpy(char *restrict str_1, const char *restrict str_2);
size_t custom_strcspn(const char *str1, const char *str2);
char *custom_strerror(int errnum);
size_t custom_strlen(const char *str);
char *custom_strpbrk(const char *str1, const char *str2);
char *custom_strrchr(const char *str, int c);
char *custom_strstr(const char *haystack, const char *needle);
char *custom_strtok(char *str, const char *delim);
void *custom_trim(const char *src, const char *trim_chars);
void *custom_to_upper(const char *str);
void *custom_to_lower(const char *str);
void *custom_insert(const char *src, const char *str, size_t start_index);
int custom_sprintf(char *str, const char *format, ...);

#endif