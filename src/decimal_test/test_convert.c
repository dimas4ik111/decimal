#include "../s21_test_decimal.h"

START_TEST(int_to_decimal_0) {
    s21_decimal var;
    s21_decimal_null(&var);
    int a = 123;
    ck_assert_int_eq(0, s21_from_int_to_decimal(a, &var));
    ck_assert_int_eq(123, var.bits[0]);
    ck_assert_int_eq(0, var.bits[1]);
    ck_assert_int_eq(0, var.bits[2]);
    ck_assert_int_eq(0, var.bits[3]);
    ck_assert_int_eq(0, s21_get_bit(&var, 127));
} END_TEST

START_TEST(int_to_decimal_1) {
    int a = 1237325487;
    ck_assert_int_eq(1, s21_from_int_to_decimal(a, NULL));
} END_TEST

START_TEST(int_to_decimal_2) {
    s21_decimal var = {{0, 1234253647, 3245678, 0}};
    int a = -2147483648;
    ck_assert_int_eq(0, s21_from_int_to_decimal(a, &var));
    ck_assert_int_eq(0, var.bits[1]);
    ck_assert_int_eq(0, var.bits[2]);
    ck_assert_int_eq(1, s21_get_bit(&var, 127));
} END_TEST

START_TEST(int_to_decimal_3) {
    s21_decimal var = {{1231, 343567, 12343, 0}};
    long int a = -2147481231236491;
    ck_assert_int_eq(0, s21_from_int_to_decimal(a, &var));
    ck_assert_int_eq(0, var.bits[1]);
    ck_assert_int_eq(0, var.bits[2]);
    ck_assert_int_eq(1, s21_get_bit(&var, 127));
} END_TEST

START_TEST(int_to_decimal_4) {
    s21_decimal var = {{1231, 343567, 12343, 0}};
    long int a = 2147481231236491;
    ck_assert_int_eq(0, s21_from_int_to_decimal(a, &var));
    ck_assert_int_eq(0, var.bits[1]);
    ck_assert_int_eq(0, var.bits[2]);
    ck_assert_int_eq(0, var.bits[3]);
    ck_assert_int_eq(0, s21_get_bit(&var, 127));
} END_TEST

START_TEST(int_to_decimal_5) {
    s21_decimal var = {{0, 1234253647, 3245678, 0}};
    unsigned long int a = 2147481231236491;
    ck_assert_int_eq(0, s21_from_int_to_decimal(a, &var));
    ck_assert_int_eq(0, var.bits[1]);
    ck_assert_int_eq(0, var.bits[2]);
    ck_assert_int_eq(0, var.bits[3]);
    ck_assert_int_eq(0, s21_get_bit(&var, 127));
} END_TEST

START_TEST(int_to_decimal_6) {
    s21_decimal var = {{0, 1234253647, 3245678, 0}};
    int a = 1;
    ck_assert_int_eq(0, s21_from_int_to_decimal(a, &var));
    ck_assert_int_eq(1, var.bits[0]);
    ck_assert_int_eq(0, var.bits[1]);
    ck_assert_int_eq(0, var.bits[2]);
    ck_assert_int_eq(0, var.bits[3]);
    ck_assert_int_eq(0, s21_get_bit(&var, 127));
} END_TEST

START_TEST(int_to_decimal_7) {
    s21_decimal var = {{0, 1234253647, 3245678, 0}};
    int a = -0;
    ck_assert_int_eq(0, s21_from_int_to_decimal(a, &var));
    ck_assert_int_eq(0, var.bits[0]);
    ck_assert_int_eq(0, var.bits[1]);
    ck_assert_int_eq(0, var.bits[2]);
    ck_assert_int_eq(0, s21_get_bit(&var, 127));
} END_TEST

START_TEST(int_to_decimal_8) {
    s21_decimal var = {{0, 1234253647, 3245678, 0}};
    int a = +99;
    ck_assert_int_eq(0, s21_from_int_to_decimal(a, &var));
    ck_assert_int_eq(99, var.bits[0]);
    ck_assert_int_eq(0, var.bits[1]);
    ck_assert_int_eq(0, var.bits[2]);
    ck_assert_int_eq(0, var.bits[3]);
    ck_assert_int_eq(0, s21_get_bit(&var, 127));
} END_TEST

