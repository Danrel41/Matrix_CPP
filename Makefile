CC = g++
FLAGS = -Wall -Werror -Wextra -std=c++17 -lm -fprofile-arcs -ftest-coverage
OS= $(shell uname)

ifeq ("$(OS)","Linux")
	TEST_FLAGS = -lgtest -lpthread
else
	TEST_FLAGS = -lgtest
endif

all: s21_matrix_oop.a test gcov_report

s21_matrix_oop.a:
	@${CC} ${FLAGS} -c *.cc 
	@ar rcs s21_matrix_oop.a *.o
	@ranlib s21_matrix_oop.a

test: s21_matrix_oop.a
	@${CC} ${FLAGS} tests/*.cc -o test.out ${TEST_FLAGS} -L. -l:s21_matrix_oop.a
	@valgrind --tool=memcheck --leak-check=yes --track-origins=yes ./test.out

gcov_report:
	@lcov -t "gcov_report" -o Coverage_Report.info -c -d .
	@genhtml -o ./report Coverage_Report.info
	@open ./report/src/index.html

clean:
	@rm -f *.o *.obj *.out *.gcda *.gcno *.info *.a
	@rm -rf report

rebuild: clean all