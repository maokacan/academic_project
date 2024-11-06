#include "../custom_string.h"

#define MAX_BUFFER_SIZE 1024

struct form {
  bool left_justify;
  bool zero_flag;
  bool plus_flag;
  bool negative;
  bool is_long;
  bool is_long_double;
  bool is_short;
  bool space_flag;
} form_opt;

int intLength(long long num) {
  int length = 0;
  if (num == 0) length = 1;
  while (num != 0) {
    num /= 10;
    length++;
  }
  return length;
}

void append_to_ibuffer(const char *str, char *output, int *out_len,
                       int *width) {
  int len = (int)custom_strlen(str);
  int spaces = (*width) - len;
  if (spaces > 0 && !form_opt.left_justify) {
    while (spaces-- > 0) output[(*out_len)++] = ' ';
  }
  for (int i = 0; i < len; ++i) {
    output[(*out_len)++] = str[i];
  }
  if (spaces > 0 && form_opt.left_justify) {
    while (spaces-- > 0) output[(*out_len)++] = ' ';
  }
}

void append_string_to_ibuffer(const char *str, char *output, int *out_len,
                              int *width, int precision) {
  char temp_first[MAX_BUFFER_SIZE] = {0};
  char temp[MAX_BUFFER_SIZE];
  int temp_len = 0;
  int count = 0;
  int count_sec = 0;
  int len_str = custom_strlen(str);
  while (*str != '\0' && (precision < 0 || temp_len < precision)) {
    if ((*width >= precision && precision == 0) ||
        (*width > precision && precision < len_str && precision != -1))
      temp_first[temp_len++] = ' ';
    else if (*width == 0 && precision < len_str && precision != -1) {
      str++;
    } else
      temp_first[temp_len++] = *str;
    str++;
  }
  if (precision == -1 || precision > temp_len) precision = temp_len;
  while (count < precision) {
    temp[count++] = temp_first[count_sec++];
  }
  temp[count] = '\0';
  append_to_ibuffer(temp, output, out_len, width);
}

void append_to_bufferq(const char *str, char *output, int *out_len,
                       int *width) {
  int len = (int)custom_strlen(str);
  int spaces = (*width) - len;
  if (spaces > 0 && !form_opt.left_justify && !form_opt.zero_flag) {
    while (spaces-- > 0) output[(*out_len)++] = ' ';
  }
  if (form_opt.zero_flag && spaces > 0 && !form_opt.left_justify) {
    while (spaces-- > 0) output[(*out_len)++] = '0';
  }
  for (int i = 0; i < len; ++i) {
    output[(*out_len)++] = str[i];
  }
  if (spaces > 0 && form_opt.left_justify) {
    while (spaces-- > 0) output[(*out_len)++] = ' ';
  }
}

void processing_spec_char(const char *str, char *output, int *out_len,
                          int *width) {
  int len = (int)custom_strlen(str);
  int spaces = (*width) - len;
  if (spaces > 0 && !form_opt.left_justify) {
    if (form_opt.zero_flag)
      while (spaces-- > 0) output[(*out_len)++] = '0';
    while (spaces-- > 0) output[(*out_len)++] = ' ';
  }
  if (str[0] == '\0') {
    output[(*out_len)++] = '\0';
  } else if (str[0] == ' ') {
    output[(*out_len)++] = ' ';
  } else {
    for (int i = 0; i < len; ++i) {
      output[(*out_len)++] = str[i];
    }
  }
  if (spaces > 0 && form_opt.left_justify) {
    while (spaces-- > 0) output[(*out_len)++] = ' ';
  }
}

void append_string_to_bufferq(const char *str, char *output, int *out_len,
                              int *width, int precision) {
  char temp_first[MAX_BUFFER_SIZE] = {0};
  char temp[MAX_BUFFER_SIZE];
  int temp_len = 0;
  int count = 0;
  int count_sec = 0;
  int dif = 0;
  while (*str != '\0') {
    temp_first[temp_len++] = *str;
    str++;
  }
  if (precision == -1 || precision > temp_len) precision = temp_len;
  while (count < precision + dif) {
    temp[count++] = temp_first[count_sec++];
  }
  temp[count] = '\0';
  append_to_bufferq(temp, output, out_len, width);
}

