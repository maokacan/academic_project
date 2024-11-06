#include "test_me.h"

START_TEST(strtok_1) {
  char str_1[] = "Hello, world!";
  char str_2[] = "Hello, world!";
  char str_3[] = "!";
  ck_assert_pstr_eq(strtok(str_1, str_3), custom_strtok(str_2, str_3));
}
END_TEST

START_TEST(strtok_2) {
  char str_1[] = "";
  char str_2[] = "";
  char str_3[] = "";
  ck_assert_pstr_eq(strtok(str_1, str_3), custom_strtok(str_2, str_3));
}
END_TEST

START_TEST(strtok_3) {
  char str_1[] = "Hello, world!";
  char str_2[] = "Hello, world!";
  char str_3[] = "\0";
  ck_assert_pstr_eq(strtok(str_1, str_3), custom_strtok(str_2, str_3));
}
END_TEST

START_TEST(strtok_4) {
  char str_1[] = "Hello, world!";
  char str_2[] = "Hello, world!";
  char str_3[] = "";
  ck_assert_pstr_eq(strtok(str_1, str_3), custom_strtok(str_2, str_3));
}
END_TEST

START_TEST(strtok_5) {
  char str_1[] = "Hello, world!";
  char str_2[] = "Hello, world!";
  char str_3[] = "Hello, world!";
  ck_assert_pstr_eq(strtok(str_1, str_3), custom_strtok(str_2, str_3));
}
END_TEST

START_TEST(strtok_6) {
  char str_1[] = "Hello, world!";
  char str_2[] = "Hello, world!";
  char str_3[] =
      "My name is Polina. I hate this, maybe I'm not supposed for this.";
  ck_assert_pstr_eq(strtok(str_1, str_3), custom_strtok(str_2, str_3));
}
END_TEST

START_TEST(strtok_7) {
  char str_1[] = "ABABABABABBABABABBABABABABABBA";
  char str_2[] = "ABABABABABBABABABBABABABABABBA";
  char str_3[] = "B";
  ck_assert_pstr_eq(strtok(str_1, str_3), custom_strtok(str_2, str_3));
}
END_TEST

START_TEST(strtok_8) {
  char str_1[] = "\0ABABABABABBABABABBABABABABABBA";
  char str_2[] = "\0ABABABABABBABABABBABABABABABBA";
  char str_3[] = "A";
  ck_assert_pstr_eq(strtok(str_1, str_3), custom_strtok(str_2, str_3));
}
END_TEST

START_TEST(strtok_9) {
  char str_1[] = "\0Hello, world!";
  char str_2[] = "\0Hello, world!";
  char str_3[] = "\0";
  ck_assert_pstr_eq(strtok(str_1, str_3), custom_strtok(str_2, str_3));
}
END_TEST

START_TEST(strtok_10) {
  char str_1[] = "\0Hello, world!";
  char str_2[] = "\0Hello, world!";
  char str_3[] = "";
  ck_assert_pstr_eq(strtok(str_1, str_3), custom_strtok(str_2, str_3));
}
END_TEST

START_TEST(strtok_11) {
  char *str_1 = NULL;
  char *str_2 = NULL;
  char str_3[] = "";
  ck_assert_pstr_eq(strtok(str_1, str_3), custom_strtok(str_2, str_3));
}
END_TEST

START_TEST(strtok_12) {
  char str_1[] = "tuz-tuz-tuz";
  char str_2[] = "tuz-tuz-tuz";
  char str_3[] = "z-tuz-tuz";
  ck_assert_pstr_eq(strtok(str_1, str_3), custom_strtok(str_2, str_3));
}
END_TEST

START_TEST(strtok_13) {
  char str_1[] = "Hello, world! And other people";
  char str_2[] = "Hello, world! And other people";
  char str_3[] = "\0Come here";
  char str_4[] = "\0Come here";
  char str_5[] = "";

  ck_assert_pstr_eq(strtok(str_1, str_5), custom_strtok(str_2, str_5));
  for (int i = 0; i < 5; i++) {
    ck_assert_pstr_eq(strtok(NULL, str_5), custom_strtok(NULL, str_5));
  }
  ck_assert_pstr_eq(strtok(str_3, str_5), custom_strtok(str_4, str_5));
  ck_assert_pstr_eq(strtok(NULL, str_5), custom_strtok(NULL, str_5));
  ck_assert_pstr_eq(strtok(NULL, str_5), custom_strtok(NULL, str_5));
}
END_TEST

START_TEST(strtok_14) {
  char str_1[] = "Hello,       world! And other people";
  char str_2[] = "Hello,       world! And other people";
  char str_3[] = "Come here";
  char str_4[] = "Come here";
  char str_5[] = " o";

  ck_assert_pstr_eq(strtok(str_1, str_5), custom_strtok(str_2, str_5));
  for (int i = 0; i < 5; i++) {
    ck_assert_pstr_eq(strtok(NULL, str_5), custom_strtok(NULL, str_5));
  }
  ck_assert_pstr_eq(strtok(str_3, str_5), custom_strtok(str_4, str_5));
  ck_assert_pstr_eq(strtok(NULL, str_5), custom_strtok(NULL, str_5));
  ck_assert_pstr_eq(strtok(NULL, str_5), custom_strtok(NULL, str_5));
}
END_TEST

