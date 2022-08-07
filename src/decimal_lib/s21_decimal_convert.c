// Конвертация типов
#include "../s21_decimal.h"

// 0 - OK
// 1 - ошибка конвертации

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
        if (counter == 28) {
            break;
        }
        exp = i + 1;
        lf *= 10;
    }
    lf = round(lf);
    if (lf < 9223372036854775807LL) {
        unsigned long long help_var = (unsigned long long)lf;
        int j = 0;
        while (help_var > 0) {
            if (help_var % 2 == 0) {
                s21_set_bit(dst, j, 0);
            } else {
                s21_set_bit(dst, j, 1);
            }
            j++;
            help_var /= 2;
        }
        s21_set_bit(dst, 127, sing);
        s21_set_exp(dst, exp);
    } else {
        
    }
    return 0;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
    if (s21_check_decimal(src))
        return 1;
    *dst = 0;
    double result = 0, two = 1;
    for (int i = 0; i < 96; i++) {
        if (s21_get_bit(&src, i)) {
            result += two;
        }
        two *= 2.0;
    }
    result = round(result);
    for (int i = 0; i < s21_get_exp_dec(&src); i++) {
        result /= 10.0;
    }
    if (s21_get_sing(&src))
        result = -result;
    *dst = result;
    return 0;
}
