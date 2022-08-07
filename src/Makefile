CC=gcc
CFLAGS=-Wall -Wextra -Werror -pedantic -std=c11
CFLAGS_T=--coverage
RM=rm -rf
SRC=./decimal_lib/s21_decimal_another.c \
	./decimal_lib/s21_decimal_arithm.c \
	./decimal_lib/s21_decimal_compar.c \
	./decimal_lib/s21_decimal_convert.c \
	./decimal_lib/s21_decimal_help.c
SRC_TEST=./decimal_test/s21_test_decimal.c \
	./decimal_test/test_another.c \
	./decimal_test/test_arithm.c \
	./decimal_test/test_compar.c \
	./decimal_test/test_convert.c \
	./decimal_test/test_help.c
OBJ_REP_DIR=./report_obj/
OBJ_DIR=./obj/
OBJ=$(SRC:.c=.o)
OBJ_TEST=$(SRC_TEST:.c=.o)
LIB=s21_decimal.a

all : $(LIB) test gcov_report

rebuild : clean $(LIB) test gcov_report

$(LIB) : $(OBJ) s21_decimal.h
	ar rcs $(LIB) $(OBJ)
	ranlib s21_decimal.a

test : $(LIB) $(OBJ_TEST)
	$(CC) $(CFLAGS) $^ -lcheck -lgcov -o s21_tests_decimal.out
	./s21_tests_decimal.out

gcov_report: $(LIB) $(OBJ_TEST) s21_decimal_another_t.o s21_decimal_arithm_t.o s21_decimal_compar_t.o s21_decimal_convert_t.o s21_decimal_help_t.o
	@$(CC) $(CFLAGS) $(OBJ_REP_DIR)*.o $(LIB) $(OBJ_TEST) -lcheck -lgcov -o s21_tests_decimal.out
	@./s21_tests_decimal.out
	@echo
	# @echo -------------------| COVERAGE |-------------------
	@echo
	@gcov -a -b ./report_obj/*.gcda
	# @echo -----------------| END COVERAGE |-----------------
	@echo
	@gcovr --html-details coverage.html

s21_decimal_another_t.o : ./decimal_lib/s21_decimal_another.c
	@$(CC) $(CFLAGS) $(CFLAGS_T) -c $< -o $(OBJ_REP_DIR)$@
s21_decimal_arithm_t.o : ./decimal_lib/s21_decimal_arithm.c
	@$(CC) $(CFLAGS) $(CFLAGS_T) -c $< -o $(OBJ_REP_DIR)$@
s21_decimal_compar_t.o : ./decimal_lib/s21_decimal_compar.c
	@$(CC) $(CFLAGS) $(CFLAGS_T) -c $< -o $(OBJ_REP_DIR)$@
s21_decimal_convert_t.o : ./decimal_lib/s21_decimal_convert.c
	@$(CC) $(CFLAGS) $(CFLAGS_T) -c $< -o $(OBJ_REP_DIR)$@
s21_decimal_help_t.o : ./decimal_lib/s21_decimal_help.c
	@$(CC) $(CFLAGS) $(CFLAGS_T) -c $< -o $(OBJ_REP_DIR)$@


clean:
	$(RM) ./decimal_lib/*.o
	$(RM) ./decimal_test/*.o
	$(RM) *.out *.a
	$(RM) *.gcov
	$(RM) ./report_obj/*.gcno
	$(RM) ./report_obj/*.gcda
	$(RM) ./report_obj/*.o
	$(RM) coverage.*

rebuild : clean all

# не отображать в консоль команды
.SILENT: $(OBJ) $(OBJ_TEST) $(OBJ_REPORT) $(LIB) test clean

# фальшивая цель
.PHONY: all test clean rep