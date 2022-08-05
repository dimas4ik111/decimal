#include "../s21_decimal.h"

void s21_sub_cicle();

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    s21_decimal_null(result);
    int res = 0, singV1 = s21_get_sing(&value_1), singV2 = s21_get_sing(&value_2);
    int exp1 = s21_get_exp_dec(&value_1);
    int exp2 = s21_get_exp_dec(&value_2);
    if (exp1 > exp2) {
        s21_set_exp(result, s21_pow_ballance(&value_1, &value_2));
    } else if (exp1 < exp2) {
        s21_set_exp(result, s21_pow_ballance(&value_2, &value_1));
    }

    if (singV1 < singV2) {
        s21_set_bit(&value_2, 127, 0);
        res = s21_sub(value_1, value_2, result);
    } else if (singV1 + singV2 == 2) {
        res = s21_binary_add(value_1, value_2, result);
        s21_sing_dec(result);
    } else if (singV1 > singV2) {
        s21_set_bit(&value_1, 127, 0);
        res = s21_sub(value_2, value_1, result);
    } else if (singV1 + singV2 == 0) {
        res = s21_binary_add(value_1, value_2, result);
    }

    if (exp1 == exp2) {
        s21_set_exp(result, exp1);
    }
    return res;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    s21_decimal_null(result);
    int res = 0, singV1 = s21_get_sing(&value_1), singV2 = s21_get_sing(&value_2);
    int exp1 = s21_get_exp_dec(&value_1);
    int exp2 = s21_get_exp_dec(&value_2);

    if (exp1 > exp2) {
        s21_set_exp(result, s21_pow_ballance(&value_1, &value_2));
    } else if (exp1 < exp2) {
        s21_set_exp(result, s21_pow_ballance(&value_2, &value_1));
    }

    if (singV1 + singV2 == 0) {
        if (s21_is_greater_or_equal(value_1, value_2)) {
            res = s21_binary_sub(value_1, value_2, result);
        } else {
            res = s21_binary_sub(value_2, value_1, result);
            s21_sing_dec(result);
        }
    } else if (singV1 > singV2) {
        s21_binary_add(value_1, value_2, result);
        s21_sing_dec(result);
    } else if (singV1 + singV2 == 2) {
        s21_set_bit(&value_1, 127, 0);
        s21_set_bit(&value_2, 127, 0);
        res = s21_sub(value_2, value_1, result);
    } else if (singV1 < singV2) {
        s21_set_bit(&value_2, 127, 0);
        res = s21_binary_add(value_1, value_2, result);
    }

    if (exp1 == exp2) {
        s21_set_exp(result, exp1);
    }
    return res;
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    s21_decimal_null(result);
    int res = 0, singV1 = s21_get_sing(&value_1), singV2 = s21_get_sing(&value_2);
    int exp1 = s21_get_exp_dec(&value_1);
    int exp2 = s21_get_exp_dec(&value_2);

    res = s21_binary_mul(value_1, value_2, result);
    if ((singV1 == 1 && singV2 == 0) || (singV1 == 0 && singV2 == 1)) {
        s21_sing_dec(result);
    }
    s21_set_exp(result, exp1 + exp2);
    return res;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    s21_decimal nuller;
    s21_decimal_null(&nuller);
    if (s21_is_equal(value_2, nuller))
        return 3;

    s21_decimal_null(result);
    int res = 0, singV1 = s21_get_sing(&value_1), singV2 = s21_get_sing(&value_2);
    int exp1 = s21_get_exp_dec(&value_1);
    int exp2 = s21_get_exp_dec(&value_2);

    s21_decimal ten_num;
    s21_from_int_to_decimal(10, &ten_num);

    if (exp1 > exp2) {
        s21_pow_ballance(&value_1, &value_2);
    } else if (exp1 < exp2) {
        s21_pow_ballance(&value_2, &value_1);
    }

    value_1.bits[3] = 0;
    value_2.bits[3] = 0;

    if (!s21_is_equal(value_1, nuller)) {
        res = s21_binary_div(value_1, value_2, result);
        s21_decimal res_mod;
        s21_decimal partial_res;
        s21_mod(value_1, value_2, &res_mod);
        if (s21_is_not_equal(res_mod, nuller)) {
            s21_decimal ten;
            s21_from_int_to_decimal(10, &ten);
            s21_mul(res_mod, ten, &res_mod);
            partial_res = res_mod;

            while (s21_is_not_equal(res_mod, nuller)) {
                s21_decimal copy_res = *result;

                if (s21_get_exp_dec(result) == 28 || s21_mul(copy_res, ten, &copy_res) > 0) {
                    break;
                }

                *result = copy_res;
                s21_set_exp(result, s21_get_exp_dec(result) + 1);

                s21_binary_div(res_mod, value_2, &partial_res);
                s21_mod(res_mod, value_2, &res_mod);
                if (s21_is_equal(res_mod, nuller)) {
                    s21_set_exp(&partial_res, s21_get_exp_dec(result));
                    s21_add(*result, partial_res, result);
                    break;
                } else {
                    s21_set_exp(&partial_res, s21_get_exp_dec(result));
                    s21_add(*result, partial_res, result);
                    s21_mul(res_mod, ten, &res_mod);
                }
            }
        }

        if ((singV1 == 1 && singV2 == 0) || (singV1 == 0 && singV2 == 1)) {
            s21_sing_dec(result);
        }
    } else {
        *result = nuller;
        s21_set_bit(result, 127, 0);
    }

    return res;
}

