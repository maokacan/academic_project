#include "test.h"

void check_add(custom_decimal decimal1, custom_decimal decimal2, custom_decimal check) {
  custom_decimal result;
  int code = custom_add(decimal1, decimal2, &result);

  ck_assert_int_eq(custom_is_equal(result, check), 1);
  ck_assert_int_eq(code, OK);
}

void check_add_fail(custom_decimal decimal1, custom_decimal decimal2, int check) {
  custom_decimal result;
  int code = custom_add(decimal1, decimal2, &result);

  ck_assert_int_eq(code, check);
}

// overflow

START_TEST(add_1) {
  // 79228162514264337593543950335
  custom_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  custom_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // overflow
  int check = BIG_NUMBER;

  check_add_fail(decimal1, decimal2, check);
}

START_TEST(add_2) {
  // 79228162514264337593543950335
  custom_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950334
  custom_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // overflow
  int check = BIG_NUMBER;

  check_add_fail(decimal1, decimal2, check);
}

START_TEST(add_3) {
  // 79228162514264337593543950335
  custom_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.5
  custom_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // overflow
  int check = BIG_NUMBER;
  check_add_fail(decimal1, decimal2, check);
}

START_TEST(add_4) {
  // -79228162514264337593543950335
  custom_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950335
  custom_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // overflow
  int check = SMALL_NUMBER;

  check_add_fail(decimal1, decimal2, check);
}

START_TEST(add_5) {
  // -79228162514264337593543950335
  custom_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -7922816251426433759354395033
  custom_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // overflow
  int check = SMALL_NUMBER;

  check_add_fail(decimal1, decimal2, check);
}

START_TEST(add_6) {
  // -79228162514264337593543950335
  custom_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.5
  custom_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // overflow
  int check = SMALL_NUMBER;

  check_add_fail(decimal1, decimal2, check);
}

START_TEST(add_7) {
  // -79228162514264337593543950335
  custom_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0
  custom_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  // -79228162514264337593543950335
  custom_decimal check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  check_add(decimal1, decimal2, check);
}

START_TEST(add_8) {
  // -79228162514264337593543950335
  custom_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0.5000000000000000000000000001
  custom_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // overflow
  int check = SMALL_NUMBER;

  check_add_fail(decimal1, decimal2, check);
}

START_TEST(add_9) {
  // 1
  custom_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};
  // 79228162514264337593543950335
  custom_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // overflow
  int check = BIG_NUMBER;

  check_add_fail(decimal1, decimal2, check);
}

START_TEST(add_10) {
  // 0.5
  custom_decimal decimal1 = {{0x5, 0x0, 0x0, 0x10000}};
  // 79228162514264337593543950335
  custom_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // overflow
  int check = BIG_NUMBER;

  check_add_fail(decimal1, decimal2, check);
}

// функциональные

START_TEST(add_11) {
  // 56124981125209321576924.010631 + 0.4999999999999999999999999999 =
  // 56124981125209321576924.510631
  custom_decimal num_1 = {{0xF555887, 0x553F1641, 0xB5597F0B, 0x60000}};
  custom_decimal num_2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x1C0000}};
  custom_decimal origin = {{0xF5CF9A7, 0x553F1641, 0xB5597F0B, 0x60000}};
  check_add(num_1, num_2, origin);
}

START_TEST(add_12) {
  // 79228162514264337593543950335
  custom_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950335
  custom_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0
  custom_decimal check = {{0x0, 0x0, 0x0, 0x0}};

  check_add(decimal1, decimal2, check);
}

START_TEST(add_13) {
  // 79228162514264337593543950335
  custom_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -79228162514264337593543950334
  custom_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1
  custom_decimal check = {{0x1, 0x0, 0x0, 0x0}};

  check_add(decimal1, decimal2, check);
}

