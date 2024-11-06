#include "test.h"

void check_sub(custom_decimal decimal1, custom_decimal decimal2, custom_decimal check) {
  custom_decimal result;
  int code = custom_sub(decimal1, decimal2, &result);

  ck_assert_int_eq(custom_is_equal(result, check), 1);
  ck_assert_int_eq(code, OK);
}

void check_sub_fail(custom_decimal decimal1, custom_decimal decimal2, int check) {
  custom_decimal result;
  int code = custom_sub(decimal1, decimal2, &result);

  ck_assert_int_eq(code, check);
}

// overflow

START_TEST(sub_1) {
  // -6148914691236517205
  custom_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  // 79228162514264337593543950335
  custom_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // overflow
  int check = SMALL_NUMBER;

  check_sub_fail(decimal1, decimal2, check);
}

START_TEST(sub_2) {
  // 6148914689804861440
  custom_decimal decimal1 = {{0x0, 0x55555555, 0x0, 0x0}};
  // -79228162514264337593543950335
  custom_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // overflow
  int check = BIG_NUMBER;

  check_sub_fail(decimal1, decimal2, check);
}

START_TEST(sub_3) {
  // 3.6336660283201536
  custom_decimal decimal1 = {{0x811800, 0x811800, 0x0, 0x100000}};
  // -79228162514264337593543950335
  custom_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // overflow
  int check = BIG_NUMBER;

  check_sub_fail(decimal1, decimal2, check);
}

START_TEST(sub_4) {
  // 79228162514264337593543950335
  custom_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950335
  custom_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // overflow
  int check = BIG_NUMBER;

  check_sub_fail(decimal1, decimal2, check);
}

START_TEST(sub_5) {
  // 79228162514264337593543950335
  custom_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.5000000000000000000000000001
  custom_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // overflow
  int check = BIG_NUMBER;

  check_sub_fail(decimal1, decimal2, check);
}

START_TEST(sub_6) {
  // -79228162514264337593543950335
  custom_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 79228162514264337593543950334
  custom_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // overflow
  int check = SMALL_NUMBER;

  check_sub_fail(decimal1, decimal2, check);
}

START_TEST(sub_7) {
  // -79228162514264337593543950335
  custom_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.5
  custom_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // overflow
  int check = SMALL_NUMBER;

  check_sub_fail(decimal1, decimal2, check);
}

START_TEST(sub_8) {
  // -0.5
  custom_decimal decimal1 = {{0x5, 0x0, 0x0, 0x80010000}};
  // 79228162514264337593543950335
  custom_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // overflow
  int check = SMALL_NUMBER;

  check_sub_fail(decimal1, decimal2, check);
}

START_TEST(sub_9) {
  // -79228162514264337593543950335
  custom_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.0000000000000000000000000001
  custom_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // overflow
  int check = SMALL_NUMBER;

  check_sub_fail(decimal1, decimal2, check);
}

START_TEST(sub_10) {
  // -6148914689804861440
  custom_decimal decimal1 = {{0x0, 0x55555555, 0x0, 0x80000000}};
  // 79228162514264337593543950335
  custom_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // overflow
  int check = SMALL_NUMBER;

  check_sub_fail(decimal1, decimal2, check);
}

// функциональные

START_TEST(sub_11) {
  // 26409387.504754779197847983445
  custom_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x150000}};
  // 79228162514264337593543950334
  custom_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593517540946
  custom_decimal check = {{0xFE6D0652, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  check_sub(decimal1, decimal2, check);
}

START_TEST(sub_12) {
  // 26409387.504754779197847983445
  custom_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x150000}};
  // -79228162514264337593543950334
  custom_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // overflow
  int check = BIG_NUMBER;

  check_sub_fail(decimal1, decimal2, check);
}

