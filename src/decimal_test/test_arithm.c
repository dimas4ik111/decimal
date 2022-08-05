#include "../s21_test_decimal.h"

START_TEST(s21_addit) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    s21_from_int_to_decimal(51354, &a);
    s21_from_int_to_decimal(1111, &b);
    s21_mul(a, b, &res);
    int rrr;
    s21_from_decimal_to_int(res, &rrr);
    ck_assert_int_eq(51354 * 1111, rrr);
}
END_TEST

START_TEST(s21_smull) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    s21_decimal_null(&a);
    s21_decimal_null(&b);
    a.bits[0] = 1111111111;
    a.bits[1] = 123456;
    a.bits[2] = 1111111111;
    b.bits[0] = 2;
    s21_mul(a, b, &res);
    ck_assert_int_eq(res.bits[0], 2222222222);
    ck_assert_int_eq(res.bits[1], 246912);
    ck_assert_int_eq(res.bits[2], 2222222222);
}
END_TEST

// ADD

START_TEST(s21_add1) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    s21_from_int_to_decimal(51354, &a);
    s21_from_int_to_decimal(1111, &b);
    s21_add(a, b, &res);
    int rrr = 0;
    s21_from_decimal_to_int(res, &rrr);
    ck_assert_int_eq(52465, rrr);
}
END_TEST

START_TEST(s21_add2) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    s21_from_int_to_decimal(-9403, &a);
    s21_from_int_to_decimal(234, &b);
    s21_add(a, b, &res);
    int rrr = 0;
    s21_from_decimal_to_int(res, &rrr);
    ck_assert_int_eq(-9169, rrr);
}
END_TEST

START_TEST(s21_add3) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    s21_from_int_to_decimal(4294967, &a);
    s21_from_int_to_decimal(-4294967, &b);
    s21_add(a, b, &res);
    int rrr = 0;
    s21_from_decimal_to_int(res, &rrr);
    ck_assert_int_eq(4294967 + (-4294967), rrr);
}
END_TEST

START_TEST(s21_add5) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    s21_from_int_to_decimal(-41523, &a);
    s21_from_int_to_decimal(-11111, &b);
    s21_add(a, b, &res);
    int rrr = 0;
    s21_from_decimal_to_int(res, &rrr);
    ck_assert_int_eq(-(41523 + 11111), rrr);
}
END_TEST

START_TEST(s21_add6) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    s21_from_int_to_decimal(6871, &a);
    s21_from_int_to_decimal(6871, &b);
    s21_add(a, b, &res);
    int rrr = 0;
    s21_from_decimal_to_int(res, &rrr);
    ck_assert_int_eq(6871 + 6871, rrr);
}
END_TEST

START_TEST(s21_add7) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    s21_from_int_to_decimal(2, &a);
    s21_from_int_to_decimal(10, &b);
    s21_add(a, b, &res);
    int rrr = 0;
    s21_from_decimal_to_int(res, &rrr);
    ck_assert_int_eq(12, rrr);
}
END_TEST

START_TEST(s21_add8) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    s21_from_int_to_decimal(123321, &a);
    s21_from_int_to_decimal(10, &b);
    s21_add(a, b, &res);
    int rrr;
    s21_from_decimal_to_int(res, &rrr);
    ck_assert_int_eq(rrr, 123321 + 10);
}
END_TEST

START_TEST(s21_add9) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    s21_from_int_to_decimal(56789, &a);
    s21_from_int_to_decimal(341111, &b);
    s21_set_exp(&a, 3);
    s21_set_exp(&b, 6);
    s21_add(a, b, &res);
    float f;
    s21_from_decimal_to_float(res, &f);
    ck_assert_float_eq(f, 56.789 + 0.341111);
}
END_TEST

START_TEST(s21_add10) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    s21_from_int_to_decimal(-56789, &a);
    s21_from_int_to_decimal(-341111, &b);
    s21_set_exp(&a, 3);
    s21_set_exp(&b, 6);
    s21_add(a, b, &res);
    float f;
    s21_from_decimal_to_float(res, &f);
    ck_assert_float_eq(f, -56.789 + (-0.341111));
}
END_TEST

