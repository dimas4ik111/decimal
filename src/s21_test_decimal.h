#ifndef SRC_S21_TEST_DECIMAL_H_
#define SRC_S21_TEST_DECIMAL_H_

#include <check.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <locale.h>
#include <stdlib.h>
#include "s21_decimal.h"

Suite *s21_test_decimal_convert();
Suite *s21_test_compare();
Suite* s21_test_help();
Suite* s21_test_another();
Suite* s21_test_arithm();
char* s21_str_bits_test(char* str_bit, s21_decimal res);

#endif  // SRC_S21_TEST_DECIMAL_H_