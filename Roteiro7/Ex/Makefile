all: compile run

compile:
	gcc *.c -o main

run:
	./main abra.txt 1 >out/abra.txt
	./main moby.txt 1 >out/moby.txt
	./main tale.txt 1 >out/tale.txt

debug: debug_compile debug_run

debug_compile:
	gcc *.c -Wall -Wextra -Werror -g -o main

debug_run:
	valgrind -s --leak-check=full --show-leak-kinds=all ./main in/abra.txt 1 >out/abra.txt