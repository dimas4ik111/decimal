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
    if (exp1 > exp2) {
        s21_pow_ballance(&dec_first, &dec_second);
    } else if (exp1 < exp2) {
        s21_pow_ballance(&dec_second, &dec_first);
    }
    if (singV1 > singV2) {
            res = FALSE;
    } else if (singV1 < singV2) {
            res = TRUE;
    } else if (singV1 == singV2) {
        if (dec_first.bits[2] > dec_second.bits[2]) {
            res = TRUE;
        } else if (dec_first.bits[2] < dec_second.bits[2]) {
            res = FALSE;
        } else {
            if (dec_first.bits[1] > dec_second.bits[1]) {
                res = TRUE;
            } else if (dec_first.bits[1] < dec_second.bits[1]) {
                res = FALSE;
            } else {
                if (dec_first.bits[0] > dec_second.bits[0]) {
                    res = TRUE;
                } else {
                    res = FALSE;
                }
            }
        }
    }
    if (s21_get_sing(&dec_first) + s21_get_sing(&dec_second) == 2) {
        res = !res;
    }
    return res;
}

int s21_is_less(s21_decimal dec_first, s21_decimal dec_second) {
    int res = TRUE;
    if (s21_is_greater(dec_first, dec_second) == TRUE) {
        res = FALSE;
    } else if (s21_is_equal(dec_first, dec_second) == TRUE) {
        res = FALSE;
    }
    return res;
}

int s21_is_greater_or_equal(s21_decimal dec_first, s21_decimal dec_second) {
    return (s21_is_greater(dec_first, dec_second) || s21_is_equal(dec_first, dec_second));
}

int s21_is_less_or_equal(s21_decimal dec_first, s21_decimal dec_second) {
    return (s21_is_less(dec_first, dec_second) || s21_is_equal(dec_first, dec_second));
}