START_TEST(s21_add11) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    s21_from_int_to_decimal(56789, &a);
    s21_from_int_to_decimal(-34, &b);
    s21_set_exp(&a, 3);
    s21_set_exp(&b, 2);
    s21_add(a, b, &res);
    float f;
    s21_from_decimal_to_float(res, &f);
    ck_assert_float_eq(f, 56.789 + (-0.34));
}
END_TEST

// SUB

START_TEST(s21_sub1) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    s21_from_int_to_decimal(123, &a);
    s21_from_int_to_decimal(23, &b);
    s21_sub(a, b, &res);
    int rrr;
    s21_from_decimal_to_int(res, &rrr);
    ck_assert_int_eq(rrr, 123 - 23);
}
END_TEST

START_TEST(s21_sub2) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    s21_from_int_to_decimal(72364, &a);
    s21_from_int_to_decimal(235472, &b);
    s21_sub(a, b, &res);
    int rrr;
    s21_from_decimal_to_int(res, &rrr);
    ck_assert_int_eq(rrr, 72364 - 235472);
    ck_assert_int_eq(s21_get_sing(&res), 1);
}
END_TEST

START_TEST(s21_sub3) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    s21_from_int_to_decimal(-123, &a);
    s21_from_int_to_decimal(-23, &b);
    s21_sub(a, b, &res);
    int rrr;
    s21_from_decimal_to_int(res, &rrr);
    ck_assert_int_eq(rrr, -123 - (-23));
}
END_TEST

START_TEST(s21_sub4) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    s21_from_int_to_decimal(123, &a);
    s21_from_int_to_decimal(-23, &b);
    s21_sub(a, b, &res);
    int rrr;
    s21_from_decimal_to_int(res, &rrr);
    ck_assert_int_eq(rrr, 123 - (-23));
}
END_TEST

START_TEST(s21_sub5) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    s21_from_int_to_decimal(-123, &a);
    s21_from_int_to_decimal(23, &b);
    s21_sub(a, b, &res);
    int rrr;
    s21_from_decimal_to_int(res, &rrr);
    ck_assert_int_eq(rrr, -123 - 23);
}
END_TEST

START_TEST(s21_sub6) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    s21_from_int_to_decimal(+56789, &a);
    s21_from_int_to_decimal(-341111, &b);
    s21_set_exp(&a, 3);
    s21_set_exp(&b, 6);
    s21_sub(a, b, &res);
    float f;
    s21_from_decimal_to_float(res, &f);
    ck_assert_float_eq(f, +56.789 - (-0.341111));
}
END_TEST

START_TEST(s21_sub7) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    s21_from_int_to_decimal(-56789, &a);
    s21_from_int_to_decimal(-341111, &b);
    s21_set_exp(&a, 3);
    s21_set_exp(&b, 6);
    s21_sub(a, b, &res);
    float f;
    s21_from_decimal_to_float(res, &f);
    ck_assert_float_eq(f, -56.789 - (-0.341111));
}
END_TEST

START_TEST(s21_sub8) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    s21_from_int_to_decimal(-0, &a);
    s21_from_int_to_decimal(0, &b);
    s21_set_exp(&a, 0);
    s21_set_exp(&b, 0);
    s21_sub(a, b, &res);
    float f;
    s21_from_decimal_to_float(res, &f);
    ck_assert_float_eq(f, -0.0 - 0.0);
}
END_TEST

START_TEST(s21_sub9) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    s21_from_int_to_decimal(-0, &a);
    s21_from_int_to_decimal(-12345665, &b);
    s21_set_exp(&a, 0);
    s21_set_exp(&b, 8);
    s21_sub(a, b, &res);
    float f;
    s21_from_decimal_to_float(res, &f);
    ck_assert_float_eq(f, -0.0 - (-0.12345665));
}
END_TEST

START_TEST(s21_sub10) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    s21_from_int_to_decimal(-0, &a);
    s21_from_int_to_decimal(+12345665, &b);
    s21_set_exp(&a, 0);
    s21_set_exp(&b, 8);
    s21_sub(a, b, &res);
    float f;
    s21_from_decimal_to_float(res, &f);
    ck_assert_float_eq(f, -0.0 - (+0.12345665));
}
END_TEST

