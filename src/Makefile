OS = $(shell uname)
CC = g++ -Wall -Werror -Wextra -std=c++17 -g
GCOV_FLAG = --coverage #-fprofile-arcs -ftest-coverage

ifeq ($(OS), Linux)
	OPEN_CMD = xdg-open
	GTEST_FLAGS = -lgtest -lgtest_main -pthread
endif
ifeq ($(OS), Darwin)
	OPEN_CMD = open
	LCOV_FLAG = --ignore-errors inconsistent
	GTEST_FLAGS = -lgtest -lgmock -pthread # -lgtest_main
endif

DIR_PROJECT = ./project/
DIR_TESTS = ./tests/
STAT_LIB = s21_matrix_oop.a
EXECUTABLE = test_matrix
FILES_SRC = $(wildcard $(DIR_PROJECT)*.cpp)
FILES_TESTS = $(wildcard $(DIR_TESTS)*.cpp)

$(STAT_LIB): clean
	@$(CC) $(GCOV_FLAG) $(FILES_SRC) -c
	@ar rc $(STAT_LIB) *.o
	@ranlib $(STAT_LIB)
	@-rm -rf *.o

test: $(STAT_LIB)
	@$(CC) $(FILES_TESTS) $(STAT_LIB) -o $(EXECUTABLE) $(GTEST_FLAGS) $(GCOV_FLAG) 
	@./$(EXECUTABLE)

gcov_report: $(STAT_LIB) test
	@./$(EXECUTABLE)
	@lcov -o test.info --no-external -c -d . $(LCOV_FLAG)
	@genhtml -o report test.info $(LCOV_FLAG)
	@$(OPEN_CMD) report/index.html
	@rm -rf *.gcda *.gcno *.info *.dSYM 

clean:
	@rm -rf *.a *.o
	@rm -rf $(EXECUTABLE)
	@rm -rf *.gcda *.gcno *.info *.dSYM 
	@rm -rf report

leaks: test
	@leaks -atExit -- ./$(EXECUTABLE) | grep LEAK:

valgrind: test
	@valgrind --tool=memcheck --leak-check=yes ./$(EXECUTABLE)
#	@CK_FORK=no valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(EXECUTABLE)

style_cp:
	cp ../materials/linters/.clang-format ../src  

style_preparation: clean style_cp
	clang-format -style=Google -i $(DIR_PROJECT)*.cpp $(DIR_PROJECT)*.h
	clang-format -style=Google -i $(DIR_TESTS)*.cpp $(DIR_TESTS)*.h
	@rm -rf .clang-format

style_check: clean style_cp
	clang-format -style=Google -n $(DIR_PROJECT)*.cpp $(DIR_PROJECT)*.h
	clang-format -style=Google -n $(DIR_TESTS)*.cpp $(DIR_TESTS)*.h
	@rm -rf .clang-format

# Цель по умолчанию
all:

.PHONY: all clean test