all: compile comparation

N ?= 1000

loop:
	@for i in $$(seq 1 $(N)); do \
		$(MAKE) run; \
	done

compile:
	gcc *.c -o main &

run:
	./main 1000000 >> heights.txt &

comparation:
	./main 10000000

debug:
	gcc *.c -c -Wall -Wextra -Werror
	gcc *.o -o main
	rm *.o
	valgrind -s --leak-check=full --show-leak-kinds=all ./main 10