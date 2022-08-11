#include "../s21_test_decimal.h"

START_TEST(help1) {
    s21_decimal a;
    s21_decimal b;
    float f;
    s21_decimal_null(&a);
    s21_decimal_null(&b);
    a.bits[0] = 0b0101001010001010100101001;
    a.bits[1] = 0b111110101001010001010100101001;
    b.bits[0] = 0b01010010100001;
    b.bits[1] = 0b11111010001010100101001;
    s21_set_exp(&a, 4);
    s21_set_exp(&b, 21);
    s21_print_binary_decimal(a, 128);
    s21_print_binary_decimal(b, 128);
    s21_get_exp_dec(&a);
    printf("============================");
    s21_pow_ballance(&a, &b);
    s21_print_binary_decimal(a, 128);
    s21_print_binary_decimal(b, 128);
}
END_TEST

Suite* s21_test_help(void) {
    Suite *s = suite_create("!!!HELP TESTS!!!");
    TCase *test_help;

    test_help = tcase_create("DEBUG AND HELP:\n");
    // tcase_add_test(test_help, help1);
    suite_add_tcase(s, test_help);
    return s;
}
