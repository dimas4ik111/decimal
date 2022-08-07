#include <stdio.h>
#include "s21_decimal.h"

int main(void) {
    // s21_decimal a;
    // s21_decimal b;
    s21_decimal res;
    // DIV
    float f;
    // for (float i = 88888.88888; i < 99999.99999; i += 190.128) {
    //     for (float j = 1.0; j < 10.0; j++) {
    //         s21_from_float_to_decimal(i, &a);
    //         s21_from_float_to_decimal(j, &b);
    //         s21_div(a, b, &res);
    //         s21_from_decimal_to_float(res, &f);
    //         printf("div     my = %f / %f = %.16f\n", i, j, f);
    //         printf("div origin = %f / %f = %.16f\n\n", i, j, i / j);
    //         if (f != i / j) {
    //             printf("!!!ERROR!!!\n");
    //             printf("%f != %f\n", f, i / j);
    //             return 0;
    //         }
    //     }
    // }

    // // MUL
    // for (float i = -123567.0F; i < 999.99999; i += 341.128) {
    //     for (float j = 1.0F; j < 10.0F; j++) {
    //         s21_from_float_to_decimal(i, &a);
    //         s21_from_float_to_decimal(j, &b);
    //         s21_mul(a, b, &res);
    //         s21_from_decimal_to_float(res, &f);
    //         printf("mul     my = %f * %f = %.28f\n", i, j, f);
    //         printf("mul origin = %f * %f = %.28f\n", i, j, i * j);
    //         if (f != i * j) {
    //             printf("!!!ERROR!!!\n");
    //             printf("%f != %f\n", f, i * j);
    //             return 0;
    //         }
    //     }
    // }

    for (float i = 42314.1641; i < 99925929981259812896235962398569.86574238; i+= 122345432738569325625900.12328374389269205293700) {
        s21_from_float_to_decimal(i, &res);
        s21_from_decimal_to_float(res, &f);
        s21_print_binary_decimal(res, 128);
        printf("I = %f\n", i);
        printf("decimal[] = %u %u %u\n\n", res.bits[0], res.bits[1], res.bits[2]);
        if (f != i) {
            printf("f = %f\ni = %f\n", f, i);
            break;
        }
    }
}