void append_zero_int_buffer(char *reversed, int *reversed_len, int *num_len,
                            int *precision) {
  while (*num_len < *precision) {
    reversed[(*reversed_len)++] = '0';
    (*num_len)++;
  }
}

void append_integer_to_buffer(long long num, char *output, int *out_len,
                              int *width, int precision) {
  char temp[MAX_BUFFER_SIZE];
  int temp_len = 0;
  int q = 0;
  int num_len = intLength(num);
  form_opt.negative = false;
  if (num < 0) {
    form_opt.negative = true;
  }
  if (num == 0) {
    if (num_len == 1 && (width != 0 && precision != 0))
      temp[temp_len++] = '0';
    else if (width == 0 && precision == 0)
      temp[temp_len++] = ' ';
  } else {
    while (num != 0) {
      (form_opt.negative) ? (q = (num % 10) * (-1)) : (q = (num % 10));
      temp[temp_len++] = q + '0';
      num /= 10;
    }
  }
  char reversed[MAX_BUFFER_SIZE];
  int reversed_len = 0;
  if (form_opt.negative) {
    reversed[reversed_len++] = '-';
  } else if ((form_opt.plus_flag) && !form_opt.negative) {
    reversed[reversed_len++] = '+';
  } else if (form_opt.space_flag && num_len >= precision &&
             !form_opt.negative && !form_opt.plus_flag) {
    reversed[reversed_len++] = ' ';
  }
  if (precision > -1) {
    append_zero_int_buffer(reversed, &reversed_len, &num_len, &precision);
    precision = num_len + intLength(num);
  } else if (*width > 0 && form_opt.zero_flag) {
    if (form_opt.negative) {
      (*width)--;
    }
    append_zero_int_buffer(reversed, &reversed_len, &num_len, width);
    *width = num_len + intLength(num) - 1;
  }
  for (int i = temp_len - 1; i >= 0; --i) {
    reversed[reversed_len++] = temp[i];
  }
  reversed[reversed_len] = '\0';
  append_string_to_ibuffer(reversed, output, out_len, width, precision);
}

void reverse_string(char *str, int len) {
  int i = 0, j = len - 1, temp;
  while (i < j) {
    temp = str[i];
    str[i] = str[j];
    str[j] = temp;
    i++;
    j--;
  }
}

void append_to_fbuffer(const char *str, char *output, int *out_len,
                       int *width) {
  int len = (int)custom_strlen(str);
  int sign_is_set = -1;
  int spaces = (*width) - len;
  if (form_opt.negative || form_opt.plus_flag) spaces--;
  if (form_opt.space_flag && !(form_opt.negative || form_opt.plus_flag)) {
    output[(*out_len)++] = ' ';
    spaces--;
  }
  if (spaces > 0 && !form_opt.left_justify) {
    if (form_opt.zero_flag) {
      if (form_opt.negative) {
        output[(*out_len)++] = '-';
        sign_is_set = 1;
      } else if ((form_opt.plus_flag)) {
        output[(*out_len)++] = '+';
        sign_is_set = 1;
      }
      while (spaces-- > 0) output[(*out_len)++] = '0';
    } else {
      while (spaces-- > 0) output[(*out_len)++] = ' ';
    }
  }
  if (sign_is_set != 1) {
    if (form_opt.negative) {
      output[(*out_len)++] = '-';
    } else if ((form_opt.plus_flag)) {
      output[(*out_len)++] = '+';
    }
  }
  for (int i = 0; i < len; ++i) {
    output[(*out_len)++] = str[i];
  }
  if (spaces > 0 && form_opt.left_justify) {
    while (spaces-- > 0) output[(*out_len)++] = ' ';
  }
}

