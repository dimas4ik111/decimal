#include "../s21_decimal.h"

int s21_check_decimal(s21_decimal dst) {
    int res;
    for (int i = 0; i < 128; i++) {
        if (((i > 95 && i < 95 + 15) || (i >= 120 && i <= 126)) && s21_get_bit(&dst, i)) {
            res = 1;
            break;
        } else {
            res = 0;
        }
    }
    return res;
}

int s21_get_bit(s21_decimal *var, int bit) {
    int res = 0;
    if (bit / 32 < 4) {
        res = var->bits[bit / 32] & (1u << (bit % 32));
    }
    return !!res;
}

void s21_set_bit(s21_decimal *var, int bit, int val) {
    unsigned int helpbit = 1u << (bit % 32);
    if (bit / 32 < 4) {
        if (val) {
            var->bits[bit / 32] = var->bits[bit / 32] | helpbit;
        } else if (!val) {
            var->bits[bit / 32] = var->bits[bit / 32] & ~helpbit;
        }
    }
}

void s21_set_exp(s21_decimal *var, int ten) {
    if (ten == 0) {
        for (int i = 96 + 15; i <= 96 + 23; i++) {
            s21_set_bit(var, i, 0);
        }
    } else {
        for (int i = 96 + 15; i <= 96 + 23; i++) {
            if (ten == 0) {
                break;
            } else {
                s21_set_bit(var, i, (ten % 2));
            }
            ten /= 2;
        }
    }
}

void s21_print_binary_decimal(s21_decimal var, int n) {
    printf("\n");
    for (int i = n - 1; i >= 0; i--) {
        int bit = s21_get_bit(&var, i);
        if (i == 127) {
            printf("%s%u%s", GREEN, bit, RESET);
        } else if (i < 127 - 8 && i >= 127 - 16) {
            printf("%s%u%s", GREEN, bit, RESET);
        } else if ((i < 127 && i >= 127 - 8) || (i < 127 - 16 && i > 95)) {
            printf("%s%u%s", RED, bit, RESET);
        } else {
            if (bit == 1) {
                printf("%s%u%s", YELLOW, bit, RESET);
            } else if (bit == 0) {
                printf("%s%u%s", MAGENTA, bit, RESET);
            }
        }
        if (i == 32 || i == 64 || i == 96) {
            printf(" ");
        }
    }
    printf("\n");
}

void s21_print_exp_bit(s21_decimal *var) {
    printf("\nEXP = ");
    for (int i = 96 + 23; i >= 96 + 15; i--) {
        printf("%s%d%s", GREEN, s21_get_bit(var, i), RESET);
    }
    printf("\n");
}

int s21_get_exp_dec(s21_decimal *var) {
    int res = 0;
    int doubleMas[9];
    int n = 8;
    for (int i = 127 - 8; i >= 96 + 15; i--) {
        if (s21_get_bit(var, i)) {
            doubleMas[n] = 1;
        } else {
            doubleMas[n] = 0;
        }
        n--;
    }
    int step = 0;
    for (int i = 0; i < 9; i++) {
        res += doubleMas[i] * (int)pow(2, step);
        step++;
    }
    return res;
}

void s21_sing_dec(s21_decimal *var) {
    var->bits[3] |= (1u << 31);
}

int s21_get_sing(s21_decimal *var) {
    return !!(var->bits[3] & 1u << 31);
}

s21_decimal* s21_decimal_null(s21_decimal *var) {
    var->bits[0] = 0;
    var->bits[1] = 0;
    var->bits[2] = 0;
    var->bits[3] = 0;
    return var;
}

int s21_pow_ballance(s21_decimal *a, s21_decimal *b) {
    int an = s21_get_exp_dec(a);
    int bn = s21_get_exp_dec(b);
    s21_decimal ten;
    s21_from_int_to_decimal(10, &ten);
    s21_decimal copy_b = *b;
    for (int i = bn; i < an; i++) {
        if (s21_binary_mul(copy_b, ten, &copy_b) > 0) {
            break;
        }
        bn++;
        *b = copy_b;
    }
    if (bn != an) {
        while (an != bn) {
            s21_bank_round(a);
            an--;
        }
    }
    s21_set_exp(a, bn);
    s21_set_exp(b, bn);
    return bn;
}

int s21_Lshift(s21_decimal* src) {
    int bit0, bit1, bit2;
    bit0 = s21_get_bit(src, 31);
    bit1 = s21_get_bit(src, 63);
    bit2 = s21_get_bit(src, 95);
    src->bits[0] <<= 1;
    src->bits[1] <<= 1;
    src->bits[2] <<= 1;
    s21_set_bit(src, 32, bit0);
    s21_set_bit(src, 64, bit1);
    return bit2;
}

int s21_Rshift(s21_decimal* src) {
    int bit0, bit1;
    bit0 = s21_get_bit(src, 32);
    bit1 = s21_get_bit(src, 64);
    src->bits[0] >>= 1;
    src->bits[1] >>= 1;
    src->bits[2] >>= 1;
    s21_set_bit(src, 31, bit0);
    s21_set_bit(src, 63, bit1);
    return 0;
}

s21_decimal* s21_reverse_dec(s21_decimal src, s21_decimal *res) {
    s21_decimal_null(res);
    for (int i = 0; i < 96; i++) {
        if (s21_get_bit(&src, i)) {
            s21_set_bit(res, i, 0);
        } else {
            s21_set_bit(res, i, 1);
        }
    }
    s21_decimal_null(&src);
    s21_set_bit(&src, 0, 1);
    s21_binary_add(*res, src, res);
    return res;
}

void s21_bank_round(s21_decimal *dst) {
    s21_decimal ten;
    s21_from_int_to_decimal(10, &ten);
    int exp = s21_get_exp_dec(dst);
    s21_set_exp(dst, 0);
    s21_decimal copy_of_dst = *dst;
    
    s21_binary_div(copy_of_dst, ten, &copy_of_dst);
    s21_binary_mul(copy_of_dst, ten, &copy_of_dst);

    s21_decimal last_num;
    s21_sub(*dst, copy_of_dst, &last_num);

    s21_decimal five;
    s21_from_int_to_decimal(5, &five);

    s21_binary_div(*dst, ten, dst);
    s21_set_exp(dst, exp - 1);

    if (s21_is_greater_or_equal(last_num, five)) {
        ten.bits[0] = 1;
        s21_binary_add(*dst, ten, dst);
    }
}