int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    if (value_2.bits[0] == 0
        && value_2.bits[1] == 0
        && value_2.bits[2] == 0)
        return 3;

    int res = 0;
    int exp1 = s21_get_exp_dec(&value_1);
    int exp2 = s21_get_exp_dec(&value_2);
    if (exp1 > exp2) {
        s21_set_exp(result, s21_pow_ballance(&value_1, &value_2));
    } else if (exp1 < exp2) {
        s21_set_exp(result, s21_pow_ballance(&value_2, &value_1));
    }

    s21_decimal help_struct;
    s21_decimal_null(result);
    s21_binary_div(value_1, value_2, &help_struct);
    s21_mul(help_struct, value_2, &help_struct);
    s21_sub(value_1, help_struct, result);
    return res;
}

int s21_binary_div(s21_decimal a, s21_decimal b, s21_decimal *res) {
    int answer = 0;
    int k1 = 0, k2 = 0, k = 0;
    s21_decimal ib = b;
    s21_decimal nuller;
    s21_decimal copy_b = b;
    s21_decimal partial;
    int h = -111;
    s21_decimal_null(res);
    s21_decimal_null(&nuller);
    s21_decimal_null(&partial);

    for (int i = 95; i > -1; i--) {
        if (s21_get_bit(&a, i)) {
            k1 = i;
            break;
        }
    }

    for (int i = 95; i > -1; i--) {
        if (s21_get_bit(&b, i)) {
            k2 = i;
            break;
        }
    }
    k  = (k1 - k2);
    for (int i = 0; i < k; i++) {
        s21_Lshift(&copy_b);
    }
    s21_reverse_dec(copy_b, &ib);
    for (int i = -1; i < k; i++) {
        if (i == -1) {
            s21_binary_add(a, ib, &partial);
            if (s21_get_bit(&partial, 95)) {
                s21_set_bit(res, 0, 0);
            } else {
                s21_set_bit(res, 0, 1);
            }
        }
        if (k > 0 && i != -1) {
            if (i == 0)
                s21_Lshift(res);
            int help_bit = s21_Lshift(&partial);
            s21_set_bit(&partial, 95, help_bit);
            if (s21_get_bit(&partial, 95)) {
                s21_binary_add(partial, copy_b, &partial);
            } else {
                s21_binary_add(partial, ib, &partial);
            }
            if (s21_get_bit(&partial, 95)) {
                s21_set_bit(res, 0, 0);
            } else {
                s21_set_bit(res, 0, 1);
            }
            partial.bits[3] = 0;
            if (s21_is_equal(partial, nuller) || s21_is_less(partial, b)) {
                if (i != k - 1) {
                    h = i;
                }
                break;
            }
            if (i != k - 1)
                s21_Lshift(res);
        }
    }
    if (h != -111) {
        for (int i = h; i < k - 1; i++) {
            s21_Lshift(res);
        }
    }
    return answer;
}

int s21_binary_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    for (int i = 0; i < 96; i++) {
        int bit1 = s21_get_bit(&value_1, i), bit2 = s21_get_bit(&value_2, i);
        if (bit1 - bit2 >= 0) {
            s21_set_bit(result, i, bit1 - bit2);
        } else if (bit1 - bit2 < 0) {
            s21_set_bit(result, i, 1);
            s21_sub_cicle(&value_1, i + 1);
        }
    }
    return 0;
}

int s21_binary_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    int buf_bit = 0;
    int res = 0;
    for (int i = 0; i <= 95; i++) {
        if ((s21_get_bit(&value_1, i) + s21_get_bit(&value_2, i)) <= 1 && buf_bit == 0) {
            s21_set_bit(result, i, s21_get_bit(&value_1, i) + s21_get_bit(&value_2, i));
            buf_bit = 0;
        } else if ((s21_get_bit(&value_1, i) + s21_get_bit(&value_2, i)) <= 1 && buf_bit == 1) {
            if ((s21_get_bit(&value_1, i) + s21_get_bit(&value_2, i)) + buf_bit > 1) {
                s21_set_bit(result, i, 0);
                buf_bit = 1;
            } else {
                s21_set_bit(result, i, buf_bit);
                buf_bit = 0;
            }
        } else if ((s21_get_bit(&value_1, i) + s21_get_bit(&value_2, i)) == 2 && buf_bit == 0) {
            s21_set_bit(result, i, 0);
            buf_bit = 1;
        } else if ((s21_get_bit(&value_1, i) + s21_get_bit(&value_2, i)) == 2 && buf_bit == 1) {
            s21_set_bit(result, i, 1);
            buf_bit = 1;
        } else {
            s21_set_bit(result, i, 0);
        }
    }
    if (buf_bit != 0) {
        res = 1;
    }
    return res;
}

int s21_binary_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    int res = 0;
    s21_decimal helpStruct;
    s21_decimal_null(result);
    int high_bit = 0;
    for (int i = 95; i >= 0; i--) {
        if (s21_get_bit(&value_1, i)) {
            high_bit = i;
            break;
        }
    }
    for (int i = 0; i < 96; i++) {
        s21_decimal_null(&helpStruct);
        if (s21_get_bit(&value_2, i)) {
            if (high_bit + i > 95) {
                res = 1;
                break;
            }
            helpStruct = value_1;
            for (int j = 0; j < i; j++) {
                s21_Lshift(&helpStruct);
            }
            res = s21_binary_add(*result, helpStruct, result);
        }
        if (res)
            break;
    }
    return res;
}

void s21_sub_cicle(s21_decimal *v, int i) {
    for (int j = i; j < 96; j++) {
        int helpBit = s21_get_bit(v, j);
        if (helpBit == 1) {
            for (int n = i - 1; n < j; n++) {
                s21_set_bit(v, n, 1);
            }
            s21_set_bit(v, j, 0);
            break;
        }
    }
}
