#include "../s21_test_decimal.h"

START_TEST(s21_negate_1) {
    int a = 10;
    s21_decimal res_a = {0};
    s21_decimal src = {0};
    int result = 0;
    s21_from_int_to_decimal(a, &src);
    s21_negate(src, &res_a);
    s21_from_decimal_to_int(res_a, &result);
    ck_assert_int_eq(-10, result);
}
END_TEST

START_TEST(s21_negate_2) {
    s21_decimal res_a = {0};
    s21_decimal src = {0};
    float result = 0;
    s21_from_float_to_decimal(10.12345, &src);
    s21_negate(src, &res_a);
    s21_from_decimal_to_float(res_a, &result);
    // ck_assert_int_eq(-10.12345, result);
}
END_TEST

START_TEST(s21_negate_3) {
    float a = 10.1234e5;
    s21_decimal res_a = {0};
    s21_decimal src = {0};
    float result = 0;
    s21_from_float_to_decimal(a, &src);
    s21_negate(src, &res_a);
    s21_from_decimal_to_float(res_a, &result);
    // ck_assert_float_eq(-10.1234e5, result);
}
END_TEST

START_TEST(trunc1) {
    s21_decimal a;
    s21_decimal res;
    s21_decimal_null(&a);
    a.bits[0] = 12345678;
    s21_set_exp(&a, 4);
    float f;
    s21_from_decimal_to_float(a, &f);
    ck_assert_int_eq(0, a.bits[1]);
    ck_assert_int_eq(0, a.bits[2]);
    ck_assert_int_eq(0, s21_get_sing(&a));
    ck_assert_float_eq(f, 1234.5678);
    s21_truncate(a, &res);
    int res_int;
    s21_from_decimal_to_int(res, &res_int);
    ck_assert_int_eq(res_int, 1234);
}
END_TEST

START_TEST(trunc2) {
    s21_decimal a;
    s21_decimal res;
    s21_decimal_null(&a);
    a.bits[0] = 28473621;
    s21_set_exp(&a, 5);
    s21_sing_dec(&a);
    float f;
    s21_from_decimal_to_float(a, &f);
    ck_assert_int_eq(0, a.bits[1]);
    ck_assert_int_eq(0, a.bits[2]);
    ck_assert_int_eq(1, s21_get_sing(&a));
    ck_assert_float_eq(f, -284.73621);
    s21_truncate(a, &res);
    int res_int;
    s21_from_decimal_to_int(res, &res_int);
    ck_assert_int_eq(res_int, -284);
}
END_TEST

START_TEST(trunc3) {
    s21_decimal a;
    s21_decimal res;
    s21_decimal_null(&a);
    a.bits[0] = 0;
    s21_set_exp(&a, 4);
    float f;
    s21_from_decimal_to_float(a, &f);
    ck_assert_int_eq(0, a.bits[1]);
    ck_assert_int_eq(0, a.bits[2]);
    ck_assert_int_eq(0, s21_get_sing(&a));
    ck_assert_float_eq(f, 0.0f);
    s21_truncate(a, &res);
    int res_int;
    s21_from_decimal_to_int(res, &res_int);
    ck_assert_int_eq(res_int, 0);
}
END_TEST

START_TEST(round1) {
    s21_decimal a;
    s21_decimal res;
    s21_from_float_to_decimal(12345.6789F, &a);
    s21_round(a, &res);
    float f;
    s21_from_decimal_to_float(res, &f);
    ck_assert_float_eq(f, roundf(12345.6789F));
}
END_TEST

START_TEST(round2) {
    s21_decimal a;
    s21_decimal res;
    s21_from_float_to_decimal(12763547.8915937694581F, &a);
    s21_round(a, &res);
    float f;
    s21_from_decimal_to_float(res, &f);
    ck_assert_float_eq(f, roundf(12763547.8915937694581F));
}
END_TEST

START_TEST(round3) {
    s21_decimal a;
    s21_decimal res;
    float f;
    for (float i = 1.123F; i < 9.0F; i += 0.92234F) {
        s21_from_float_to_decimal(i, &a);
        s21_round(a, &res);
        s21_from_decimal_to_float(res, &f);
        // printf("lolololololo = %f\n", i);
        // printf("ITS MY ROUND = %f\n", f);
        // printf("ORIGIN ROUND = %f\n\n", roundf(i));
        ck_assert_float_eq(f, roundf(i));
    }
}
END_TEST

START_TEST(floor1) {
    s21_decimal a;
    s21_decimal res;
    float f;
    for (float i = 1.123F; i < 99.0F; i += 0.92234F) {
        s21_from_float_to_decimal(i, &a);
        s21_floor(a, &res);
        s21_from_decimal_to_float(res, &f);
        // printf("lolololololo = %f\n", i);
        // printf("ITS MY ROUND = %f\n", f);
        // printf("ORIGIN ROUND = %f\n\n", floorf(i));
        ck_assert_float_eq(f, floorf(i));
    }
}
END_TEST

Suite* s21_test_another(void) {
    Suite *s = suite_create("!!!!!ANOTHER!!!!!!");
    TCase *test_another;

    test_another = tcase_create("--TRUNCATE--");
    tcase_add_test(test_another, s21_negate_1);
    tcase_add_test(test_another, trunc1);
    tcase_add_test(test_another, trunc2);
    tcase_add_test(test_another, trunc3);
    tcase_add_test(test_another, s21_negate_2);
    tcase_add_test(test_another, s21_negate_3);
    suite_add_tcase(s, test_another);


    test_another = tcase_create("--ROUND--");
    tcase_add_test(test_another, round1);
    tcase_add_test(test_another, round2);
    tcase_add_test(test_another, round3);
    suite_add_tcase(s, test_another);

    test_another = tcase_create("--ROUND--");
    tcase_add_test(test_another, floor1);
    suite_add_tcase(s, test_another);

    return s;
}
