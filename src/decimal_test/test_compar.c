#include "../s21_test_decimal.h"

START_TEST(compare_less) {
    s21_decimal dst1, dst2;

    s21_from_int_to_decimal(12, &dst1);
    s21_from_int_to_decimal(22, &dst2);
    ck_assert_int_eq(s21_is_less(dst1, dst2), TRUE);
    ck_assert_int_eq(s21_is_less(dst2, dst1), FALSE);

    s21_from_int_to_decimal(22, &dst1);
    s21_from_int_to_decimal(12, &dst2);
    ck_assert_int_eq(s21_is_less(dst1, dst2), FALSE);
    ck_assert_int_eq(s21_is_less(dst2, dst1), TRUE);

    s21_from_int_to_decimal(22, &dst1);
    s21_from_int_to_decimal(22, &dst2);
    ck_assert_int_eq(s21_is_less(dst1, dst2), FALSE);
    ck_assert_int_eq(s21_is_less(dst2, dst1), FALSE);

    s21_from_int_to_decimal(-1, &dst1);
    s21_from_int_to_decimal(-5, &dst2);
    ck_assert_int_eq(s21_is_less(dst1, dst2), FALSE);
    ck_assert_int_eq(s21_is_less(dst2, dst1), TRUE);

    s21_from_int_to_decimal(-5, &dst1);
    s21_from_int_to_decimal(33, &dst2);
    ck_assert_int_eq(s21_is_less(dst1, dst2), TRUE);
    ck_assert_int_eq(s21_is_less(dst2, dst1), FALSE);

    s21_from_int_to_decimal(0, &dst1);
    s21_from_int_to_decimal(0, &dst2);
    ck_assert_int_eq(s21_is_less(dst1, dst2), FALSE);
    ck_assert_int_eq(s21_is_less(dst2, dst1), FALSE);

    s21_from_int_to_decimal(0, &dst1);
    s21_from_int_to_decimal(1, &dst2);
    ck_assert_int_eq(s21_is_less(dst1, dst2), TRUE);

    s21_decimal_null(&dst1);
    s21_decimal_null(&dst2);
    dst1.bits[0] = 123456789;
    dst1.bits[1] = 9999999;
    dst2.bits[0] = 123456788;
    dst2.bits[1] = 9999999;
    ck_assert_int_eq(s21_is_less(dst1, dst2), FALSE);
}
END_TEST

START_TEST(compare_greater) {
    s21_decimal dst1, dst2;

    s21_from_int_to_decimal(12, &dst1);
    s21_from_int_to_decimal(22, &dst2);
    ck_assert_int_eq(s21_is_greater(dst1, dst2), FALSE);
    ck_assert_int_eq(s21_is_greater(dst2, dst1), TRUE);

    s21_from_int_to_decimal(22, &dst1);
    s21_from_int_to_decimal(12, &dst2);
    ck_assert_int_eq(s21_is_greater(dst1, dst2), TRUE);
    ck_assert_int_eq(s21_is_greater(dst2, dst1), FALSE);

    s21_from_int_to_decimal(22, &dst1);
    s21_from_int_to_decimal(22, &dst2);
    ck_assert_int_eq(s21_is_greater(dst1, dst2), FALSE);
    ck_assert_int_eq(s21_is_greater(dst2, dst1), FALSE);

    s21_from_int_to_decimal(-1, &dst1);
    s21_from_int_to_decimal(-5, &dst2);
    ck_assert_int_eq(s21_is_greater(dst1, dst2), TRUE);
    ck_assert_int_eq(s21_is_greater(dst1, dst2), TRUE);

    s21_from_int_to_decimal(-5, &dst1);
    s21_from_int_to_decimal(33, &dst2);
    ck_assert_int_eq(s21_is_greater(dst1, dst2), FALSE);
    ck_assert_int_eq(s21_is_greater(dst2, dst1), TRUE);
}
END_TEST

START_TEST(compare_less_or_equal) {
    s21_decimal dst1, dst2;

    s21_from_int_to_decimal(12, &dst1);
    s21_from_int_to_decimal(22, &dst2);
    ck_assert_int_eq(s21_is_less_or_equal(dst1, dst2), TRUE);
    ck_assert_int_eq(s21_is_less_or_equal(dst2, dst1), FALSE);

    s21_from_int_to_decimal(22, &dst1);
    s21_from_int_to_decimal(12, &dst2);
    ck_assert_int_eq(s21_is_less_or_equal(dst1, dst2), FALSE);
    ck_assert_int_eq(s21_is_less_or_equal(dst2, dst1), TRUE);

    s21_from_int_to_decimal(22, &dst1);
    s21_from_int_to_decimal(22, &dst2);
    ck_assert_int_eq(s21_is_less_or_equal(dst1, dst2), TRUE);
    ck_assert_int_eq(s21_is_less_or_equal(dst2, dst1), TRUE);

    s21_from_int_to_decimal(-1, &dst1);
    s21_from_int_to_decimal(-5, &dst2);
    ck_assert_int_eq(s21_is_less_or_equal(dst1, dst2), FALSE);
    ck_assert_int_eq(s21_is_less_or_equal(dst2, dst1), TRUE);

    s21_from_int_to_decimal(-5, &dst1);
    s21_from_int_to_decimal(33, &dst2);
    ck_assert_int_eq(s21_is_less_or_equal(dst1, dst2), TRUE);
    ck_assert_int_eq(s21_is_less_or_equal(dst2, dst1), FALSE);
}
END_TEST

