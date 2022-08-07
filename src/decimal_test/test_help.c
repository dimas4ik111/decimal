#include "../s21_test_decimal.h"

// START_TEST(div_b_2048) {
//     s21_decimal a;
//     s21_decimal b;
//     s21_decimal res;
//     int rrr;
//     for (int i = 1; i < 2048; i++) {
//         for (int j = 2048; j >= 0; j--) {
//             s21_from_int_to_decimal(j, &a);
//             s21_from_int_to_decimal(i, &b);
//             s21_binary_div(a, b, &res);
//             s21_from_decimal_to_int(res, &rrr);
//             ck_assert_int_eq(rrr, j / i);
//         }
//     }
// }
// END_TEST

START_TEST(float_dec_2048) {
    s21_decimal res;
    float f;
    char buf1[256] = {'\0'};
    char buf2[256] = {'\0'};
    for (float i = 114; i < 31111111.402823F; i += 1131231.1) {
        int result = s21_from_float_to_decimal(i, &res);
        if (result == 0) {
            s21_from_decimal_to_float(res, &f);
            sprintf(buf1, "%f", i);
            sprintf(buf2, "%f", f);
            // printf(" i = %f  ||  %s\n", i, buf1);
            // printf(" f = %f  ||  %s\n", f, buf2);
            // printf(" b = %u     %u %u\n\n", res.bits[0], res.bits[1], res.bits[2]);
            ck_assert_str_eq(buf1, buf2);
            ck_assert_float_eq(i, f);
        }
    }
}
END_TEST

START_TEST(bank_r) {
    s21_decimal a;
    s21_decimal_null(&a);
    for (int i = 0; i < 93; i++) {
        s21_set_bit(&a, i, i % 3);
    }
    s21_set_exp(&a, 15);
    s21_print_binary_decimal(a, 128);
    s21_bank_round(&a);
    s21_print_binary_decimal(a, 128);
}

// START_TEST(mod_2048) {
//     s21_decimal a;
//     s21_decimal b;
//     s21_decimal res;
//     int rrr;
//     for (int i = 1; i < 2048; i++) {
//         for (int j = 2048; j >= 0; j--) {
//             s21_from_int_to_decimal(j, &a);
//             s21_from_int_to_decimal(i, &b);
//             s21_mod(a, b, &res);
//             s21_from_decimal_to_int(res, &rrr);
//             ck_assert_int_eq(rrr, j % i);
//         }
//     }
// }
// END_TEST

Suite* s21_test_help(void) {
    Suite *s = suite_create("!!!HELP TESTS!!!");
    TCase *test_help;

    test_help = tcase_create("DEBUG AND HELP:\n");
    // tcase_add_test(test_help, float_dec_2048);
    // tcase_add_test(test_help, div_b_2048);
    // tcase_add_test(test_help, mod_2048);
    // tcase_add_test(test_help, bank_r);
    suite_add_tcase(s, test_help);
    return s;
}