START_TEST(sub_13) {
  // 26409387.504754779197847983445
  custom_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x150000}};
  // 7922816251426433759354395033
  custom_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x0}};
  // -7922816251426433759327985645.5
  custom_decimal check = {{0xF0423F47, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  check_sub(decimal1, decimal2, check);
}

START_TEST(sub_14) {
  // 26409387.504754779197847983445
  custom_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x150000}};
  // -7922816251426433759354395033
  custom_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 7922816251426433759380804420
  custom_decimal check = {{0x9B2C9344, 0x99999999, 0x19999999, 0x0}};

  check_sub(decimal1, decimal2, check);
}

START_TEST(sub_15) {
  // 26409387.504754779197847983445
  custom_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x150000}};
  // 7922816251426433759354395033.5
  custom_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -7922816251426433759327985646.0
  custom_decimal check = {{0xF0423F4C, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  check_sub(decimal1, decimal2, check);
}

START_TEST(sub_16) {
  // 26409387.504754779197847983445
  custom_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x150000}};
  // -7922816251426433759354395033.5
  custom_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // 7922816251426433759380804421
  custom_decimal check = {{0x9B2C9345, 0x99999999, 0x19999999, 0x0}};

  check_sub(decimal1, decimal2, check);
}

START_TEST(sub_17) {
  // 26409387.504754779197847983445
  custom_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x150000}};
  // 7922816251426433759354395034
  custom_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};
  // -7922816251426433759327985646.5
  custom_decimal check = {{0xF0423F51, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  check_sub(decimal1, decimal2, check);
}

START_TEST(sub_18) {
  // 26409387.504754779197847983445
  custom_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x150000}};
  // 7922816251426433759354395035
  custom_decimal decimal2 = {{0x9999999B, 0x99999999, 0x19999999, 0x0}};
  // -7922816251426433759327985647.5
  custom_decimal check = {{0xF0423F5B, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  check_sub(decimal1, decimal2, check);
}

START_TEST(sub_19) {
  // 6148914691236517205
  custom_decimal decimal1 = {{0x55555555, 0x55555555, 0x0, 0x0}};
  // -1
  custom_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  // 6148914691236517206
  custom_decimal check = {{0x55555556, 0x55555555, 0x0, 0x0}};

  check_sub(decimal1, decimal2, check);
}

START_TEST(sub_20) {
  // 0
  custom_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
  // 7922816251426433759354395033.5
  custom_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -7922816251426433759354395033.5
  custom_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  check_sub(decimal1, decimal2, check);
}

START_TEST(sub_21) {
  // 26409387.504754779197847983445
  custom_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x150000}};
  // -1
  custom_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  // 26409388.504754779197847983445
  custom_decimal check = {{0x33F55555, 0x8B1F031B, 0x5555558B, 0x150000}};

  check_sub(decimal1, decimal2, check);
}

START_TEST(sub_22) {
  // 0
  custom_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
  // -7922816251426433759354395034
  custom_decimal decimal2 = {{0x9999999A, 0x99999999, 0x19999999, 0x80000000}};
  // 7922816251426433759354395034
  custom_decimal check = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};

  check_sub(decimal1, decimal2, check);
}

START_TEST(sub_23) {
  // 26409387.504754779197847983445
  custom_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x150000}};
  // -0.5
  custom_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // 26409388.004754779197847983445
  custom_decimal check = {{0x44A55555, 0x703A2C38, 0x55555570, 0x150000}};

  check_sub(decimal1, decimal2, check);
}

START_TEST(sub_24) {
  // 0
  custom_decimal decimal1 = {{0x0, 0x0, 0x0, 0x0}};
  // -1
  custom_decimal decimal2 = {{0x1, 0x0, 0x0, 0x80000000}};
  // 1
  custom_decimal check = {{0x1, 0x0, 0x0, 0x0}};

  check_sub(decimal1, decimal2, check);
}

START_TEST(sub_25) {
  // -6148914689804861440
  custom_decimal decimal1 = {{0x0, 0x55555555, 0x0, 0x80000000}};
  // 0.4999999999999999999999999999
  custom_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // -6148914689804861440.5000000000
  custom_decimal check = {{0x2A05F200, 0x8EA6B401, 0xC6AEA154, 0x800A0000}};

  check_sub(decimal1, decimal2, check);
}