// MUL

START_TEST(s21_mul1) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    s21_from_int_to_decimal(123, &a);
    s21_from_int_to_decimal(23, &b);
    s21_mul(a, b, &res);
    int rrr;
    s21_from_decimal_to_int(res, &rrr);
    ck_assert_int_eq(rrr, 123 * 23);
}
END_TEST
START_TEST(s21_mul2) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    s21_from_int_to_decimal(723, &a);
    s21_from_int_to_decimal(2354, &b);
    s21_mul(a, b, &res);
    int rrr;
    s21_from_decimal_to_int(res, &rrr);
    ck_assert_int_eq(rrr, 723 * 2354);
    ck_assert_int_eq(s21_get_sing(&res), 0);
}
END_TEST

START_TEST(s21_mul3) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    s21_from_int_to_decimal(-123, &a);
    s21_from_int_to_decimal(-23, &b);
    s21_mul(a, b, &res);
    int rrr;
    s21_from_decimal_to_int(res, &rrr);
    ck_assert_int_eq(rrr, -123 * (-23));
}
END_TEST

START_TEST(s21_mul4) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    s21_from_int_to_decimal(123, &a);
    s21_from_int_to_decimal(-23, &b);
    s21_mul(a, b, &res);
    int rrr;
    s21_from_decimal_to_int(res, &rrr);
    ck_assert_int_eq(rrr, 123 * (-23));
}
END_TEST

START_TEST(s21_mul5) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    s21_from_int_to_decimal(-123, &a);
    s21_from_int_to_decimal(23, &b);
    s21_mul(a, b, &res);
    int rrr;
    s21_from_decimal_to_int(res, &rrr);
    ck_assert_int_eq(rrr, -123 * 23);
}
END_TEST

START_TEST(s21_mul6) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    s21_from_int_to_decimal(+56789, &a);
    s21_from_int_to_decimal(-341111, &b);
    s21_set_exp(&a, 3);
    s21_set_exp(&b, 6);
    s21_mul(a, b, &res);
    float f;
    s21_from_decimal_to_float(res, &f);
    ck_assert_float_eq(f, +56.789 * (-0.341111));
}
END_TEST

START_TEST(s21_mul7) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    s21_from_int_to_decimal(-56789, &a);
    s21_from_int_to_decimal(-341111, &b);
    s21_set_exp(&a, 3);
    s21_set_exp(&b, 6);
    s21_mul(a, b, &res);
    float f;
    s21_from_decimal_to_float(res, &f);
    ck_assert_float_eq(f, -56.789 * (-0.341111));
}
END_TEST

START_TEST(s21_mul8) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    s21_from_int_to_decimal(-0, &a);
    s21_from_int_to_decimal(0, &b);
    s21_set_exp(&a, 0);
    s21_set_exp(&b, 0);
    s21_mul(a, b, &res);
    float f;
    s21_from_decimal_to_float(res, &f);
    ck_assert_float_eq(f, -0.0 * 0.0);
}
END_TEST

START_TEST(s21_mul9) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    s21_from_int_to_decimal(-0, &a);
    s21_from_int_to_decimal(-12345665, &b);
    s21_set_exp(&a, 0);
    s21_set_exp(&b, 8);
    s21_mul(a, b, &res);
    float f;
    s21_from_decimal_to_float(res, &f);
    ck_assert_float_eq(f, -0.0 * (-0.12345665));
}
END_TEST

START_TEST(s21_mul10) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    s21_from_int_to_decimal(-0, &a);
    s21_from_int_to_decimal(+12345665, &b);
    s21_set_exp(&a, 0);
    s21_set_exp(&b, 8);
    s21_mul(a, b, &res);
    float f;
    s21_from_decimal_to_float(res, &f);
    ck_assert_float_eq(f, -0.0 * (+0.12345665));
}
END_TEST

// DIV

START_TEST(s21_div1) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    s21_from_int_to_decimal(123456, &a);
    s21_from_int_to_decimal(2, &b);
    int check = s21_binary_div(a, b, &res);
    int rrr;
    s21_from_decimal_to_int(res, &rrr);
    ck_assert_int_eq(rrr, 123456 / 2);
    ck_assert_int_eq(check, 0);
}
END_TEST

