// Операции сравнения
#include "../s21_decimal.h"

// 0 - FALSE
// 1 - TRUE

int s21_is_equal(s21_decimal dec_first, s21_decimal dec_second) {
    int res = TRUE;
    if (dec_first.bits[0] != dec_second.bits[0] ||
        dec_first.bits[1] != dec_second.bits[1] ||
        dec_first.bits[2] != dec_second.bits[2] ||
        dec_first.bits[3] != dec_second.bits[3])
        res = FALSE;
    return res;
}

int s21_is_not_equal(s21_decimal dec_first, s21_decimal dec_second) {
    return (!s21_is_equal(dec_first, dec_second));
}

int s21_is_greater(s21_decimal dec_first, s21_decimal dec_second) {
    int res = FALSE, singV1 = s21_get_sing(&dec_first), singV2 = s21_get_sing(&dec_second);
    int exp1 = s21_get_exp_dec(&dec_first);
    int exp2 = s21_get_exp_dec(&dec_second);
    s21_pow_ballance(&dec_first, &dec_second);
    if (singV2 < singV1) {
        res = 0;
    } else if (singV1 < singV2) {
        res = 1;
    } else if (singV1 == singV2) {
        int bits1 = 0;
        int bits2 = 0;
        for (int i = 95; i >= 0; i--) {
            bits1 = s21_get_bit(&dec_first, i);
            bits2 = s21_get_bit(&dec_second, i);
            if (bits1 > bits2) {
                res = 1;
                break;
            } else if (bits1 < bits2) {
                res = 0;
                break;
            }
        }
    }
    if (singV1 + singV2 == 2) {
        res = !res;
    }
    return res;
}

int s21_is_less(s21_decimal dec_first, s21_decimal dec_second) {
    return !s21_is_greater_or_equal(dec_first, dec_second);
}

int s21_is_greater_or_equal(s21_decimal dec_first, s21_decimal dec_second) {
    return (s21_is_greater(dec_first, dec_second) || s21_is_equal(dec_first, dec_second));
}

int s21_is_less_or_equal(s21_decimal dec_first, s21_decimal dec_second) {
    return (s21_is_less(dec_first, dec_second) || s21_is_equal(dec_first, dec_second));
}
