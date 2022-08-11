#include "../s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
    int res = 0;
    long usrc = src;
    if (dst != NULL) {
        s21_decimal_null(dst);
        if (src < 0) {
            usrc = -src;
            s21_sing_dec(dst);
        }
        size_t i = 0;
        while (usrc > 0) {
            int helpVal = usrc % 2;
            if (i / 32 < 4) {
                s21_set_bit(dst, i, helpVal);
            }
            usrc /= 2;
            i++;
        }
        res = 0;
    } else {
        res = 1;
    }
    return res;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
    if (s21_check_decimal(src))
        return 1;
    *dst = 0;
    if (s21_get_exp_dec(&src) > 0)
        s21_truncate(src, &src);
    for (int i = 0; i < 32; i++) {
        *dst += s21_get_bit(&src, i) * pow(2, i);
    }
    if (s21_get_sing(&src)) {
        *dst *= (-1);
    }
    return 0;
}

int s21_from_float_to_decimal(float f, s21_decimal *dst) {
    s21_decimal_null(dst);
    if ((0 < f && f < 1e-28) || (f > 79228162514264337593543950335.0))
        return 1;
    int sing = 0;
    if (f < 0) {
        sing = 1;
        f = -f;
    }
    double lf = fabs(f);
    double copy_lf = lf;
    int counter = 0;
    while (copy_lf > 1) {
        copy_lf /= 10;
        counter++;
    }
    int exp = 0;
    for (int i = 0; i < 6; i++, counter++) {
        if (counter == 29 || f * 10.0 > 79228162514264337593543950335.0) {
            break;
        }
        exp = i + 1;
        lf *= 10;
    }
    lf = round(lf);

    double part_del;
    int j = 0;
    while (lf >= 1 && j < 96) {
        part_del = lf / 2;
        double i;
        double f;
        f = modf(part_del, &i);
        if (f == 0.0) {
            s21_set_bit(dst, j, 0);
        } else {
            s21_set_bit(dst, j, 1);
        }
        lf /= 2;
        lf -= f;
        j++;
    }
    s21_set_bit(dst, 127, sing);
    s21_set_exp(dst, exp);
    return 0;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
    if (s21_check_decimal(src))
        return 1;

    *dst = 0;
    int exp = s21_get_exp_dec(&src);
    long double ldst = 0.0;

    for (int i = 0; i < 96; i++)
        ldst += pow(2.0, i) * s21_get_bit(&src, i);

    while (exp--)
        ldst /= 10.0;

    if (s21_get_bit(&src, 127))
        ldst = -ldst;

    *dst = ldst;
    return 0;
}
