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
    s21_from_int_to_decimal(-10, &b);
    s21_add(a, b, &res);
    int rrr;
    s21_from_decimal_to_int(res, &rrr);
    ck_assert_int_eq(rrr, 123321 - 10);
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
    ck_assert_float_eq(f, 370412.0 / 37.0);
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
    s21_from_float_to_decimal(1, &a);
    s21_from_float_to_decimal(3, &b);
    s21_div(a, b, &res);
    float f;
    s21_from_decimal_to_float(res, &f);
    ck_assert_float_eq(f, 1.0 / 3.0);
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
    s21_from_float_to_decimal(12.5, &a);
    s21_from_float_to_decimal(2.2, &b);
    s21_mod(a, b, &res);
    float f;
    s21_from_decimal_to_float(res, &f);
    ck_assert_float_eq(f, fmod(12.5, 2.2));
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

START_TEST(mul_inf1) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    a.bits[0] = 0b01100001001001001000000110111000;
    a.bits[1] = 0b00000000000000000010111000011101;
    a.bits[2] = 0b00000000000000000000000000000000;
    a.bits[3] = 0b00000000000000000000000000000000;
    b.bits[0] = 0b11101111011111100001010111101100;
    b.bits[1] = 0b11011010101100110101000001011110;
    b.bits[2] = 0b00000000001001001110011100110111;
    b.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(s21_mul(a, b, &res), 1);
}
END_TEST

START_TEST(mul_inf2) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    a.bits[0] = 0b11101011011000100100110100001011;
    a.bits[1] = 0b11001110110111101010100000001111;
    a.bits[2] = 0b00001001101010111011001111100001;
    a.bits[3] = 0b10000000000000000000000000000000;
    b.bits[0] = 0b11000101101111011101001101001110;
    b.bits[1] = 0b00000000000001111111111001111000;
    b.bits[2] = 0b00000000000000000000000000000000;
    b.bits[3] = 0b00000000000000000000000000000000;
    ck_assert_int_eq(s21_mul(a, b, &res), 2);
}
END_TEST

START_TEST(float_add1) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    a.bits[0] = 0b00001111110101001100001101011100;
    a.bits[1] = 0b10000110011101010001111011111101;
    a.bits[2] = 0b100011111110000011;
    a.bits[3] = 0;
    s21_set_exp(&a, 10);
    b.bits[0] = 0b01100101111000111111010010010011;
    b.bits[1] = 0b11011010011000000100000001100101;
    b.bits[2] = 0b110100010;
    b.bits[3] = 0;
    s21_set_exp(&b, 10);
    float f = 0.0;
    s21_add(a, b, &res);
    s21_from_decimal_to_float(res, &f);
    ck_assert_float_eq(272551341447866.041819F, f);
}
END_TEST

START_TEST(float_add2) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    a.bits[0] = 0b10000001001001101001011101110010;
    a.bits[1] = 0;
    a.bits[2] = 0;
    a.bits[3] = 0;
    s21_set_exp(&a, 13);
    b.bits[0] = 0b11001010001100010101111001110000;
    b.bits[1] = 0b11011000110101001000111110001000;
    b.bits[2] = 0b11101010001000;
    b.bits[3] = 0;
    s21_set_exp(&b, 7);
    float f = 0.0;
    s21_add(a, b, &res);
    s21_from_decimal_to_float(res, &f);
    ck_assert_float_eq(27642163747128884.706400F, f);
}
END_TEST

START_TEST(float_add3) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    a.bits[0] = 0b00001010000111000000000100011101;
    a.bits[1] = 0b00001010000111000000000100011101;
    a.bits[2] = 0b11001101000100110110100;
    a.bits[3] = 0;
    s21_sing_dec(&a);
    s21_set_exp(&a, 6);
    b.bits[0] = 0b10001011111110001001111101100011;
    b.bits[1] = 0b1011100010010000010000100;
    b.bits[2] = 0;
    b.bits[3] = 0;
    s21_set_exp(&b, 9);
    float f = 0.0;
    s21_add(a, b, &res);
    s21_from_decimal_to_float(res, &f);
    ck_assert_float_eq(-123960718951133149053.000000F, f);
}
END_TEST

START_TEST(float_add4) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    float f = 0.0;
    a.bits[0] = 0b01000000111111011001100011100010;
    a.bits[1] = 0b01010110111001000111111010111100;
    a.bits[2] = 0b00000001101101011001011001110101;
    a.bits[3] = 0b10000000000001110000000000000000;

    b.bits[0] = 0b00010101010110101111011110110100;
    b.bits[1] = 0b01100011101000111000010111111100;
    b.bits[2] = 0b00000000000000000000100011001010;
    b.bits[3] = 0b00000000000001100000000000000000;

    s21_add(a, b, &res);
    s21_from_decimal_to_float(res, &f);
    ck_assert_float_eq(-5.2859598456878E19F, f);
}
END_TEST

START_TEST(float_sub1) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    float f = 0.0;
    a.bits[0] = 0b01100110000100011101000111100101;
    a.bits[1] = 0b110100000110101011;
    a.bits[2] = 0;
    a.bits[3] = 0;
    s21_set_exp(&a, 11);

    b.bits[0] = 0b100000011011000010001010100;
    b.bits[1] = 0;
    b.bits[2] = 0;
    b.bits[3] = 0;
    s21_set_exp(&b, 9);

    s21_sub(a, b, &res);
    s21_from_decimal_to_float(res, &f);
    ck_assert_float_eq(9166.225383F, f);
}
END_TEST

START_TEST(float_sub2) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    float f = 0.0;
    a.bits[0] = 0b11110010100001000111110100110110;
    a.bits[1] = 0b110100110110111;
    a.bits[2] = 0;
    a.bits[3] = 0b10000000000000000000000000000000;

    b.bits[0] = 0b01000110100000000001001110011011;
    b.bits[1] = 0b11000001011101011010;
    b.bits[2] = 0;
    b.bits[3] = 0b10000000000000000000000000000000;
    s21_set_exp(&b, 14);

    s21_sub(a, b, &res);
    s21_from_decimal_to_float(res, &f);
    ck_assert_float_eq(-116238768700691.966238F, f);
}
END_TEST

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
    tcase_add_test(arithm_a_test, float_add1);
    tcase_add_test(arithm_a_test, float_add2);
    tcase_add_test(arithm_a_test, float_add3);
    tcase_add_test(arithm_a_test, float_add4);
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
    tcase_add_test(arithm_a_test, float_sub1);
    tcase_add_test(arithm_a_test, float_sub2);
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
    tcase_add_test(arithm_a_test, mul_inf1);
    tcase_add_test(arithm_a_test, mul_inf2);
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

    return s;
}