START_TEST(strtok_15) {
  char str_1[] = "Hello,      worllllllllllld! And lother people      ";
  char str_2[] = "Hello,      worllllllllllld! And lother people      ";
  char str_3[] = "Come here";
  char str_4[] = "Come here";
  char str_5[] = " l";

  ck_assert_pstr_eq(strtok(str_1, str_5), custom_strtok(str_2, str_5));
  for (int i = 0; i < 5; i++) {
    ck_assert_pstr_eq(strtok(NULL, str_5), custom_strtok(NULL, str_5));
  }
  ck_assert_pstr_eq(strtok(str_3, str_5), custom_strtok(str_4, str_5));
  ck_assert_pstr_eq(strtok(NULL, str_5), custom_strtok(NULL, str_5));
  ck_assert_pstr_eq(strtok(NULL, str_5), custom_strtok(NULL, str_5));
}
END_TEST

START_TEST(strtok_16) {
  char str_1[] = "Helllllllo,      worllllllllllld! And lother people      ";
  char str_2[] = "Helllllllo,      worllllllllllld! And lother people      ";
  char str_3[] = "Come here";
  char str_4[] = "Come here";
  char str_5[] = "l";
  char str_6[] = " ";

  ck_assert_str_eq(strtok(str_1, str_5), custom_strtok(str_2, str_5));
  for (int i = 0; i < 5; i++) {
    ck_assert_pstr_eq(strtok(NULL, str_6), custom_strtok(NULL, str_6));
  }
  ck_assert_pstr_eq(strtok(str_3, str_6), custom_strtok(str_4, str_6));
  ck_assert_pstr_eq(strtok(NULL, str_6), custom_strtok(NULL, str_6));
  ck_assert_pstr_eq(strtok(NULL, str_6), custom_strtok(NULL, str_6));
}
END_TEST

START_TEST(strtok_17) {
  char str_1[] = "ROROROROMA!!!!!!!!!";
  char str_2[] = "ROROROROMA!!!!!!!!!";
  char str_3[] = "R";
  strtok(str_1, str_3);
  strtok(NULL, str_3);
  custom_strtok(str_2, str_3);
  custom_strtok(NULL, str_3);
  ck_assert_pstr_eq(str_1, str_2);
}
END_TEST

START_TEST(strtok_18) {
  char str_1[] = "AGONIA";
  char str_2[] = "AGONIA";
  char str_3[] = "A";
  strtok(str_1, str_3);
  strtok(NULL, str_3);
  strtok(NULL, str_3);
  custom_strtok(str_2, str_3);
  custom_strtok(NULL, str_3);
  custom_strtok(NULL, str_3);
  ck_assert_pstr_eq(str_1, str_2);
}
END_TEST

START_TEST(strtok_19) {
  char str_1[] = "MYPHONENUM68697317172648";
  char str_2[] = "MYPHONENUM68697317172648";
  char str_3[] = "MYPHONENUM6869";
  char *str_4 = strtok(str_1, str_3);
  char *str_6 = strtok(NULL, str_3);

  char *str_5 = custom_strtok(str_2, str_3);
  char *str_7 = custom_strtok(NULL, str_3);

  ck_assert_pstr_eq(str_1, str_2);
  ck_assert_pstr_eq(str_4, str_5);
  ck_assert_pstr_eq(str_6, str_7);
}
END_TEST

START_TEST(strtok_20) {
  char str_1[] = "AAAAAAGOONIAAAAA";
  char str_2[] = "AAAAAAGOONIAAAAA";
  char str_3[] = "A";
  strtok(str_1, str_3);
  strtok(NULL, str_2);
  strtok(NULL, str_2);
  custom_strtok(str_2, str_3);
  custom_strtok(NULL, str_3);
  custom_strtok(NULL, str_3);
  ck_assert_pstr_eq(str_1, str_2);
}
END_TEST

Suite *test_strtok(void) {
  Suite *s = suite_create("\033[45m-=S21_STRTOK=-\033[0m");
  TCase *tc = tcase_create("strtok_tc");

  tcase_add_test(tc, strtok_1);
  tcase_add_test(tc, strtok_2);
  tcase_add_test(tc, strtok_3);
  tcase_add_test(tc, strtok_4);
  tcase_add_test(tc, strtok_5);
  tcase_add_test(tc, strtok_6);
  tcase_add_test(tc, strtok_7);
  tcase_add_test(tc, strtok_8);
  tcase_add_test(tc, strtok_9);
  tcase_add_test(tc, strtok_10);
  tcase_add_test(tc, strtok_11);
  tcase_add_test(tc, strtok_12);
  tcase_add_test(tc, strtok_13);
  tcase_add_test(tc, strtok_14);
  tcase_add_test(tc, strtok_15);
  tcase_add_test(tc, strtok_16);
  tcase_add_test(tc, strtok_17);
  tcase_add_test(tc, strtok_18);
  tcase_add_test(tc, strtok_19);
  tcase_add_test(tc, strtok_20);

  suite_add_tcase(s, tc);
  return s;
}