void append_string_to_fbuffer(const char *str, char *output, int *out_len,
                              int *width, int precision) {
  char temp_first[MAX_BUFFER_SIZE] = {0};
  char temp[MAX_BUFFER_SIZE];
  int temp_len = 0;
  int count = 0;
  int count_sec = 0;
  int dif = 0;
  while (*str != '\0') {
    temp_first[temp_len++] = *str;
    str++;
  }
  if (precision == -1 || precision > temp_len) precision = temp_len;
  while (count < precision + dif) {
    temp[count++] = temp_first[count_sec++];
  }
  temp[count] = '\0';
  append_to_fbuffer(temp, output, out_len, width);
}

void append_float_to_buffer(long double num, char *output, int *out_len,
                            int *width, int *precision) {
  char temp[MAX_BUFFER_SIZE];
  int temp_len = 0;
  form_opt.negative = false;
  if (num < 0) {
    form_opt.negative = true;
    num = -num;
  }
  long double arr[16];
  for (int i = 1; i <= 16; ++i) {
    arr[i - 1] = powl(10, -i);
  }
  long long integer_part = 0;
  if (*precision == 0) {
    integer_part = (long long)roundl(num);
  } else {
    integer_part = (long long)num;
  }
  long double fractional_part = num - (long double)integer_part;
  if (*precision > 0) {
    int fract_len = *precision;
    long double check = fractional_part * (pow(10, (*precision + 1)));
    if (((long int)check % 10) >= 5) {
      fractional_part += arr[*precision - 1];
    }
    if ((int)fractional_part == 1) (integer_part++);
    while (fract_len-- > 0) {
      fractional_part *= 10;
      int digit = (int)fractional_part % 10;
      temp[temp_len++] = '0' + digit;
      fractional_part -= digit;
    }
    if (*precision > 0) {
      temp[temp_len++] = '.';
    }
    reverse_string(temp, temp_len - 1);
  }
  if (integer_part == 0) {
    temp[temp_len++] = '0';
  }
  while (integer_part > 0) {
    temp[temp_len++] = '0' + (integer_part % 10);
    integer_part /= 10;
  }
  reverse_string(temp, temp_len);
  *precision = temp_len;
  append_string_to_fbuffer(temp, output, out_len, width, *precision);
}

void append_unsigned_to_buffer(long unsigned num, char *output, int *out_len,
                               int *width, int *precision) {
  char temp[MAX_BUFFER_SIZE];
  int temp_len = 0;
  int num_len = 1;
  long unsigned copy_num = num;
  long unsigned divisor = 1;
  if (num != 0) {
    while (num / divisor >= 10) {
      divisor *= 10;
      num_len++;
    }
  }
  if (*width > 0 && form_opt.zero_flag && *precision == -1)
    append_zero_int_buffer(temp, &temp_len, &num_len, width);
  else
    append_zero_int_buffer(temp, &temp_len, &num_len, precision);

  if (*precision == 0 && *width > 0 && copy_num == 0) {
    ;
  } else if (*precision == 0 && *width == 0 && copy_num == 0) {
    ;
  } else {
    while (divisor != 0) {
      temp[temp_len++] = '0' + num / divisor;
      num %= divisor;
      divisor /= 10;
    }
  }
  temp[temp_len] = '\0';
  append_to_ibuffer(temp, output, out_len, width);
}

