all: compile run

VALGRIND_FLAGS = -s --leak-check=full --show-leak-kinds=all

compile:
	gcc *.c -o main

run:
	./main in/abra.txt 1 >out/abra.txt
	./main in/moby.txt 1 >out/moby.txt
	./main in/tale.txt 1 >out/tale.txt

test: debug_compile run_test

run_test:
	valgrind $(VALGRIND_FLAGS) ./main test.txt 1

debug: debug_compile debug_run

debug_compile:
	gcc *.c -Wall -Wextra -Werror -g -o main

debug_run:
	valgrind $(VALGRIND_FLAGS) ./main in/abra.txt 1 >out/abra.txt