START_TEST(int_to_decimal_9) {
    s21_decimal var = {{0, 1234253647, 3245678, 0}};
    int a = 2147483647;
    ck_assert_int_eq(0, s21_from_int_to_decimal(a, &var));
    ck_assert_int_eq(2147483647, var.bits[0]);
    ck_assert_int_eq(0, var.bits[1]);
    ck_assert_int_eq(0, var.bits[2]);
    ck_assert_int_eq(0, var.bits[3]);
    ck_assert_int_eq(0, s21_get_bit(&var, 127));
} END_TEST

START_TEST(s21_from_decimal_to_float_1) {
    s21_decimal src;
    int result = 0;
    float number = 0.00;
    src.bits[0] = 18122;
    src.bits[1] = 0;
    src.bits[2] = 0;
    src.bits[3] = 0;
    s21_set_exp(&src, 3);
    s21_sing_dec(&src);
    result = s21_from_decimal_to_float(src, &number);
    ck_assert_float_eq(number, -18.122);
    ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_float_2) {
    s21_decimal src;
    int result = 0;
    float number = 0.0;
    src.bits[0] = 1812;
    src.bits[1] = 0;
    src.bits[2] = 0;
    src.bits[3] = 2147483648;
    result = s21_from_decimal_to_float(src, &number);
    ck_assert_float_eq(number, -1812);
    ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_float_3) {
    s21_decimal src;
    int result = 0;
    float number = 0.0;
    src.bits[0] = 0XFFFFFF;
    src.bits[1] = 0;
    src.bits[2] = 0;
    src.bits[3] = 0;
    result = s21_from_decimal_to_float(src, &number);
    ck_assert_float_eq(number, 16777215);
    ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_float_4) {
    s21_decimal src;
    int result = 0;
    float number = 0.0;
    src.bits[0] = 23450987;
    src.bits[1] = 0;
    src.bits[2] = 0;
    src.bits[3] = 0;
    s21_sing_dec(&src);
    s21_set_exp(&src, 4);
    result = s21_from_decimal_to_float(src, &number);
    ck_assert_float_eq(number, -2345.0987);
    ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_float_5) {
    s21_decimal src;
    int result = 0;
    float number = 0.0;
    src.bits[0] = 4294967295;
    src.bits[1] = 4294967295;
    src.bits[2] = 0;
    src.bits[3] = 0;
    result = s21_from_decimal_to_float(src, &number);
    ck_assert_float_eq(number, 0xFFFFFFFFFFFFFFFF);
    ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_decimal_to_int_1) {
    s21_decimal src;
    int result = 0;
    int number = 0;
    src.bits[0] = 1812;
    src.bits[1] = 0;
    src.bits[2] = 0;
    src.bits[3] = 2147483648;
    result = s21_from_decimal_to_int(src, &number);
    ck_assert_float_eq(number, -1812);
    ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(s21_from_float_to_decimal_1) {
    s21_decimal val;
    float f;
    float b = 123.456;
    s21_from_float_to_decimal(b, &val);
    s21_from_decimal_to_float(val, &f);
    ck_assert_float_eq(f, b);
}
END_TEST

START_TEST(s21_from_float_to_decimal_2) {
    s21_decimal val;
    float f;
    float b = 116987.21930F;
    s21_from_float_to_decimal(b, &val);
    s21_from_decimal_to_float(val, &f);
    ck_assert_float_eq(f, b);
}
END_TEST

START_TEST(s21_from_float_to_decimal_3) {
    s21_decimal val;
    float f;
    float b = 12623532.7256347F;
    s21_from_float_to_decimal(b, &val);
    s21_from_decimal_to_float(val, &f);
    ck_assert_float_eq(f, b);
}
END_TEST

START_TEST(s21_from_float_to_decimal_4) {
    s21_decimal val;
    float f;
    float b = -34212312412432143214321342.6411F;
    s21_from_float_to_decimal(b, &val);
    s21_from_decimal_to_float(val, &f);
    ck_assert_float_eq(f, b);
}
END_TEST

START_TEST(s21_from_float_to_decimal_5) {
    s21_decimal val;
    float f;
    float b = 126235235432532.7256123512347F;
    s21_from_float_to_decimal(b, &val);
    s21_from_decimal_to_float(val, &f);
    ck_assert_float_eq(f, b);
}
END_TEST

START_TEST(s21_from_float_to_decimal_6) {
    s21_decimal val;
    float f;
    float b = 1262351243126523463632.725633246234673247F;
    s21_from_float_to_decimal(b, &val);
    s21_from_decimal_to_float(val, &f);
    ck_assert_float_eq(f, b);
}
END_TEST

START_TEST(s21_from_float_to_decimal_7) {
    s21_decimal val;
    float f;
    float b = -234632612623532.7256347F;
    s21_from_float_to_decimal(b, &val);
    s21_from_decimal_to_float(val, &f);
    ck_assert_float_eq(f, b);
}
END_TEST

START_TEST(s21_from_float_to_decimal_8) {
    s21_decimal val;
    float f;
    float b = 12623532.7256347F;
    s21_from_float_to_decimal(b, &val);
    s21_from_decimal_to_float(val, &f);
    ck_assert_float_eq(f, b);
}
END_TEST

START_TEST(s21_from_float_to_decimal_9) {
    s21_decimal val;
    float f;
    float b = 12724536456745374772623532.7256347F;
    s21_from_float_to_decimal(b, &val);
    s21_from_decimal_to_float(val, &f);
    ck_assert_float_eq(f, b);
}
END_TEST

Suite *s21_test_decimal_convert(void) {
    Suite *s = suite_create("!!!CONVERT TYPE!!!");
    TCase *convert_a_case;

    convert_a_case = tcase_create("--INT TO DECIMAL--");
    tcase_add_test(convert_a_case, int_to_decimal_0);
    tcase_add_test(convert_a_case, int_to_decimal_1);
    tcase_add_test(convert_a_case, int_to_decimal_2);
    tcase_add_test(convert_a_case, int_to_decimal_3);
    tcase_add_test(convert_a_case, int_to_decimal_4);
    tcase_add_test(convert_a_case, int_to_decimal_5);
    tcase_add_test(convert_a_case, int_to_decimal_6);
    tcase_add_test(convert_a_case, int_to_decimal_7);
    tcase_add_test(convert_a_case, int_to_decimal_8);
    tcase_add_test(convert_a_case, int_to_decimal_9);
    tcase_add_test(convert_a_case, s21_from_decimal_to_int_1);
    suite_add_tcase(s, convert_a_case);

    convert_a_case = tcase_create("--FLOAT TO DECIMAL--");
    tcase_add_test(convert_a_case, s21_from_float_to_decimal_1);
    tcase_add_test(convert_a_case, s21_from_float_to_decimal_2);
    tcase_add_test(convert_a_case, s21_from_float_to_decimal_3);
    tcase_add_test(convert_a_case, s21_from_float_to_decimal_4);
    tcase_add_test(convert_a_case, s21_from_float_to_decimal_5);
    tcase_add_test(convert_a_case, s21_from_float_to_decimal_6);
    tcase_add_test(convert_a_case, s21_from_float_to_decimal_7);
    tcase_add_test(convert_a_case, s21_from_float_to_decimal_8);
    tcase_add_test(convert_a_case, s21_from_float_to_decimal_9);
    suite_add_tcase(s, convert_a_case);

    convert_a_case = tcase_create("--DECIMAL TO FLOAT--");
    tcase_add_test(convert_a_case, s21_from_decimal_to_float_1);
    tcase_add_test(convert_a_case, s21_from_decimal_to_float_2);
    tcase_add_test(convert_a_case, s21_from_decimal_to_float_3);
    tcase_add_test(convert_a_case, s21_from_decimal_to_float_4);
    tcase_add_test(convert_a_case, s21_from_decimal_to_float_5);
    suite_add_tcase(s, convert_a_case);

    return s;
}