START_TEST(add_14) {
  // 79228162514264337593543950335
  custom_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -7922816251426433759354395033
  custom_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // 71305346262837903834189555302
  custom_decimal check = {{0x66666666, 0x66666666, 0xE6666666, 0x0}};

  check_add(decimal1, decimal2, check);
}

START_TEST(add_15) {
  // 79228162514264337593543950335
  custom_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.5
  custom_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // 79228162514264337593543950334
  custom_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  check_add(decimal1, decimal2, check);
}

// -1.0000000000000000000000000001
START_TEST(add_16) {
  custom_decimal decimal1 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // 7.9228162514264337593543950335
  custom_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // 6.9228162514264337593543950334
  custom_decimal check = {{0xEFFFFFFE, 0xC1DAFD9E, 0xDFB031A1, 0x1C0000}};

  check_add(decimal1, decimal2, check);
}

START_TEST(add_17) {
  // 79228162514264337593543950335
  custom_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.4999999999999999999999999999
  custom_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // 79228162514264337593543950334
  custom_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  check_add(decimal1, decimal2, check);
}

START_TEST(add_18) {
  // 0.5
  custom_decimal decimal1 = {{0x5, 0x0, 0x0, 0x10000}};
  // -7922816251426433759354395033
  custom_decimal decimal2 = {{0x99999999, 0x99999999, 0x19999999, 0x80000000}};
  // -7922816251426433759354395032.5
  custom_decimal check = {{0xFFFFFFF5, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  check_add(decimal1, decimal2, check);
}

START_TEST(add_19) {
  // 0.5
  custom_decimal decimal1 = {{0x5, 0x0, 0x0, 0x10000}};
  // 0.4999999999999999999999999999
  custom_decimal decimal2 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // 0.9999999999999999999999999999
  custom_decimal check = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};

  check_add(decimal1, decimal2, check);
}

START_TEST(add_20) {
  // 0.5
  custom_decimal decimal1 = {{0x5, 0x0, 0x0, 0x10000}};
  // -0.5000000000000000000000000001
  custom_decimal decimal2 = {{0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // -0.0000000000000000000000000001
  custom_decimal check = {{0x1, 0x0, 0x0, 0x801C0000}};

  check_add(decimal1, decimal2, check);
}

START_TEST(add_21) {
  // 0.5
  custom_decimal decimal1 = {{0x5, 0x0, 0x0, 0x10000}};
  // -1.9999999999999999999999999000
  custom_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // -1.4999999999999999999999999000
  custom_decimal check = {{0x97FFFC18, 0x5D378391, 0x3077B58D, 0x801C0000}};

  check_add(decimal1, decimal2, check);
}

START_TEST(add_22) {
  // 0.5
  custom_decimal decimal1 = {{0x5, 0x0, 0x0, 0x10000}};
  // 26409387.704754779197847983445
  custom_decimal decimal2 = {{0x1B755555, 0x2CE411B0, 0x55555560, 0x150000}};
  // 26409388.204754779197847983445
  custom_decimal check = {{0xAC55555, 0x47C8E893, 0x5555557B, 0x150000}};

  check_add(decimal1, decimal2, check);
}

START_TEST(add_23) {
  // 0.5
  custom_decimal decimal1 = {{0x5, 0x0, 0x0, 0x10000}};
  // 8
  custom_decimal decimal2 = {{0x8, 0x0, 0x0, 0x0}};
  // 8.5
  custom_decimal check = {{0x55, 0x0, 0x0, 0x10000}};

  check_add(decimal1, decimal2, check);
}

START_TEST(add_24) {
  // -0.5
  custom_decimal decimal1 = {{0x5, 0x0, 0x0, 0x80010000}};
  // -79228162514264337593543950334
  custom_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950334
  custom_decimal check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  check_add(decimal1, decimal2, check);
}

START_TEST(add_25) {
  // -0.5
  custom_decimal decimal1 = {{0x5, 0x0, 0x0, 0x80010000}};
  // 0.5
  custom_decimal decimal2 = {{0x5, 0x0, 0x0, 0x10000}};
  // -0.0
  custom_decimal check = {{0x0, 0x0, 0x0, 0x80010000}};

  check_add(decimal1, decimal2, check);
}

START_TEST(add_26) {
  // -0.5
  custom_decimal decimal1 = {{0x5, 0x0, 0x0, 0x80010000}};
  // -1431655765
  custom_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80000000}};
  // -1431655765.5
  custom_decimal check = {{0x55555557, 0x3, 0x0, 0x80010000}};

  check_add(decimal1, decimal2, check);
}

START_TEST(add_27) {
  // -0.5
  custom_decimal decimal1 = {{0x5, 0x0, 0x0, 0x80010000}};
  // -0.0000000000000000000000000000
  custom_decimal decimal2 = {{0x0, 0x0, 0x0, 0x801C0000}};
  // -0.5000000000000000000000000000
  custom_decimal check = {{0x88000000, 0x1F128130, 0x1027E72F, 0x801C0000}};

  check_add(decimal1, decimal2, check);
}

START_TEST(add_28) {
  // 0.4999999999999999999999999999
  custom_decimal decimal1 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x1C0000}};
  // -26409387.498605864508043122005
  custom_decimal decimal2 = {{0x55555555, 0x0, 0x55555555, 0x80150000}};
  // -26409386.998605864508043122005
  custom_decimal check = {{0x66055555, 0xE51B291D, 0x55555539, 0x80150000}};

  check_add(decimal1, decimal2, check);
}