START_TEST(s21_div2) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    s21_from_int_to_decimal(100000, &a);
    s21_from_int_to_decimal(10, &b);
    s21_div(a, b, &res);
    int rrr;
    s21_from_decimal_to_int(res, &rrr);
    ck_assert_int_eq(rrr, 100000 / 10);
    ck_assert_int_eq(s21_div(a, b, &res), 0);
}
END_TEST

START_TEST(s21_div3) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    s21_from_int_to_decimal(370412, &a);
    s21_from_int_to_decimal(37, &b);
    int check = s21_div(a, b, &res);
    float f;
    s21_from_decimal_to_float(res, &f);
    ck_assert_float_eq(f, 370412.0F / 37.0F);
    ck_assert_int_eq(check, 0);
}
END_TEST

START_TEST(s21_div4) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    s21_from_int_to_decimal(1, &a);
    s21_from_int_to_decimal(3, &b);
    int check = s21_div(a, b, &res);
    int rrr;
    s21_from_decimal_to_int(res, &rrr);
    ck_assert_int_eq(rrr, 1 / 3);
    ck_assert_int_eq(check, 0);
}
END_TEST

START_TEST(s21_div5) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    s21_from_float_to_decimal(121.0F, &a);
    s21_from_float_to_decimal(11.0F, &b);
    int check = s21_div(a, b, &res);
    float f;
    s21_from_decimal_to_float(res, &f);
    ck_assert_float_eq(f, 121.0 / 11.0);
    ck_assert_int_eq(check, 0);
}
END_TEST

START_TEST(s21_div6) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    s21_from_int_to_decimal(-370412, &a);
    s21_from_int_to_decimal(+37, &b);
    int check = s21_div(a, b, &res);
    int rrr;
    s21_from_decimal_to_int(res, &rrr);
    ck_assert_int_eq(rrr, -370412 / (+37));
    ck_assert_int_eq(check, 0);
}
END_TEST

START_TEST(s21_div7) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    s21_from_int_to_decimal(+0, &a);
    s21_from_int_to_decimal(-0, &b);
    int check = s21_div(a, b, &res);
    int rrr;
    s21_from_decimal_to_int(res, &rrr);
    ck_assert_int_eq(check, 3);
}
END_TEST

START_TEST(s21_div8) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    s21_from_int_to_decimal(-0, &a);
    s21_from_int_to_decimal(+0, &b);
    int check = s21_div(a, b, &res);
    int rrr;
    s21_from_decimal_to_int(res, &rrr);
    ck_assert_int_eq(check, 3);
}
END_TEST

START_TEST(s21_div9) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    s21_from_int_to_decimal(0, &a);
    s21_from_int_to_decimal(1000, &b);
    int check = s21_div(a, b, &res);
    ck_assert_int_eq(check, 0);
}
END_TEST

START_TEST(s21_div10) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    s21_from_float_to_decimal(125123123123.99317F, &a);
    s21_from_float_to_decimal(22123123123.888344521F, &b);
    s21_div(a, b, &res);
    float f;
    s21_from_decimal_to_float(res, &f);
    ck_assert_float_eq(f, 125123123123.99317F / 22123123123.888344521F);
}
END_TEST

START_TEST(s21_div11) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    s21_from_float_to_decimal(12.5, &a);
    s21_from_float_to_decimal(2.2, &b);
    s21_div(a, b, &res);
    float f;
    s21_from_decimal_to_float(res, &f);
    ck_assert_float_eq(f, 12.5F / 2.2F);
}
END_TEST

START_TEST(s21_mod1) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    int rrr;
    s21_from_int_to_decimal(11, &a);
    s21_from_int_to_decimal(2, &b);
    s21_mod(a, b, &res);
    s21_from_decimal_to_int(res, &rrr);
    ck_assert_int_eq(rrr, 11 % 2);
}
END_TEST

