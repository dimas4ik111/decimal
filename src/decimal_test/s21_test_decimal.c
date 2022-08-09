#include "../s21_test_decimal.h"
#include "../s21_decimal.h"

int main() {
    setlocale(LC_ALL, "en_US.UTF-8");
    int no_failed = 0;

    Suite *s1 = s21_test_decimal_convert("CONVERT");
    Suite *s2 = s21_test_compare("COMPARE");
    Suite *s3 = s21_test_help("HELP");
    Suite *s4 = s21_test_another("ANOTHER");
    Suite *s5 = s21_test_arithm("ARITHM");

    SRunner *test_convert;
    SRunner *test_compare;
    SRunner *test_help;
    SRunner *test_another;
    SRunner *test_arithm;

    test_convert = srunner_create(s1);
    test_compare = srunner_create(s2);
    
    test_help = srunner_create(s3);
    test_another = srunner_create(s4);
    test_arithm = srunner_create(s5);

    srunner_set_fork_status(test_convert, CK_NOFORK);
    srunner_set_fork_status(test_compare, CK_NOFORK);
    srunner_set_fork_status(test_help, CK_NOFORK);
    srunner_set_fork_status(test_another, CK_NOFORK);
    srunner_set_fork_status(test_arithm, CK_NOFORK);

    // srunner_run_all(test_convert, CK_NORMAL);
    // srunner_run_all(test_compare, CK_NORMAL);
    // srunner_run_all(test_another, CK_NORMAL);
    // srunner_run_all(test_arithm, CK_NORMAL);
    srunner_run_all(test_help, CK_NORMAL);

    no_failed += srunner_ntests_failed(test_convert);
    no_failed += srunner_ntests_failed(test_compare);
    no_failed += srunner_ntests_failed(test_help);
    no_failed += srunner_ntests_failed(test_another);
    no_failed += srunner_ntests_failed(test_arithm);

    srunner_free(test_convert);
    srunner_free(test_compare);
    srunner_free(test_help);
    srunner_free(test_another);
    srunner_free(test_arithm);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

char* s21_str_bits_test(char* str_bit, s21_decimal res) {
    char* beginner = str_bit;
    for (int i = 95; i >= 0; i--) {
        *str_bit = 48 + s21_get_bit(&res, i);
        str_bit++;
    }
    *str_bit = '\0';
    str_bit = beginner;
    return str_bit;
}