START_TEST(add_29) {
  // -0.4999999999999999999999999999
  custom_decimal decimal1 = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};
  // -49704001422.391670881925172831
  custom_decimal decimal2 = {{0x7F7B8E5F, 0x2B4271A6, 0xA09A2FB4, 0x80120000}};
  // -49704001422.891670881925172831
  custom_decimal check = {{0x532D8E5F, 0x3232CD00, 0xA09A2FB4, 0x80120000}};

  check_add(decimal1, decimal2, check);
}

START_TEST(add_30) {
  // -56124981125209321576924.010631
  custom_decimal decimal1 = {{0xF555887, 0x553F1641, 0xB5597F0B, 0x80060000}};
  // -7.9228162514264337593543950335
  custom_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // -56124981125209321576931.933447
  custom_decimal check = {{0xFCE3D07, 0x553F1641, 0xB5597F0B, 0x80060000}};

  check_add(decimal1, decimal2, check);
}

Suite *test_add(void) {
  Suite *s = suite_create("\033[45m-=CUS_ADD=-\033[0m");
  TCase *tc = tcase_create("add_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, add_1);
  tcase_add_test(tc, add_2);
  tcase_add_test(tc, add_3);
  tcase_add_test(tc, add_4);
  tcase_add_test(tc, add_5);
  tcase_add_test(tc, add_6);
  tcase_add_test(tc, add_7);
  tcase_add_test(tc, add_8);
  tcase_add_test(tc, add_9);
  tcase_add_test(tc, add_10);
  tcase_add_test(tc, add_11);
  tcase_add_test(tc, add_12);
  tcase_add_test(tc, add_13);
  tcase_add_test(tc, add_14);
  tcase_add_test(tc, add_15);
  tcase_add_test(tc, add_16);
  tcase_add_test(tc, add_17);
  tcase_add_test(tc, add_18);
  tcase_add_test(tc, add_19);
  tcase_add_test(tc, add_20);
  tcase_add_test(tc, add_21);
  tcase_add_test(tc, add_22);
  tcase_add_test(tc, add_23);
  tcase_add_test(tc, add_24);
  tcase_add_test(tc, add_25);
  tcase_add_test(tc, add_26);
  tcase_add_test(tc, add_27);
  tcase_add_test(tc, add_28);
  tcase_add_test(tc, add_29);
  tcase_add_test(tc, add_30);

  suite_add_tcase(s, tc);
  return s;
}