START_TEST(compare_greater_or_equal) {
    s21_decimal dst1, dst2;

    s21_from_int_to_decimal(12, &dst1);
    s21_from_int_to_decimal(22, &dst2);
    ck_assert_int_eq(s21_is_greater_or_equal(dst1, dst2), FALSE);
    ck_assert_int_eq(s21_is_greater_or_equal(dst2, dst1), TRUE);

    s21_from_int_to_decimal(22, &dst1);
    s21_from_int_to_decimal(12, &dst2);
    ck_assert_int_eq(s21_is_greater_or_equal(dst1, dst2), TRUE);
    ck_assert_int_eq(s21_is_greater_or_equal(dst2, dst1), FALSE);

    s21_from_int_to_decimal(22, &dst1);
    s21_from_int_to_decimal(22, &dst2);
    ck_assert_int_eq(s21_is_greater_or_equal(dst1, dst2), TRUE);
    ck_assert_int_eq(s21_is_greater_or_equal(dst2, dst1), TRUE);

    s21_from_int_to_decimal(-1, &dst1);
    s21_from_int_to_decimal(-5, &dst2);
    ck_assert_int_eq(s21_is_greater_or_equal(dst1, dst2), TRUE);
    ck_assert_int_eq(s21_is_greater_or_equal(dst2, dst1), FALSE);

    s21_from_int_to_decimal(-5, &dst1);
    s21_from_int_to_decimal(33, &dst2);
    ck_assert_int_eq(s21_is_greater_or_equal(dst1, dst2), FALSE);
    ck_assert_int_eq(s21_is_greater_or_equal(dst2, dst1), TRUE);
}
END_TEST

START_TEST(compare_equal) {
    s21_decimal dst1, dst2;

    s21_from_int_to_decimal(12, &dst1);
    s21_from_int_to_decimal(22, &dst2);
    ck_assert_int_eq(s21_is_equal(dst1, dst2), FALSE);
    ck_assert_int_eq(s21_is_equal(dst2, dst1), FALSE);

    s21_from_int_to_decimal(22, &dst1);
    s21_from_int_to_decimal(12, &dst2);
    ck_assert_int_eq(s21_is_equal(dst1, dst2), FALSE);
    ck_assert_int_eq(s21_is_equal(dst2, dst1), FALSE);

    s21_from_int_to_decimal(22, &dst1);
    s21_from_int_to_decimal(22, &dst2);
    ck_assert_int_eq(s21_is_equal(dst1, dst2), TRUE);
    ck_assert_int_eq(s21_is_equal(dst2, dst1), TRUE);

    s21_from_int_to_decimal(-1, &dst1);
    s21_from_int_to_decimal(-5, &dst2);
    ck_assert_int_eq(s21_is_equal(dst1, dst2), FALSE);
    ck_assert_int_eq(s21_is_equal(dst2, dst1), FALSE);

    s21_from_int_to_decimal(-5, &dst1);
    s21_from_int_to_decimal(33, &dst2);
    ck_assert_int_eq(s21_is_equal(dst1, dst2), FALSE);
    ck_assert_int_eq(s21_is_equal(dst2, dst1), FALSE);
}
END_TEST  // 56.789 - 0.340

START_TEST(lol_kek_123) {
    s21_decimal dst1, dst2;
    s21_decimal_null(&dst1);
    s21_decimal_null(&dst2);
    dst1.bits[0] = 56789;
    s21_set_exp(&dst1, 3);
    dst2.bits[0] = 340;
    s21_set_exp(&dst2, 3);
    ck_assert_int_eq(s21_is_greater_or_equal(dst1, dst2), 1);
}
END_TEST

START_TEST(compare_not_equal) {
    s21_decimal dst1, dst2;

    s21_from_int_to_decimal(12, &dst1);
    s21_from_int_to_decimal(22, &dst2);
    ck_assert_int_eq(s21_is_not_equal(dst1, dst2), TRUE);
    ck_assert_int_eq(s21_is_not_equal(dst2, dst1), TRUE);

    s21_from_int_to_decimal(22, &dst1);
    s21_from_int_to_decimal(12, &dst2);
    ck_assert_int_eq(s21_is_not_equal(dst1, dst2), TRUE);
    ck_assert_int_eq(s21_is_not_equal(dst2, dst1), TRUE);

    s21_from_int_to_decimal(22, &dst1);
    s21_from_int_to_decimal(22, &dst2);
    ck_assert_int_eq(s21_is_not_equal(dst1, dst2), FALSE);
    ck_assert_int_eq(s21_is_not_equal(dst2, dst1), FALSE);

    s21_from_int_to_decimal(-1, &dst1);
    s21_from_int_to_decimal(-5, &dst2);
    ck_assert_int_eq(s21_is_not_equal(dst1, dst2), TRUE);
    ck_assert_int_eq(s21_is_not_equal(dst2, dst1), TRUE);

    s21_from_int_to_decimal(-5, &dst1);
    s21_from_int_to_decimal(33, &dst2);
    ck_assert_int_eq(s21_is_not_equal(dst1, dst2), TRUE);
    ck_assert_int_eq(s21_is_not_equal(dst2, dst1), TRUE);
}
END_TEST

Suite *s21_test_compare(void) {
    Suite *s = suite_create("!!!!!COMPARE!!!!!");
    TCase *compare_a_test;

    compare_a_test = tcase_create("COMPARE: ");
    tcase_add_test(compare_a_test, compare_less);
    tcase_add_test(compare_a_test, compare_greater);
    tcase_add_test(compare_a_test, compare_less_or_equal);
    tcase_add_test(compare_a_test, compare_greater_or_equal);
    tcase_add_test(compare_a_test, compare_equal);
    tcase_add_test(compare_a_test, compare_not_equal);
    tcase_add_test(compare_a_test, lol_kek_123);
    suite_add_tcase(s, compare_a_test);
    return s;
}
