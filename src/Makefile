#===========================================================================
CC = gcc
FLAGS = -std=c11 -Wall -Werror -Wextra -lm
#===========================================================================
TARGET = s21_matrix.a
#===========================================================================
OS := $(shell uname -s)
#===========================================================================
ifeq ($(OS),Linux)
    TEST_FLAGS = -lcheck -lrt -lpthread -lsubunit -lm
else
    TEST_FLAGS = -lcheck -lm
endif
#===========================================================================
all: $(TARGET)

$(TARGET):
	$(CC) $(FLAGS) -c functions/*.c
	ar rcs $(TARGET) *.o
	ranlib $(TARGET)
	rm -rf *.o

test: $(TARGET)
	$(CC) tests/test.c $(TARGET) $(TEST_FLAGS) -o test.out
	./test.out

gcov_report:
	$(CC) tests/test.c functions/*.c $(TEST_FLAGS) --coverage -o coverage.out
	./coverage.out
	lcov -c -d ./ -o coverage.info
	genhtml -o coverage_html coverage.info 
	open coverage_html/index.html

clang_i:
	clang-format -i -style=Google *.h functions/*.c tests/*.c

clang_n:
	clang-format -n -style=Google *.h functions/*.c tests/*.c

clean:
	rm -rf coverage_html *.gcno *.gcda *.out *.info *.a *.o

rebuild: clean all
#===========================================================================