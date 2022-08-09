#include "../s21_test_decimal.h"

START_TEST(div_b_2048) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    int rrr;
    for (int i = 3; i < 2048; i += 124) {
        for (int j = 31124124; j >= 0; j -= 55555) {
            s21_from_int_to_decimal(j, &a);
            s21_from_int_to_decimal(i, &b);
            s21_binary_div(a, b, &res);
            s21_from_decimal_to_int(res, &rrr);
            printf("%d / %d = %d\n", j, i, j / i);
            printf("%d / %d = %d\n\n", j, i, rrr);
            ck_assert_int_eq(rrr, j / i);
        }
    }
}
END_TEST

START_TEST(div_b_1) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    int rrr;
    // 7679914 / 375 = 20479
    s21_from_int_to_decimal(121, &a);
    s21_from_int_to_decimal(11, &b);
    s21_binary_div(a, b, &res);
    s21_from_decimal_to_int(res, &rrr);
    ck_assert_int_eq(rrr, 121 / 11);
}
END_TEST

START_TEST(div_b_2) {
    printf("\n\n\n\n============================================================\n");
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    int rrr;
    // 7679914 / 375 = 20479
    s21_from_int_to_decimal(7679914, &a);
    s21_from_int_to_decimal(37, &b);
    s21_binary_div(a, b, &res);
    s21_from_decimal_to_int(res, &rrr);
    ck_assert_int_eq(rrr, 7674 / 37);
}
END_TEST

START_TEST(float_dec_2048) {
    s21_decimal res;
    float f;
    char buf1[256] = {'\0'};
    char buf2[256] = {'\0'};
    for (float i = 1.114; i < 31111111.402823; i += 0.1) {
        int result = s21_from_float_to_decimal(i, &res);
        if (result == 0) {
            s21_from_decimal_to_float(res, &f);
            sprintf(buf1, "%f", i);
            sprintf(buf2, "%f", f);
            printf(" i = %f  ||  %s\n", i, buf1);
            printf(" f = %f  ||  %s\n", f, buf2);
            printf(" b = %u     %u %u\n\n", res.bits[0], res.bits[1], res.bits[2]);
            ck_assert_str_eq(buf1, buf2);
        }
    }
}
END_TEST

// START_TEST(bank_r) {
//     s21_decimal a;
//     s21_decimal_null(&a);
//     for (int i = 0; i < 93; i++) {
//         s21_set_bit(&a, i, i % 3);
//     }
//     s21_set_exp(&a, 15);
//     s21_print_binary_decimal(a, 128);
//     s21_bank_round(&a);
//     s21_print_binary_decimal(a, 128);
// }

START_TEST(tr_123) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    s21_from_float_to_decimal(50.549999, &a);
    s21_from_float_to_decimal(-100000.000000, &b);
    s21_div(a, b, &res);
}

START_TEST(div_15) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    s21_decimal_null(&a);
    s21_decimal_null(&b);
    a.bits[0] = 51251;
    a.bits[1] = 999511;
    a.bits[2] = 1111;
    b.bits[0] = 6332;
    b.bits[1] = 777234;
    s21_div(a, b, &res);
    s21_print_binary_decimal(a, 128);
    s21_print_binary_decimal(b, 128);
    s21_print_binary_decimal(res, 128);
    float f;
    s21_from_decimal_to_float(res, &f);
    s21_truncate(res, &a);
    s21_print_binary_decimal(a, 128);
    s21_round(res, &a);
    s21_print_binary_decimal(a, 128);

    // dec: 00000000000010110000000000000000 11000110010111110111111000100111 11010010111110111101110010110110 01000111011011100111000100100010

    // 6139347.5650291 ONLINE CALC
    // OUR DEC
    // 6139347.5650293 DIV
    // 6139347         TRUCN
    // 6139348         ROUND
}
END_TEST

