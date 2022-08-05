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
    int res = 0;
    if (f < 0) {
        s21_sing_dec(dst);
        f = -f;
    }
    int pow_ten = 0;
    int n = 0;
    if (dst != NULL && f >= -(pow(2, 96)) && f <= pow(2, 96)) {
        if (f < 0 || f == -0.0F) {
            s21_sing_dec(dst);
            f = -f;
        }
        size_t size = sizeof(f);
        unsigned char *p = (unsigned char *) &f;
        p += size - 1;
        while (size--) {
            for (int i = 0; i < 8 ; i++) {
                int help_var = (*p & 128 ? 1 : 0);
                *p <<= 1;
                s21_set_bit(dst, 31 - n, !!help_var);
                n++;
            }
            p--;
        }
    }
    int exp = 0;
    for (int i = 23; i < 31; i++) {
        exp += pow(2, (i - 23)) * s21_get_bit(dst, i);
        s21_set_bit(dst, i, 0);
    }
    exp -= 127;

    s21_set_bit(dst, 23, 1);
    s21_decimal ten;
    s21_from_int_to_decimal(10, &ten);
    if (23 - exp < 0) {
        for (int i = 0; i < exp - 23; i++) {
            if (s21_get_bit(dst, 0)) {
                s21_mul(*dst, ten, dst);
                pow_ten++;
            }
            s21_Lshift(dst);
            if (pow_ten >= 28)
                break;
        }
    }
    for (int i = exp; i < 23; i++) {
        if (s21_get_bit(dst, 0)) {
            s21_mul(*dst, ten, dst);
            pow_ten++;
        }
        s21_Rshift(dst);
        if (pow_ten >= 28)
            break;
    }
    s21_set_exp(dst, pow_ten);
    return res;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
    if (s21_check_decimal(src))
        return 1;
    *dst = 0;
    long double result = 0, two = 1;
    for (int i = 0; i < 96; i++) {
        if (s21_get_bit(&src, i)) {
            result += two;
        }
        two *= 2.0;
    }
    for (int i = 0; i < s21_get_exp_dec(&src); i++) {
        result /= 10.0;
    }
    if (s21_get_sing(&src))
        result = -result;
    *dst = result;
    return 0;
}