START_TEST(s21_mod2) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    int rrr;
    s21_from_int_to_decimal(11123, &a);
    s21_from_int_to_decimal(232, &b);
    s21_mod(a, b, &res);
    s21_from_decimal_to_int(res, &rrr);
    ck_assert_int_eq(rrr, 11123 % 232);
}
END_TEST

START_TEST(s21_mod3) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    s21_from_float_to_decimal(12.5F, &a);
    s21_from_float_to_decimal(2.2F, &b);
    s21_mod(a, b, &res);
    float f;
    s21_from_decimal_to_float(res, &f);
    ck_assert_float_eq(f, fmodf(12.5F, 2.2F));
}
END_TEST

START_TEST(s21_mod4) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    int rrr;
    s21_from_int_to_decimal(121, &a);
    s21_from_int_to_decimal(11, &b);
    s21_mod(a, b, &res);
    s21_from_decimal_to_int(res, &rrr);
    ck_assert_int_eq(rrr, 121 % 11);
}
END_TEST

// START_TEST(s21_multi_add) {
//     s21_decimal a;
//     s21_decimal b;
//     s21_decimal res;
//     float f;
//     for (float i = 50.55F; i <= 200.0F; i += 50.0F) {
//         for (float j = -99999.99999F; j <= 99999.99999F; j += 0.25F) {
//             if (i == 0.0F || j == 0.0) {
//                 i++; j++;
//             }
//             s21_from_float_to_decimal(i, &a);
//             s21_from_float_to_decimal(j, &b);
//             s21_add(a, b, &res);
//             s21_from_decimal_to_float(res, &f);
//             ck_assert_float_eq(f, i + j);
//             ck_abort_msg("asfsafasdsa");
//             printf("my fun %f + %f = %.28f\n", i, j, f);
//             printf("RESULT %f + %f = %.28f\n\n", i, j, i + j);
//         }
//     }
// }
// END_TEST

// START_TEST(s21_multi_sub) {
//     s21_decimal a;
//     s21_decimal b;
//     s21_decimal res;
//     float f;
//     for (float i = 50.55F; i <= 200.0F; i += 50.0F) {
//         for (float j = -99999.99999F; j <= 99999.99999F; j += 0.25F) {
//             if (i == 0.0F || j == 0.0) {
//                 i++; j++;
//             }
//             s21_from_float_to_decimal(i, &a);
//             s21_from_float_to_decimal(j, &b);
//             s21_sub(a, b, &res);
//             s21_from_decimal_to_float(res, &f);
//             ck_assert_float_eq(f, i - j);
//             printf("my fun %f - %f = %.28f\n", i, j, f);
//             printf("RESULT %f - %f = %.28f\n\n", i, j, i - j);
//         }
//     }
// }
// END_TEST

// START_TEST(s21_multi_mul) {
//     s21_decimal a;
//     s21_decimal b;
//     s21_decimal res;
//     float f;
//     for (float i = 50.55F; i <= 200.0F; i += 50.0F) {
//         for (float j = -99999.99999F; j <= 99999.99999F; j += 0.25F) {
//             if (i == 0.0F || j == 0.0) {
//                 i++; j++;
//             }
//             s21_from_float_to_decimal(i, &a);
//             s21_from_float_to_decimal(j, &b);
//             s21_mul(a, b, &res);
//             s21_from_decimal_to_float(res, &f);
//             ck_assert_float_eq(f, i * j);
//             printf("my fun %f * %f = %.28f\n", i, j, f);
//             printf("RESULT %f * %f = %.28f\n\n", i, j, i * j);
//         }
//     }
// }
// END_TEST

// START_TEST(s21_multi_div) {
//     s21_decimal a;
//     s21_decimal b;
//     s21_decimal res;
//     float f;
//     for (float i = 50.55F; i <= 200.0F; i += 50.0F) {
//         for (float j = -99999.99999F; j <= 99999.99999F; j += 0.25F) {
//             if (i == 0.0F || j == 0.0) {
//                 i++; j++;
//             }
//             s21_from_float_to_decimal(i, &a);
//             s21_from_float_to_decimal(j, &b);
//             s21_div(a, b, &res);
//             s21_from_decimal_to_float(res, &f);
//             printf("my fun %f / %f = %.28f\n", i, j, f);
//             printf("RESULT %f / %f = %.28f\n\n", i, j, i * j);
//             ck_assert_float_eq(f, i / j);
//         }
//     }
// }