START_TEST(div12) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    s21_decimal_null(&a);
    s21_decimal_null(&b);
    a.bits[0] = 0b00000000000000000000011101110000;
    a.bits[3] = 0b00000000000001100000000000000000;
    b.bits[0] = 0b00000000000000000000000000000110;
    b.bits[3] = 0b10000000000001110000000000000000;
    // s21_from_float_to_decimal(513765417.0F, &a);
    // s21_from_float_to_decimal(1194921390.97F, &b);
    s21_div(a, b, &res);
    float f;
    s21_from_decimal_to_float(res, &f);
    printf("F = %.28f\n", f);
    ck_assert_float_eq(f, 0.001904F / -0.0000006F);
}
END_TEST

START_TEST(div13) {
    printf("==============================\n");
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    s21_decimal_null(&a);
    s21_decimal_null(&b);
    a.bits[0] = 0b00011011100011010101100001000001;
    a.bits[1] = 0b00000000000000000000000000000010;
    a.bits[2] = 0b00000000000000000000000000000000;
    a.bits[3] = 0b00000000000001000000000000000000;
    b.bits[0] = 0b10110100111100011101100001110000;
    b.bits[1] = 0b00000000000000000000010001010011;
    b.bits[2] = 0b00000000000000000000000000000000;
    b.bits[3] = 0b10000000000010010000000000000000;
    // s21_from_float_to_decimal(513765417.0F, &a);
    // s21_from_float_to_decimal(1194921390.97F, &b);
    s21_div(a, b, &res);
    float f;
    s21_from_decimal_to_float(res, &f);
    printf("F = %.28f\n", f);
    ck_assert_float_eq(f, 905218.2593000F / -4757.5645451360F);
    // last int is 00011011100011010101100001000001 00000000000000000000000000000010 00000000000000000000000000000000 00000000000001000000000000000000  
    // last int is 10110100111100011101100001110000 00000000000000000000010001010011 00000000000000000000000000000000 10000000000010010000000000000000

    // num1 is 905218.2593000000000000000000000000
    // num2 is -4757.5645451360000000000000000000
}
END_TEST

START_TEST(add13) {
    printf("==============================\n");
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    s21_decimal_null(&a);
    s21_decimal_null(&b);
    a.bits[0] = 0b00011011100011010101100001000001;
    a.bits[1] = 0b00000000000000000000000000000010;
    a.bits[2] = 0b00000000000000000000000000000000;
    a.bits[3] = 0b00000000000001000000000000000000;
    b.bits[0] = 0b10110100111100011101100001110000;
    b.bits[1] = 0b00000000000000000000010001010011;
    b.bits[2] = 0b00000000000000000000000000000000;
    b.bits[3] = 0b10000000000010010000000000000000;
    // s21_from_float_to_decimal(513765417.0F, &a);
    // s21_from_float_to_decimal(1194921390.97F, &b);
    s21_div(a, b, &res);
    float f;
    s21_from_decimal_to_float(res, &f);
    printf("F = %.28f\n", f);
    ck_assert_float_eq(f, 905218.2593000F / -4757.5645451360F);
    // last int is 00011011100011010101100001000001 00000000000000000000000000000010 00000000000000000000000000000000 00000000000001000000000000000000  
    // last int is 10110100111100011101100001110000 00000000000000000000010001010011 00000000000000000000000000000000 10000000000010010000000000000000

    // num1 is 905218.2593000000000000000000000000
    // num2 is -4757.5645451360000000000000000000
}
END_TEST



Suite* s21_test_help(void) {
    Suite *s = suite_create("!!!HELP TESTS!!!");
    TCase *test_help;

    test_help = tcase_create("DEBUG AND HELP:\n");
    // tcase_add_test(test_help, float_dec_2048);
    // tcase_add_test(test_help, div_b_2048);
    // tcase_add_test(test_help, div_b_1);
    // tcase_add_test(test_help, div_b_2);
    // tcase_add_test(test_help, bank_r);
    // tcase_add_test(test_help, tr_123);
    // tcase_add_test(test_help, div_15);
    // tcase_add_test(test_help, div12);
    // tcase_add_test(test_help, div13);
    tcase_add_test(test_help, add13);
    suite_add_tcase(s, test_help);
    return s;
}