START_TEST(sub_26) {
  // -6148914689804861440
  custom_decimal decimal1 = {{0x0, 0x55555555, 0x0, 0x80000000}};
  // 6148914689804861440
  custom_decimal decimal2 = {{0x0, 0x55555555, 0x0, 0x0}};
  // -12297829379609722880
  custom_decimal check = {{0x0, 0xAAAAAAAA, 0x0, 0x80000000}};

  check_sub(decimal1, decimal2, check);
}

START_TEST(sub_27) {
  // -6148914689804861440
  custom_decimal decimal1 = {{0x0, 0x55555555, 0x0, 0x80000000}};
  // 0
  custom_decimal decimal2 = {{0x0, 0x0, 0x0, 0x0}};
  // -6148914689804861440
  custom_decimal check = {{0x0, 0x55555555, 0x0, 0x80000000}};

  check_sub(decimal1, decimal2, check);
}

START_TEST(sub_28) {
  // -6148914689804861440
  custom_decimal decimal1 = {{0x0, 0x55555555, 0x0, 0x80000000}};
  // -24246937143470783.81744120110
  custom_decimal decimal2 = {{0x11B612E, 0xA2A675B4, 0x7D5A8DD, 0x800B0000}};
  // -6124667752661390656.1825587989
  custom_decimal check = {{0x997D4315, 0x97FC7507, 0xC5E61071, 0x800A0000}};

  check_sub(decimal1, decimal2, check);
}

START_TEST(sub_29) {
  // 1431655765
  custom_decimal decimal1 = {{0x55555555, 0x0, 0x0, 0x0}};
  // 7922816251426433759354395033.5
  custom_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -7922816251426433757922739268.5
  custom_decimal check = {{0xAAAAAAAD, 0xFFFFFFFC, 0xFFFFFFFF, 0x80010000}};

  check_sub(decimal1, decimal2, check);
}

START_TEST(sub_30) {
  // 0.0000000000000000000000000001
  custom_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // -8
  custom_decimal decimal2 = {{0x8, 0x0, 0x0, 0x80000000}};
  // 8.000000000000000000000000000
  custom_decimal check = {{0x40000000, 0xFE8401E7, 0x19D971E4, 0x1B0000}};

  check_sub(decimal1, decimal2, check);
}

Suite *test_sub(void) {
  Suite *s = suite_create("\033[45m-=CUS_SUB=-\033[0m");
  TCase *tc = tcase_create("sub_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, sub_1);
  tcase_add_test(tc, sub_2);
  tcase_add_test(tc, sub_3);
  tcase_add_test(tc, sub_4);
  tcase_add_test(tc, sub_5);
  tcase_add_test(tc, sub_6);
  tcase_add_test(tc, sub_7);
  tcase_add_test(tc, sub_8);
  tcase_add_test(tc, sub_9);
  tcase_add_test(tc, sub_10);
  tcase_add_test(tc, sub_11);
  tcase_add_test(tc, sub_12);
  tcase_add_test(tc, sub_13);
  tcase_add_test(tc, sub_14);
  tcase_add_test(tc, sub_15);
  tcase_add_test(tc, sub_16);
  tcase_add_test(tc, sub_17);
  tcase_add_test(tc, sub_18);
  tcase_add_test(tc, sub_19);
  tcase_add_test(tc, sub_20);
  tcase_add_test(tc, sub_21);
  tcase_add_test(tc, sub_22);
  tcase_add_test(tc, sub_23);
  tcase_add_test(tc, sub_24);
  tcase_add_test(tc, sub_25);
  tcase_add_test(tc, sub_26);
  tcase_add_test(tc, sub_27);
  tcase_add_test(tc, sub_28);
  tcase_add_test(tc, sub_29);
  tcase_add_test(tc, sub_30);

  suite_add_tcase(s, tc);
  return s;
}