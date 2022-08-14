# DECIMAL
    Create type decimal for numbers from -(2^96 - 1) to (2^96 - 1)
-------------------------------------------------------------
decimal have 128 bytes
from 0 to 95 byte have mantisa
from 111 to 119 have pow of 10 (max in dec pow of ten: 28)
in 127 byte have sing '+' / '-'

    Example:
    mantisa 12345678
    pow: 4
    sing: 1 (127 byte == 1)
    res dec = 1234.5678
-------------------------------------------------------------
#MAKEFILE

    make s21_decimal.a: create library 
    make test: test for library, in use lib "check.h" last version in MacOS
                                         on Linux they can't work correctly
    make gcov-report: coverage report with help tests and create html page 
               (with gcovr) where you can see covarage and also information
    make clean: delete trust (*.o *.gcda and another)
-------------------------------------------------------------
ABOUT FUNC

    All function replace in dir library and sort

    About arithm func:
    Add, sub work very well, without errors

    about "MUL" in some cases I have error after convert decimal > float, but in binary view, all right

    func "DIV" work very well, BUT i think some edge situations can crash programm, becouse answer will be wrong

    function compare work very well

    another func work work on base bank rounding: 100.5 = 100, 101.5 = 102 (without 0.5 part -> if a % 2 != 0.0 a++)
