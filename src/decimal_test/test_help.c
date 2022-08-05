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

// START_TEST(div_2048) {
//     s21_decimal a;
//     s21_decimal b;
//     s21_decimal res;
//     float rrr;
//     for (float i = 312439.000000F; i < 9999999.999999F; i += 156212.5F) {
//         for (float j = 2048.0F; j >= 1.0F; j -= 9.123F) {
//             s21_from_float_to_decimal(i, &a);
//             s21_from_float_to_decimal(j, &b);
//             s21_div(a, b, &res);
//             s21_from_decimal_to_float(res, &rrr);
//             printf("my fun %f / %f = %.28f\n", i, j, rrr);
//             printf("RESULT %f / %f = %.28f\n\n", i, j, i / j);
//             ck_assert_float_eq(rrr, (float)i / (float)j);
//         }
//     }
// }
// END_TEST

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
    // tcase_add_test(test_help, div_2048);
    // tcase_add_test(test_help, div_b_2048);
    // tcase_add_test(test_help, mod_2048);
    suite_add_tcase(s, test_help);
    return s;
}
