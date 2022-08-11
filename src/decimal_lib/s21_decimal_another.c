#include "../s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
    if (s21_check_decimal(value))
        return 1;
    s21_decimal_null(result);
    int res = 0;
    int sing = s21_get_bit(&value, 127);
    s21_decimal one;
    s21_from_int_to_decimal(10, &one);
    s21_decimal nuller;
    s21_decimal_null(&nuller);
    s21_decimal mod_res;

    s21_mod(value, one, &mod_res);
    s21_truncate(value, result);

    if (s21_is_not_equal(mod_res, nuller)) {
        if (sing) {
            s21_from_int_to_decimal(-1, &nuller);
            s21_add(*result, nuller, result);
        }
    }

    s21_set_bit(result, 127, sing);
    return res;
}

int s21_round(s21_decimal value, s21_decimal *result) {
    if (s21_check_decimal(value))
        return 1;
    s21_decimal_null(result);
    int res = 0;
    s21_decimal mod_val;
    s21_decimal trunc_val;
    s21_decimal five;
    s21_from_int_to_decimal(5, &five);
    s21_set_exp(&five, 1);
    s21_truncate(value, &trunc_val);
    float f;
    s21_sub(value, trunc_val, &mod_val);
    s21_from_decimal_to_float(mod_val, &f);
    if (f >= 0.5) {
        s21_decimal help_str;
        s21_from_int_to_decimal(1, &help_str);
        if (f == 0.5) {
            if (s21_get_bit(result, 0)) {
                s21_add(trunc_val, help_str, &trunc_val);
            }
        } else if (f > 0.5) {
            s21_add(trunc_val, help_str, &trunc_val);
        }
        *result = trunc_val;
    } else if (f <= -0.5) {
        s21_decimal help_str;
        s21_from_int_to_decimal(-1, &help_str);
        s21_add(trunc_val, help_str, &trunc_val);
        *result = trunc_val;

    } else {
        *result = trunc_val;
    }

    return res;
}

int s21_truncate(s21_decimal value, s21_decimal *result) {
    if (s21_check_decimal(value))
        return 1;
    s21_decimal_null(result);
    int res = 0;
    int flag = 0;
    if (s21_get_bit(&value, 127)) {
        flag = 1;
    }
    s21_set_bit(&value, 127, 0);
    int exp = s21_get_exp_dec(&value);
    s21_decimal power_ten;
    s21_from_int_to_decimal(10, &power_ten);
    s21_set_exp(&value, 0);
    for (int i = 0; i < exp; i++) {
        s21_binary_div(value, power_ten, &value);
    }
    *result = value;
    if (flag) {
        s21_sing_dec(result);
    }
    return res;
}

int s21_negate(s21_decimal value, s21_decimal *result) {
    if (s21_check_decimal(value))
        return 1;
    int res = 0;
    if (result != NULL && value.bits[0] <= ALLISONE_OVERFLOW) {
        value.bits[3] ^= 0x80000000;
        *result = value;
    } else {
        res = 1;
    }
    return res;
}