void append_hexadecimal_to_buffer(long unsigned int num, char *output,
                                  int *out_len, int *width, int mode,
                                  int precision) {
  char temp[MAX_BUFFER_SIZE];
  int temp_len = 0;
  int num_len = 0;
  char hex_digits[] = "0123456789abcdef";
  if (mode == 1) {
    hex_digits[10] = 'A';
    hex_digits[11] = 'B';
    hex_digits[12] = 'C';
    hex_digits[13] = 'D';
    hex_digits[14] = 'E';
    hex_digits[15] = 'F';
  }
  if (mode == 2) {
    temp[temp_len++] = '0';
    temp[temp_len++] = 'x';
  }
  char hex_representation[30];
  int index = 0;
  if (num == 0) {
    temp[temp_len++] = '0';
  }
  while (num != 0) {
    hex_representation[index++] = hex_digits[num % 16];
    num /= 16;
    num_len++;
  }
  append_zero_int_buffer(hex_representation, &index, &num_len, &precision);
  while (index > 0) {
    temp[temp_len++] = hex_representation[--index];
  }
  temp[temp_len] = '\0';
  append_to_ibuffer(temp, output, out_len, width);
}

void append_octal_to_buffer(long unsigned int num, char *output, int *out_len,
                            int *width, int *precision) {
  char temp[MAX_BUFFER_SIZE];
  int temp_len = 0;
  int num_len = 0;
  if (num == 0) {
    temp[temp_len++] = '0';
  }
  char octal_representation[30];
  int index = 0;
  while (num != 0) {
    octal_representation[index++] = '0' + (num % 8);
    num /= 8;
    num_len++;
  }
  append_zero_int_buffer(octal_representation, &index, &num_len, precision);
  while (index > 0) {
    temp[temp_len++] = octal_representation[--index];
  }
  temp[temp_len] = '\0';
  append_to_ibuffer(temp, output, out_len, width);
}

void choice_flags(const char *format) {
  if (*format == '-')
    form_opt.left_justify = true;
  else if (*format == '0')
    form_opt.zero_flag = true;
  else if (*format == ' ')
    form_opt.space_flag = true;
  else if (*format == '+')
    form_opt.plus_flag = true;
}

void conversion_specifiers(const char *format, va_list args, int *out_len,
                           char *output, int *precision, int *width) {
  switch (*format) {
    case 'c': {
      if (form_opt.is_long) {
        char ch = va_arg(args, int);
        char temp[2] = {ch, '\0'};
        processing_spec_char(temp, output, out_len, width);
      } else {
        char ch = (char)va_arg(args, int);
        char temp[2] = {ch, '\0'};
        processing_spec_char(temp, output, out_len, width);
      }
      break;
    }
    case 'i':
    case 'd': {
      if (form_opt.is_short) {
        short num = (short)va_arg(args, int);
        append_integer_to_buffer(num, output, out_len, width, *precision);
      } else if (form_opt.is_long) {
        long long num = (long long)va_arg(args, long long);
        append_integer_to_buffer(num, output, out_len, width, *precision);
      } else {
        int num = va_arg(args, int);
        append_integer_to_buffer(num, output, out_len, width, *precision);
      }
      break;
    }
    case 'f': {
      if ((*precision) == -1) (*precision) = 6;
      if (form_opt.is_long_double) {
        long double num = va_arg(args, long double);
        append_float_to_buffer(num, output, out_len, width, precision);
      } else {
        double num = va_arg(args, double);
        append_float_to_buffer(num, output, out_len, width, precision);
      }
      break;
    }
    case 's': {
      char *str_arg = va_arg(args, char *);
      if (str_arg != NULL) {
        append_string_to_bufferq(str_arg, output, out_len, width, *precision);
      } else {
        append_string_to_bufferq("(null)", output, out_len, width, *precision);
      }
      break;
    }
    case 'u': {
      if (form_opt.is_short) {
        unsigned num = va_arg(args, unsigned int);
        append_unsigned_to_buffer(num, output, out_len, width, precision);
      } else if (form_opt.is_long) {
        long unsigned num = (long unsigned)va_arg(args, long unsigned int);
        append_unsigned_to_buffer(num, output, out_len, width, precision);
      } else {
        unsigned num = va_arg(args, unsigned int);
        append_unsigned_to_buffer(num, output, out_len, width, precision);
      }
      break;
    }
    case 'x': {
      if (form_opt.is_short) {
        unsigned hex_num = (unsigned)va_arg(args, unsigned);
        append_hexadecimal_to_buffer(hex_num, output, out_len, width, 0,
                                     *precision);
      } else if (form_opt.is_long) {
        unsigned long hex_num = (unsigned long)va_arg(args, unsigned long);
        append_hexadecimal_to_buffer(hex_num, output, out_len, width, 0,
                                     *precision);
      } else {
        unsigned int hex_num = va_arg(args, unsigned int);
        append_hexadecimal_to_buffer(hex_num, output, out_len, width, 0,
                                     *precision);
      }
      break;
    }
    case 'X': {
      if (form_opt.is_short) {
        unsigned hex_num_capital = (unsigned)va_arg(args, unsigned);
        append_hexadecimal_to_buffer(hex_num_capital, output, out_len, width, 1,
                                     *precision);
      } else if (form_opt.is_long) {
        unsigned long hex_num_capital =
            (unsigned long)va_arg(args, unsigned long);
        append_hexadecimal_to_buffer(hex_num_capital, output, out_len, width, 1,
                                     *precision);
      } else {
        unsigned int hex_num_capital = va_arg(args, unsigned int);
        append_hexadecimal_to_buffer(hex_num_capital, output, out_len, width, 1,
                                     *precision);
      }
      break;
    }
    case 'o': {
      if (form_opt.is_short) {
        unsigned oct_num = (unsigned)va_arg(args, unsigned);
        append_octal_to_buffer(oct_num, output, out_len, width, precision);
      } else if (form_opt.is_long) {
        unsigned long oct_num = (unsigned long)va_arg(args, unsigned long);
        append_octal_to_buffer(oct_num, output, out_len, width, precision);
      } else {
        unsigned int oct_num = va_arg(args, unsigned int);
        append_octal_to_buffer(oct_num, output, out_len, width, precision);
      }
      break;
    }
    case 'p': {
      void *ptr = va_arg(args, void *);
      append_hexadecimal_to_buffer((unsigned long)ptr, output, out_len, width,
                                   2, *precision);
      break;
    }
    case '%': {
      output[(*out_len)++] = '%';
      break;
    }
  }
}