Suite* s21_test_arithm(void) {
    Suite *s = suite_create("!!!!ARITHM!!!!!");
    TCase *arithm_a_test;

    arithm_a_test = tcase_create("--ADD--");
    tcase_add_test(arithm_a_test, s21_addit);
    tcase_add_test(arithm_a_test, s21_smull);
    tcase_add_test(arithm_a_test, s21_add1);
    tcase_add_test(arithm_a_test, s21_add2);
    tcase_add_test(arithm_a_test, s21_add3);
    tcase_add_test(arithm_a_test, s21_add5);
    tcase_add_test(arithm_a_test, s21_add6);
    tcase_add_test(arithm_a_test, s21_add7);
    tcase_add_test(arithm_a_test, s21_add8);
    tcase_add_test(arithm_a_test, s21_add9);
    tcase_add_test(arithm_a_test, s21_add10);
    tcase_add_test(arithm_a_test, s21_add11);
    suite_add_tcase(s, arithm_a_test);

    arithm_a_test = tcase_create("--SUB--");
    tcase_add_test(arithm_a_test, s21_sub1);
    tcase_add_test(arithm_a_test, s21_sub2);
    tcase_add_test(arithm_a_test, s21_sub3);
    tcase_add_test(arithm_a_test, s21_sub4);
    tcase_add_test(arithm_a_test, s21_sub5);
    tcase_add_test(arithm_a_test, s21_sub6);
    tcase_add_test(arithm_a_test, s21_sub7);
    tcase_add_test(arithm_a_test, s21_sub8);
    tcase_add_test(arithm_a_test, s21_sub9);
    tcase_add_test(arithm_a_test, s21_sub10);
    suite_add_tcase(s, arithm_a_test);

    arithm_a_test = tcase_create("--MUL--");
    tcase_add_test(arithm_a_test, s21_mul1);
    tcase_add_test(arithm_a_test, s21_mul2);
    tcase_add_test(arithm_a_test, s21_mul3);
    tcase_add_test(arithm_a_test, s21_mul4);
    tcase_add_test(arithm_a_test, s21_mul5);
    tcase_add_test(arithm_a_test, s21_mul6);
    tcase_add_test(arithm_a_test, s21_mul7);
    tcase_add_test(arithm_a_test, s21_mul8);
    tcase_add_test(arithm_a_test, s21_mul9);
    tcase_add_test(arithm_a_test, s21_mul10);
    suite_add_tcase(s, arithm_a_test);

    arithm_a_test = tcase_create("--DIV--");
    tcase_add_test(arithm_a_test, s21_div1);
    tcase_add_test(arithm_a_test, s21_div2);
    tcase_add_test(arithm_a_test, s21_div3);
    tcase_add_test(arithm_a_test, s21_div4);
    tcase_add_test(arithm_a_test, s21_div5);
    tcase_add_test(arithm_a_test, s21_div6);
    tcase_add_test(arithm_a_test, s21_div7);
    tcase_add_test(arithm_a_test, s21_div8);
    tcase_add_test(arithm_a_test, s21_div9);
    tcase_add_test(arithm_a_test, s21_div10);
    tcase_add_test(arithm_a_test, s21_div11);
    suite_add_tcase(s, arithm_a_test);

    arithm_a_test = tcase_create("--MOD--");
    tcase_add_test(arithm_a_test, s21_mod1);
    tcase_add_test(arithm_a_test, s21_mod2);
    tcase_add_test(arithm_a_test, s21_mod3);
    tcase_add_test(arithm_a_test, s21_mod4);
    suite_add_tcase(s, arithm_a_test);

    // arithm_a_test = tcase_create("--MULTI_TEST__");
    // tcase_add_test(arithm_a_test, s21_multi_add);
    // tcase_add_test(arithm_a_test, s21_multi_sub);
    // tcase_add_test(arithm_a_test, s21_multi_mul);
    // tcase_add_test(arithm_a_test, s21_multi_div);
    // suite_add_tcase(s, arithm_a_test);

    return s;
}
