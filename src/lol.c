#include <stdio.h>
#include "s21_decimal.h"

int main(void) {
    s21_decimal a;
    s21_decimal b;
    s21_decimal res;
    float f;
    s21_from_float_to_decimal(25.5F, &a);
    s21_from_float_to_decimal(4.4F, &b);
    // s21_mul(a, b, &res);
    s21_div(a, b, &res);
    s21_from_decimal_to_float(res, &f);
    printf("my fun = %f\n", f);
    printf("origin = %f\n", 25.5F / 4.4F);
}
