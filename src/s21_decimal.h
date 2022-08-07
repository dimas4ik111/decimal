#ifndef SRC_S21_DECIMAL_H_
#define SRC_S21_DECIMAL_H_

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

//comparison
#define TRUE 1
#define FALSE 0

// overflow
#define ALLISONE_OVERFLOW 0x7FFFFFFF  // 0 11111111 11111111111111111111111
#define MINUS_EXP_ALL_ONE 0xFF800000  // 1 11111111 00000000000000000000000
#define PLUS_EXP_ALL_ONE 0x7F800000  //  0 11111111 00000000000000000000000

// color
#define RED "\033[0;31m"
#define YELLOW "\033[93m"
#define RESET "\033[0m"
#define GREEN   "\033[32m"
#define MAGENTA "\033[35m"

typedef struct {
    unsigned int bits[4]; 
} s21_decimal;

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_is_less(s21_decimal dec_first, s21_decimal dec_second);
int s21_is_less_or_equal(s21_decimal dec_first, s21_decimal dec_second);
int s21_is_greater(s21_decimal dec_first, s21_decimal dec_second);
int s21_is_greater_or_equal(s21_decimal dec_first, s21_decimal dec_second);
int s21_is_equal(s21_decimal dec_first, s21_decimal dec_second);
int s21_is_not_equal(s21_decimal dec_first, s21_decimal dec_second);

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

int s21_get_bit(s21_decimal *var, int bit);
void s21_set_bit(s21_decimal *var, int bit, int val);
int s21_get_exp_float(long double n);
void s21_set_exp(s21_decimal *var, int ten);
void s21_print_binary_decimal(s21_decimal var, int n);
void s21_print_exp_bit(s21_decimal *var);
void s21_sing_dec(s21_decimal *var);
void s21_print_reverse_decimal(s21_decimal var, int n, int exp);
int s21_get_exp_dec(s21_decimal *var);
s21_decimal* s21_decimal_null(s21_decimal *var);
int s21_get_sing(s21_decimal *var);
int s21_binary_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_binary_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_check_decimal(s21_decimal dst);
int s21_pow_ballance(s21_decimal* a, s21_decimal* b);
int s21_binary_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_binary_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
s21_decimal* s21_reverse_dec(s21_decimal src, s21_decimal *res);
int s21_Lshift(s21_decimal* src);
int s21_mini_cicle_ballance(s21_decimal *var, s21_decimal ten, int n, int *flag);
int s21_Rshift(s21_decimal* src);
int s21_from_float_to_decimal_help(float src, s21_decimal *dst);
void s21_bank_round(s21_decimal *dst);

#endif  // SRC_S21_DECIMAL_H_