void reset_struct() {
  form_opt.left_justify = false;
  form_opt.zero_flag = false;
  form_opt.plus_flag = false;
  form_opt.is_long = false;
  form_opt.is_long_double = false;
  form_opt.is_short = false;
  form_opt.space_flag = false;
  form_opt.negative = false;
}

void choice_len_descriptor(const char *format) {
  switch (*format) {
    case 'h': {
      form_opt.is_short = true;
      break;
    }
    case 'l': {
      form_opt.is_long = true;
      break;
    }
    case 'L': {
      form_opt.is_long_double = true;
      break;
    }
  }
}

int custom_sprintf(char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);

  int out_len = 0;
  char output[MAX_BUFFER_SIZE];
  custom_memset(output, 0, sizeof(output));

  while (*format != '\0') {
    if (*format == '%') {
      format++;
      reset_struct();
      int width = 0;
      int precision = -1;

      while (*format == '-' || *format == '0' || *format == ' ' ||
             *format == '+') {
        choice_flags(format);
        format++;
      }
      while (*format >= '0' && *format <= '9') {
        width = width * 10 + (*format - '0');
        format++;
      }
      if (*format == '.') {
        format++;
        precision = 0;
        while (*format >= '0' && *format <= '9') {
          precision = precision * 10 + (*format - '0');
          format++;
        }
      }
      if (*format == 'l' || *format == 'L' || *format == 'h') {
        choice_len_descriptor(format);
        format++;
      }
      conversion_specifiers(format, args, &out_len, output, &precision, &width);
      format++;
    } else {
      output[out_len++] = *format++;
    }
    if (out_len >= MAX_BUFFER_SIZE - 1) break;
  }
  va_end(args);
  output[out_len] = '\0';
  custom_strcpy(str, output);

  return out_len;
}
