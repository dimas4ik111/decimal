#include "../s21_test_decimal.h"

START_TEST(help1) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal_null(&a);
    s21_decimal_null(&b);
    a.bits[0] = 10818857;
    a.bits[1] = 1051006249;
    b.bits[0] = 5281;
    b.bits[1] = 8197417;
    s21_set_exp(&a, 4);
    s21_set_exp(&b, 21);
    s21_get_exp_dec(&a);
    s21_pow_ballance(&a, &b);
}
END_TEST

START_TEST(bank_round1) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal_null(&a);
    s21_decimal_null(&b);
    a.bits[0] = 10818857;
    a.bits[1] = 1051006249;
    b.bits[0] = 5281;
    b.bits[1] = 8197417;
    s21_set_exp(&a, 4);
    s21_set_exp(&b, 21);
    s21_get_exp_dec(&a);
    s21_pow_ballance(&a, &b);
}
END_TEST

Suite* s21_test_help(void) {
    Suite *s = suite_create("!!!HELP TESTS!!!");
    TCase *test_help;

    test_help = tcase_create("DEBUG AND HELP:\n");
    tcase_add_test(test_help, help1);
    tcase_add_test(test_help, bank_round1);
    suite_add_tcase(s, test_help);
    return s;
}
